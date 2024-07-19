class Solution {
public:
    //Function to check if Koko can finish all bananas with current speed
    bool checkIfKokoFinishes(int k,int h,vector<int>&piles){
        int hours=0;
            //(pile/k) is hours taken to compete piles number of bananas with a
            //speed of k bananas per hour

            for(int pile:piles) {
            // Calculate the number of hours needed to finish the current pile
            hours+=(pile+k-1)/k; // Equivalent to ceil(pile / k)
            if (hours>h) return false;
        }
        return hours<=h;

    }

    int minEatingSpeed(vector<int>& piles, int h) {
        //Lowest speed bananas-per-hour Koko can have
        int low=1;

        //Highest speed bananas-per-hour Koko can have
        int high=*max_element(piles.begin(),piles.end());

        int speed=0;

        //Go on applying binary search to find min possible speed to finish all 
        //bananas
        while(low<=high){
            int mid=low+((high-low)/2);

            if(checkIfKokoFinishes(mid,h,piles)==true){
                high=mid-1;
                speed=mid;
            }
            else{
                low=mid+1;
            }
        }
        return speed;
    }
};