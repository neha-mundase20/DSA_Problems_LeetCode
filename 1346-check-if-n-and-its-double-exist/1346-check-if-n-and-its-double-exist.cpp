class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        bool flag=false;

        for(int i=0;i<arr.size();i++){
            for(int j=0;j<arr.size();j++){
                if(arr[i]==2*arr[j] && i!=j){
                    flag=true;
                    break;
                }
            }
        }
        return flag;
    }
};