class Solution {
public:
    int countPalindromicSubsequence(string s) {
        // unordered_set<string>result;
        // int n=s.size();

        // Approach-1
        // for(int i=0;i<n-2;i++){
        //     for(int j=i+1;j<n-1;j++){
        //         for(int k=j+1;k<n;k++){
        //             if(s[i]==s[k]){   //String is a palindrome
        //                 string temp;
        //                 temp.push_back(s[i]);
        //                 temp.push_back(s[j]);
        //                 temp.push_back(s[k]);

        //                 result.insert(temp);
        //             }
        //         }
        //     }
        // }
        // return result.size();

        // Approach-2
        // //Iterate over all possible middle characters
        // for(int j=1;j<n-1;j++){
        //     //Possible left and right characters
        //     unordered_set<char>leftSet;
        //     unordered_set<char>rightSet;

        //     //Left Set possible characters
        //     for(int i=0;i<j;i++){
        //         leftSet.insert(s[i]);
        //     }

        //     //Right Set possible characters
        //     for(int k=j+1;k<n;k++){
        //         rightSet.insert(s[k]);
        //     }

        //     //Check for palindromes
        //     for(auto it:leftSet){
        //         if(rightSet.find(it)!=rightSet.end()){
        //             //Same characters exists in both left and right sets

        //             string temp;
        //             temp=string(1,it)+s[j]+it;

        //             result.insert(temp);
        //         }
        //     }
        // }
        // return result.size();

        // Approach-3

        vector<int> first(26, -1), last(26, -1);
        int n = s.size();
        
        // Record the first and last occurrence of each character
        for (int i = 0; i < n; ++i) {
            if (first[s[i] - 'a'] == -1) {
                first[s[i] - 'a'] = i;
            }
            last[s[i] - 'a'] = i;
        }

        int count = 0;
        // Check for valid palindromes
        for (int i = 0; i < 26; ++i) {
            if (first[i] != -1 && last[i] != -1 && first[i] < last[i]) {
                unordered_set<char> middle;
                // Collect unique characters between first[i] and last[i]
                for (int j = first[i] + 1; j < last[i]; ++j) {
                    middle.insert(s[j]);
                }
                count += middle.size();
            }
        }

        return count;
    }
};