class Solution {
public:

    struct Element{
        string atom;
        int count;
    };
    

    string countOfAtoms(string formula) {

        stack<Element>st;
        stack<Element>temp1;

        for(int i=0;i<formula.length();i++){
            string val;
            
            //When atom consists of more than 1 letter
            if (isupper(formula[i])) {  
                val+=formula[i];
                if(i+1<formula.length() && islower(formula[i+1])) {
                    val+=formula[i+1];
                    i++;
                }
                st.push({val,1});
            }
            //If we come across digits in formula
            else if(isdigit(formula[i])) {
                int num=0;
                while (i<formula.length() && isdigit(formula[i])) {
                    num=num*10+(formula[i]-'0');    //for 2 digit numbers
                    i++;
                }
                i--; // adjust the index
                auto element=st.top();
                st.pop();
                element.count=num;
                st.push(element);
            }
            //Push open brackets 
            else if(formula[i]=='('){
                st.push({"(",0});
            }
            //When we have closed brackets followed by a number
            else if(formula[i]==')' && isdigit(formula[i+1])){
                int multiplier=0;
                i++;
                while(i<formula.length() && isdigit(formula[i])) {
                    multiplier=multiplier*10+(formula[i]-'0');
                    //for more than one digit numbers
                    i++;
                }
                i--; // adjust the index

                if(multiplier==0){
                    multiplier=1;
                }

                //Multiply with multiplier and store it in temp stack
                while(!st.empty() && st.top().atom!="(") {
                    auto element=st.top();
                    st.pop();
                    element.count=(element.count)*multiplier;
                    temp1.push(element);
                }

                st.pop(); // pop the '('

                //Again push back elements in temp stack to st stack
                while(!temp1.empty()){
                    auto element=temp1.top();
                    st.push(element);
                    temp1.pop();
                }   
            }
            else if(formula[i]==')' && formula[i+1]=='('){   // )( condition
                auto element=st.top();
                st.pop();

                if(st.top().atom=="("){
                    st.pop();
                }
                st.push(element);
            }
            else{
                //Pop and store it in temp stack
                while(!st.empty() && st.top().atom!="(") {
                    auto element=st.top();
                    st.pop();
                    temp1.push(element);
                }

                st.pop(); // pop the '('

                //Again push back elements in temp stack to st stack
                while(!temp1.empty()){
                    auto element=temp1.top();
                    st.push(element);
                    temp1.pop();
                }   
            }
        }

        map<string,int>mp;

        while(!st.empty()){
            auto element=st.top();
            st.pop();
            mp[element.atom]=mp[element.atom]+element.count;
        }

        string solution;

        for (auto it:mp) {
            solution+=it.first;
            if (it.second>1) {
                solution+=to_string(it.second);
            }
        }

        return solution;
    }
};