class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> result;

        int maxi = INT_MIN;

        for(int it:candies){
            maxi = max(maxi,it);
        }

        for(int it:candies){
            if(it+extraCandies>=maxi){
                result.push_back(true);
            }else{
                result.push_back(false);
            }
        }
        
        return result;

    }
};