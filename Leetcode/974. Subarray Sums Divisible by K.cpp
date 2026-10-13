class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        long long sum = 0;
        unordered_map<int, int> mpp; // {remainder, count}

        for (int i = 0; i < n; i++) {
            sum += nums[i];
            int rem = sum % k;
            if (rem < 0) rem += k;
            
            if (rem == 0) ans++; // subarray (0, i)

            if (mpp.find(rem) != mpp.end()) {
                ans += mpp[rem];
                mpp[rem]++;
            } else {
                mpp[rem] = 1;
            }
        }

        return ans;
    }
};

// Time Complexity = O(N)
// Space Complexity = O(K)
