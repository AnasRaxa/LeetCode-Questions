//{ Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
public:
    //Function to count subarrays with sum equal to 0.
    long long int findSubarray(vector<long long int> &arr, int n ) {
        //code here
        
        
        long long int total = 0;
        
        unordered_map<long long int,long long int>mp;
        
        long long int prefix_sum = 0;
        
        mp[0] = 1;
        
        
        
        
        
        for(int i = 0; i<n; i++){
            
            prefix_sum+=arr[i];
            
            
            if(mp.count(prefix_sum)){
                total+=mp[prefix_sum];
                mp[prefix_sum]++;
            }else{
            mp[prefix_sum] = 1;
                
            }
            
            
            
        }
        
        
        
        return total;
        
        
        
        
        
        
        
        
        
        
    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n; //input size of array
       
        vector<long long int> arr(n,0);
        
        for(int i=0;i<n;i++)
            cin>>arr[i]; //input array elements
        Solution ob;
        cout << ob.findSubarray(arr,n) << "\n";
    }
	return 0;
}
// } Driver Code Ends