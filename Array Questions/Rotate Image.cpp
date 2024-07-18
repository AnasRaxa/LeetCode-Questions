class Solution {
public:
    void rotate(vector<vector<int>>& arr) {




        int row = arr.size() , col = arr[0].size();


        for(int i = 0; i<row; i++){
            for(int j = i+1; j<col; j++){

                swap(arr[i][j],arr[j][i]);

            }
        }


        for(int i = 0; i<row; i++){

            int start = 0, end = row-1;

            while(start<end){

                swap(arr[i][start],arr[i][end]);
                start++;
                end--;

            }

        }





        
    }
};