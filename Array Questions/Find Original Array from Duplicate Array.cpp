class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {

        int n = changed.size();

        vector<int>result;

        if(n%2 != 0 ){ // if lenth is not even it means there is not complte duplicates
            return {};
        }

        
        unordered_map<int,int>mp;

        sort(changed.begin(),changed.end());


        for( auto &it:changed){
            mp[it]++;
        }

        for(int num:changed){

            int twice = 2*num;


            if(mp[num] == 0)continue;

            if(!mp.count(twice) || mp[twice] == 0) return {};

            result.push_back(num);

            mp[num]--;
            mp[twice]--;

        }



        return result;


        
    }
};