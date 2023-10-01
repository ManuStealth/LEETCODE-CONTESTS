class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans =0;
        int tot = (k*(k+1))/2;
        
        set<int>st;
        for(int i =nums.size()-1;i>=0;i--){
            if(nums[i]<=k && st.find(nums[i])==st.end()){
                tot-=nums[i];
                st.insert(nums[i]);
            }
            if(tot==0){
                ans++;
                break;
            }
            else{
                ans++;
            }
        }
        
        return ans;
    }
};
