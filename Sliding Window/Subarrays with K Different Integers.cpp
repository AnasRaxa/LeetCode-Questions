 class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        //at least(k)-at least(k-1)
        int total=0;
      unordered_map<int,int>ferq;
      // use count of different integer
      int start=0,end=0,count=0;
      int n=nums.size();
      while(end<n){
        //add the frequency
        ferq[nums[end]]++;
        //only different intger count duplicate element not count
        if(ferq[nums[end]]==1)
        count++;
        //incresae the window size
        //number of differnt integer is equl to k
        //decrease the window size 
        while(count>k &&start<=end){
            ferq[nums[start]]--;
            if(ferq[nums[start]]==0)
            count--;
            start++;
        }
          total+=(end-start+1);
      end++;
      }
      end=0,count=0,start=0;
      ferq.clear();
      k--;
      while(end<n){
        //add the frequency
        ferq[nums[end]]++;
        if(ferq[nums[end]]==1)
        count++;
        //incresae the window size
        //number of differnt integer is equl to k
        //decrease the window size 
        while(count>k &&start<=end){
            ferq[nums[start]]--;
            if(ferq[nums[start]]==0)
            count--;
            start++;
        }
          total-=(end-start+1);
      end++;
      }
      return total;
    }
};


































class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        
        unordered_map<int, int> mp;
        
        int i_chota  = 0;
        int j        = 0;
        int i_bada   = 0;
        
        int result   = 0;
  
        while(j < n) {
            mp[nums[j]]++;
            
            while(mp.size() > k) {
                mp[nums[i_chota]]--;
                if(mp[nums[i_chota]] == 0) {
                    mp.erase(nums[i_chota]);
                }
                i_chota++;
                i_bada = i_chota;
            }
            
            while(mp[nums[i_chota]] > 1) {
                mp[nums[i_chota]]--;
                i_chota++;
            }
            
            if(mp.size() == k) {
                result += i_chota - i_bada + 1;
            }
            j++;
        }
        
        return result;
    }
};