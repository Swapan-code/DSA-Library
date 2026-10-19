// Notes: https://app.notion.com/p/91-Decode-Ways-3fbdbda921558040a0eae201f968245d?source=copy_link

// Approach 1: Tabulation (Time = O(N) ; Space = O(N))
class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if (s[0] == '0') {
            return 0;
        }
        if (n == 1) {
            return 1;
        }

        vector<int> dp(n + 1, 0);
        dp[0] = 1;

        // Take individually
        if (s[1] != '0') {
            dp[1]++;
        }
        // Take both together
        if ((s[0] == '1') || (s[0] == '2' && s[1] <= '6')) {
            dp[1]++;
        }

        for (int i = 2; i < n; i++) {
            // Option 1: Take s[i] individually
            if (s[i] >= '1') {
                dp[i] += dp[i - 1];
            }

            // Option 2: Take s[i-1]s[i] together
            if ((s[i - 1] == '1') || (s[i - 1] == '2' && s[i] <= '6')) {
                dp[i] += dp[i - 2];
            }
        }

        return dp[n - 1];
    }
};

// Approach 2: Space Optimized (Time = O(N) ; Space = O(1))
class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if (s[0] == '0') {
            return 0;
        }
        if (n == 1) {
            return 1;
        }

        int prev2 = 1;
        int prev1 = 0;

        // Take individually
        if (s[1] != '0') {
            prev1++;
        }
        // Take both together
        if ((s[0] == '1') || (s[0] == '2' && s[1] <= '6')) {
            prev1++;
        }

        for (int i = 2; i < n; i++) {
            int curr = 0;
            // Option 1: Take s[i] individually
            if (s[i] >= '1') {
                curr += prev1;
            }

            // Option 2: Take s[i-1]s[i] together
            if ((s[i - 1] == '1') || (s[i - 1] == '2' && s[i] <= '6')) {
                curr += prev2;
            }

            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};
