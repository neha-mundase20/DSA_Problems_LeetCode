class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        vector<int>waitTimes;
        int currentTime=customers[0][0],orderArrivalTime=0;

        for(int i=0;i<customers.size();i++){
            int extraWaitTime=0,totalWaitTime=0;
            orderArrivalTime=customers[i][0];
            if(orderArrivalTime<currentTime){   //  Order has already arrived
                extraWaitTime=currentTime-orderArrivalTime;
            }
            else{   //Chef is idle coz no order is arrived
                currentTime=customers[i][0];
            }
            totalWaitTime=customers[i][1]+extraWaitTime;
            waitTimes.push_back(totalWaitTime);
            currentTime=currentTime+customers[i][1];
        }

        long long totalSum=0;
        for(int i=0;i<waitTimes.size();i++){
            totalSum=totalSum+waitTimes[i];
        }

        return (double)totalSum/(waitTimes.size());
    }
};