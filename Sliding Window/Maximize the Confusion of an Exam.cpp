//Approach-1 (Simple Brute Force) - O(n * 2^n)
class Solution {
public:
    int ans = 0;
    int n;
    
    void findMax(string answerKey) {
        int length = 0;
        
        int i = 0;

        while(i < n) {
            
            if(answerKey[i] == 'T') {
                length = 1;
                i++;
                while(i < n && answerKey[i] == 'T') {
                    length++;
                    i++;
                }
                ans = max(ans, length);
            } else {
                length = 1;
                i++;
                while(i < n && answerKey[i] == 'F') {
                    length++;
                    i++;
                }
                ans = max(ans, length);
            }
            
        }
    }
    
    void solve(int idx, string &answerKey, int k) {
        
        findMax(answerKey);
        
        if(idx >= n || k <= 0) {
            return;
        }
        
        answerKey[idx] = answerKey[idx] == 'T' ? 'F' : 'T'; //Flipped
        
        solve(idx+1, answerKey, k-1);
        
        answerKey[idx] = answerKey[idx] == 'T' ? 'F' : 'T'; //Flipped back
        solve(idx+1, answerKey, k);
        
    }
    
    int maxConsecutiveAnswers(string answerKey, int k) {
        n = answerKey.length();
        
        solve(0, answerKey, k);
        
        return ans;
    }
};


//Approach-2 (Using a Sliding Window twice)
class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.length();
        int result = 0;
        //First pass for flipping 'F' -> 'T'
        
        int i = 0, j = 0;
        int countF = 0;
        while(j < n) {
            if(answerKey[j] == 'F')
                countF++;
            
            while(countF > k) {
                if(answerKey[i] == 'F')
                    countF--;
                i++;
            }
            
            result = max(result, j-i+1);
            
            j++;
        }
        
        i = 0, j = 0;
        int countT = 0;
        while(j < n) {
            if(answerKey[j] == 'T')
                countT++;
            
            while(countT > k) {
                if(answerKey[i] == 'T')
                    countT--;
                i++;
            }
            
            result = max(result, j-i+1);
            j++;
        }
        
        
        return result;
    }
    
};

//Approach-3 (Using One Pass Sliding Window)
class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int result = k;
        
        unordered_map<char, int> mp;

        int i = 0;
        for (int j = 0; j < answerKey.length(); j++) {

            mp[answerKey[j]]++;
            
            while (min(mp['T'], mp['F']) > k) {
                mp[answerKey[i]]--;
                i++;
            }
            
            result = max(result, j - i + 1);
        }
        
        return result;
    }
};
















































class Solution {
public:
    int maxConsecutiveAnswers(string arr, int k) {

         int n = arr.size();
        if(n==1)
            return 1;
        
        
        unordered_map<char,int> mp;
        
        
        int i , j = 0 , ans = 0;
        int maxi = 0;
        
        
        for(i = 0 ; i < n ; i++)
        {
            
            mp[arr[i]]++;
            
          
            // freq of max element in curr window 
            maxi = max(maxi , mp[arr[i]]);
            
            // currwindowsize-maxi ==> least frequent element 
            while(  (i-j+1) - maxi > k )
            {
                
                
                mp[arr[j]]--;
                
                j++;
                
                
                
                
            }
            
            ans = max(ans,i-j+1);
            
            
            
            
            
            
            
        }
        
        return ans;
        
    }
};