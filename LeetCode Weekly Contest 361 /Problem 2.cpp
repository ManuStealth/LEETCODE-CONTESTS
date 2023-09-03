class Solution {
public:
    int helper(string  &s,int rem ,int i,vector<vector<int>>&dp){
        if(i>=s.size()){
            if(rem==0){
                return 0;
            }
            
            return 1e8;
        }
        
        if(dp[rem][i]!=-1){
            return dp[rem][i];
        }
        
        //delete
        int p1 = helper(s,rem,i+1,dp)+1;
        //take
        int newrem = (rem*10+(s[i]-'0'))%25;
        int p2 = helper(s,newrem,i+1,dp);
        
        return  dp[rem][i] = min(p1,p2);
    }
    
    int minimumOperations(string num) {
        
        vector<vector<int>>dp(26,vector<int>(num.size(),-1));
        int ans= helper(num,0,0,dp);
        if(ans>=1e8){
            return num.size();
        }
        
        
        
        return ans;
        
    }
};
