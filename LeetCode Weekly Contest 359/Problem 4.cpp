****Find the Longest Equal Subarray****

Make a 2D array let say “stor” which would stor the index’s of all nums[i] as in the given **Constraints** `1 <= nums[i] <= nums.length` ,
  which means all the numbers in “nums” will be in this range . Now we just have to check for every stor value in order to find
the longest equal subarray with atmost k deletions . we would have an array of index’s for each number and we can use
two pointer (i,j)  approach here and apply the condition if number of deletion unitl now are less than k then j is incremented 
otherwise i is incremented.

  
CODE ---------CODE--------CODE--------CODE-------CODE--------CODE--------CODE---------CODE--------CODE-------CODE--------CODE-----------


  class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        
        int ans = 1;
        
        int n = nums.size();
        
        vector<vector<int>>stor(n+1);
        
        
        for(int i =0;i<nums.size();i++){
            stor[nums[i]].push_back(i);
        } 
        
        
        for(int l =0;l<=n;l++){
            
            vector<int>temp = stor[l];
          
            int i =0;
            int j =0;
      
            
            while(j<temp.size() && i<temp.size() ){
                int val = temp[j]-j+i-temp[i];
              
                if((val)<=k){
                    
                    ans = max(ans,j-i+1);
                    j++;
                }
                else{
                    i++;
                }
                
            }
            
            
        }
      
        
        return ans;
    }
};
