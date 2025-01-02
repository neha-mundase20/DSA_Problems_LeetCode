class Solution {
public:

    bool isVowel(char c){
        if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'){
            return true;
        }
        return false;
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {

        vector<int>v(words.size());
        //each index will store the value indicating how many 
        //requires strings appeared till the specified index

        vector<int>result;

        int vowelStringCount=0;
        //keeps a track of how many required srings appeared till now

        for(int i=0;i<words.size();i++){

            string temp=words[i];
            int n=temp.size()-1;

            if(isVowel(temp[0])&&isVowel(temp[n])){
                vowelStringCount++;
            }
            v[i]=vowelStringCount;
        }

        for(auto it:queries){
            int startIndex=it[0];
            int endIndex=it[1];

            if(startIndex==0){
                result.push_back(v[endIndex]);
            }
            else{
                result.push_back(v[endIndex]-v[startIndex-1]);
            }

//             If startIndex == 0, the result is v[endIndex], as all valid vowel strings up to endIndex are included.
// If startIndex > 0, the result must include the valid string count at startIndex. This is achieved by subtracting v[startIndex - 1] from v[endIndex].
        }
        return result;
    }
};