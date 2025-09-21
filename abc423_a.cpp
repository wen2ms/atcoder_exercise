#include <iostream>

int main() {
    int deposit;
    int tax;
    std::cin >> deposit >> tax;

    int count = deposit / (1000 + tax);
    int result = 1000 * count;
    std::cout << result << '\n';

    return 0;
}