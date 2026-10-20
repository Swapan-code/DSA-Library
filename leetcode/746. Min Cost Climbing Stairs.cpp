// Notes: https://app.notion.com/p/746-Min-Cost-Climbing-Stairs-3fadbda9215580a59a4bf681c0efdf34?source=copy_link

class Solution {
private:
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int prev2 = 0;
        int prev = 0;

        for(int i=2; i<=n; i++){
            int curr = min(prev + cost[i-1], prev2 + cost[i-2]);
            prev2 = prev;
            prev = curr;
        }

        return prev;
    }
};
