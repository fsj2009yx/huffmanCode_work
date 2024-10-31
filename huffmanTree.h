#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H

#include<string>
#include<QDebug>
#include<queue>
#include <unordered_map>
#include <vector>
#include <fstream>
using namespace std;

// 哈夫曼树节点
struct Node {
    char data;       // 节点存储的字符
    int frequency;   // 字符出现的频率（权值）
    Node* left;      // 左子树指针
    Node* right;     // 右子树指针

    Node(char data, int frequency) : data(data), frequency(frequency), left(nullptr), right(nullptr) {}
};

// 比较节点频率的优先队列
struct Compare {
    bool operator()(Node* left, Node* right) {
        return left->frequency > right->frequency; //频率小的优先级高
    }
};

class HaffmanCode
{
public:
    HaffmanCode(const string& text);
    ~HaffmanCode();
    int writeToFile(const string& filename,const string &text);//将编码写入文件
private:
    Node* root;//哈夫曼树根节点
    unordered_map<char, string> dict;//哈夫曼编码字典
    Node* buildHuffmanTree(const string& text);//构建哈夫曼树
    void buildDict(Node* root, const string& code, unordered_map<char, string>& dict);//生成哈夫曼编码
    string encode(const string& text);//编码
    void freeTree(Node* root);//释放哈夫曼树
};
#endif // HUFFMANTREE_H
