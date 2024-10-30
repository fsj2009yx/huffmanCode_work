#include "huffmanDecode.h"

unordered_map<string, char> readDictionary(ifstream& ifs)
{
    unordered_map<string, char> dict;
    uint32_t dictSize;

    // 读取字典大小
    ifs.read(reinterpret_cast<char*>(&dictSize), sizeof(dictSize));

    // 读取字典内容
    for (uint32_t i = 0; i < dictSize; ++i) {
        char character;
        ifs.read(&character, sizeof(character)); // 读取字符

        uint8_t codeLength;
        ifs.read(reinterpret_cast<char*>(&codeLength), sizeof(codeLength)); // 读取编码长度

        string code(codeLength, ' ');
        ifs.read(&code[0], codeLength); // 读取编码

        dict[code] = character; // 存储编码到字符的映射
    }

    return dict;
}

string decodeFromFile(const string& filename) {
    ifstream ifs(filename, ios::binary);
    if (!ifs) {
        qDebug() << "Failed to open file for reading.";
        return "";
    }

    // 获取字典
    auto dict = readDictionary(ifs);

    // 获取编码数据
    string encodedString;
    char byte;
    while (ifs.get(byte)) {
        for (int i = 0; i < 8; ++i) { // 逐位读取
            encodedString += (byte & (1 << (7 - i))) ? '1' : '0';
        }
    }
    ifs.close();

    // 解码
    string decodedString;
    string currentCode;
    for (char bit : encodedString) {
        currentCode += bit;
        if (dict.find(currentCode) != dict.end()) {
            decodedString += dict[currentCode]; // 找到对应的字符
            currentCode.clear(); // 清空当前编码
        }
    }

    return decodedString;
}
