class Solution{
    public:
    
    vector<string>ans;
    
    

    bool valid(int i, int j ,int n){
        return (i>=0 && j>=0 && i<n && j<n);
    }


    void solve(vector<vector<int>>&m,int i,int j,int n,string& path){


            if(!valid(i,j,n) || m[i][j] == 0)   return;
            
            if(i == n-1 && j == n-1){
                ans.push_back(path);
            }
            
            
            m[i][j] = 0;
            
            
            path.push_back('D');
            solve(m,i+1,j,n,path);
            path.pop_back();
            
            path.push_back('L');
            solve(m,i,j-1,n,path);
            path.pop_back();
            
            path.push_back('R');
            solve(m,i,j+1,n,path);
            path.pop_back();
            
            path.push_back('U');
            solve(m,i-1,j,n,path);
            path.pop_back();
            
            
            
            m[i][j] = 1;


    }

    
    
    
    
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        
        
        string path = "";
        
        solve(m,0,0,n,path);
        
        
        return ans;
        
        
        
    }
};