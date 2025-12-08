//
// Created by Chu Khánh on 8/12/25.
//

#include "Product.h"

#include <iostream>
#include <utility>

Product::Product(const std::string &id, const std::string &name, std::string expiryDate,
                 const std::string &manufacturer, int manufactureYear, const std::string &categoryId, int quantity) {
    this->id = id;
    this->name = name;
    this->expiryDate = std::move(expiryDate);
    this->manufacturer = manufacturer;
    this->manufactureYear = manufactureYear;
    this->categoryId = categoryId;
    this->quantity = quantity;
}

std::string Product::getId() const {
    return this->id;
}

std::string Product::getName() const {
    return this->name;
}

std::string Product::getExpiryDate() const {
    return this->expiryDate;
}

std::string Product::getManufacturer() const {
    return this->manufacturer;
}

int Product::getManufactureYear() const {
    return this->manufactureYear;
}

std::string Product::getCategoryId() const {
    return this->categoryId;
}

void Product::setId(std::string id) {
    this->id = std::move(id);
}

void Product::setName(const std::string &name) {
    this->name = name;
}

void Product::setExpiryDate(std::string expiry) {
    this->expiryDate = std::move(expiry);
}

void Product::setManufacturer(std::string manufacturer) {
    this->manufacturer = std::move(manufacturer);
}

void Product::setYear(int year) {
    this->manufactureYear = year;
}

void Product::setCategoryId(std::string id) {
    this->categoryId = std::move(id);
}

void Product::setQuantity(int quantity) {
    this->quantity = quantity;
}

int Product::getQuantity() const {
    return this->quantity;
}

void Product::input() {
    std::cout << "Ma hang: ";
    getline(std::cin, id);
    std::cout << "Ten hang: ";
    getline(std::cin, name);
    std::cout << "Han dung (YYYY-MM-DD): ";
    getline(std::cin, expiryDate);
    std::cout << "Cong ty SX: ";
    getline(std::cin, manufacturer);
    std::cout << "Nam SX: ";
    std::cin >> manufactureYear;
    std::cin.ignore();
    std::cout << "So luong: ";
    std::cin >> quantity;
    std::cout << "Ma loai: ";
    getline(std::cin, categoryId);
}

void Product::display() {
    std::cout << id << " | " << name << " | HSD: " << expiryDate
            << " | SX: " << manufacturer
            << " | Nam: " << manufactureYear
            << " | Loai: " << categoryId << std::endl;
}
