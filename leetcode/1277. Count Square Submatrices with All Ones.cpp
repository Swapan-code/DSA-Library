// Notes: https://app.notion.com/p/1277-Count-Square-Submatrices-with-All-Ones-3fbdbda9215580bea4cada18d09aa07f?source=copy_link

// Approach 1: Tabulation DP (Time = O(M*N), Space = O(M*N))
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = 0;

        vector<vector<int>> dp(m, vector<int>(n));
        // Filling 1st row
        for (int j = 0; j < n; j++) {
            dp[0][j] = matrix[0][j];
        }
        // Filling 1st col
        for (int i = 1; i < m; i++) {
            dp[i][0] = matrix[i][0];
        }

        // Filling rest of matrix
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] =
                        1 + min({dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]});
                }
            }
        }

        // Sum over dp -> can also calculate it in 3 loops before instead
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans += dp[i][j];
            }
        }

        return ans;
    }
};

// Approach 2: Space-Optimized DP (Time = O(M*N), Space = O(N))
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = 0;

        vector<int> prev(n);

        // Filling 1st row
        for (int j = 0; j < n; j++) {
            prev[j] = matrix[0][j];
            ans += prev[j];
        }

        // Filling rest of matrix
        for (int i = 1; i < m; i++) {
            vector<int> curr(n);
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    curr[j] = 0;
                } else if (j == 0) {
                    curr[j] = 1;
                    ans++;
                } else {
                    curr[j] = 1 + min({curr[j - 1], prev[j], prev[j - 1]});
                    ans += curr[j];
                }
            }
            swap(prev, curr);
        }

        return ans;
    }
};
