class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {

        long long mx = *max_element(nums.begin(),nums.end());

        int n = nums.size();

        int start = 0, end = 0;

        long long total = 0;
        int count = 0;

        while(end < nums.size()){

            if(nums[end] == mx){
                count++;
            }

            while(count==k){
                total+=n-end;
                if(nums[start]==mx)count--;
                start++;
            }


            end++;

        }

        return total;
        
    }
};