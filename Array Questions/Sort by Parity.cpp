class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {


        int n = nums.size();


        int i = 0;
        int j = n-1;


        while(i<j){
            if(nums[i]%2!=0 && nums[j]%2==0){
                swap(nums[i],nums[j]);
                i++;
                j--;
            }else if(nums[i]%2 == 0 ) i++;
            else if(nums[j]%2!=0) j--;
            
        }


        return nums;


        
    }
};



















class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int j = 0;
        
        for(int i = 0; i<nums.size(); i++) {
            
            if(nums[i]%2 == 0) {//even
                swap(nums[i], nums[j]);
                j++;
            }
        }
        
        return nums;
    }
};



























class Solution {
public:
    
    static bool comparator(int a, int b) {
        return a%2 < b%2; //a%2 will be 0 if it's even and since we do a%2 < b%2, hence a will come first if it's even
    }
    
    vector<int> sortArrayByParity(vector<int>& nums) {
        sort(begin(nums), end(nums), comparator);
        
        return nums;
    }
};