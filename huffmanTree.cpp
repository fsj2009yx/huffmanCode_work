#include "huffmanTree.h"
#include<QFile>
HaffmanCode::HaffmanCode(const string &text)
{
    root=buildHuffmanTree(text);
    buildDict(root,"", dict);
}

HaffmanCode::~HaffmanCode()
{
    freeTree(root);
}

Node* HaffmanCode::buildHuffmanTree(const string& text)
{
    unordered_map<char, int> frequency; // 字符频率的映射
    for (char c : text) {
        frequency[c]++; // 统计字符频率
    }

    priority_queue<Node*, vector<Node*>, Compare> minHeap; // 优先队列，用于构建Huffman树

    // 将所有字符及其频率放入优先队列
    for (auto& pair : frequency) {
        minHeap.push(new Node(pair.first, pair.second));//（字符，字符频率）
    }

    // 合并节点直到只剩一个节点
    while (minHeap.size() > 1)
    {
        Node* left = minHeap.top(); minHeap.pop(); // 取出频率最小的两个节点
        Node* right = minHeap.top(); minHeap.pop();
        Node* newNode = new Node('\0', left->frequency + right->frequency); // 创建新节点，频率为左右子节点频率之和
        newNode->left = left; // 将两个节点作为新节点的子节点
        newNode->right = right;
        minHeap.push(newNode); // 将新节点放入优先队列
    }
    return minHeap.top(); // 返回根节点
}

void HaffmanCode::buildDict(Node* root, const string& code, unordered_map<char, string>& dict)
{
    if (!root) return; //节点为空返回

    if (root->data != '\0') {
        dict[root->data] = code; // 记录字符对应的编码
    }
    // 递归构建字典
    buildDict(root->left, code + "0", dict); // 左子树编码加 0
    buildDict(root->right, code + "1", dict); // 右子树编码加 1
}

void HaffmanCode::freeTree(Node* root)
{
    if (root)
    {
        freeTree(root->left); // 递归释放左子树
        freeTree(root->right); // 递归释放右子树
        delete root; // 释放当前节点
    }
}

string HaffmanCode::encode(const string& text)
{
    string encodedString;//二进制字符串
    for (char c : text) {
        encodedString += dict[c]; // 根据编码表拼接编码字符串
    }
    return encodedString;
}

int HaffmanCode::writeToFile(const string& filename, const string& text)
{
    ofstream ofs(filename, ios::binary);//binary以二进制模式打开文件
    if (!ofs)
    {
        qDebug() << "Failed to open file for writing." ;
        return -1;
    }

    // 写入字典的大小
    uint32_t dictSize = dict.size();
    ofs.write(reinterpret_cast<const char*>(&dictSize), sizeof(dictSize));//reinterpret_cast将dictSize转换为char类型写入文件

    // 写入字典内容
    for (const auto& pair : dict)
    {
        char character = pair.first;
        string code = pair.second;
        ofs.write(&character, sizeof(character)); // 写入字符
        uint8_t codeLength = code.size();//编码长度（8位无符号整数）
        ofs.write(reinterpret_cast<const char*>(&codeLength), sizeof(codeLength));// 写入编码的长度
        ofs.write(code.data(), codeLength); // 写入编码
    }

    // 写入编码数据
    string encodedString = encode(text);
    vector<uint8_t> binaryData((encodedString.size() + 7) / 8, 0); // 计算字节数

    for (size_t i = 0; i < encodedString.size(); ++i)
    {
        if (encodedString[i] == '1')
        {
            binaryData[i / 8] |= (1 << (7 - (i % 8))); // 设置对应的位
        }
    }

    ofs.write(reinterpret_cast<const char*>(binaryData.data()), binaryData.size());
    ofs.close();
    QFile out(QString::fromStdString(filename));
    quint64 Size=out.size();
    int sizeKB=static_cast<int>(qFloor(static_cast<double>(Size)/1024.0));//转为KB
    return sizeKB;
}
