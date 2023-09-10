class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        int ans =0;
        
        vector<int>stor(101,0);
        
        for(int i =0;i<nums.size();i++){
            int s = nums[i][0];
            int e = nums[i][1];
            
            for(int j =s ;j<=e;j++){
                
                if(stor[j]==0){
                    ans++;
                    stor[j]++;
                }
            }
        }
        
        return ans;
        
    }
};
