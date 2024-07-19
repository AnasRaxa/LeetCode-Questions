class Solution {
public:

    int bSearch(vector<int>& nums,int target){

        int index = -1;


        int start = 0;
        int end  = nums.size()-1;

        int mid;

        while(start<=end){

            mid = (start+end)/2;

            if(nums[mid]<=target){
                index = mid;
                start = mid + 1;
            }else{
                end = mid - 1;
            }

        }

        return index+1;


    }

    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {

        int n = nums.size();

        sort(nums.begin(),nums.end());

        vector<int>ans;
        
        for(int i = 1; i<n; i++){
            nums[i] = nums[i-1]+nums[i];
        }


        for(int &q:queries){
            
            int idx = bSearch(nums,q);

            ans.push_back(idx);

        }


        return ans;

        
    }
};