class Solution {
public:
    long long maximumSumOfHeights(vector<int>& arr) {
        long long ans =0;
        
        for(int i=0;i<arr.size();i++){
             long long l = arr[i];
             long long r =arr[i];
             long long sum =arr[i];
            
            for(int j = i+1;j<arr.size();j++){
                sum+=min((  long long)arr[j],r);
                r = min((  long long)arr[j],r);
            }
            
            for(int j = i-1;j>=0;j--){
                sum+=min((  long long)arr[j],l);
                l = min((  long long)arr[j],l);
            }
            
            ans = max(sum,ans);
            
        }
        
        return ans;
        
    }
};
