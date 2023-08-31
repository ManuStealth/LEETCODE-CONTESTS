class Solution {
public:
    
#define ll long long 
    
    void bin(ll n,vector<ll>&stor)
  {
    long i;
    // cout << "0";
        stor.push_back(0);
    for (i = 1 << 30; i > 0; i = i / 2)
    {
      if((n & i) != 0)
      {
         stor.push_back(1);
      }
      else
      {
        stor.push_back(0);
      }
    }
        
        reverse(stor.begin(),stor.end());
       // cout<<stor.size()<<endl;
        
  }
    
    
    int minOperations(vector<int>& nums, int target) {
        
        vector<ll>stor(32,0);
        
        for(int i =0;i<nums.size();i++){
            
            int pow = log2(nums[i])/log2(2);
            stor[pow]++;
        }
        
        
        
        vector<ll>temp;
    
        bin(target,temp);
        
        
//         for(int i =0 ;i<=31;i++){
//             cout<<temp[i]<<" ";
//         }
//         cout<<endl;
    
//         for(int i =0 ;i<=31;i++){
//             cout<<stor[i]<<" ";
//         }
        
        
        
        ll sum =0 ;
        ll currnum = 0;
        int ans = 0;
        
        for(int i =0 ;i<=31;i++){
            currnum += temp[i]*pow(2,i);
            sum += stor[i]*pow(2,i);
            
            if(temp[i]==0 || sum>=currnum){
                continue;
            }
            else{
                
                bool flag = false;
                
                for(int j = i+1;j<=31;j++){
                    
                    if(stor[j]>0){
                        
                         flag = true;
                       
                       for(int k = j;k>=i+1;k--){
                          stor[k] =  stor[k]-1;
                           stor[k-1]+=2;
                          ans++;
                       }        
                        
                        sum+=stor[i]*pow(2,i);
                        
                        break;
                    }
                    
                }
                
                if(!flag){
                    return -1;
                }
            }
            
            
        }
        
        
        return ans;
        
    }
};
