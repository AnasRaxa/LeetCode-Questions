class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {

        unordered_map<int,int>mp;
    
        int i = 0;
        int j = 0;


        while(j<nums.size()){
            
            

            if(j-i <= k){
                
                if(mp.count(nums[j]))return true;

                mp[nums[j]]++;

                j++;

            }else{
                mp.erase(nums[i]);
                i++;
            }

            

        }


        return false;
        
        
        
    }
};


