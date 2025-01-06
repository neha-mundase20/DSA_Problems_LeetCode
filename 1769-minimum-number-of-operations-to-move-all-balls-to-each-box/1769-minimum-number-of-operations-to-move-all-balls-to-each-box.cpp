class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n=boxes.size();
        vector<int>result(n,0);
        set<int>st;

        //Storing positions where ball is already present
        for(int i=0;i<n;i++){
            if(boxes[i]=='1'){
                st.insert(i);
            }
        }

        //Checking the number of operations required to bring all balls to a  
        //specified box

        for(int i=0;i<n;i++){
            if(boxes[i]=='0'){
                int operations=0;
                for(auto it:st){
                    operations=operations+abs(it-i);
                }
                result[i]=operations;
            }
            else{
                int operations=0;
                for(auto it:st){
                    if(it!=i){
                        operations=operations+abs(it-i);
                    }
                }
                result[i]=operations;
            }
        }
        return result;
    }
};