class Solution {
public:

    struct Value{
        int num;
        int mappedVal;
    };

    static bool comparator(const struct Value&a, const struct Value&b){
        return a.mappedVal<b.mappedVal; //ascending order
    }


    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        unordered_map<char,char>hashmap(mapping.size());
        vector<Value>v;
        vector<int>solution;

        for(int i=0;i<mapping.size();i++){
            hashmap['0'+i]='0'+mapping[i]; //converting int to char
        }

        for(int i=0;i<nums.size();i++){
            string temp1=to_string(nums[i]);
            string temp2;

            for(int i=0;temp1[i]!='\0';i++){
                if(hashmap[temp1[i]]!=0){
                    temp2.push_back(hashmap[temp1[i]]);
                }
            }
            int mappedValue=stoi(temp2);

            v.push_back({nums[i],mappedValue});
        }

        sort(v.begin(),v.end(),comparator);

        for(int i=0;i<v.size();i++){
            solution.push_back(v[i].num);
        }

        return solution;
    }
};