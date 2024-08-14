class Solution {
public:
    string addBinary(string a, string b) {
        /*int l1=a.length()-1;
        int l2=b.length()-1;
        int num1=0,num2=0,k=0;

        for(int i=l1;i>=0;i--){
            num1=num1+(a[k]-'0')*pow(2,i);
            k++;
        }

        k=0;
        for(int i=l2;i>=0;i--){
            num2=num2+(b[k]-'0')*pow(2,i);
            k++;
        }

        int num3=num1+num2;

        if(num3==0){
            return "0";
        }

        stack<int>st;

        while(num3>0){
            st.push(num3%2);
            num3=num3/2;
        }

        string solution;

        while(!st.empty()){
            solution.push_back(st.top()+'0');   
            // Convert int to char and add to result
            st.pop();
        }
        return solution;*/

        int l1=a.length()-1;
        int l2=b.length()-1;
        int carry=0;
        string solution;

        while(l1>=0 || l2>=0 || carry){
            if(l1>=0){
                carry=carry+(a[l1--]-'0'); //char to int
            }
            if(l2>=0){
                carry=carry+(b[l2--]-'0'); //char to int
            }
            
            solution.push_back(carry%2+'0');    
            //returns sum along with previous carry
            carry=carry/2;
            //determines the new carry
        }
        reverse(solution.begin(),solution.end());
        return solution;
    }
};