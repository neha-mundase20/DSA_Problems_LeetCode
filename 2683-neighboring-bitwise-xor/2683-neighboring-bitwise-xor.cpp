class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        //For each binary value to occur we have 2 possibilities
        //0=0^0,1^1
        //1=1^0,0^1
        int n=derived.size();

        if(n==1){
            if(derived[0]==0){
                return true;
            }
            else{
                return false;
            }
        }

        vector<int>v1(n,-1);
        vector<int>v2(n,-1);

        if(derived[n-1]==0){
            v1[0]=0;
            v1[n-1]=0;
            v2[0]=1;
            v2[n-1]=1;
        }
        else{
            v1[0]=0;
            v1[n-1]=1;
            v2[0]=1;
            v2[n-1]=0;
        }


        if(n==2){
            if((v1[0]^v1[1]==derived[0] && v1[0]^v1[1]==derived[1]) || (v2[0]^v2[1]==derived[0] && v2[0]^v2[1]==derived[1])){
                return true;
            }
            else{
                return false;
            }
        }

        bool flag=true;

        for(int i=0;i<n;i++){

            if(i==n-2){
                if(v1[i]^v1[i+1]!=derived[i]){
                    flag=false;
                    break;
                }
                else{
                    flag=true;
                    break;
                }

                if(v2[i]^v2[i+1]!=derived[i]){
                    flag=false;
                    break;
                }
                else{
                    flag=true;
                    break;
                }
            }



            if(derived[i]==0){
                if(v1[i]==0){
                    v1[i+1]=0;
                }
                else{
                    v1[i+1]=1;
                }

                if(v2[i]==0){
                    v2[i+1]=0;
                }
                else{
                    v2[i+1]=1;
                }
            }
            else{
                if(v1[i]==0){
                    v1[i+1]=1;
                }
                else{
                    v1[i+1]=0;
                }

                if(v2[i]==0){
                    v2[i+1]=1;
                }
                else{
                    v2[i+1]=0;
                }
            }
        }
        return flag;
    }
};