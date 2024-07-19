class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int n = nums.size();

        int i = 0; // will look for 0s
        int j = 0; // will look for 1s
        int k = n-1; // will look for 2s

        while(j<=k){

            if(nums[j] == 1){
                j++;
            }else if(nums[j] == 2){
                swap(nums[j],nums[k]);
                k--;
            }else{ // nums[j] = 0
                swap(nums[j],nums[i]);
                j++; // we will move j because i and j were both at same place
                i++;
            }
        }



    }
};