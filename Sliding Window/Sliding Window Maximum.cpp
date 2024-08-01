class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        vector<int>ans;
        list<int>q;


        int i = 0, j = 0;


        while(j<nums.size()){

            while(nums[j]>q.back() && q.size()>0){
                q.pop_back();
            }

            q.push_back(nums[j]);

            if(j-i+1 < k) j++;
            else if(j-i+1 == k){

                ans.push_back(q.front());

                if(nums[i] == q.front()){
                    q.pop_front();
                }

                i++;
                j++;

            }
            



        }

        return ans;
        
    }
};