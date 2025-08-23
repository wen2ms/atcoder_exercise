#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int num_of_people;
    std::cin >> num_of_people;

    std::vector<int> pos_x(num_of_people);
    std::vector<int> pos_y(num_of_people);

    for (int i = 0; i < num_of_people; ++i) {
        std::cin >> pos_x[i] >> pos_y[i];
    }

    int max_x = *std::max_element(pos_x.begin(), pos_x.end()) - *std::min_element(pos_x.begin(), pos_x.end());
    int max_y = *std::max_element(pos_y.begin(), pos_y.end()) - *std::min_element(pos_y.begin(), pos_y.end());
    int result = (std::max(max_x, max_y) + 1) / 2;
    std::cout << result << '\n';

    return 0;
}