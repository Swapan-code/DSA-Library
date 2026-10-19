// Notes: https://app.notion.com/p/121-Best-Time-to-Buy-and-Sell-Stock-3fddbda9215580628f8dca794f2f0a32?source=copy_link

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int buyPrice = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            buyPrice = min(buyPrice, prices[i]);
            ans = max(ans, prices[i] - buyPrice);
        }
        return ans;
    }
};
