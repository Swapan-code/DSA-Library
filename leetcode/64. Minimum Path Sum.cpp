// Notes: https://app.notion.com/p/64-Minimum-Path-Sum-3fbdbda92155808a9d03c160c9e7373d

// 1. Tabulation (Time = O(M*N), Space = O(M*N))
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n));
        dp[0][0] = grid[0][0];

        // 1st row
        for (int j = 1; j < n; j++) {
            dp[0][j] = dp[0][j - 1] + grid[0][j];
        }

        // 1st col
        for (int i = 1; i < m; i++) {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        return dp[m - 1][n - 1];
    }
};


// 2. Space-Optimized (Time = O(M*N), Space = O(N))
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> dp(n);
        dp[0] = grid[0][0];

        // 1st row
        for (int j = 1; j < n; j++) {
            dp[j] = dp[j - 1] + grid[0][j];
        }

        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (j == 0) {
                    dp[0] = dp[0] + grid[i][0];

                } else {
                    dp[j] = grid[i][j] + min(dp[j], dp[j - 1]);
                }
            }
        }

        return dp[n - 1];
    }
};
