//Approach-1 (Using Binary Search)
//T.C : O(nlogn)
//S.C : O(n) for prefixSum for effienctly calculating windowSum
class Solution {
public:
    
    int findBest(int target_idx, int k, vector<int>& nums, vector<long>& prefixSum) {
        int target = nums[target_idx];
        
        int i = 0;
        int j = target_idx;
        int result = target_idx;
        
        while(i <= j) {
            int mid = i + (j-i)/2;
            
            long count      = (target_idx - mid + 1);
            long windowSum  = (count * target);
            long currSum    = prefixSum[target_idx] - prefixSum[mid] + nums[mid];
            
            int ops         = windowSum - currSum;
            
            if(ops > k) {
                i = mid+1;
            } else {
                result = mid;
                j = mid-1;
            }
        }
        
        return target_idx-result+1;
    }
    
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        
        sort(begin(nums), end(nums));
        vector<long> prefixSum(n);
        prefixSum[0] = nums[0];
        
        for(int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i-1] + nums[i];
        }
        
        int result = 0;
        
        for(int i = 0; i<n; i++) {
            result = max(result, findBest(i, k, nums, prefixSum));
        }
        
        return result;
    }
};

//Approach-2 (Using sliding window)
//T.C : O(nlogn)
//S.C : O(1)
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));
        
        int n = nums.size();
        
        int result = 0;
        
        int i = 0;
        long currSum = 0;
        
        for(int j = 0; j<n; j++) {
            
            long target = nums[j];
            currSum   += nums[j];
            
            while((j-i+1)*target - currSum > k) {
                currSum -= nums[i];
                i++;
            }
            
            result = max(result, j-i+1);
            
        }
        return result;
    }
};

//Approach-3 (Improved sliding window)
//T.C : O(nlogn)
//S.C : O(1)
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));
        
        int n = nums.size();
        
        int result = 0;
        
        int i = 0;
        long currSum = 0;
        
        for(int j = 0; j<n; j++) {
            
            long target = nums[j];
            currSum   += nums[j];
            
            if((j-i+1)*target - currSum > k) {
                currSum -= nums[i];
                i++;
            }
            
            result = max(result, j-i+1);
            
        }
        return result;
    }
};