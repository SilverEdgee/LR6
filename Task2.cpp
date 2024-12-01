#include <iostream>
#include <cctype>

const int MAX_SIZE = 80;

void inputString(wchar_t* str, int maxLength, int& length) {
    wchar_t c;
    length = 0;
    
    while ((c = getchar()) != '\n' && length < maxLength) {
        str[length++] = c;
    }
    
    str[length] = '\0';
}

bool isVowel(wchar_t c) {
    c = std::tolower(c);

    const char vowelseng[] = "aeiou";
    const char vowelsrus[] = "уеыаоэяию";

    if (std::isalpha(c)) {
        for (int i = 0; vowelseng[i] != '\0'; ++i) {
            if (c == vowelseng[i]) {
                return true;
            }
        }
        for (int i = 0; vowelsrus[i] != '\0'; ++i) {
            if (c == vowelsrus[i]) {
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
        if (std::isalpha(str[i])) {
            ++letterCount;
            if (isVowel(str[i])) {
                ++vowelCount;
            }
        }
    }

    int consonantCount = letterCount - vowelCount;

    if (vowelCount > consonantCount) {
        std::cout << "More vowels" << std::endl;
    } else if (vowelCount < consonantCount) {
        std::cout << "More consonants" << std::endl;
    } else {
        std::cout << "Equal vowels and consonants" << std::endl;
    }
}

int main() {
    setlocale(LC_ALL, "rus");
    wchar_t* str = new wchar_t[MAX_SIZE + 1];
    int length = 0;
    
    std::cout << "Enter a string: ";
    inputString(str, MAX_SIZE, length);
    
    analyzeVowelsConsonants(str, length);
    
    delete[] str;
    return 0;
}