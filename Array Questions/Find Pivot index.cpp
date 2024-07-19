class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
        int n = nums.size();

        int leftSum = 0;
        int rightSum = 0;
        int totalSum = 0;

        for(int it:nums) totalSum+=it;

        for(int i = 0; i<n; i++){

            rightSum = totalSum-leftSum-nums[i];

            if(rightSum==leftSum) return i;           


            leftSum+=nums[i];
        }
        
        

    return -1;
        
    }
};