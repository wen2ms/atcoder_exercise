#include <iostream>

int main() {
    int origin_year;
    int month;
    std::cin >> origin_year >> month;

    std::cout << (origin_year + month <= 12 ? origin_year + month : origin_year + month - 12) << '\n';

    return 0;
}