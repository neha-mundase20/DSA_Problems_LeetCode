class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        /*int currentAmount=0;

        for(auto it:bills){
            if(it==5){
                currentAmount=currentAmount+it;
            }
            else{
                if(currentAmount>=(it-5)){  //we can provide change
                    currentAmount=currentAmount-(it-5); //Return change
                    currentAmount=currentAmount+5;  
                    //Keep the cost of one lemonade
                }
                else{   //we cannot provide change
                    return false;
                }
            }
        }
        return true;*/

        int fiveCount=0,tenCount=0;

        for(auto it:bills){
            if(it==5){
                fiveCount++;
            }
            else if(it==10){
                if(fiveCount>0){
                    fiveCount--;
                    tenCount++;
                }
                else{
                    return false;
                }
            }
            else{
                if(fiveCount>0 && tenCount>0){
                    tenCount--;
                    fiveCount--;
                }
                else if(fiveCount>=3){
                    fiveCount=fiveCount-3;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};