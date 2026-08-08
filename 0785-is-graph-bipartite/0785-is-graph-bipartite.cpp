class Solution {
public:
    bool exist = true;

    void dfs(vector<vector<int>>& graph, int node, int c, vector<int>& colour) {
        colour[node] = c;

        for(int i = 0; i < graph[node].size(); i++){
            int neigh = graph[node][i];

            if(colour[neigh] != -1 && colour[neigh] == c){
                exist = false;
            }
            if(colour[neigh] == -1){
                dfs(graph, neigh, 1-c, colour);
            }
        }

        return;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colour(n, -1);

        for(int i = 0; i < n; i++){
            if(colour[i] == -1){
                dfs(graph, i, 0, colour);
            }

        }

        return exist;
    }
};