// Notes: https://app.notion.com/p/122-Best-Time-to-Buy-and-Sell-Stock-II-3ffdbda9215580ca990dfab1cc2d0709?source=copy_link

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int profit = 0;
        int buyPrice = prices[0];

        for (int i = 1; i < n; i++) {
            if (prices[i] > buyPrice) {
                profit += prices[i] - buyPrice;
            }
            
            buyPrice = prices[i];
        }

        return profit;
    }
};
