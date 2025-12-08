cmake_minimum_required(VERSION 3.30)
project(Restaurant_Management)

set(CMAKE_CXX_STANDARD 20)

add_executable(Restaurant_Management main.cpp
        Constant/Common.h
        Constant/Common.cpp
        Model/File.h
        Model/Category/Category.cpp
        Model/Category/Category.h
        Model/Category/CategoryFile.cpp
        Model/Category/CategoryFile.h
        Model/Item/Product.cpp
        Model/Item/Product.h
        Model/Item/ProductFile.cpp
        Model/Item/ProductFile.h
        Model/BaseClass.cpp
        Model/BaseClass.h
        Model/InvoiceItem/InvoiceItem.cpp
        Model/InvoiceItem/InvoiceItem.h
        Model/Invoice/Invoice.cpp
        Model/Invoice/Invoice.h
        Model/StoreManager/StoreManager.cpp
        Model/StoreManager/StoreManager.h
)
