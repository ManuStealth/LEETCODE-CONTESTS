class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int mod, int k) {
        
        
        vector<int>stor;
        
        for(int i =0;i<nums.size();i++){
            if(nums[i]%mod==k){
            stor.push_back(1);    
            }
            else{
                stor.push_back(0);   
            }
            
        }
        
      
        
       long long ans =0 ;
        
//         for(int i =0;i<stor.size();i++){
//             long long sum =0;
//             for(int j =i;j<stor.size();j++){
//                 sum+=stor[j];
                
//                 if(sum%mod==k){
//                     ans++;
//                 }
                
//             }
//         }
        
        
        long long sum =0;
        
       unordered_map<long long, int> prefixsum;
   
        int n = stor.size();
        for(int i =0;i<n;i++){
             
            sum+=stor[i];
            
         long long  rem = sum%mod;
    
            if(rem==k){
                ans++;
            }
            
            ans+=prefixsum[(rem-k+mod)%mod];
            prefixsum[rem]++;
            
        }


        
    return ans;

    }
};
