// Notes: https://app.notion.com/p/1463-Cherry-Pickup-II-3fbdbda9215580deb827e84c0fb86a57?source=copy_link

// Approach 1: Tabulation DP (Time = O(M*N*N), Space = O(M*N*N))
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(n, vector<int>(n, -1)));
        dp[0][0][n - 1] = grid[0][0] + grid[0][n - 1];

        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if (k < n - i - 1 || j > i) {
                        // Robots can't reach at (j,k) -> geometrically
                        // impossible
                        continue;
                    }
                    int temp = -1;
                    for (int x = -1; x <= 1; x++) {
                        for (int y = -1; y <= 1; y++) {
                            if (j + x >= 0 && j + x < n && k + y >= 0 &&
                                k + y < n && dp[i - 1][j + x][k + y] != -1) {
                                temp = max(temp, dp[i - 1][j + x][k + y]);
                            }
                        }
                    }

                    if (temp == -1) {
                        // None of 9 were valid paths
                        continue;
                    }
                    if (j == k) {
                        temp += grid[i][j];
                    } else {
                        temp += grid[i][j] + grid[i][k];
                    }

                    dp[i][j][k] = temp;
                }
            }
        }

        // Find max of dp[m-1][j][k]
        int ans = -1;
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                ans = max(ans, dp[m - 1][j][k]);
            }
        }

        return ans;
    }
};

// Approach 2: Space Optimized DP (Time = O(M*N*N), Space = O(N*N))
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> prev(n, vector<int>(n, -1));
        prev[0][n - 1] = grid[0][0] + grid[0][n - 1];

        for (int i = 1; i < m; i++) {
            vector<vector<int>> dp(n, vector<int>(n, -1));
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if (k < n - i - 1 || j > i) {
                        // Robots can't reach at (j,k) -> geometrically
                        // impossible
                        continue;
                    }
                    int temp = -1;
                    for (int x = -1; x <= 1; x++) {
                        for (int y = -1; y <= 1; y++) {
                            if (j + x >= 0 && j + x < n && k + y >= 0 &&
                                k + y < n && prev[j + x][k + y] != -1) {
                                temp = max(temp, prev[j + x][k + y]);
                            }
                        }
                    }

                    if (temp == -1) {
                        // None of 9 were valid paths
                        continue;
                    }
                    if (j == k) {
                        temp += grid[i][j];
                    } else {
                        temp += grid[i][j] + grid[i][k];
                    }

                    dp[j][k] = temp;
                }
            }

            swap(dp, prev);
        }

        // Find max of prev[j][k]
        int ans = -1;
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                ans = max(ans, prev[j][k]);
            }
        }

        return ans;
    }
};
