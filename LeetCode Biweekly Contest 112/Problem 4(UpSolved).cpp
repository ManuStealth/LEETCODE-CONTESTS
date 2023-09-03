class Solution {
public:
    
    unordered_map<string ,   long long > dp;
    int mod = 1e9+7;
    
      long long helper(string &s,int i,int k,int tar,vector<int>&stor){
       
        if(i>=s.size()){
            return (k==0 && tar==0);
        }
        
        if(k<0){
            return 0;
        }
        
        
        string key = to_string(i) + '#' + to_string(k) + '#' + to_string(tar);
        
        if(dp.find(key)!=dp.end()){
            return dp[key];
        }
        
        //not take 
          long long p1 = helper(s,i+1,k,tar,stor);
        // take
        long long p2 = (helper(s,i+1,k-1,tar-stor[s[i]-'a'],stor)%mod*(stor[s[i]-'a'])%mod)%mod;
        
        
        return dp[key] = (p1%mod+p2%mod)%mod;
        
        
    }
    
    int countKSubsequencesWithMaxBeauty(string s, int k) {
     
        if(k>26){
            return 0;
        }
        
        vector<int>stor(26,0);
    
        string temp = "";
        int count =0;
        
        for(int i =0;i<s.size();i++){
            int val = s[i]-'a';
            
            stor[val]++;
            
            if(stor[val]==1){
                temp+=s[i];
              count++;
            }
        }
        
        if(k>count){
            return 0;
        }
        
        vector<int>dup = stor;
        
        sort(dup.begin(),dup.end(),greater<int>());
        
        int total = 0;
        for(int i =0;i<k;i++){
            total+=dup[i];
        }
        
        
        return helper(temp,0,k,total,stor);
        
        
        
        
    }
};
