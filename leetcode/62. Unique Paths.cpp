// Notes: https://app.notion.com/p/62-Unique-Paths-3fbdbda92155806cba6cd190ef507d78

// Approach 1: Tabulation DP (Time = O(M*N), Space = O(M*N))
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 1));

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[m - 1][n - 1];
    }
};


// Approach 2: Space-Optimized DP (Time = O(M*N), Space = O(N))
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 1));

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[m - 1][n - 1];
    }
};


// Approach 3: Combinatorics O(min(M, N)) Time & O(1) Space
class Solution {
public:
    int uniquePaths(int m, int n) {
        int N = m + n - 2;
        int r = min(m - 1, n - 1); // Minimize multiplications
        long long res = 1;

        // Compute N C r iteratively to prevent intermediate integer overflow
        for (int i = 1; i <= r; i++) {
            res = res * (N - r + i) / i;
        }

        return res;
    }
};
