class Solution {
public:
    
  
    
    int maxSubarrays(vector<int>& nums) {
  
        int maxval = INT_MAX;
        
        for(int i =0;i<nums.size();i++){
            maxval = maxval&nums[i];
        }
        
        if(maxval!=0){
            return 1;
        }
        
        int dup= INT_MAX;
        int ans = 0;
        
        for(int i =0;i<nums.size();i++){
            dup = dup&nums[i];
            if(dup==maxval){
                ans++;
                dup = INT_MAX;
            }
            
        }
        
        return ans;
        
    }
};
