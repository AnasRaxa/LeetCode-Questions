class Solution {
public:

    vector<vector<string>>result;
    int N;

    bool isValid(vector<string>& board,int row,int col){

        for(int i = row-1; i>=0; i--){

            if(board[i][col] == 'Q') return false;

        }

        for(int i = row-1, j = col-1; i>=0 && j>=0; i--,j--){

            if(board[i][j] == 'Q') return false;

        }
        for(int i = row-1, j = col+1; i>=0 && j<N; i--,j++){

            if(board[i][j] == 'Q') return false;

        }

        return true;


    }



    void solve(vector<string>& board,int row){

        if(row >= N){
            result.push_back(board);
            return;
        }

        for(int col = 0; col<N; col++){

            if(isValid(board,row,col)){
                
                board[row][col] = 'Q';

                solve(board,row+1);

                board[row][col] = '.';

            }

        }



    }




    vector<vector<string>> solveNQueens(int n) {
        N = n;

        vector<string>board(n,string(n,'.'));


        solve(board,0);


        return result;

        
    }
};















class Solution {
public:

    vector<vector<string>>result;
    int N;

    unordered_set<int>column;
    unordered_set<int>diagonal;
    unordered_set<int>Antidiagonal;



    void solve(vector<string>& board,int row){

        if(row >= N){
            result.push_back(board);
            return;
        }

        for(int col = 0; col<N; col++){

            int diag = row + col;
            int Antidiag = row - col;

            if(column.find(col) != column.end() || diagonal.find(diag) != diagonal.end() || Antidiagonal.find(Antidiag) != Antidiagonal.end()){
                continue;
            }

            column.insert(col);
            diagonal.insert(diag);
            Antidiagonal.insert(Antidiag);
            board[row][col] = 'Q';

            solve(board,row+1);


            column.erase(col);
            diagonal.erase(diag);
            Antidiagonal.erase(Antidiag);
            board[row][col] = '.';


        }



    }




    vector<vector<string>> solveNQueens(int n) {
        N = n;

        vector<string>board(n,string(n,'.'));


        solve(board,0);


        return result;

        
    }
};