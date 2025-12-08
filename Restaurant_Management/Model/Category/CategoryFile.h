//
// Created by Chu Khánh on 8/12/25.
//

#ifndef CATEGORYFILE_H
#define CATEGORYFILE_H
#include "Category.h"
#include "../File.h"


class CategoryFile : public File<Category> {
public:
    std::string toFile(const Category &item) override;
    Category fromFile(const std::string &line);
    std::vector<Category> readFromFile(const std::string &fileName) override;
};


#endif //CATEGORYFILE_H
