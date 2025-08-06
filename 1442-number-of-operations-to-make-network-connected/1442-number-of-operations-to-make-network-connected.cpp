class disjointset{
public:
    vector<int>size,rank,parent;
    disjointset(int n){
        size.resize(n+1,1);
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    int findUparent(int node){
        if(parent[node]==node) return node;
        return parent[node]=findUparent(parent[node]);
    }
    void unionbyrank(int u,int v){
        int ulp_u=findUparent(u);
        int ulp_v=findUparent(v);
        if(ulp_v==ulp_u) return;
        if(rank[ulp_u]>rank[ulp_v]){
            parent[ulp_v]=ulp_u;
        }
        else if(rank[ulp_u]<rank[ulp_v]){
            parent[ulp_u]=ulp_v;
        }
        else{
            parent[ulp_u]=ulp_v;
            rank[ulp_v]++;
        }
    }

};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int extra_edges=0,provinces=0;
        disjointset ds(n);
        for(auto it:connections){
            int u=it[0];
            int v=it[1];
            if(ds.findUparent(u)==ds.findUparent(v)){
                extra_edges++;
            }
            else ds.unionbyrank(u,v);
        }
        for(int i=0;i<n;i++){
            if(ds.findUparent(i)==i) provinces++;
        }
        if(extra_edges>=provinces-1) return provinces-1;
        return -1;
    }
};
