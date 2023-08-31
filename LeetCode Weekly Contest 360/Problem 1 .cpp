class Solution {
public:
    int furthestDistanceFromOrigin(string s) {
        int l = 0;
        int r =0;
        int e = 0;
        for(int i =0;i<s.size();i++){
            if(s[i]=='R'){
                r++;
            }
            else if(s[i]=='L'){
                l++;
            }
            else{
                e++;
            }
        }
        
        
        if(r>=l){
            return r-l+e;
        }
        else{
          return   l-r+e;
        }
        
    }
};
