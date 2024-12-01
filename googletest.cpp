#include <gtest/gtest.h>
#include "tests.h"
#include <cstring>

void testAnalyze(const char* input, int expectedVowels, int expectedConsonants, const char* expectedOutput) {
    int length = strlen(input);
    char buffer[1024] = {0};
    std::streambuf* old = std::cout.rdbuf();
    std::ostringstream tempStream; 
    std::cout.rdbuf(tempStream.rdbuf());

    analyzeVowelsAndConsonants(input, length);
    std::cout.rdbuf(old); 
    strncpy(buffer, tempStream.str().c_str(), sizeof(buffer) - 1); 
    char expectedVowelStr[50];
    snprintf(expectedVowelStr, sizeof(expectedVowelStr), "Number of vowels = %d", expectedVowels);
    EXPECT_NE(strstr(buffer, expectedVowelStr), nullptr); 


    char expectedConsonantStr[50];
    snprintf(expectedConsonantStr, sizeof(expectedConsonantStr), "Number of consonant = %d", expectedConsonants);
    EXPECT_NE(strstr(buffer, expectedConsonantStr), nullptr);


    EXPECT_NE(strstr(buffer, expectedOutput), nullptr);
}

void testParseAndSort(const char* input, const char* expectedOutput) {
    char buffer[1024] = {0};

    // Перенаправляем std::cout
    std::streambuf* old = std::cout.rdbuf();
    std::ostringstream tempStream;
    std::cout.rdbuf(tempStream.rdbuf());

    int length = strlen(input);
    parseAndSortNumbers(input, length);

    std::cout.rdbuf(old); // Восстановление std::cout

    strncpy(buffer, tempStream.str().c_str(), sizeof(buffer) - 1);

    EXPECT_NE(strstr(buffer, expectedOutput), nullptr);
}

void testisSymetric(const char* input, const char* expectedOutput) {
    char buffer[1024] = {0};
    std::streambuf* old = std::cout.rdbuf();
    std::ostringstream tempStream;
    std::cout.rdbuf(tempStream.rdbuf());
    int length = strlen(input);
    isSymmetric(input, length);
    std::cout.rdbuf(old);
    strncpy(buffer, tempStream.str().c_str(), sizeof(buffer) - 1);
    EXPECT_NE(strstr(buffer, expectedOutput), nullptr);
}



// Тест t1 1
TEST(AnalyzeVowelsAndConsonants, EmptyString) {
    testAnalyze("", 0, 0, "Equal vowels and consonants");
}
//2
TEST(AnalyzeVowelsAndConsonants, NoLetters) {
    testAnalyze("12345!@#$%", 0, 0, "Equal vowels and consonants");
}
//3
TEST(AnalyzeVowelsAndConsonants, AllVowels) {
    testAnalyze("aeiouAEIOU", 10, 0, "More vowels");
}
//4
TEST(AnalyzeVowelsAndConsonants, AllConsonants) {
    testAnalyze("bcdfgBCDFG", 0, 10, "More consonants");
}
//5
TEST(AnalyzeVowelsAndConsonants, EqualVowelsAndConsonants) {
    testAnalyze("aAaAabBbBb", 5, 5, "Equal vowels and consonants");
}
//6
TEST(AnalyzeVowelsAndConsonants, MixedWithSpaces) {
    testAnalyze("Hello World", 3, 7, "More consonants");
}
//7
TEST(AnalyzeVowelsAndConsonants, MixedWithDigitsAndSymbols) {
    testAnalyze("a1b2c3d!E@f#g$H%i^j&", 3, 7, "More consonants");
}
//8
TEST(AnalyzeVowelsAndConsonants, UppercaseLetters) {
    testAnalyze("RaZbomBil PoIT", 5, 8, "More consonants");
}
//9
TEST(AnalyzeVowelsAndConsonants, SingleVowel) {
    testAnalyze("A", 1, 0, "More vowels");
}
//10
TEST(AnalyzeVowelsAndConsonants, SingleConsonant) {
    testAnalyze("Z", 0, 1, "More consonants");
}
//T2 T1
TEST(parseAndSortNumbers, EmptyString) {
    testParseAndSort("", "No numbers found in the string.");
}
//2
TEST(parseAndSortNumbers, NoNumbers) {
testParseAndSort("SIGMABOY", "No numbers found in the string.");
}
//3
TEST(parseAndSortNumbers, oneNumber) {
    testParseAndSort("1488", "1488");
}
//4
TEST(parseAndSortNumbers, AllinOrder) {
    testParseAndSort("1 3 5 7 9", "1 3 5 7 9");
}
//5
TEST(parseAndSortNumbers, lettersAndNumbers) {
    testParseAndSort("1 ab 2 3 4 bc 0", "0 1 2 3 4");
}
//6
TEST(parseAndSortNumbers, negative) {
    testParseAndSort("1 -2 0 1 2 3", "-2 0 1 1 2 3");
}
//7
TEST(parseAndSortNumbers, bigNumbers) {
    testParseAndSort("148888 1488 1488888 148888888", "1488 148888 1488888 148888888");
}
//8
TEST(parseAndSortNumbers, yayzhexzchepridumat) {
    testParseAndSort("esli vi chitaete eto postavte mne pzh 10 za 6 labu i 10 za vse ostalnie", "6 10 10");
}
//9
TEST(parseAndSortNumbers, yaustaldumat) {
    testParseAndSort("a ya prostila ya prostila ego opyat opyat opyat o kak namayalas' ya s toboi moya popitka 505", "505");
}
//10
TEST(parseAndSortNumbers, pobeda10) {
    testParseAndSort("ya xz chto tut pisat 1 2 3 3 2 1", "1 1 2 2 3 3");
}
//bozhe konets 1
TEST(isSymetric, EmptyString) {
    testisSymetric("", "Symmetric");
}
//2
TEST(isSymetric, hello) {
    testisSymetric("hello", "Not symmetric"); 
}
//3
TEST(isSymetric, GanusevichMaksimVasilyevich) {
    testisSymetric("GanusevichMaksimVasilyevich", "Not symmetric");
}
//4
TEST(isSymetric, aboba) {
    testisSymetric("aboba", "Symmetric");
}
TEST(isSymetric, kek) {
    testisSymetric("kek", "Symmetric");
}
//5
TEST(isSymetric, chiloviparen12) {
    testisSymetric("chiloviparen12", "Not symmetric");
}
//6
TEST(isSymetric, 228nagibatorirotabigan822) {
    testisSymetric("228nagibatorirotabigan822", "Symmetric");
}
//7
TEST(isSymetric, a) {
    testisSymetric("a", "Symmetric");
}
//8
TEST(isSymetric, postavte10) {
    testisSymetric("postavte10", "Not symmetric");
}
//9
TEST(isSymetric, nupzh) {
    testisSymetric("nupzh", "Not symmetric");
}
//POBEDA
TEST(isSymetric, 10001) {
    testisSymetric("10 0 01", "Symmetric");
}