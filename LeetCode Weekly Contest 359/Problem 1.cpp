
****Check if a String Is an Acronym of Words****

check the size of the array “words” and string “s” and if they are not equal in size return false. 
  If they are of equal size just run a loop and check whether the first alphabet of the string present at position/index i in “word” 
is equal to the alphabet present at position/index i in “s”.

CODE ---------CODE--------CODE--------CODE-------CODE--------CODE--------CODE---------CODE--------CODE-------CODE--------CODE-------------------------------------------------------------------------------------------------------

  class Solution {
public:
    bool isAcronym(vector<string>& w, string s) {
        
        if(s.size()!=w.size()){
            return false;
        }
        
        bool flag = true;
        
        for(int i =0;i<s.size();i++){
            string temp = w[i];
            
            if(temp[0]!=s[i]){
                return false;
            }
            
        }
        
        return true;
        
    }
};
