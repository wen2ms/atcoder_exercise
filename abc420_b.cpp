#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
    int num_of_people;
    int rounds;
    std::cin >> num_of_people >> rounds;
    std::vector<int> round_votes(rounds);
    std::vector<std::vector<int>> people_votes(num_of_people, std::vector<int>(rounds));

    std::vector<std::string> votes(num_of_people);
    for (std::string& vote : votes) {
        std::cin >> vote;
    }
    std::vector<int> points(num_of_people);
    for (int j = 0; j < rounds; ++j) {
        int zeros = 0;
        int ones = 0;
        for (int i = 0; i < num_of_people; ++i) {
            if (votes[i][j] == '0') {
                ++zeros;
            } else {
                ++ones;
            }
        }
        for (int i = 0; i < num_of_people; ++i) {
            if (votes[i][j] == '0') {
                if (zeros < ones) {
                    ++points[i];
                }
            } else {
                if (ones < zeros) {
                    ++points[i];
                }
            }
        }
    }
    int maximum = *std::max_element(points.begin(), points.end());
    for (int i = 0; i < num_of_people; ++i) {
        if (points[i] == maximum) {
            std::cout << i + 1 << ' ';
        }
    }
    std::cout << '\n';

    return 0;
}