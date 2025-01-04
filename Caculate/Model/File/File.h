//
// Created by ChuKhanhhh on 1/1/25.
//

#ifndef FILE_H
#define FILE_H
#include <fstream>
#include <vector>
#include <string>


std::vector<std::string> loadCalculations(const std::string &filePath);
void saveOutPutCalculations(const std::string &filePath, const std::vector<std::string>& results);

#endif //FILE_H
