class Solution {
public:
    
  
    int minOperations(vector<int>& nums, int target) {
           std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
        for (int i : nums) {
            pq.push(i);
        }
        
        int s = 0, c = 0;
        std::unordered_set<int> h;
        
        while (!pq.empty()) {
            while (target < pq.top() && pq.top() > 0) {
                int n = pq.top();
                pq.pop();
                
                if (h.find(n - target) != h.end()) {
                    return c;
                }
                
                pq.push(n / 2);
                pq.push(n / 2);
                c++;
            }
            
            s += pq.top();
            h.insert(s);
            target -= pq.top();
            
            if (target == 0) {
                return c;
            }
            
            pq.pop();
        }
        
        return -1;
    
    }
};
