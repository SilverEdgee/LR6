#include <iostream>
#include "tests.h"

void runMainProgram() {
    const int MAX_SIZE = 80;
    char* str = new char[MAX_SIZE + 1];
    int length;

    inputString(str, length, MAX_SIZE);

    while (true) {
        std::cout << "\nChoose an option:\n";
        std::cout << "1. Analyze vowels and consonants\n";
        std::cout << "2. Parse and sort numbers\n";
        std::cout << "3. Check symmetry\n";
        std::cout << "4. Exit\n";
        std::cout << "Your choice: ";

        int choice;
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
            case 1:
                analyzeVowelsAndConsonants(str, length);
                break;
            case 2:
                parseAndSortNumbers(str, length);
                break;
            case 3:
                isSymmetric(str, length);
                break;
            case 4:
                std::cout << "Exiting program." << std::endl;
                delete[] str;
                return;
            default:
                std::cout << "Invalid choice. Try again." << std::endl;
        }
    }
}

bool isDigitChar(char c) {
    return (c >= '0' && c <= '9');
}

void swap(int& i, int& j) {
    int temp = i;
    i = j;
    j = temp;
}

void insertionSort(int* array, int arrayLength) {
    for (int i = 1; i < arrayLength; i++) {
        int j = i - 1;
        while (j >= 0 && array[j] > array[j + 1]) {
            swap(array[j], array[j + 1]);
            j--;

        }
    }
}

bool isVowel(char c) {
    c = std::tolower(c);
    const char vowelsEng[] = "aeiou";

    if (std::isalpha(c)) {
        for (int i = 0; vowelsEng[i] != '\0'; ++i) {
            if (c == vowelsEng[i]) {
                return true;
            }
        }
    }
    return false;
}

void inputString(char* str, int& length, const int MAX_SIZE) {
    char c;
    length = 0;
    std::cout << "Enter a string: ";
    while ((c = getchar()) != '\n' && length < MAX_SIZE) {
        str[length++] = c;
    }
    str[length] = '\0';
}

void printresult(int vowelCount, int consonantCount) {
        std::cout << "Number of vowels = " << vowelCount << std::endl;
        std::cout << "Number of consonant = " << consonantCount << std::endl;
    if (vowelCount > consonantCount) {
        std::cout << "More vowels" << std::endl;
    } else if (vowelCount < consonantCount) {
        std::cout << "More consonants" << std::endl;
    } else {
        std::cout << "Equal vowels and consonants" << std::endl;
    }
}

void analyzeVowelsAndConsonants(const char* str, int length) {
    int vowelCount = 0;
    int letterCount = 0;

    for (int i = 0; i < length; ++i) {
        if (std::isalpha(str[i])) {
            ++letterCount;
            if (isVowel(str[i])) {
                ++vowelCount;
            }
        }
    }

    int consonantCount = letterCount - vowelCount;
    printresult(vowelCount, consonantCount);
}


void parseAndSortNumbers(const char* str, int length) {
    int* numbers = new int[length];
    int count = 0;
    int currentNumber = 0;
    bool isNumber = false;
    int sign = 1;
for (int i = 0; i < length; i++) {
    if (str[i] == '-' && i + 1 < length && isDigitChar(str[i + 1])) {
        sign = -1;
    } else if (isDigitChar(str[i])) {
        currentNumber = currentNumber * 10 + (str[i] - '0');
        isNumber = true;
    } else if (isNumber) {
        numbers[count++] = currentNumber * sign;
        currentNumber = 0;
        isNumber = false;
        sign = 1;
    }
}

if (isNumber) {
    numbers[count++] = currentNumber * sign;
}

    if (count > 0) {
        insertionSort(numbers, count);
        std::cout << "Sorted numbers: ";
        for (int i = 0; i < count; i++) {
            std::cout << numbers[i] << ' ';
        }
        std::cout << std::endl;
    } else {
        std::cout << "No numbers found in the string." << std::endl;
    }

    delete[] numbers;
}

void isSymmetric(const char* str, int length) {
    int left = 0, right = length - 1;
    bool symmetric = true;

    while (left < right) {
        if (str[left] != str[right]) {
            symmetric = false;
            break;
        }
        left++;
        right--;
    }

    if (symmetric)
        std::cout << "Symmetric" << std::endl;
    else
        std::cout << "Not symmetric" << std::endl;
}
// Функция для отображения условий задач
void menu(short number) {
    std::cout << "Laba " << number << " made by Denis Pometko \n";
    for (int i = 0; i < 20; i++) {
        std::cout << "x";
    }
    std::cout << "\n";
}

// Функция для выбора и отображения условия задачи
void showTaskConditions() {
    std::cout << "Выберите задачу для отображения условия:\n";
    std::cout << "1. Отсортировать числа в строке.\n";
    std::cout << "2. Проанализировать гласные и согласные.\n";
    std::cout << "3. Проверить симметричность строк.\n";
    std::cout << "Ваш выбор: ";

    int choice;
    std::cin >> choice;
    std::cin.ignore();

    switch (choice) {
        case 1:
            std::cout << "Условие задачи 1:\n";
            std::cout << "Дана строка цифр, разделенных пробелами. Необходимо вывести на экран числа этой строки в порядке возрастания их значений.\n";
            break;
        case 2:
            std::cout << "Условие задачи 2:\n";
            std::cout << "Необходимо найти, каких букв в тексте больше – гласных или согласных.\n";
            break;
        case 3:
            std::cout << "Условие задачи 3:\n";
            std::cout << "Введите массив строк. Для каждой строки необходимо проверить, является ли она симметричной.\n";
            std::cout << "Симметричной считается строка, которая одинаково читается слева направо и справа налево.\n";
            break;
        default:
            std::cout << "Неверный выбор. Пожалуйста, выберите одну из задач (1, 2 или 3).\n";
            break;
    }

    // Разделитель после отображения условия
    for (int i = 0; i < 20; i++) {
        std::cout << "-";
    }
    std::cout << "\n";
}

// Функция для запуска тестов
void runGoogleTests() {
    // Выполнение тестов
    std::cout << "Запуск Google тестов...\n";
    system("./tests");
}

