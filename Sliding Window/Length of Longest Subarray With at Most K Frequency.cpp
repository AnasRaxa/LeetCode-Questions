class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {

        int start = 0, end = 0;
        int ans = INT_MIN;

        unordered_map<int,int>mp;

        while(end < nums.size()){

            mp[nums[end]]++;

            while(mp[nums[end]]>k){
                mp[nums[start]]--;
                start++;
            }

            ans = max(ans,end-start+1);


            end++;


        }


        return ans;
        
    }
};