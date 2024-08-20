class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        //Check for empty plots, if any plot is empty check if left 
        //and right plots are empty so that we can plant on that plot
        int canBePlanted=0;

        if(n==0){
            return true;
        }

        if(flowerbed.size()==1){
            if(flowerbed[0]==0 && n==1){
                return true;
            }
            else if(flowerbed[0]==1 && n==0){
                return true;
            }
            else{
                return false;
            }
        }

        for(int i=0;i<flowerbed.size();i++){
            if(flowerbed[i]==0){
                if(i-1>0 && i+1<flowerbed.size()-1){
                    if(flowerbed[i-1]==0 && flowerbed[i+1]==0){
                        canBePlanted++;
                        flowerbed[i]=1;
                    }
                }
                else if(i==0 && flowerbed[i+1]==0){
                    canBePlanted++;
                    flowerbed[i]=1;
                }
                else if(i==flowerbed.size()-1 && flowerbed[i-1]==0){
                    canBePlanted++;
                    flowerbed[i]=1;
                }
            }
        }

        if(canBePlanted>=n){
            return true;
        }
        return false;
    }
};