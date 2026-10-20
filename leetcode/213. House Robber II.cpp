// Notes: https://app.notion.com/p/213-House-Robber-II-3fadbda9215580ac8fe5cdaeb5c8bb4d?source=copy_link

class Solution {
private:
    int robLinear(vector<int>& nums, int s, int e) {
    int prev2 = 0;
    int prev1 = 0;

    for (int i = s; i <= e; i++) {
        int curr = max(prev1, prev2 + nums[i]);
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        if (n == 2)
            return max(nums[0], nums[1]);

        int choice1 = robLinear(nums, 0, n - 2);
        int choice2 = robLinear(nums, 1, n - 1);

        return max(choice1, choice2);
    }
};
