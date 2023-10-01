class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int>mp;
        
        for(int i =0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        
        for(auto it:mp){
            if(it.second==1){
                return -1;
            }
        }
        
        int ans = 0;
        for(auto it:mp){
            int val = it.second;
           
            while(val%3!=0){
                val-=2;
                ans++;
            }
        
             ans+=(val/3);
            
        }
        
        return ans;
       
        
        
    }
};
