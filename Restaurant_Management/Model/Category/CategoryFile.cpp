//
// Created by Chu Khánh on 8/12/25.
//

#include "CategoryFile.h"

#include <iostream>
#include <fstream> t

std::string CategoryFile::toFile(const Category &item) {
    return item.getId() + "," + item.getName();
}

Category CategoryFile::fromFile(const std::string &line) {
    std::stringstream ss(line);
    std::string id, name;

    std::getline(ss, id, ',');   // lấy mã loại
    std::getline(ss, name);      // lấy tên loại

    return Category(id, name);
}


std::vector<Category> CategoryFile::readFromFile(const std::string &fileName) {
    std::vector<Category> list;
    std::ifstream file(fileName);

    if (!file.is_open()) {
        std::cout << "Khong mo duoc file: " << fileName << std::endl;
        return list;
    }

    std::string line;
    while (std::getline(file, line)) {
        if (line.empty()) continue;
        Category c = fromFile(line);
        list.push_back(c);
    }

    file.close();
    return list;
}

