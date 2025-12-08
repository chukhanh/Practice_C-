//
// Created by Chu Khánh on 8/12/25.
//

#ifndef ITEM_H
#define ITEM_H
#include <string>

#include "../BaseClass.h"


class Product : public BaseClass{
private:
    std::string id;
    std::string name;
    std::string expiryDate;
    std::string manufacturer;
    int manufactureYear{};
    std::string categoryId;
    int quantity{};

    public:
    Product() = default;
    Product(const std::string &id, const std::string &name, std::string expiryDate, const std::string &manufacturer, int manufactureYear, const std::string &categoryId, int quantity);
    std::string getId() const;
    std::string getName() const;
    std::string getExpiryDate() const;
    std::string getManufacturer() const;
    int getManufactureYear() const;
    std::string getCategoryId() const;
    int getQuantity() const;
    void setId(std::string id);
    void setName(const std::string &name);
    void setExpiryDate(std::string expiry);
    void setManufacturer(std::string manufacturer);
    void setYear(int year);
    void setCategoryId(std::string categoryId);
    void setQuantity(int quantity);

    void input() override;
    void display() override;
};


#endif //ITEM_H
