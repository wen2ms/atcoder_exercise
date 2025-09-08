#include <iostream>
#include <vector>

int main() {
    int size;
    int num_of_queries;
    std::cin >> size >> num_of_queries;
    std::vector<std::string> matrix(size);
    for (std::string& word : matrix) {
        std::cin >> word;
    }
    std::vector<std::vector<int>> count(size, std::vector<int>(size));
    for (int i = 1; i < size; ++i) {
        for (int j = 1; j < size; ++j) {
            count[i][j] = count[i - 1][j] + count[i][j - 1] - count[i - 1][j - 1];
            if (matrix[i][j] == '.' && matrix[i - 1][j] == '.' && matrix[i][j - 1] == '.' && matrix[i - 1][j - 1] == '.') {
                ++count[i][j];
            }
        }
    }

    while (num_of_queries > 0) {
        --num_of_queries;
        int row_start;
        int row_end;
        int col_start;
        int col_end;
        std::cin >> row_start >> row_end >> col_start >> col_end;
        int ans = count[row_end - 1][col_end - 1] - count[row_start - 1][col_end - 1] - count[row_end - 1][col_start - 1] +
                  count[row_start - 1][col_start - 1];

        std::cout << ans << '\n';
    }

    return 0;
}