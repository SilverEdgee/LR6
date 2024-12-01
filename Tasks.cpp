#include <iostream>
#include <cctype>

bool isDigitChar(char c) {
    return (c >= '0' && c <= '9'); 
}

void OutputString(const char *string, int length) {
    for (int i = 0; i < length; i++) {
        std::cout << string[i];
    }
    std::cout << std::endl;
}

void swap(int &i, int &j) {
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

void inputString(char* str, int maxLength, int &length) {
    char c;
    length = 0;
    while ((c = getchar()) != '\n' && length < maxLength) {
        str[length++] = c;
    }
    str[length] = '\0';
}

void parseNumbers(const char* str, int length, int* numbers, int &count) {
    int currentNumber = 0;
    bool isNumber = false;
    count = 0;
    
    for (int i = 0; i < length; i++) {
        if (isDigitChar(str[i])) {
            currentNumber = currentNumber * 10 + (str[i] - '0');
            isNumber = true;
        }
        else if (str[i] == ' ' || i == length - 1) {
            if (isNumber) {
                numbers[count++] = currentNumber;
                currentNumber = 0;
                isNumber = false;
            }
        }
    }

    if (isNumber) {
        numbers[count++] = currentNumber;
    }
}

void outputNumbers(int* numbers, int count) {
    for (int i = 0; i < count; i++) {
        std::cout << numbers[i] << ' ';
    }
    std::cout << std::endl;
}

int main() {
        
        const int MAX_LENGTH = 80;
        int length = 0;
        int count = 0;

        char* str = new char[MAX_LENGTH + 1];
        
        // Ввод строки с проверкой
        inputString(str, MAX_LENGTH, length);
        
        // Вывод строки
        OutputString(str, length);
        
        // Массив для хранения чисел
        int* numbers = new int[length];
        
        // Разбор чисел из строки
        parseNumbers(str, length, numbers, count);
        
        // Сортировка чисел
        insertionSort(numbers, count);
        
        // Вывод отсортированных чисел
        outputNumbers(numbers, count);
        
        // Освобождение памяти
        delete[] str;
        delete[] numbers;

    
    return 0;
}
