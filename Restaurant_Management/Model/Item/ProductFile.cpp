//
// Created by Chu Khánh on 8/12/25.
//

#include "ProductFile.h"
#include <fstream>
#include <iostream>

std::string ProductFile::toFile(const Product &item) {
    return item.getId() + " " + item.getName();
}

std::vector<Product> ProductFile::readFromFile(const std::string &fileName) {
    std::vector<Product> list;
    std::ifstream file(fileName);   // ✅ KHÔNG CÒN LỖI INCOMPLETE

    if (!file.is_open()) {
        std::cout << "Khong mo duoc file: " << fileName << std::endl;
        return list;
    }

    std::string line;
    while (std::getline(file, line)) {
        if (line.empty()) continue;

        Product p = fromFile(line);   // parse
        list.push_back(p);            // ✅ INSERT VECTOR
    }

    file.close();
    return list;
}

Product ProductFile::fromFile(const std::string &line) {
    std::stringstream ss(line);
    std::string id, name, expiry, manu, yearStr, catId, qtyStr;

    std::getline(ss, id, ',');
    std::getline(ss, name, ',');
    std::getline(ss, expiry, ',');
    std::getline(ss, manu, ',');
    std::getline(ss, yearStr, ',');
    std::getline(ss, catId, ',');
    std::getline(ss, qtyStr);

    int year = std::stoi(yearStr);
    int qty  = std::stoi(qtyStr);

    return Product(id, name, expiry, manu, year, catId, qty);
}
