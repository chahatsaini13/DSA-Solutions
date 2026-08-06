class Solution {
public:

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n);
        vector<bool> vis(n, false);
        queue<int> q;
        int provinces = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i != j && isConnected[i][j] == 1){
                    adj[i].push_back(j);
                }
            }
        }

        for(int i = 0; i < n; i++){
            if(!vis[i]){
                provinces++;
                q.push(i);
                vis[i] = true;

                while(!q.empty()){
                    int node = q.front();
                    q.pop();
                    
                    for(int j = 0; j < adj[node].size(); j++){
                        int neigh = adj[node][j];
                        if(!vis[neigh]){
                            q.push(neigh);
                            vis[neigh] = true;
                        }
                    }
                }
            }
        }

        return provinces;
    }
};