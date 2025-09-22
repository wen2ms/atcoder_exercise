#include <iostream>
#include <queue>
#include <vector>

int main() {
    int num_of_skills;
    std::cin >> num_of_skills;
    std::vector<std::vector<int>> grid(num_of_skills + 1);
    std::queue<int> queue;
    std::vector<bool> learned(num_of_skills + 1);
    for (int i = 1; i <= num_of_skills; ++i) {
        int skill_a;
        int skill_b;
        std::cin >> skill_a >> skill_b;
        if (skill_a == 0 && skill_b == 0) {
            queue.push(i);
            learned[i] = true;
            continue;
        }
        grid[skill_a].push_back(i);
        grid[skill_b].push_back(i);
    }
    int result = 0;
    while (!queue.empty()) {
        int learned_skill = queue.front();
        ++result;
        queue.pop();
        for (int skill : grid[learned_skill]) {
            if (!learned[skill]) {
                learned[skill] = true;
                queue.push(skill);
            }
        }
    }
    std::cout << result << '\n';

    return 0;
}