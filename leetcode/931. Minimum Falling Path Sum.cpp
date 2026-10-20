// Notes: https://app.notion.com/p/931-Minimum-Falling-Path-Sum-3fbdbda9215580cda499f1cd03e97089?source=copy_link

// Approach 1: Tabulation DP (Time = O(N^2), Space = O(N^2))
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int ans;

        vector<vector<int>> dp(n, vector<int>(n));
        for (int j = 0; j < n; j++) {
            dp[0][j] = matrix[0][j];
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j] = dp[i - 1][j];
                if (j > 0 && dp[i - 1][j - 1] < dp[i][j]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                if (j < n - 1 && dp[i - 1][j + 1] < dp[i][j]) {
                    dp[i][j] = dp[i - 1][j + 1];
                }
                dp[i][j] += matrix[i][j];
            }
        }

        // Find min in last row
        ans = dp[n - 1][0];
        for (int j = 1; j < n; j++) {
            if (dp[n - 1][j] < ans) {
                ans = dp[n - 1][j];
            }
        }

        return ans;
    }
};


// Approach 2: Space-Optimized DP (Time = O(N^2), Space = O(N))
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();

        vector<int> dp(n);
        vector<int> temp(n);
        for (int j = 0; j < n; j++) {
            dp[j] = matrix[0][j];
        }
        temp = dp;
        // Use this instead of above
        // swap(temp, dp); // O(1) pointer swap instead of copying elements in O(n)

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dp[j] = temp[j];
                if (j > 0 && temp[j - 1] < dp[j]) {
                    dp[j] = temp[j - 1];
                }
                if (j < n - 1 && temp[j + 1] < dp[j]) {
                    dp[j] = temp[j + 1];
                }
                dp[j] += matrix[i][j];
            }
            temp = dp;
            // Use this instead of above
		        // swap(temp, dp); // O(1) pointer swap instead of copying elements in O(n)
        }

        // Find min in dp
        return *min_element(temp.begin(), temp.end());
    }
};
