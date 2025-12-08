//
// Created by Chu Khánh on 8/12/25.
//

#ifndef INVOICE_H
#define INVOICE_H
#include <string>
#include <vector>

#include "../InvoiceItem/InvoiceItem.h"


class Invoice {
private:
    std::string id;
    std::string date;
    bool isImport = false; // true = nhập, false = bán
    std::vector<InvoiceItem> items;

public:
    Invoice(std::string id, const std::string &date, const bool isImport) {
        this->id = std::move(id);
        this->date = date;
        this->isImport = isImport;
    }

    bool isImportInvoice() const {
        return isImport;
    }

    std::string getId() const {
        return id;
    }

    void addItem(const std::string& productId, int quantity);
    std::vector<InvoiceItem> getItems() const;
};


#endif //INVOICE_H
