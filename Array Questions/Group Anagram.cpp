class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        int n = strs.size();

        vector<vector<string>> result;
        unordered_map<string,vector<string>>mp;



        for(int i = 0; i<n; i++){

            string temp = strs[i];

            sort(temp.begin(),temp.end());

            mp[temp].push_back(strs[i]);


        }

        for(auto str:mp){
            result.push_back(str.second);
        }


        return result;
      
    }
};











class Solution {
public:

    
    string generate(string & word){

        int arr[26] = {0};

        string new_word = "";

        for(auto c:word){
            
            arr[c-'a']++;
        }

        for(int i = 0; i<26; i++){
            int freq = arr[i];

            if(freq>0){

                new_word+= string(freq,i+'a');

            }
        }

        return new_word;

    }
    



    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        int n = strs.size();

        vector<vector<string>> result;
        unordered_map<string,vector<string>>mp;



        for(int i = 0; i<n; i++){

            string temp = strs[i];

            string new_word = generate(temp);

            mp[new_word].push_back(strs[i]);


        }

        for(auto str:mp){
            result.push_back(str.second);
        }





        return result;

        



        
    }
};