#include <array>
#include <iostream>
#include <queue>
#include <vector>

int main() {
    int rows;
    int cols;
    std::cin >> rows >> cols;

    std::vector<std::vector<char>> matrix(rows, std::vector<char>(cols));
    std::pair<int, int> start;
    std::pair<int, int> end;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cin >> matrix[i][j];
            if (matrix[i][j] == 'S') {
                start = {i, j};
            } else if (matrix[i][j] == 'G') {
                end = {i, j};
            }
        }
    }

    std::vector<std::vector<std::vector<int>>> dist(rows, std::vector<std::vector<int>>(cols, std::vector<int>(2)));
    dist[start.first][start.second][0] = 0;
    std::queue<std::array<int, 3>> queue;
    queue.push({start.first, start.second, 0});
    std::array<int, 5> directions = {1, 0, -1, 0, 1};

    while (!queue.empty()) {
        auto [row, col, status] = queue.front();
        queue.pop();

        if (row == end.first && col == end.second) {
            std::cout << dist[row][col][status] << '\n';
            return 0;
        }

        for (int i = 0; i < 4; ++i) {
            int new_row = row + directions[i];
            int new_col = col + directions[i + 1];
            if (new_row < 0 || new_col < 0 || new_row >= rows || new_col >= cols || matrix[new_row][new_col] == '#') {
                continue;
            }
            if (status == 0 && matrix[new_row][new_col] == 'x') {
                continue;
            }
            if (status == 1 && matrix[new_row][new_col] == 'o') {
                continue;
            }
            int new_status = status ^ static_cast<int>(matrix[new_row][new_col] == '?');
            if (dist[new_row][new_col][new_status] == 0) {
                dist[new_row][new_col][new_status] = dist[row][col][status] + 1;
                queue.push({new_row, new_col, new_status});
            }
        }
    }

    std::cout << "-1" << '\n';

    return 0;
}