class Solution {
public:
    int minJumps(vector<int>& arr) {

        int n = arr.size();
        unordered_map<int,vector<int>>mp;

        vector<bool>visited(n,false);

        for(int i = 0; i<n; i++){
            mp[arr[i]].push_back(i);
        }

        queue<int>q;

        q.push(0);
        visited[0] = true;


        int steps = 0;

        while(!q.empty()){
            
            int size = q.size();

            while(size--){
                
                int curr = q.front();
                q.pop();

                int left = curr-1;
                int right = curr+1;

                if(curr == n-1){
                    return steps;
                }

                if(left>0 && !visited[left]){
                    q.push(left);
                    visited[left] = true;
                }
                if(right<=n-1 && !visited[right]){
                    q.push(right);
                    visited[right] = true;
                }

                for(int idx:mp[arr[curr]]){
                    if(!visited[idx]){
                        q.push(idx);
                        visited[idx] = true;
                    }
                }

                mp.erase(arr[curr]);


            }

            steps++;


        }
return steps;
        
    }
};