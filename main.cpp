#include <iostream>
#include "tests.h"
int main() {
    while (true) {
        // Главное меню
        std::cout << "Главное меню:\n";
        std::cout << "1. Показать условия задач\n";
        std::cout << "2. Показать и запустить Google тесты\n";
        std::cout << "3. Запустить выполнение программы (решения задач)\n";
        std::cout << "4. Выйти\n";
        std::cout << "Ваш выбор: ";

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
                std::cout << "Выход из программы.\n";
                return 0;
            case 3:
                runMainProgram();
                break;
            default:
                std::cout << "Неверный выбор. Попробуйте снова.\n";
                break;
        }
    }
}