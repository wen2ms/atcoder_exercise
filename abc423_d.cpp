#include <cstdint>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>

int main() {
    int num_of_groups;
    int capacity;
    std::cin >> num_of_groups >> capacity;
    std::vector<int64_t> join_times(num_of_groups);
    std::vector<int> durations(num_of_groups);
    std::vector<int64_t> people_counts(num_of_groups);
    for (int i = 0; i < num_of_groups; ++i) {
        std::cin >> join_times[i] >> durations[i] >> people_counts[i];
    }
    std::priority_queue<std::pair<int64_t, int64_t>, std::vector<std::pair<int64_t, int64_t>>, std::greater<>> queue;
    std::vector<int64_t> entry_times(num_of_groups, -1);
    int64_t current_sum = 0;
    int64_t time = 0;
    for (int i = 0; i < num_of_groups; ++i) {
        time = std::max(time, join_times[i]);
        while (current_sum + people_counts[i] > capacity) {
            auto [leave_time, people_count] = queue.top();
            queue.pop();
            time = std::max(time, leave_time);
            current_sum -= people_count;
        }
        entry_times[i] = time;
        queue.emplace(time + durations[i], people_counts[i]);
        current_sum += people_counts[i];
    }
    for (int64_t entry_time : entry_times) {
        std::cout << entry_time << '\n';
    }

    return 0;
}
