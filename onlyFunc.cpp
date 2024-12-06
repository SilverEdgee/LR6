#include <iostream>
#include "tests.h"

void runMainProgram() {
    const int MAX_SIZE = 80;
    int length;
    char *str = NULL;
    char **strArray = NULL;
    int count = 0;
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
                if (!str) {
                    std::cout << "Enter a string for analysis: ";
                    str = read_line(&length);
                }
                analyzeVowelsAndConsonants(str, length);
                break;
            case 2:
                if (!str) {
                    std::cout << "Enter a string for analysis: ";
                    str = read_line(&length);
                }
                parseAndSortNumbers(str, length);
                break;
            case 3:
                if (!strArray) {
                    strArray = readStrings(&count);
                }
                isSymmetricall(strArray, &count);
                break;
            case 4:
                std::cout << "Exiting program." << std::endl;
                delete[] str;
                if (strArray) {
                for (int i = 0; i < count; i++) {
                    free(strArray[i]);
                    }
                free(strArray);
                }
            return;
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

void printresult(int vowelCount, int consonantCount) {
        std::cout << "Number of vowels = " << vowelCount << std::endl;
        std::cout << "Number of consonants = " << consonantCount << std::endl;
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
    bool isnorm = true;
    for (int i = 0; i < length; ++i) {
        if (std::isalpha(str[i])) {
            ++letterCount;
            if (isVowel(str[i])) {
                ++vowelCount;
            }
        } else if (str[i] != '\n' && str[i] != '\t' && str[i] != ' ') {
            isnorm = false;
        }
    }
    if (!isnorm) {
        std::cout  << "Type the word correctly" << std::endl;
    } else {
    int consonantCount = letterCount - vowelCount;
    printresult(vowelCount, consonantCount);
    }
}


void parseAndSortNumbers(const char* str, int length) {
    int* numbers = new int[length];
    int count = 0;
    int currentNumber = 0;
    bool isNumber = false;
    int sign = 1;
    bool invalidCharacterFound = false;

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
        } else if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n') {
            invalidCharacterFound = true;
        }
    }
    if (isNumber) {
        numbers[count++] = currentNumber * sign;
    }
    if (invalidCharacterFound) {
        std::cout << "Please enter numbers only." << std::endl;
    } else {
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
void menu(short number) {
    std::cout << "Lab " << number << " made by Denis Pometko \n";
    for (int i = 0; i < 20; i++) {
        std::cout << "x";
    }
    std::cout << "\n";
}

void showTaskConditions() {
    std::cout << "Choose a task to display the conditions:\n";
    std::cout << "1. Sort numbers in a string.\n";
    std::cout << "2. Analyze vowels and consonants.\n";
    std::cout << "3. Check string symmetry.\n";
    std::cout << "Your choice: ";

    int choice;
    std::cin >> choice;
    std::cin.ignore();

    switch (choice) {
        case 1:
            std::cout << "Task 1 condition:\n";
            std::cout << "Given a string of numbers separated by spaces."
            << "You need to print the numbers in ascending order.\n";
            break;
        case 2:
            std::cout << "Task 2 condition:\n";
            std::cout << "Determine whether there are more vowels or consonants in the text.\n";
            break;
        case 3:
            std::cout << "Task 3 condition:\n";
            std::cout << "Enter an array of strings. For each string, check if it is symmetric.\n";
            std::cout << "A string is symmetric if it reads the same left-to-right and right-to-left.\n";
            break;
        default:
            std::cout << "Invalid choice. Please choose one of the tasks (1, 2, or 3).\n";
            break;
    }

    for (int i = 0; i < 20; i++) {
        std::cout << "-";
    }
    std::cout << "\n";
}

void runGoogleTests() {
    std::cout << "Running Google tests...\n";
    system("./tests");
}

char* read_line(int* length) {
    char *buffer = NULL;
    int size = 0;
    int capacity = 16;

    buffer = (char*) (malloc(capacity));
    if (!buffer) {
        fprintf(stderr, "Memory allocation error\n");
        return NULL;
    }

    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        if (size + 1 >= capacity) {
            capacity *= 2;
            char *new_buffer = (char*) realloc(buffer, capacity);
            if (!new_buffer) {
                fprintf(stderr, "Memory reallocation error\n");
                free(buffer);
                return NULL;
            }
            buffer = new_buffer;
        }
        buffer[size++] = static_cast<char>(c);
    }

    if (buffer) {
        buffer[size] = '\0';
    }
    if (length) {
        *length = size;
    }
    return buffer;
}

bool isStringSymmetric(const char* str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    int left = 0, right = length - 1;
    while (left < right) {
        if (str[left] != str[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}


char** readStrings(int* count) {
    std::cout << "Enter the number of strings: ";
    std::cin >> *count;
    std::cin.ignore();

    char** strings = new char*[*count];
    for (int i = 0; i < *count; i++) {
        std::cout << "Enter string " << i + 1 << ": ";

        int length = 0;
        strings[i] = read_line(&length);
    }
    return strings;
}

void isSymmetricall(char** str, int* count) {
    for (int i = 0; i < *count; i++) {
        if (isStringSymmetric(str[i])) {
            std::cout << "String " << str[i] << " is symmetric" << std::endl;
        } else {
            std::cout << "String " << str[i] << " is not symmetric" << std::endl;
        }
    }
}
