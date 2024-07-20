class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        int result = 0;
        
        for(auto row:grid){

            int idx = upper_bound(begin(row),end(row),0,greater<int>())-begin(row);

            result+=n-idx;

        }
        
        return result;
    }
};





class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        int row = m-1;
        int col = 0;
        
        int result = 0;
        while( row >= 0 && col < n) {
            
            if(grid[row][col] < 0) {
                result += n-col;
                row--;
            } else {
                col++;
            }
        }
        
        return result;
    }
};