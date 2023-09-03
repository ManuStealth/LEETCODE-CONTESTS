class Solution {
public:
   #define ll long long 
    long long maxSum(vector<int>& nums, int m, int k) {
        
        ll ans =0;
        
        ll currsum =0;
        int cnt =0;
        unordered_map<ll,ll>mp;
        for(int i =0;i<k;i++){
            currsum+=nums[i];
            
            
            mp[nums[i]]++;
            
            if(mp[nums[i]]==1){
                cnt++;
            }
            
            
        }
        
        if(cnt>=m){
            ans = currsum;
        }
        
        for(int i =k;i<nums.size();i++){
         
            currsum-=nums[i-k];
            mp[nums[i-k]]--;
            if( mp[nums[i-k]]==0){
                cnt--;
            }
            
            currsum+=nums[i];
            
            mp[nums[i]]++;
            
            if(mp[nums[i]]==1){
                cnt++;
            }
            
            if(cnt>=m){
                ans = max(ans,currsum);
            }
            
        }
        
        
        return ans;
    }
};
