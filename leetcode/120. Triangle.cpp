// Notes: https://app.notion.com/p/120-Triangle-3fbdbda921558078a812dc318789090f?source=copy_link

// Approach 1: Tabulation DP (Time = O(N^2), Space = O(N^2))
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n));
        dp[0][0] = triangle[0][0];

        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                if (j == 0) {
                    dp[i][j] = dp[i - 1][j];
                } else if (j == i) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1]);
                }
                dp[i][j] += triangle[i][j];
            }
        }

        return *min_element(dp[n - 1].begin(), dp[n - 1].end());
    }
};

// Approach 2: Space-Optimized DP (Time = O(N^2), Space = O(N))
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp(n);
        vector<int> temp(n);
        dp[0] = triangle[0][0];
        temp[0] = triangle[0][0];

        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                if (j == 0) {
                    dp[j] = temp[j];
                } else if (j == i) {
                    dp[j] = temp[j - 1];
                } else {
                    dp[j] = min(temp[j], temp[j - 1]);
                }
                dp[j] += triangle[i][j];
            }
            swap(temp, dp);
        }

        return *min_element(temp.begin(), temp.end());
    }
};
