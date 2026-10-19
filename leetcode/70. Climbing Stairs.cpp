// Notes: https://app.notion.com/p/70-Climbing-Stairs-3fadbda9215580c0bd5df61ce78a1798?source=copy_link

class Solution {
public:
    int climbStairs(int n) {
        int prev2 = 1;
        int prev = 1;
        
        for(int i=2; i<=n; i++){
            int curr = prev2 + prev;
            prev2 = prev;
            prev = curr;
        }

        return prev;
    }
};
