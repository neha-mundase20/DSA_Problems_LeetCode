class Solution {
public:
    string getEncryptedString(string s, int k) {
        int n=s.length();
        string answer(n,' ');

        for(int i=0;i<n;i++){
            answer[i]=s[(i+k)%n];
        }

        return answer;
    }
};