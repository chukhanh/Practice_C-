//
// Created by Chu Khánh on 8/12/25.
//
#pragma once


#include <string>
#include <sstream>

template<typename T>
class File {
private:
    std::vector<T> values;
    std::string type;

public:
    virtual ~File() = default;
    File() = default;

    virtual std::string toFile(const T &data) = 0;
    virtual std::vector<T> readFromFile(const std::string &fileName) = 0;
};
