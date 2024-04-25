class Solution {
public:
    int longestIdealString(string s, int k) {
        /*int i=0,j=i+1;
        int n=s.length();
        vector<char>solution;
        solution.push_back(s[i]);
        
        while(i<n && j<n){
            int val=int(s[j])-int(s[i]);
            if(val<0){  //if difference is neagtive, make it poistive
                val=-(val);
            }
            if(val<=k){ //ideal character found move both i & j
                solution.push_back(s[j]);
                i++;
                j++;
            }
            else{   //ideal character isn't found, only move j
                j++;
            }
        }
        return solution.size();*/
        
        vector<int> dp(26, 0);  // DP array to track the longest subsequence ending with each letter

    for (int i = 0; i < s.length(); i++) {
        int val = s[i] - 'a';  // Convert char to index (0 for 'a', 25 for 'z')

        int maxDp = 0;  
        // Consider characters within the allowed k distance
        for (int j = max(0, val - k); j <= min(25, val + k); j++) {
            maxDp = max(maxDp, dp[j]); // Find the maximum existing length within allowed distance
        }

        dp[val] = max(dp[val], maxDp + 1); // Update the dp value for this character
    }

    return *max_element(dp.begin(), dp.end());  // Return the longest length from dp array
    }
};