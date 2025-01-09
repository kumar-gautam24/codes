#include<bits/stdc++.h>
#include <cctype>
#include <string>

// Function to get the vowel count in a single string
int getVowelCount(const std::string& str) {
    int count = 0;
    for (char c : str) {
        if (tolower(c) == 'a' || tolower(c) == 'e' || tolower(c) == 'i' || tolower(c) == 'o' || tolower(c) == 'u') {
            count++;
        }
    }
    return count;
}

// Function to process a list of strings and return the count of vowels for each string
std::vector<int> getVowelCounts(const std::vector<std::string>& strings) {
    std::vector<int> counts;
    for (const std::string& str : strings) {
        counts.push_back(getVowelCount(str));
    }
    return counts;
}

int getVowelIndex(const std::string& str) {
    for (int i = 0; i < str.length(); i++) {
        char c = tolowPer(str[i]);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            return i;
        }
    }
    return -1; // Return -1 if no vowel is found
}

int main() {
    std::string input;
    std::cout << "Enter a string: ";
    std::getline(std::cin, input);

    int vowelCount = getVowelCount(input);
    int vowelIndex = getVowelIndex(input);

    std::cout << "Vowel count: " << vowelCount << std::endl;
    if (vowelIndex != -1) {
        std::cout << "First vowel index: " << vowelIndex << std::endl;
    } else {
        std::cout << "No vowel found." << std::endl;
    }

    return 0;
}