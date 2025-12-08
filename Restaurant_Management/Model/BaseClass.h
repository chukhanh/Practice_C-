//
// Created by Chu Khánh on 8/12/25.
//

#ifndef BASECLASS_H
#define BASECLASS_H


class BaseClass {
public:
    virtual ~BaseClass() = default;

    virtual void input() = 0;
    virtual void display() = 0;
};


#endif //BASECLASS_H
