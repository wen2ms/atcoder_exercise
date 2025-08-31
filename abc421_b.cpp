#include <algorithm>
#include <cstdint>
#include <iostream>
#include <string>

int main() {
    int64_t first;
    int64_t second;
    std::cin >> first >> second;

    for (int i = 0; i < 8; ++i) {
        std::string temp = std::to_string(first + second);
        std::reverse(temp.begin(), temp.end());
        first = second;
        second = std::stoll(temp);
    }

    std::cout << second << '\n';

    return 0;
}