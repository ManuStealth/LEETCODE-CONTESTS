TOPIC - BINARY LIFTING


#define pii pair<int, int>
const int N = 1e4+1;
const int W = 27;

    
vector<vector<int>>up(15, vector<int>(N, 0));
vector<vector<int>> freq(N,  vector<int>(W, 0));
vector<int> depth(N, 0);
vector<vector<pii>> g(N);
    

class Solution {
    
void Reset() {
        for (auto &i: depth) i = 0;
        for (auto &i: up) 
            for (auto &j: i) j = 0;
        for (auto &i: g)
            i.clear();
    }
        
    void dfs(int src,int par){
        
        depth[src]  = depth[par]+1;
        
        up[0][src] = par;
        
        for(int j = 1;j<15;j++){
            
            up[j][src] = up[j-1][up[j-1][src]];
         
        }
        
        
         for(auto child : g[src]){
                if(child.first==par){
                    continue;
                }
                
                freq[child.first] = freq[src];
                freq[child.first][child.second]++;
                
                dfs(child.first,src);
                
            }
        
    }
    
    
    int lca(int u, int v){
        if(depth[u]>depth[v]){
            swap(u,v);
        }
        
        
        int diff = depth[v]-depth[u];
        
        for(int j = 0;j<15;j++){
            if(diff & (1<<j)){
                v = up[j][v];
            }
        }
        
        if(v==u){
            return u;
        }
        
        
        for(int j = 14;j>=0;j--){
            if(up[j][v]!=up[j][u]){
               v =  up[j][v];
                u =  up[j][u]; 
            }
        }
        
        
        return up[0][u];
        
    }
    
    
public:
 

    
    vector<int> minOperationsQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        
         Reset();
        
        for (auto i : edges) {
            g[i[0]+1].push_back({i[1]+1, i[2]});
            g[i[1]+1].push_back({i[0]+1, i[2]});
        }
    dfs (1, 0);
        
        vector<int>ans;
        
        for(auto it:queries){
            int u = it[0]+1;
            int v = it[1]+1;
            int LCA = lca(u,v);
            
            vector<int>temp(W,0);
            
            for(int j =0;j<W;j++){
                temp[j]+=freq[u][j]+freq[v][j]-2*freq[LCA][j];
            }
            
            int mx =0;
            int sum =0;
            
            for(auto i:temp){
                mx = max(i,mx);
                
                sum+=i;
            }
            
            ans.push_back(sum-mx);
            
        }
        
        return ans;
        
        
        
    }
};



