// Notes: https://app.notion.com/p/174-Dungeon-Game-3fbdbda921558045acabfa32a2fe046e?source=copy_link

// Approach 1: Tabulation DP (Time = O(M*N), Space = O(M*N))
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();

        vector<vector<int>> dp(m, vector<int>(n));
        dp[m - 1][n - 1] = max(1, 1 - dungeon[m - 1][n - 1]);

        // last row
        for (int j = n - 2; j >= 0; j--) {
            dp[m - 1][j] = dp[m - 1][j + 1];
            dp[m - 1][j] = max(1, dp[m - 1][j] - dungeon[m - 1][j]);
        }

        // last col
        for (int i = m - 2; i >= 0; i--) {
            dp[i][n - 1] = dp[i + 1][n - 1];
            dp[i][n - 1] = max(1, dp[i][n - 1] - dungeon[i][n - 1]);
        }

        // Rest of dp matrix
        for (int i = m - 2; i >= 0; i--) {
            for (int j = n - 2; j >= 0; j--) {
                dp[i][j] = min(dp[i][j + 1], dp[i + 1][j]);
                dp[i][j] = max(1, dp[i][j] - dungeon[i][j]);
            }
        }

        return dp[0][0];
    }
};

// Approach 2: Space-Optimized DP (Time = O(M*N), Space = O(N))
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();

        vector<int> dp(n);
        dp[n - 1] = max(1, 1 - dungeon[m - 1][n - 1]);

        // last row
        for (int j = n - 2; j >= 0; j--) {
            dp[j] = dp[j + 1];
            dp[j] = max(1, dp[j] - dungeon[m - 1][j]);
        }

        for (int i = m - 2; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (j != n - 1) {
                    dp[j] = min(dp[j + 1], dp[j]);
                }
                dp[j] = max(1, dp[j] - dungeon[i][j]);
            }
        }

        return dp[0];
    }
};
