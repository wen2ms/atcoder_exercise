#include <iostream>
#include <string>
#include <vector>

int main() {
    int num_of_rooms;
    std::cin >> num_of_rooms;

    std::vector<std::string> names(num_of_rooms);
    for (std::string& name : names) {
        std::cin >> name;
    }
    int room;
    std::string person;
    std::cin >> room >> person;

    std::cout << (names[room - 1] == person ? "Yes" : "No") << '\n';

    return 0;
}