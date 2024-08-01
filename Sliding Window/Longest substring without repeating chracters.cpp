class Solution {
public:


    int lengthOfLongestSubstring(string s) {

        map<char,int>mp;
        
        

        int i = 0, j = 0;

        int ans = 0;


        while(j<s.size()){

            mp[s[j]]++;

            while(mp[s[j]]>1){
                mp[s[i]]--;
                i++;
            }
            

            ans = max(ans,j-i+1);

            j++;


        }


        return ans;
    }
};


















class Solution {
public:


    int lengthOfLongestSubstring(string s) {

        map<char,int>mp;
        
        

        int i = 0, j = 0;

        int ans = 0;


        while(j<s.size()){

            mp[s[j]]++;

            if(mp.size() == j-i+1){
                ans = max(ans,j-i+1);
                j++;
            })
            else if(mp.size() < j-i+1){

                while(mp.size() < j-i+1{
                    mp[s[i]]--;
                    f(mp[s[i]] == 0)mp.erase(s[i]);
                    i++;
                })

            }else if(mp.size() > j-i+1){
                j++;
            }

        }

        return ans;
    }
};