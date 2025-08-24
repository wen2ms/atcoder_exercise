#include <iostream>
#include <vector>

int main() {
    int seq_len;
    int queries;
    std::cin >> seq_len >> queries;

    std::vector<int> vals1(seq_len);
    std::vector<int> vals2(seq_len);
    for (int i = 0; i < seq_len; ++i) {
        std::cin >> vals1[i];
    }
    for (int i = 0; i < seq_len; ++i) {
        std::cin >> vals2[i];
    }

    int64_t sum = 0;
    for (int i = 0; i < seq_len; ++i) {
        sum += std::min(vals1[i], vals2[i]);
    }

    for (int i = 0; i < queries; ++i) {
        char letter;
        int pos;
        int value;
        std::cin >> letter >> pos >> value;

        sum -= std::min(vals1[pos - 1], vals2[pos - 1]);
        if (letter == 'A') {
            vals1[pos - 1] = value;
        } else {
            vals2[pos - 1] = value;
        }
        sum += std::min(vals1[pos - 1], vals2[pos - 1]);
        std::cout << sum << '\n';
    }

    return 0;
}