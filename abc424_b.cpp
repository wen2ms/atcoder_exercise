#include <iostream>
#include <vector>

int main() {
    int num_of_persons;
    int num_of_problems;
    int num_of_events;
    std::cin >> num_of_persons >> num_of_problems >> num_of_events;
    std::vector<int> persons(num_of_persons, num_of_problems);
    while (num_of_events > 0) {
        --num_of_events;
        int num;
        int problem;
        std::cin >> num >> problem;
        --persons[num - 1];
        if (persons[num - 1] == 0) {
            std::cout << num << ' ';
        }
    }
    std::cout << '\n';

    return 0;
}