class Solution {
public:
    string reverseWords(string s) {

        

        stringstream ss(s);

        string token;
        string result = "";


        while(ss>>token){

            result = token + " " + result;

        }

        return result.substr(0, result.size()-1);
        
    }
};



















class Solution {
public:
    string reverseWords(string s) {

        int n = s.size();

        reverse(s.begin(),s.end());

        int l = 0, r = 0, i= 0;


        while(i<n){


            while(i<n && s[i]!=' '){
                
                s[r] = s[i];
                i++;
                r++;
            }

            if(l<r){

                reverse(s.begin()+l,s.begin()+r);
                s[r] = ' ';
                r++;
                l = r;

            }


            i++;

        }



        return s.substr(0,r-1);


        
    }
};