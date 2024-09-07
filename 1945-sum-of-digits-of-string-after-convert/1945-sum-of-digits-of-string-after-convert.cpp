class Solution {
public:
    int getLucky(string s, int k) {
        string result;
        for(int i=0;i<s.length();i++){
            int val=s[i]-'a'+1;
            result=result+to_string(val);
        }

        int sum=0;
        for(int i=0;i<result.length();i++){
            sum=sum+(result[i]-'0');
        }

        while(--k>0){
            int tempSum = 0;
            while(sum>0) {
                tempSum=tempSum+sum%10; // Extract each digit and sum them
                sum=sum/10;
            }
            sum=tempSum;
        }
        return sum;
    }
};