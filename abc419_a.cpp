#include <iostream>
#include <unordered_map>

int main() {
    std::unordered_map<std::string, std::string> hash = {{"red", "SSS"}, {"blue", "FFF"}, {"green", "MMM"}};
    std::string str;
    std::cin >> str;

    if (str == "red") {
        std::cout << "SSS" << '\n';
    } else if (str == "blue") {
        std::cout << "blue" << '\n';
    } else if (str == "green") {
        std::cout << "MMM" << '\n';
    } else {
        std::cout << "Unknown" << '\n';
    }

    return 0;
}