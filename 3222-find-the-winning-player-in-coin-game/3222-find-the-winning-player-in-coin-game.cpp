class Solution {
public:
    string losingPlayer(int x, int y) {
        int totalSum=x*75+y*10;
        int flip=0;
        string answer;

        while(x>0 && y-4>=0){
            flip++;
            x=x-1;
            y=y-4;

            totalSum=x*75+y*10;
        }

        if(flip%2!=0){
            answer="Alice";
        }
        else{
            answer="Bob";
        }
        return answer;
    }
};