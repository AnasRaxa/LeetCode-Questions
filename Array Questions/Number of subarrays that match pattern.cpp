class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int n = nums.size();
        int m = pattern.size();
        
        int count = 0;
        
        for(int i = 0; i < n-m; i++) {

            int k = 0;
            while(k < m) {
                if(pattern[k] == 1 && nums[i+k+1] > nums[i+k]) {
                    k++;
                } else if(pattern[k] == 0 && nums[i+k+1] == nums[i+k]) {
                    k++;
                } else if(pattern[k] == -1 && nums[i+k+1] < nums[i+k]) {
                    k++;
                } else {
                    break;
                } 
            }

            if(k == m) { //Found complete pattern
                count++;
            }
            
        }
        
        return count;
    }
};










class Solution {
public:
    void longestPrefixSuffix(vector<int>& pattern, vector<int>& lps) {
        int M = pattern.size();
        int len = 0; // Length of the previous longest prefix & suffix
    
        lps[0] = 0; // Because there is no proper suffix and prefix of pattern[0..0]
    
        int i = 1;
        while (i < M) {
            if (pattern[i] == pattern[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1]; //You can also write, len = len-1;
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }

    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int N = nums.size();
        int M = pattern.size();

        vector<int> nums2;
        for(int i = 0 ; i < N-1 ; i++) {
            if(nums[i] < nums[i+1]) 
                nums2.push_back(1);
            else if(nums[i] > nums[i+1]) 
                nums2.push_back(-1);
            else 
                nums2.push_back(0);
        }
        
        vector<int> lps(M, 0);
        longestPrefixSuffix(pattern, lps);

        int i       = 0;
        int j       = 0;
        int result  = 0;

        while(i < nums2.size()) {
            if(pattern[j] == nums2[i]) {
                i++;
                j++;
            }
            
            if (j == pattern.size()) {
                result++; //Pattern found at index i-j+1 (If you have to return 1 Based indexing, that's why added + 1)
                j = lps[j - 1];
            } else if (i < nums2.size() && pattern[j] != nums2[i]) {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }

        }
        return result;


    }
};
