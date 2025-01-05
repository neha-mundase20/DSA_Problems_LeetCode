class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        // vector<int>v(s.size());
        // for(int i=0;i<s.size();i++){
        //     v[i]=int(s[i]); //converting to ASCII array
        // }

        // for(int i=0;i<shifts.size();i++){

        //     int start=shifts[i][0];
        //     int end=shifts[i][1];
        //     int direction=shifts[i][2];

        //     if(direction==0){
        //         //Moving backward
        //         for(int j=start;j<=end;j++){
        //             v[j]=(v[j]-'a'-1+26)%26+'a';
        //             s[j]=char(v[j]);
        //         }
        //     }
        //     else{
        //         //Moving forward
        //         for(int j=start;j<=end;j++){
        //             v[j]=(v[j]-'a'+1)%26+'a';
        //             s[j]=char(v[j]);
        //         }
        //     }
        // }
        // return s;

        
        int n=s.size();
        vector<int>v(n,0);

        for(int i=0;i<shifts.size();i++){
            int s=shifts[i][0];
            int e=shifts[i][1];
            int d=shifts[i][2];

            if(d==1){
                v[s]=v[s]+1;
                if(e+1<n){
                    v[e+1]=v[e+1]-1;
                }
            }
            else{
                v[s]=v[s]-1;
                if(e+1<n){
                    v[e+1]=v[e+1]+1;
                }
            }
        }

        //Calculate cumulative sum array

        for(int i=1;i<n;i++){
            v[i]=v[i]+v[i-1];
        }

        for(int i=0;i<n;i++){
            s[i]=((s[i]-'a'+v[i])%26 + 26) %26+'a'; //Shift and handle
            //wrap-around
        }

        return s;
    }
};