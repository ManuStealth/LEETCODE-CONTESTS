class Solution {
public:

    
    int helper(int node,int par,int n, vector<vector<int>>& edges, vector<int>& values, int k,vector<vector<int>>&g,int &ans){
        
   
        
        int res = 0;
        
        for(int i =0;i<g[node].size();i++){
            if(par==g[node][i]){
                continue;
            }
            
            res+=helper(g[node][i],node,n,edges,values,k,g,ans);
            
        }
        
        res+=values[node];
        if(res%k==0){
            ans++;
            return 0;
        }
        
        
        
        return res;
        
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        
        
        vector<vector<int>>g(n);
        
        
        for(int i =0;i<edges.size();i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            
            g[u].push_back(v);
            g[v].push_back(u);
            
            
        }   
        
        int ans  =0;
         helper(0,-1,n,edges,values,k,g,ans);
        
        return ans;
        
        
    
    }
};

