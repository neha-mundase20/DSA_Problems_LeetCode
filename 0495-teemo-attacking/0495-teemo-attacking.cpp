class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if (timeSeries.empty()) return 0;
        
        int totalPoisonedDuration = 0;
        int currentEnd = timeSeries[0] + duration - 1;
        
        for (int i = 1; i < timeSeries.size(); ++i) {
            if (timeSeries[i] > currentEnd) {
                totalPoisonedDuration += duration;
            } else {
                totalPoisonedDuration += timeSeries[i] - timeSeries[i - 1];
            }
            currentEnd = timeSeries[i] + duration - 1;
        }
        
        totalPoisonedDuration += duration; // add the last interval
        
        return totalPoisonedDuration;
    }
};