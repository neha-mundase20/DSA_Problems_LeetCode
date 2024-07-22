class Solution {
public:

    struct Person{
        string name;
        int height;
    };

    static bool sortHeightsDescending(const Person& p1,const Person& p2){
        return p1.height>p2.height; //descending order
    }

    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {

        vector<Person>p(names.size());
        vector<string>solution;

        for(int i=0;i<names.size();i++){
            p[i].name=names[i];
            p[i].height=heights[i];
        }

        sort(p.begin(),p.end(),sortHeightsDescending);

        for(int i=0;i<names.size();i++){
            solution.push_back(p[i].name);
        }

        return solution;
    }
};