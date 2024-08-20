class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int m=word1.length(),n=word2.length();
        int i=0,j=0;
        string solution;

        while(i<m && j<n){
            solution.push_back(word1[i++]);
            solution.push_back(word2[j++]);
        }

        while(i<m){
            solution.push_back(word1[i++]);
        }

        while(j<n){
            solution.push_back(word2[j++]);
        }

        return solution;
    }
};