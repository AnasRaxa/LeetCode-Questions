class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        unordered_map<int,int>mp;
        mp[0] = 1;

        int prefix = 0, rem, total = 0;



        for(int i = 0; i<nums.size(); i++){

            prefix+=nums[i];
            rem = prefix%k;

            if(rem<0){ // if remnder is -
                rem+=k;
            }
            
            if(mp.count(rem)){
                total+=mp[rem];
                mp[rem]++;
            }else{
                mp[rem] = 1;
            }


        }

        return total;


    }
};




























class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int count = 0;
        int n = nums.size();

        

        for(int i = 1; i<n; i++){
            nums[i]+=nums[i-1];
        }


        for(int i = 0; i<n; i++){
            for(int j = i; j<n; j++){

                int sum = i==0 ? nums[j] : nums[j]-nums[i-1];

                if(sum%k==0) count++;
                

            }
        }

        return count;
    }
};