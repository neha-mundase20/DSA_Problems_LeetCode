class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //To make maximum profit, if we sell stock on 'i th' day then we must have bought it
        //on a day from 1st->(i-1)th which has minimal buying price
        
        int minElement=prices[0],profit=0,maxProfit=0;
        
        for(int i=0;i<prices.size();i++){
            
            profit=prices[i]-minElement;
            maxProfit=max(maxProfit,profit);
            
            minElement=min(minElement,prices[i]);   //Each time update the minimum element 
            //value that represents the day with minimal buying price
        }
        return maxProfit;
    }
};