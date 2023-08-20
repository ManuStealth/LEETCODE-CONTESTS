****Determine the Minimum Sum of a k-avoiding Array****

Initialise a variable “sum” and an array let say “stor” which will keep track of the integers which would make 
the ***minimum** possible sum of a k-avoiding array and* Initialise a while Loop which would work until the 
  size of array “stor” is less than the parameter n . now just keep on adding the integers starting from one until 
size of “stor” is not equal to n . **remember to keep track of the integer (k-i) , it should not be added in stor so what 
you can do is to maintain a set in which not only store the integer which you just added in array “stor” but also integer k-i to eliminate 
the pair whose some turn out to be exactly k.**



  class Solution {
public:
    int minimumSum(int n, int k) {
       
    int sum =0;

        vector<int>stor;
        set<int>st;
        
        
        int i = 1;
        
        while(stor.size()<n){
            
            
            if(st.find(i)==st.end()){
                
                st.insert(i);
                st.insert(k-i);
                
                stor.push_back(i);
                
            }
            
            
          i++;  
            
        }
        
        
        for(int i =0;i<stor.size();i++){
            sum+=stor[i];
        }
        
        return sum;
    
            
    }
};
