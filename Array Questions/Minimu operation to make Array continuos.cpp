class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        
        int result = INT_MAX;
        
        for(int i = 0; i < n; i++) {
            
            int left_range  = nums[i]; //L
            int right_range = left_range + n - 1;
            
            int mehnat = 0;
            
            unordered_set<int> used;
            
            for(int j = 0; j < n; j++) {
                
                if(nums[j] >= left_range && nums[j] <= right_range && used.find(nums[j]) == used.end()) {
                    used.insert(nums[j]);
                    continue;
                } else {
                    mehnat++;
                }
                
            }
            
            result = min(result, mehnat);
            
        }
        
        return result;
    }
};













class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        
        set<int> st(begin(nums), end(nums));
        
        vector<int> temp(begin(st), end(st));
        
        int result = INT_MAX;
        
        for(int i = 0; i<temp.size(); i++) {
            
            int left_range  = temp[i];
            int right_range = left_range + n - 1;
            
            int j = upper_bound(begin(temp), end(temp), right_range) - begin(temp);
            
            int in_range  = j - i;
            int out_range = n - in_range;
            
            result = min(result, out_range);
            
        }
        
        return result;
    }
};
