class Solution {
public:

    bool isVowel(char &ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }


    int maxVowels(string s, int k) {

        int i = 0 , j = 0;

        int count = 0;
        int ans = -1;


        while(j<s.size()){

            if(isVowel(s[j])) count++;


            if(j-i+1 == k){
                ans = max(ans,count);

                if(isVowel(s[i])){
                    count--;
                }
                i++;
            }


            j++;


        }
        
        return ans;
    }
};