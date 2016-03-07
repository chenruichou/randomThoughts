class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            if(prices.size()<2) return 0;
            return solMaxProfit(prices, 0, false,-1);
        }
        int solMaxProfit(vector<int> &prices, int indx, bool isBought, int indx_bought){
            if(!isBought){
                if(indx>=prices.size()-2) return 0;
                int gain1 = solMaxProfit(prices, indx++, true, indx);
                int gain2 = solMaxProfit(prices, indx++, false, indx_bought);
                return max(gain1, gain2);
            }else{
                int gain1 = prices[indx]-prices[indx_bought];
                if(indx==prices.size()-1) return gain1;

                int gain2 = solMaxProfit(prices, indx++, true, indx_bought);
                return max(gain1, gain2);
            }
        }
};
