class Solution {
public:
    bool checkStrings(string s1, string s2) {
        
        
        vector<int>even(26,0);
         vector<int>odd(26,0);
        
        for(int i =s1.size()-1;i>=0;i--){
        if(i%2==0){
          even[s1[i]-'a']++;
        }
            else{
                odd[s1[i]-'a']++;
            }
        }
        
        
         for(int i =s2.size()-1;i>=0;i--){
             if(i%2==0){
          even[s2[i]-'a']--;
                 
                 if(even[s2[i]-'a']<0){
                     return false;
                 }
        }
            else{
                odd[s2[i]-'a']--;
                
                if(odd[s2[i]-'a']<0){
                     return false;
                 }
            }
             
         }
        
        
        
        return true;
        
        
        
        
    }
};
