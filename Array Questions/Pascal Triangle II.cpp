class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> result(rowIndex+1);
        
        for(int i = 0; i<rowIndex+1; i++) {
            
            result[i] = vector<int>(i+1, 1);
            
            for(int j = 1; j < i; j++) {
                
                result[i][j] = result[i-1][j] + result[i-1][j-1];
                
            }
            
            if(i == rowIndex) //Just return when you find rowIndex
                return result[i];
            
        }
        
        return {};
    }
};



class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> prev;
        
        for(int i = 0; i<rowIndex+1; i++) {
            
            vector<int> curr = vector<int>(i+1, 1);
            
            for(int j = 1; j < i; j++) {
                
                curr[j] = prev[j] + prev[j-1];
                
            }
            prev = curr;
        }
        
        return prev;
    }
};