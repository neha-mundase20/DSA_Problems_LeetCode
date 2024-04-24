class Solution {
public:
    int tribonacci(int n) {
        /*int val=n-3;
        
        //Recursive approach
        if(n==0){
            return 0;
        }
        else if(n==1 || n==2){
            return 1;
        }
        else{
            return tribonacci(val)+tribonacci(val+1)+tribonacci(val+2);
            //coz Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.
        }*/
        
        if(n==0){
            return 0;
        }
        if(n==1 || n==2){
            return 1;
        }
        int a=0,b=1,c=1;    //represents T0,T1,T2 i.e. the starting terms
        
        for(int i=3;i<=n;i++){
            int next=a+b+c;
            a=b;
            b=c;
            c=next;
        }
        return c;
    }
};