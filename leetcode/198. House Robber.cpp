// Notes: https://app.notion.com/p/Maximum-sum-of-non-adjacent-elements-3fadbda92155803a8bc9d1b9d4c1fafe?source=copy_link

class Solution {
public:
    int nonAdjacent(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return max(0, nums[0]);

        // Option to pick 0 elements if negative
        int prev2 = max(0, nums[0]);
        int prev1 = max({0, nums[0], nums[1]});

        for (int i = 2; i < n; i++) {
            // Choice 1: Exclude nums[i] -> prev1
            // Choice 2: Include nums[i] -> prev2 + nums[i]
            // Choice 3: Take nothing -> 0
            int curr = max({prev1, prev2 + nums[i], 0});
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};
