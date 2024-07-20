
class Solution {
public:

    int kadaneMax(vector<int>& nums){

        int n = nums.size();

        int prefix = 0;
        int maxi = INT_MIN;

        for(int i = 0; i<n; i++){

            prefix+=nums[i];
            maxi = max(prefix,maxi);

            if(prefix<0){
                prefix = 0;
            }

        }

        return maxi;
        

    }
    int kadaneMin(vector<int>& nums){

        int n = nums.size();

        int prefix = 0;
        int mini = INT_MAX;

        for(int i = 0; i<n; i++){

            prefix+=nums[i];
            mini = min(prefix,mini);

            if(prefix>0){
                prefix = 0;
            }

        }

        return mini;
        

    }

    int maxSubarraySumCircular(vector<int>& nums) {

        int n = nums.size();

        int sum = accumulate(begin(nums),end(nums),0);

        int minSum = kadaneMin(nums);
        int maxSum = kadaneMax(nums);

        int circularSum = sum-minSum;

        if(maxSum>0){
            return max(maxSum,circularSum);
        }

        return maxSum;


        
    }
};















class Solution {
public:

    int kadane(vector<int>& nums){

        int n = nums.size();

        int prefix = 0;
        int maxi = INT_MIN;

        for(int i = 0; i<n; i++){

            prefix+=nums[i];
            maxi = max(prefix,maxi);

            if(prefix<0){
                prefix = 0;
            }

        }

        return maxi;
        

    }

    int maxSubarraySumCircular(vector<int>& nums) {

        int n = nums.size();

        int result = kadane(nums);

        for(int i = 0; i<n; i++){

            int first = nums.front();
            nums.erase(nums.begin());
            nums.push_back(first);
            


            int sum = kadane(nums);

            result = max(result,sum);
        }

        return result;
        
    }
};