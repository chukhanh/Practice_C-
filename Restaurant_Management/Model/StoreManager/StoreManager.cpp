//
// Created by Chu Khánh on 8/12/25.
//

#include "StoreManager.h"

#include <iostream>

#include "../../Constant/Common.h"
#include "../Category/CategoryFile.h"
#include "../Item/ProductFile.h"

StoreManager::StoreManager() {
    CategoryFile categoryFile;
    ProductFile productFile;

    categories = categoryFile.readFromFile(CATEGORY_PATH);

    products = productFile.readFromFile(PRODUCT_PATH);

    std::cout << "Da khoi phuc du lieu tu file!\n";
    std::cout << "So loai hang: " << categories.size() << std::endl;
    std::cout << "So san pham: " << products.size() << std::endl;
}



void StoreManager::addCategory() {
    Category newCategory;
    newCategory.input();
    categories.push_back(newCategory);
}

void StoreManager::showCategories() {
    std::cout << "\n===== Thông tin toàn bộ mặt hàng =====\n";
    for (auto &c: categories) {
        c.display();
    }
}

void StoreManager::addProduct() {
    Product newProduct;
    newProduct.input();
    products.push_back(newProduct);
}

void StoreManager::showProducts() {
    std::cout << "\n===== Thông tin toàn bộ Hàng Hoá =====\n";
    for (auto &p: products) {
        p.display();
    }
}

void StoreManager::addInvoice(bool isImport) {
    std::string id, date;
    std::cout << "Ma hoa don: ";
    std::cin >> id;
    std::cout << "Ngay: ";
    std::cin >> date;

    Invoice invoice(id, date, isImport);

    int n;
    std::cout << "So mat hang: ";
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        std::string pid;
        int qty;
        std::cout << "Ma hang: ";
        std::cin >> pid;
        std::cout << "So luong: ";
        std::cin >> qty;

        invoice.addItem(pid, qty);

        for (auto &p: products) {
            if (p.getId() == pid) {
                if (isImport) {
                    p.setQuantity(p.getQuantity() + qty);
                } else {
                    p.setQuantity(p.getQuantity() - qty);
                }
            }
        }
    }
    invoices.push_back(invoice);
}

void StoreManager::inventoryReport() {
    std::cout << "\n===== TON KHO =====\n";
    for (auto &p: products) {
        p.display();
    }
}

void StoreManager::expiredReport(const int currentYear) {
    std::cout << "\n===== HANG QUA HAN =====\n";
    for (auto &p : products) {
        if (currentYear - p.getManufactureYear() > 3)
            p.display();
    }
}

