#include <iostream>
#include <queue>

int main() {
    std::priority_queue<int, std::vector<int>, std::greater<>> heap;
    int queries;
    std::cin >> queries;

    for (int i = 0; i < queries; ++i) {
        int type;
        std::cin >> type;
        if (type == 1) {
            int num;
            std::cin >> num;
            heap.push(num);
        } else {
            if (!heap.empty()) {
                int ans = heap.top();
                heap.pop();
                std::cout << ans << '\n';
            }
        }
    }

    return 0;
}