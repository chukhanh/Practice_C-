//
// Created by Chu Khánh on 8/12/25.
//

#ifndef ITEMFILE_H
#define ITEMFILE_H
#include "Product.h"
#include "../File.h"


class ProductFile : public File<Product> {
public:
    std::string toFile(const Product &item) override;

    std::vector<Product> readFromFile(const std::string &fileName) override;

    Product fromFile(const std::string &line);
};


#endif //ITEMFILE_H
