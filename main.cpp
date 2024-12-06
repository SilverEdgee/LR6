#include <iostream>
#include "tests.h"
int main() {
    while (true) {
        std::cout << "Main Menu:\n";
        std::cout << "1. Show task conditions\n";
        std::cout << "2. Show and run Google tests\n";
        std::cout << "3. Run program (task solutions)\n";
        std::cout << "4. Exit\n";
        std::cout << "Your choice: ";

        int choice;
        std::cin >> choice;
        std::cin.ignore();
        switch (choice) {
            case 1:
                showTaskConditions();
                break;
            case 2:
                runGoogleTests();
                break;
            case 4:
                std::cout << "Exiting the program.\n";
                return 0;
            case 3:
                runMainProgram();
                break;
            default:
                std::cout << "Invalid choice. Try again.\n";
                break;
        }
    }
}
