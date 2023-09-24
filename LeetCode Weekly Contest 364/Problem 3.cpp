class Solution {
public:
    vector<long long> helper(vector<int>& arr){
        stack<long long>st;
        int n = arr.size();
        
        vector<long long>stor(n);
        
        long long sum  =0;
        for(int i =n-1;i>=0;i--){
        
            
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            
            if(st.empty()){
                stor[i] = (long long)arr[i]*(long long)(n-i);
                sum = stor[i];
            }
            else {
                stor[i] = (long long )(arr[i])*(long long)(st.top()-i) + stor[st.top()];
                sum = stor[i];
            }
            
            st.push(i);
            
        }
        
        
//         for(int i=0;i<n;i++){
//             cout<<stor[i]<<" ";
//         }
        
//         cout<<endl;
        return stor;
        
        
    }
    long long maximumSumOfHeights(vector<int>& arr) {
      
        int n = arr.size();
        vector<long long>right =   helper(arr);
        
        reverse(arr.begin(),arr.end());
        vector<long long>left = helper(arr);
        
        
         reverse(arr.begin(),arr.end());
         reverse(left.begin(),left.end());
        
        long long ans = 0;
        
        for(int i =0;i<n;i++){
            long long val = left[i]+right[i]-arr[i];
            ans = max(ans,val);
        }
        
        
        return ans;
    }
};
