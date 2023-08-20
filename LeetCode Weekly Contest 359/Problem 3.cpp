****Maximize the Profit as the Salesman****

A traditional DP problem .we just have to use the concept of pick not-pick and we have to take care if 
we picked a element out of the “offers” array we should only pick the next element which do not coincide with each 
other so we should sort the array “offers” then using binary search find the nearest index of the element
whose range do not coincide with the currently chosen/picked index in order to eliminate the possibility of clashes in ranges.

CODE ---------CODE--------CODE--------CODE-------CODE--------CODE--------CODE---------CODE--------CODE-------CODE--------CODE-----------

  class Solution {
public:
    
    int bs(vector<vector<int>>& nums,int val){
        
        int s = 0;
        int e = nums.size()-1;
        int ans = e+1;
        
        
        while(e>=s){
            
            int m  = s+(e-s)/2;
            
            if(nums[m][0]>val){
                ans = m;
                e = m-1;
            }
            else{
                s = m+1;
            }
            
        }
        
        return ans;
        
    }
    
    
    int helper(vector<vector<int>>& nums,int i,vector<int>&dp){
        
        if(i>=nums.size()){
            return 0;
        }
        
        if(dp[i]!=-1){
            return dp[i];
        }
        
        
        int p1 = helper(nums,i+1,dp);
        
        
        int idx = bs(nums,nums[i][1]);
        
        int p2 = helper(nums,idx,dp)+nums[i][2];
        
        
        return dp[i] = max(p1,p2);
        
    }
    
    int maximizeTheProfit(int n, vector<vector<int>>& nums) {
        
        sort(nums.begin(),nums.end());
        vector<int>dp(nums.size(),-1);
        return helper(nums,0,dp);
        
    }
};
