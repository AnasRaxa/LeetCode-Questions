class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {

        vector<int>indegree(n+1);
        vector<int>outdegree(n+1);

        for(auto vec:trust){
            
            int out = vec[0];
            int in = vec[1];

            outdegree[out]++;
            indegree[in]++;

        }

        for(int i = 1; i<=n; i++){
            
            if(outdegree[i] == 0 && indegree[i] == n-1) return i;

        }
        return -1;
    }
};








class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {

        vector<int>connections(n+1);
        

        for(auto vec:trust){
            
            int out = vec[0];
            int in = vec[1];

            connections[out]--;
            connections[in]++;

        }

        for(int i = 1; i<=n; i++){
            
            if(connections[i] == n-1) return i;

        }
        return -1;
    }
};