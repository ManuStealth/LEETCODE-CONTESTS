class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
         
        
     
        
        int val = max(abs(sx-fx),abs(sy-fy));
        
        if(val==0){
            
            if(t==1){
                return false;
            }
            else{
                return true;
            }
            
            
        }
        
        if(val <=t)
        {
            return true;
        }
        else
        {
            return false;
        } 
        
    }
};
