/*

problem --> we have to find the subarray of maximum sum with size 5 -- here size of subarray is 5
            k = 5
            Brute force --> 
                            i = o->n
                            j = i->i+k
                            find sum
                            
            issue with brute force is that we are doing repetative work
                1 -> 1,2,3,4,5 
                2 -> 2,3,4,5,6 
                3 -> 3,4,5,6,7 

            as u can see we are iterating through k-1 element again and again

            to avoid this repetative work we use slididng window

            logic --> we remove one elmenet from left of window and add one elment at right side of window

            types --> 
                        1 - fixed sized windwo     --> window size is given
                        2 - variable sized window  --> window size is not given we have to figure it out


            we mostly do 3 task -->
                        1- do some claculation
                        2- find answer 
                        3- slide the windwo


            


            pseudo code --> 
                                i = 0, j = 0
                                ans = INT_MIN
                                sum = 0

                                while(j<n){


                                    sum+=arr[j] // calculation

                                    if(j-i+1 == k) // mean windwo size is completed
                                            ans = max(ans,sum) // find answer
                                            sum-=arr[i] // slide window
                                            i++
                                            j++

                                    else{

                                            j++ // complete window

                                    }

                                }



                    variable sized --> 

                                int lenOfLongSubarr(int A[],  int N, int K) 
                                { 
                                        // Complete the function
                                        
                                        
                                int i = 0, j = 0, sum = 0;

                                    int maxLen = INT_MIN;

                                

                                    while (j < N) {

                                        sum += A[j];  //calculation

                                        if (sum == K) {

                                        maxLen = max(maxLen, j-i+1);     //taking results

                                            j++;

                                        }

                                        else if (sum < K) {    //adjusting window

                                            j++;

                                        }

                                        else if (sum>K){
                                                while(sum>K){
                                                    sum = sum - A[i];
                                                    i++;
                                                    if(sum==K){
                                                        maxLen = max(maxLen,(j-i+1));
                                                    }
                                                }
                                                j++;
                                        }

                                    }

                                    return maxLen;

                                    } 










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










*/