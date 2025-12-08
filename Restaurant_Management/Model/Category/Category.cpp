//
// Created by Chu Khánh on 8/12/25.
//

#include "Category.h"

#include <iostream>

Category::Category() = default;

Category::Category(const std::string &id, const std::string &name) {
    this->id = id;
    this->name = name;
}

std::string Category::getId() const {
    return this->id;
}

std::string Category::getName() const {
    return this->name;
}

void Category::setId(const std::string &id) {
    this->id = id;
}

void Category::setName(const std::string &name) {
    this->name = name;
}

void Category::display() {
    std::cout << id << " - " << name << std::endl;
}

void Category::input() {
    std::cout << "Nhap ma loai: ";
    getline(std::cin, id);
    std::cout << "Nhap ten loai: ";
    getline(std::cin, name);
}



