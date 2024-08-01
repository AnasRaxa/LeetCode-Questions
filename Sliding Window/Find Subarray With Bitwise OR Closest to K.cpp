class Solution {
public:
    int bits[32] = {};
    int minimumDifference(vector<int>& nums, int k) {
        int res = INT_MAX, n = nums.size();
        for(int left = 0, right = 0; right < n; right++)
        {
            int curr = update(nums[right], 1);
            res = min(res, abs(curr - k));
            while(left < right && curr > k)
            {
                curr = update(nums[left++], -1);
                res = min(res, abs(curr - k));
            }
        }
        return res;
    }

    int update(int num, int val)
    {
        int res = 0;
        for(int i = 0; i < 32; i++)
        {
            if((num >> i) & 1)
            {
                bits[i] += val;
            }
            if(bits[i]) res |= 1 << i;
        }
        return res;
    }

};