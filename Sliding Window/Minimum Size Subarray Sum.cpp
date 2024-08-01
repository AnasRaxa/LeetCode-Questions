class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int ans = INT_MAX;

        int left = 0, right = 0;

        int sum = 0;


        while(right<nums.size()){

            sum+=nums[right];


            while(sum>=target){
                ans = min(ans,right-left+1);
                sum-=nums[left];
                left++;
            }


            right++;


        }


        return ans == INT_MAX ? 0 : ans;
        
    }
};