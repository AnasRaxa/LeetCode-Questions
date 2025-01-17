class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long result = 0;
        
        int n = nums.size();
        
        int i = 0;
        while(i < n) {
            
            long long zeros = 0;
            
            if(nums[i] == 0) {
                
                while(i < n && nums[i] == 0) {
                    i++;
                    zeros++;
                }
                
            } else {
                    i++;
            }
            result += (zeros)*(zeros+1)/2;
        }
        
        return result;
        
    }
};


class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long result = 0;
        
        int n = nums.size();
        
        int countSubArray = 0;
        
        for(int i = 0; i<n; i++) {
            
            if(nums[i] == 0)
                countSubArray += 1;
            else
                countSubArray = 0;
            
            result += countSubArray;
            
        }
        
        return result;
        
    }
};