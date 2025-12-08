//
// Created by Chu Khánh on 8/12/25.
//

#include "InvoiceItem.h"

#include "../Invoice/Invoice.h"

void Invoice::addItem(const std::string& productId, int quantity) {
    items.emplace_back(productId, quantity);
}

std::vector<InvoiceItem> Invoice::getItems() const {
    return items;
}