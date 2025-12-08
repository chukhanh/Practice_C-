#include <iostream>

#include "Model/StoreManager/StoreManager.h"

int main() {
    StoreManager sm;

    int choice;

    do {
        std::cout << "\n===== QUAN LY CUA HANG =====\n";
        std::cout << "1. Them loai hang\n";
        std::cout << "2. Them mat hang\n";
        std::cout << "3. Hien thi hang\n";
        std::cout << "4. Them hoa don nhap\n";
        std::cout << "5. Them hoa don ban\n";
        std::cout << "6. Thong ke ton kho\n";
        std::cout << "7. Thong ke hang het han\n";
        std::cout << "0. Thoat\n";
        std::cout << "Chon: ";
        std::cin >> choice;

        switch (choice) {
            case 1: sm.addCategory();
                break;
            case 2: sm.addProduct();
                break;
            case 3: sm.showProducts();
                break;
            case 4: sm.addInvoice(true);
                break;
            case 5: sm.addInvoice(false);
                break;
            case 6: sm.inventoryReport();
                break;
            case 7: sm.expiredReport(2025);
                break;
            default:
                std::cout << "Invalid Choice\n";
        }
    } while (choice != 0);

    return 0;
}
