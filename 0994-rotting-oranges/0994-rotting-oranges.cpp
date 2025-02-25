class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
    int minutes = 0;
    int freshCount = 0;
    queue<pair<int, int>> rottenQueue;
    int rows = grid.size();
    int cols = grid[0].size();

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (grid[i][j] == 2) {
                rottenQueue.push({i, j});
            } else if (grid[i][j] == 1) {
                freshCount++;
            }
        }
    }

    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    while (!rottenQueue.empty()) {
        int size = rottenQueue.size();
        bool rottenThisMinute = false;

        for (int i = 0; i < size; ++i) {
            auto [x, y] = rottenQueue.front();
            rottenQueue.pop();

            for (const auto& dir : directions) {
                int newX = x + dir.first;
                int newY = y + dir.second;

                if (newX >= 0 && newX < rows && newY >= 0 && newY < cols && grid[newX][newY] == 1) {
                    grid[newX][newY] = 2; 
                    rottenQueue.push({newX, newY});
                    freshCount--; 
                    rottenThisMinute = true; 
                }
            }
        }

        if (rottenThisMinute) {
            minutes++; 
        }
    }

    return freshCount == 0 ? minutes : -1; 
    }
};