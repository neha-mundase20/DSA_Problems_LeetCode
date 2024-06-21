class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int alreadySatisfied=0;
        int n=customers.size();
        
        for(int i=0;i<n;i++){
            if(grumpy[i]==0){
                alreadySatisfied=alreadySatisfied+customers[i];
            }
        }
        
        int additionalSatisfied=0;
        
        for(int i=0;i<minutes;i++){
            if(grumpy[i]==1){
                additionalSatisfied=additionalSatisfied+customers[i];
            }
        }
        
        int maxAdditionalSatisfied = additionalSatisfied;

        // Use a sliding window to find the maximum number of additional satisfied customers.
        for (int i = minutes; i < n; ++i) {
            if (grumpy[i] == 1) {
                additionalSatisfied += customers[i];
            }
            if (grumpy[i - minutes] == 1) {
                additionalSatisfied -= customers[i - minutes];
            }
            maxAdditionalSatisfied = max(maxAdditionalSatisfied, additionalSatisfied);
        }

        // The total number of satisfied customers is the sum of the already satisfied                 //customers and the maximum additional satisfied customers.
        return alreadySatisfied + maxAdditionalSatisfied;
    }
};