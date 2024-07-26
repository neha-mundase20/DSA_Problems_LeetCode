class Solution {
public:

/*Floyd Warshall Algorithm

The algorithm uses three nested loops to check all possible paths between cities.
=> k is the intermediate city we are considering.
=> i is the starting city.
=> j is the ending city.

How It Works:
Initially, we have direct distances between cities based on the given edges.
The algorithm checks if traveling from city i to city j through an intermediate city k provides a shorter path than the current known shortest path.
If it does, we update the shortest path to be this new path through k.*/

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>graph(n,vector<int>(n,INT_MAX));  //set to infinity

        for(int i=0;i<n;i++){
            graph[i][i]=0;  //distance from every city to itself
        }

        for(auto edge:edges){
            int u=edge[0],v=edge[1],w=edge[2];
            graph[u][v]=w;  //bidirectional graph
            graph[v][u]=w;
        }

        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(graph[i][k]!=INT_MAX && graph[k][j]!=INT_MAX){
                        graph[i][j]=min(graph[i][j],graph[i][k]+graph[k][j]);
                    }
                }
            }
        }

        //Counting Reachable Cities
        int resultCity=-1;
        int minReachableCity=INT_MAX;

        for(int i=0;i<n;i++){
            int reachableCities=0;
            for(int j=0;j<n;j++){
                if(i!=j && graph[i][j]<=distanceThreshold){
                    reachableCities++;
                }
            }
            if(reachableCities<=minReachableCity){
                if(reachableCities==minReachableCity){
                    resultCity=max(resultCity,i);
                    //select city with greater index
                }
                else{
                    resultCity=i;
                    minReachableCity=reachableCities;
                }
            }
        }
        return resultCity;
    }
};