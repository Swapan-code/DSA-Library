// Notes: https://app.notion.com/p/63-Unique-Paths-II-3fbdbda921558030a08dc16e78bb975d

// Approach 1: Tabulation DP (Time = O(M*N), Space = O(M*N))
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1) return 0;

        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 1;

        // Filling 1st row
        for (int j = 1; j < n; j++) {
            if (obstacleGrid[0][j] == 0) dp[0][j] = 1;
            else break;
        }

        // Filling 1st col
        for (int i = 1; i < m; i++) {
            if (obstacleGrid[i][0] == 0) dp[i][0] = 1;
            else break;
        }

        // Filling rest of dp matrix
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j] == 1) dp[i][j] = 0;
                else dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[m - 1][n - 1];
    }
};


// Approach 2: Space-Optimized DP (Time = O(M*N), Space = O(N))
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1) return 0;

        vector<int> dp(n,0);
        dp[0] = 1;
        for (int j = 1; j < n; j++) {
            if (obstacleGrid[0][j] == 0) dp[j] = 1;
            else break;
        }

        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (obstacleGrid[i][j] == 1) dp[j] = 0;
                else if(j > 0) dp[j] = dp[j] + dp[j - 1];
            }
        }

        return dp[n - 1];
    }
};
