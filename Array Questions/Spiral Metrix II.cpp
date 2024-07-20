class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if(n == 0)
            return {};
        int m = n;
        vector<vector<int>> matrix(m, vector<int>(n));
        int row = n;
        int col = n;

        int top = 0,right = col - 1, bottom = row - 1, left = 0;

        int counter  = 1;

        while(left<=right && top<=bottom){

            for(int j = left; j<=right; j++)
            matrix[top][j] = counter++;
            top++;
            

            for(int i = top; i<=bottom; i++)
            matrix[i][right] = counter++;
            right--;
            

            if(top<=bottom){
                for(int j = right; j>=left; j--)
                    matrix[bottom][j] = counter++;
                    bottom--;
                
            }

            if(left<=right){
                for(int i = bottom; i>=top; i--)
                    matrix[i][left] = counter++;
                    left++;
                
            }

        }
        return matrix;
    }
};