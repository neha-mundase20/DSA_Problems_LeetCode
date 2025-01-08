class Solution {
public:

    bool isPrefixAndSuffix(string str1, string str2){
        //Returns if str1 is both prefix and suffix of str2
        if(str1.size()>str2.size()){
            return false;
        }
        int m=str1.length();
        int n=str2.length();

        // s.substr(startIndex,length)

        string prefix=str2.substr(0,m);
        string suffix=str2.substr(n-m,m);

        if(prefix==str1 && suffix==str1){
            return true;
        }

        return false;
    }

    int countPrefixSuffixPairs(vector<string>& words) {
        int n=words.size();
        int count=0;

        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(isPrefixAndSuffix(words[i],words[j])==true){
                    count=count+1;
                }
            }
        }
        return count;
    }
};