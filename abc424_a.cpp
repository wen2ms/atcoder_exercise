#include <iostream>

int main() {
    int side_a;
    int side_b;
    int side_c;
    std::cin >> side_a >> side_b >> side_c;
    if (side_a == side_b || side_a == side_c || side_b == side_c) {
        std::cout << "Yes" << '\n';
    } else {
        std::cout << "No" << '\n';
    }

    return 0;
}