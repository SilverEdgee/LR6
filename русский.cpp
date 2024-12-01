#include <iostream>
#include <cwctype>
#include <clocale>

const int MAX_SIZE = 80;

void inputString(wchar_t* str, int maxLength, int& length) {
    setlocale(LC_ALL, "ru_RU.UTF-8"); 
    char c;
    length = 0;
    
    while ((c = getchar()) != '\n' && length < maxLength) {
        str[length++] = c;
    }
    
    str[length] = L'\0';
}

bool isVowel(wchar_t c) {
    c = std::towlower(c);
    
    const wchar_t vowels[] = L"аоиеёэыуюя";
    
    if (std::iswalpha(c)) {
        for (int i = 0; vowels[i] != L'\0'; ++i) {
            if (c == vowels[i]) {
                return true;
            }
        }
    }
    return false;
}

void analyzeVowelsConsonants(wchar_t* str, int length) {
    int vowelCount = 0;
    int letterCount = 0; 
    
    for (int i = 0; i < length; ++i) {
        if (std::iswalpha(str[i])) {
            ++letterCount;
            if (isVowel(str[i])) {
                ++vowelCount;
            }
        }
    }
    
    int consonantCount = letterCount - vowelCount;
    
    if (vowelCount > consonantCount) {
        std::cout << "Гласных больше" << std::endl;
    } else if (vowelCount < consonantCount) {
        std::cout << "Согласных больше" << std::endl;
    } else {
        std::cout << "Гласных и согласных одинаково" << std::endl;
    }
}

int main() {
    setlocale(LC_ALL, "rus");
    
    wchar_t* str = new wchar_t[MAX_SIZE + 1];
    int length = 0;
    
    std::cout << "Введите строку: ";
    inputString(str, MAX_SIZE, length);
    
    analyzeVowelsConsonants(str, length);
    
    delete[] str;
    
    return 0;
}