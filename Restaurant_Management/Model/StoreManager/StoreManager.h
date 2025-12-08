//
// Created by Chu Khánh on 8/12/25.
//

#ifndef STOREMANAGER_H
#define STOREMANAGER_H
#include <vector>

#include "../Invoice/Invoice.h"
#include "../Item/Product.h"
#include "./../Category/Category.h"


class StoreManager {
private:
    std::vector<Category> categories;
    std::vector<Product> products;
    std::vector<Invoice> invoices;

public:
    StoreManager();
    void addCategory();
    void showCategories();
    void addProduct();
    void showProducts();
    void addInvoice(bool isImport);
    void inventoryReport();
    void expiredReport(int currentYear);
};


#endif //STOREMANAGER_H
