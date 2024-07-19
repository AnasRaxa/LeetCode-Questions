
class Solution {
public:

    int isEven(int num){

        return num%2 == 0;

    }

    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {

        vector<int>result;
        
        int n = nums.size();

        int sumEven = 0;

        for(auto nm:nums){
            if(nm%2==0) sumEven+=nm;
        }


        for(int i = 0; i<n; i++){

            auto q = queries[i];

            int val = q[0];
            int indx = q[1];

            if(!isEven(nums[indx])){
                nums[indx] = nums[indx]+val;
                if(isEven(nums[indx])){
                    sumEven+=nums[indx];
                }

            }else{

                sumEven-=nums[indx];

                nums[indx]+=val;

                if(isEven(nums[indx])){
                    sumEven+=nums[indx];
                }

            }

            

            

            result.push_back(sumEven);


        }

        return result;
        
    }
};



















class Solution {
public:

    int getSum(vector<int>& nums){

        int sum = 0;

        for(int it:nums){
            if(it%2==0){
                sum+=it;
            }
        }

        return sum;

    }

    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {

        vector<int>result;
        
        int n = nums.size();


        for(int i = 0; i<n; i++){

            auto q = queries[i];

            int val = q[0];
            int indx = q[1];

            nums[indx] = nums[indx]+val;

            int sum = getSum(nums);

            result.push_back(sum);


        }

        return result;
        
    }
};