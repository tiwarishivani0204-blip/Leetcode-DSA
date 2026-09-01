class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int n = classroom.size();
        int m = classroom[0].size();

        vector<pair<int,int>> litter;
        int sr, sc;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (classroom[i][j] == 'L')
                    litter.push_back({i, j});
                else if (classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                }
            }
        }

        int k = litter.size();

        if (k == 0)
            return 0;

        unordered_map<int, int> id;
        for (int i = 0; i < k; i++) {
            id[litter[i].first * m + litter[i].second] = i;
        }

        int full = (1 << k) - 1;

        queue<array<int, 4>> q;
        q.push({sr, sc, energy, 0});

        vector<vector<vector<vector<bool>>>> vis(
            n, vector<vector<vector<bool>>>(
                m, vector<vector<bool>>(
                    energy + 1, vector<bool>(1 << k, false)
                )
            )
        );

        vis[sr][sc][energy][0] = true;

        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        int moves = 0;

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                auto [r, c, e, mask] = q.front();
                q.pop();

                if (mask == full)
                    return moves;

                for (int d = 0; d < 4; d++) {
                    int nr = r + dr[d];
                    int nc = c + dc[d];

                    if (nr < 0 || nr >= n || nc < 0 || nc >= m)
                        continue;

                    if (classroom[nr][nc] == 'X')
                        continue;

                    if (e == 0)
                        continue;

                    int ne = e - 1;
                    int nmask = mask;

                    if (classroom[nr][nc] == 'L') {
                        int idx = id[nr * m + nc];
                        nmask |= (1 << idx);
                    }

                    if (classroom[nr][nc] == 'R')
                        ne = energy;

                    if (!vis[nr][nc][ne][nmask]) {
                        vis[nr][nc][ne][nmask] = true;
                        q.push({nr, nc, ne, nmask});
                    }
                }
            }

            moves++;
        }

        return -1;
    }
};