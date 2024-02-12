#include "Bank.h"

int main() {
    Bank::initialize();
    Bank *object = &Bank::getInstance();

    do {
        std::cout << "\t================== BANKING SYSTEM ================" << std::endl;
        std::cout << "\t\t1. You already have an account." << std::endl;
        std::cout << "\t\t2. Create new account." << std::endl;
        std::cout << "\t\tYour option: ";

        int option;
        std::cin >> option;
        
        if (option == 1) {
            object->enterInforUser();
        } else if (option == 2) {
            object->createNewAccount();
        } else if (option == 0) {
            break;
        }
    } 
    while (true);

    delete object;
}