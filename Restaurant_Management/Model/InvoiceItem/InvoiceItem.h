//
// Created by Chu Khánh on 8/12/25.
//

#ifndef INVOICEITEM_H
#define INVOICEITEM_H
#include <string>
#include <utility>


class InvoiceItem {
private:
    std::string itemId;
    int quantity;

public:
    InvoiceItem(std::string itemId, const int quantity)
        : itemId(std::move(itemId)), quantity(quantity) {
    }
};


#endif //INVOICEITEM_H
