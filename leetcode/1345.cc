typedef map<int, vector<int>> graph;

class Solution {
public:

    void print(graph& g) {
        printf("size: %d\n", g.size());
        printf("\n");
        for (auto it: g) {
            printf("%d: ", it.first);
            for (auto e: it.second)
                printf("%d ", e);
            printf("\n");
        }
    }

    graph buildGraph(vector<int>& arr) {
        graph g;
        for (int i=0; i<arr.size(); i++){
            g[arr[i]].push_back(i);
        }
        return g;
    }
    int bfs(graph &g, vector<int>& arr, int n, int s, int e) {
        queue<pair<int, int>> q;
        vector<int> visited(n, 0);
        q.push({s, 0});
        visited[s] = 1;

        while (!q.empty()) {
            auto [val, dist] = q.front();
            q.pop();

            // printf("Visiting: %d\n", val);

            if (val == e)
                return dist;

            // same value
            int u = arr[val];
            for (int i=0; i<g[u].size(); i++){
                int v = g[u][i];
                if (!visited[v]){
                    // printf("v: %d\n", v);
                    visited[v] = 1;
                    q.push({v, dist+1});
                }
            }

            g[u].clear();

            // neighborhood
            for (int i=val-1; i<=val+1; i++){
                if (i >= 0 && i < n && !visited[i]) {
                    // printf("i: %d\n", i);
                    visited[i] = 1;
                    q.push({i, dist+1});
                }
            }

        }
        return -1;
    }
    int minJumps(vector<int>& arr) {
        if (arr.size() == 1)
            return 0;
        auto g = buildGraph(arr);
        // print(g);
        return bfs(g, arr, arr.size(), 0, arr.size()-1);
    }
};
