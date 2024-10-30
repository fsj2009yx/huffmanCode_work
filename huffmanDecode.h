#ifndef HUFFMANDECODE_H
#define HUFFMANDECODE_H

#include <fstream>
#include <unordered_map>
#include <vector>
#include <string>
#include<QDebug>
using namespace std;

unordered_map<string, char> readDictionary(ifstream& ifs);//读取字典
string decodeFromFile(const string& filename);//解码
#endif // HUFFMANDECODE_H
