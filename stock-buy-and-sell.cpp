class Solution {
public:

    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int minPrice = INT_MAX;

        for(int i:prices){
            if(minPrice > i){
                minPrice = i;
            }
            maxProfit = max(maxProfit,i-minPrice);
        }
        return maxProfit;
    }
};
