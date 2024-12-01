#include <iostream>

class StringAnalyzer {
private:
    const int MAX_LENGTH = 80;
    char* str;
    int length;

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
        const char vowelsRus[] = "уеыаоэяию";

        if (std::isalpha(c)) {
            for (int i = 0; vowelsEng[i] != '\0'; ++i) {
                if (c == vowelsEng[i]) {
                    return true;
                }
            }
            for (int i = 0; vowelsRus[i] != '\0'; ++i) {
                if (c == vowelsRus[i]) {
                    return true;
                }
            }
        }
        return false;
    }

public:
    StringAnalyzer() {
        str = new char[MAX_LENGTH + 1];
        length = 0;
    }

    ~StringAnalyzer() {
        delete[] str;
    }

    void inputString() {
        char c;
        length = 0;
        std::cout << "Enter a string: ";
        while ((c = getchar()) != '\n' && length < MAX_LENGTH) {
            str[length++] = c;
        }
        str[length] = '\0';
    }

    void analyzeVowelsAndConsonants() {
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

    void parseAndSortNumbers() {
        int* numbers = new int[length];
        int count = 0;
        int currentNumber = 0;
        bool isNumber = false;

        for (int i = 0; i < length; i++) {
            if (isDigitChar(str[i])) {
                currentNumber = currentNumber * 10 + (str[i] - '0');
                isNumber = true;
            } else if (isNumber) {
                numbers[count++] = currentNumber;
                currentNumber = 0;
                isNumber = false;
            }
        }

        if (isNumber) {
            numbers[count++] = currentNumber;
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
    void isSymmetric() {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    
    int left = 0;
    int right = length - 1;
    bool symetric = true;
    
    while (left < right) {
        if (str[left] != str[right]) {
            symetric = false;
            break;
        }
        left++;
        right--;
    }
    if (symetric) 
        std::cout << "Symmetric" << std::endl; 
    else
         std::cout << "Not symmetric" << std::endl;
    }
};

int main() {
    setlocale(LC_ALL, "rus");

    StringAnalyzer analyzer;

    analyzer.inputString();

    while (true) {
        std::cout << "\nChoose an option:\n";
        std::cout << "1. Analyze vowels and consonants\n";
        std::cout << "2. Parse and sort numbers\n";
        std::cout << "3. symetrchichnie\n";
        std::cout << "4. Exit\n";
        std::cout << "Your choice: ";

        int choice;
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
            case 1:
                analyzer.analyzeVowelsAndConsonants();
                break;
            case 2:
                analyzer.parseAndSortNumbers();
                break;
            case 3:
                analyzer.isSymmetric();
                break;
            case 4:
                std::cout << "Exiting program." << std::endl;
                return 0;
            default:
                std::cout << "Invalid choice. Try again." << std::endl;
        }
    }
}
