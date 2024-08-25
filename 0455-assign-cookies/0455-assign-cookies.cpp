class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        //Greedy Approach

        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        int p=0,q=0,satisfiedChildren=0;

        while(p<g.size() && q<s.size()){
            if(s[q]>=g[p]){ 
                //If size of cookie is greater than or equal to greed factor
                satisfiedChildren++;
                p++;
                q++;
            }
            else{
                q++;
            }
            //If size of cookie is not greater than or equal to greed factor
            //that means that cookie will not satisfy any children further coz the
            //greed factor increases ascendingly
        }
        return satisfiedChildren;
    }
};