class Solution{   
public:
    long maximumSumSubarray(int K, vector<int> &arr , int N){
        // code here 
        
        
        long maxi = INT_MIN;
        
        int i = 0, j = 0;
        
        long sum = 0;
        
        
        while(j<N){
            
            sum+=arr[j];
            
            
            if(j-i+1 == K){
                
                maxi = max(maxi,sum);
                sum-=arr[i];
                i++;
                j++;
            }else if(j-i+1 < K){
                j++;
            }
            
            
        }
        
        return maxi;
        
             
    }
};