class Solution {
   public:
    int min_idx(vector<int>& key, vector<bool>& mst) {
        int idx = 0, idx_val = INT_MAX;
        for (int i = 0; i < key.size(); i++) {
            if (!mst[i] && idx_val > key[i]) {
                idx = i;
                idx_val = key[i];
            }
        }
        return idx;
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<int>> graph(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                int x1 = points[i][0], y1 = points[i][1];
                int x2 = points[j][0], y2 = points[j][1];

                int dist = abs(x1 - x2) + abs(y1 - y2);
                graph[i][j] = dist;
                graph[j][i] = dist;
            }
        }

        vector<int> parent(n);
        vector<int> key(n, INT_MAX);
        vector<bool> mst(n, false);

        key[0] = 0;
        parent[0] = -1;

        for (int c = 0; c < n - 1; c++) {
            int u = min_idx(key, mst);
            mst[u] = true;

            for (int v = 0; v < n; v++) {
                if (graph[u][v] && !mst[v] && graph[u][v] < key[v]) {
                    parent[v] = u;
                    key[v] = graph[u][v];
                }
            }
        }

        int ans = 0;
        for (int i = 1; i < n; i++) {
            int p = parent[i];
            ans += graph[i][p];
        }
        return ans;
    }
};
