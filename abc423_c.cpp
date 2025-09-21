#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int doors_count;
    int start;
    std::cin >> doors_count >> start;
    std::vector<int> doors(doors_count);
    for (int& door : doors) {
        std::cin >> door;
    }
    int left = doors_count;
    int right = 0;
    for (int i = 0; i < doors_count; ++i) {
        if (doors[i] == 0) {
            left = i;
            break;
        }
    }
    for (int i = doors_count - 1; i >= 0; --i) {
        if (doors[i] == 0) {
            right = i;
            break;
        }
    }
    int open = std::count(doors.begin(), doors.end(), 0);
    int count = 0;
    if (left <= start - 1) {
        for (int i = left + 1; i < start; ++i) {
            if (doors[i] == 1) {
                ++count;
            }
        }
    }
    if (right >= start) {
        for (int i = start; i < right; ++i) {
            if (doors[i] == 1) {
                ++count;
            }
        }
    }

    int result = 2 * count + open;
    std::cout << result << '\n';

    return 0;
}