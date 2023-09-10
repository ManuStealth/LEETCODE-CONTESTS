class Solution {
public:
    
    int helper(vector<vector<int>>& grid){
        
        bool flag = true;
        for(int i =0;i<3;i++){
            for(int j =0;j<3;j++){
                if(grid[i][j]!=1){
                    flag = false;
                    break;
                }
            }
        }
        
        if(flag){
            return  0;
        }
        
        int ans = INT_MAX;
        
        for(int i =0;i<3;i++){
            for(int j =0;j<3;j++){
                for(int x =0;x<3;x++){
                    for(int y =0;y<3;y++ ){
                        
                        if(grid[i][j]==0 && grid[x][y]>1){
                            
                            grid[i][j]++;
                            grid[x][y]--;
                            
                            int val = helper(grid)+abs(x-i)+abs(y-j);
                            
                            ans = min(ans,val);
                            
                             grid[i][j]--;
                            grid[x][y]++;
                            
                            
                        }
                        
                    }
                }
            }
        }
        return ans;
        
    }
    int minimumMoves(vector<vector<int>>& grid) {
        return helper(grid);
    }
};
