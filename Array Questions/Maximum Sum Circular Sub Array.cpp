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