/*class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        unordered_set<char>st;

        //To obtain all possible characters
        for(auto it:original){
            st.insert(it);
        }
        for(auto it:changed){
            st.insert(it);
        }

        //Storing all the required costs in map
        map<pair<char,char>,int>mp;

        for(int i=0;i<cost.size();i++){
            mp[{original[i],changed[i]}]=cost[i];
        }

        long long totalCostIncurred=0;
        bool isConverted=false;

        for(int i=0;i<source.size();i++){

            long long minCost=0;
            isConverted=false;

            if(source[i]!=target[i]){
                if(mp.find({source[i],target[i]})!=mp.end()){
                    //Direct Costs Exists
                    minCost=mp[{source[i],target[i]}];
                    isConverted=true;
                }

                if(isConverted==false){
                    minCost=LLONG_MAX;
                }

                //Check for substitue costs
                for(auto it:st){
                        if(mp.find({source[i],it})!=mp.end() && mp.find({it,target[i]})!=mp.end()){
                            minCost=min(minCost,static_cast<long long>(mp[{source[i],it}]+mp[{it,target[i]}]));
                            isConverted=true;
                        }
                    }

                    if(isConverted==true){
                        totalCostIncurred=totalCostIncurred+minCost;
                    }
                    else{
                       totalCostIncurred=-1;
                        break; 
                    }
            }
        }
        return totalCostIncurred;
    }
};*/

class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        unordered_set<char> characters;
        map<pair<char, char>, long long> conversionCost;

        // To obtain all possible characters
        // Add all characters from the source and target strings
        for (char c : source){
            characters.insert(c);
        }
        for (char c : target){
            characters.insert(c);
        }
        for (auto c : original){
            characters.insert(c);
        }
        for (auto c : changed){
            characters.insert(c);
        } 

        // Initialize conversion costs to infinity
        for (auto from : characters) {
            for (auto to : characters) {
                conversionCost[{from, to}] = LLONG_MAX;
            }
        }

        // Storing all the required costs in map
        for (int i = 0; i < cost.size(); ++i) {
            conversionCost[{original[i], changed[i]}] = min(conversionCost[{original[i], changed[i]}], (long long)cost[i]);
        }

        // Floyd-Warshall algorithm to find the shortest path between all pairs of nodes (characters)
        for (auto k : characters) {
            for (auto i : characters) {
                for (auto j : characters) {
                    if (conversionCost[{i, k}] != LLONG_MAX && conversionCost[{k, j}] != LLONG_MAX) {
                        conversionCost[{i, j}] = min(conversionCost[{i, j}], conversionCost[{i, k}] + conversionCost[{k, j}]);
                    }
                }
            }
        }

        long long totalCostIncurred = 0;

        // Calculate the total minimum cost for converting source to target
        for (int i = 0; i < source.size(); ++i) {
            if (source[i] != target[i]) {
                long long minCost = conversionCost[{source[i], target[i]}];
                if (minCost == LLONG_MAX){
                     return -1; // No valid conversion path
                }
                totalCostIncurred += minCost;
            }
        }

        return totalCostIncurred;
    }
};
