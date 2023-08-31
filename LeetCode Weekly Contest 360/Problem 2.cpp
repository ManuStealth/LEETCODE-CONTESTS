class Solution {
public:
    #define ll long long 
    long long minimumPossibleSum(int n, int tar) {
       
        vector<ll>stor;
        
        set<ll>st;
        ll i = 1;
        while(stor.size()!=n){
            
            if(st.find(i)==st.end()){
                stor.push_back(i);
                st.insert(i);
                st.insert(tar-i);
                
            }
            
            i++;
            
        }
        ll ans = 0;
        
        for(int j =0;j<stor.size();j++){
            ans+=stor[j];
        }
        
        return ans;
        
        
       
    }
};
