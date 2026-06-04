class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        for(int i=0;i<flights.size();i++){
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        queue<pair<int,pair<int,int>>> q;
        vector<int> dist(n,1e9);
        dist[src] = 0;
        q.push({src,{0,0}});
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int node = it.first;
            int weight = it.second.first;
            int stops = it.second.second;
            if(stops>k){
                continue;
            }
            for(auto neig : adj[node]){
                if(weight+neig.second<dist[neig.first]){
                    dist[neig.first] = weight + neig.second;
                    q.push({neig.first,{dist[neig.first],stops+1}});
                }
            }
        }
        if(dist[dst]==1e9){
            return -1;
        }
        return dist[dst];
    }
};