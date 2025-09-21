#include <iostream>
#include <vector>

int main() {
    int doors_count;
    std::cin >> doors_count;
    std::vector<int> doors(doors_count);
    for (int& door : doors) {
        std::cin >> door;
    }
    int left = 0;
    for (int i = 0; i < doors_count; ++i) {
        if (doors[i] == 1) {
            left = i;
            break;
        }
    }
    int right = 0;
    for (int i = doors_count - 1; i >= 0; --i) {
        if (doors[i] == 1) {
            right = i;
            break;
        }
    }
    std::cout << right - left << '\n';

    return 0;
}