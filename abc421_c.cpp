#include <cstdint>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

int main() {
    int num;
    std::string str;
    std::cin >> num >> str;

    std::vector<int> pos;
    for (int i = 0; i < 2 * num; ++i) {
        if (str[i] == 'A') {
            pos.push_back(i);
        }
    }
    int64_t result = std::numeric_limits<int64_t>::max();
    for (int i = 0; i < 2; ++i) {
        int64_t sum = 0;
        for (int j = 0; j < num; ++j) {
            sum += std::abs(pos[j] - (2 * j + i));
        }
        result = std::min(result, sum);
    }

    std::cout << result << '\n';

    return 0;
}