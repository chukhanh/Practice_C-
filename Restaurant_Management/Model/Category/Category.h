//
// Created by Chu Khánh on 8/12/25.
//

#ifndef CATEGORY_H
#define CATEGORY_H
#include <string>

#include "../BaseClass.h"


class Category : public BaseClass{
private:
    std::string id;
    std::string name;

public:
    Category();

    Category(const std::string &id, const std::string &name);

    std::string getId() const;
    std::string getName() const;
    void setId(const std::string &id);
    void setName(const std::string &name);
    void input() override;
    void display() override;
};


#endif //CATEGORY_H
