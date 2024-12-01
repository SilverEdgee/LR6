#include <iostream>
#include <cwchar>

bool isSymmetric(const wchar_t* str) {
    int length = 0;
    while (str[length] != L'\0') {
        length++;
    }
    
    int left = 0;
    int right = length - 1;
    
    while (left < right) {
        if (str[left] != str[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

int main() {
    std::setlocale(LC_ALL, ""); // Устанавливаем локаль для корректного ввода/вывода Unicode-символов
    int N;
    std::wcin >> N;
    std::wcin.ignore(10000, L'\n'); 
    wchar_t** str = new wchar_t*[N];
    for (int i = 0; i < N; i++) {
        str[i] = new wchar_t[81]; // Для широких символов
        std::wcout << L"Введите " << i + 1 << L" строку" << std::endl;
        std::wcin.getline(str[i], 81);
    }
    for (int i = 0; i < N; i++) {
        std::wcout << L"Строка " << str[i] << L" ";
        if (isSymmetric(str[i])) std::wcout << L"симметрична" << std::endl;
        else std::wcout << L"не симметрична" << std::endl;
    }
    for (int i = 0; i < N; i++) {
        delete[] str[i];
    }
    delete[] str;
}
