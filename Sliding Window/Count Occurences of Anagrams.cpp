//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int search(string pat, string txt) {
	    // code here
	    
	    
	    int k = pat.size();
	    
	    unordered_map<char,int>mp;
	    
	    for(auto x:pat) mp[x]++;
	    
	    int i = 0, j= 0;
	    int ans = 0;
	    int count = mp.size();
	    
	    
	    while(j<txt.size()){
	        
	        if(mp.count(txt[j])){
	            mp[txt[j]]--;
	            if(mp[txt[j]] == 0){
	                count--;
	            }
	        }
	        
	        
	        if(j-i+1<k) j++;
	        else if(j-i+1 == k){
	            
	            if(count == 0) ans++;
	            
	            if(mp.count(txt[i])){
	                
	                if(mp[txt[i]] == 0){
	                    count++;
	                }
	                
	                mp[txt[i]]++;
	                
	            }
	            
	            
	            i++;
	            j++;
	            
	            
	            
	        }
	        
	        
	    }
	    
	    
	    
	    
	    
	    return ans;
	    
	    
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends