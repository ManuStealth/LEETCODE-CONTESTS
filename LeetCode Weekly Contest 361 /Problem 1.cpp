class Solution {
public:
    
    bool helper(int val){
        vector<int>stor;
        
        while(val>0){
            int k = val%10;
            stor.push_back(k);
            val=val/10;
        }
        
        if(stor.size()%2!=0){
            return false;
        }
        
        int i =0;
        int j = stor.size()-1;
        
        int s =0 ;
        int e =0;
        while(j>i){
            s+=stor[i];
            e+=stor[j];
            i++;j--;
        }
        
        if(s==e){
            return true;
        }
        
        return false;
        
    }
    
    int countSymmetricIntegers(int low, int high) {
        
        int ans = 0;
        for(int i = low;i<=high;i++){
            bool check = helper(i);
            if(check){
               ans++;
            }
            
        }
        
        return ans;
        
    }
};
