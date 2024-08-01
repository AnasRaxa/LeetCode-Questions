class Solution {
public:
    string minWindow(string s, string t) {

        int n = s.size();

        int total = t.size();

        unordered_map<char,int>mp;


        for(int i = 0; i<t.size(); i++)mp[t[i]]++;

        int start = 0, end = 0;
        int ans = INT_MAX;
        int index = -1;


        while(end < n){

            mp[s[end]]--;

            if(mp[s[end]]>=0) total--;

            while(!total && start<=end){

                if(ans>end-start+1){

                    ans = end-start+1;
                    index = start;

                }

                mp[s[start]]++;

                if(mp[s[start]]>0) total++;

                start++;
                

            }


            end++;

        }

        if(index == -1) return "";

        string str = "";

        for(int i = index; i<index+ans; i++){

            str+=s[i];

        }

        return str;
        
    }
};







#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s="totmtaptat";
    string s1="tta";
// Making the Map

    unordered_map<char,int> mp;
    for(int i=0 ; i<s1.length() )
     mp[s1[i]]++;

//Creating Variables

    int ans=INT_MAX;
    int i=0,j=0;
    int count=mp.size();

// starting to  solve

    while(j<s.length())
    {
      // CALCULATION STEP ( As Aditya's general format)

       if(mp.find(s[j])!=mp.end())
       {
           mp[s[j]]--;
           if(mp[s[j]]==0)
           count--;
       }

// step to slide " j "

       if(count>0)
       j++;

// step where we will find a candidate for answer

       else if(count==0)
       {
           ans=min(ans,j-i+1);    // A candidate for our Answer

// trying to minimize the window size after getting a candidate for answer

           while(count==0)
           {
               if(mp.find(s[i])==mp.end())
               {
                   i++;
                   ans=min(ans,j-i+1);   // updating the answer
               }
               else
               {
                   mp[s[i]]++;
                   if(mp[s[i]]>0)
                   {
                       i++;
                       count++;
                   }
                   else
                   {
                       i++;
                       ans=min(ans,j-i+1);   // updating the answer
                   }
               }
           }
           j++;
       }
    }
    cout<<ans<<endl;
    return 0;
}