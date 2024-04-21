class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string> result;
        int minIndexSum = INT_MAX; // Use max value to start comparing for minimum

        for (int i = 0; i < list1.size(); ++i) {
            for (int j = 0; j < list2.size(); ++j) {
                if (list1[i] == list2[j]) { // When we find a common string
                    int sum = i + j;
                    if (sum < minIndexSum) {
                        // Found a new minimum sum
                        minIndexSum = sum;
                        result.clear(); // Clear previous results
                        result.push_back(list1[i]); // Add this restaurant
                    } else if (sum == minIndexSum) {
                        // Same minimum sum found, add this restaurant to results
                        result.push_back(list1[i]);
                    }
                }
            }
        }

        return result;
    }
};