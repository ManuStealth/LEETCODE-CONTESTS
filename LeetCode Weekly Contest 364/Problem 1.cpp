class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        
        int cnt= 0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                cnt++;
            }
        }
        string ans = "";
        if(cnt==1){
            for(int i=0;i<s.size()-1;i++){
                ans+='0';
            }
            ans = ans + '1';
        }
        else{
            
            for(int i=0;i<cnt-1;i++){
                ans+='1';
            }
            
            for(int i =0;i<s.size()-cnt;i++){
                ans = ans+'0';
            }
            
            
            ans = ans + '1';
            
        }
        
        return ans;
        
    }
};
