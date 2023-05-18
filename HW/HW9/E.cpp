#include <bits/stdc++.h>
using namespace std;

#define N 1300

// Left Right Up Down
const int xdir[4] = {-1, 1, 0, 0};
const int ydir[4] = {0, 0, -1, 1};

struct Node {
    int color;
    unordered_set <int> embassies;
};

struct Elm {
    int node;
    int pass;
    int spent;
};

Node nodes[N*N];
int mp[N][N], n, m, node_cnt = 0, node_mp[N][N];
vector <int> embass[N][N];
bool visited[N][N], visited2[N][N], vis[N*N], add_embassies_to_q_vis[N*N];
unordered_set < int > G[N*N], vis0[N*N];

inline bool valid_coord(int y, int x) {
    return y >= 0 && x >= 0 && y < n && x < m;
}

inline bool found(int node_ind, int color) {
    return nodes[node_ind].embassies.find(color) != nodes[node_ind].embassies.end();
}

void dfs(int y, int x, int node_ind) {
    node_mp[y][x] = node_ind;
    visited[y][x] = true;
    for (int i = 0; i < embass[y][x].size(); i++)
        nodes[node_ind].embassies.insert(embass[y][x][i]);

    int par_color = mp[y][x];
    for (int i = 0; i < 4; i++) {
        int new_x = x + xdir[i], new_y = y + ydir[i];
        if (!valid_coord(new_y, new_x)) 
            continue;
        // cout << "y,x:" << y << "," << x << " y2,x2:" << new_y << ',' << new_x << endl;

        if (!visited[new_y][new_x] && par_color == mp[new_y][new_x]) 
            dfs(new_y, new_x, node_ind);
    }
}

void dfs2(int y, int x) {
    visited2[y][x] = true;
    int par_color = mp[y][x], par_node = node_mp[y][x];
    for (int i = 0; i < 4; i++) {
        int new_x = x + xdir[i], new_y = y + ydir[i];
        if (!valid_coord(new_y, new_x) || visited2[new_y][new_x]) 
            continue;
        if (mp[new_y][new_x] == par_color) 
            dfs2(new_y, new_x);
        else {
            int node = node_mp[new_y][new_x];
            G[node].insert(par_node);
            G[par_node].insert(node);
            // printf("%d connects to %d\n", node, par_node);
        }
    }
}

void add_embassies_to_q(queue <Elm>& q, int node, Elm old_elm) {
    if (!add_embassies_to_q_vis[node]) {
        add_embassies_to_q_vis[node] = true;
        unordered_set <int>::iterator it = nodes[node].embassies.begin();
        for (; it != nodes[node].embassies.end(); it++) {
            if (vis0[node].find(nodes[*it].color) == vis0[node].end()) {
                Elm new_elm = old_elm; new_elm.pass = nodes[*it].color; 
                q.push(new_elm);
                vis0[node].insert(nodes[*it].color);
            }
        }
    }
}

int32_t main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);

    int k; cin >> n >> m >> k;
    int sx, sy, ex, ey; cin >> sy >> sx >> ey >> ex; sx--; sy--; ex--; ey--;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) 
            cin >> mp[i][j];
    for (int i = 0; i < k; i++) {
        int x, y, p; cin >> y >> x >> p; x--; y--;
        embass[y][x].push_back(p);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j]) {
                nodes[node_cnt].color = mp[i][j];
                dfs(i, j, node_cnt++);
            }
            // cout << node_mp[i][j] << ' ';
        } // cout << endl;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited2[i][j]) {
                dfs2(i, j);
            }
        }
    }

    int src_node = node_mp[sy][sx], dest_node = node_mp[ey][ex];
    // Special Case: src == dest
    if (src_node == dest_node) {
        cout << "0\n";
        return 0;
    }

    queue <Elm> q;
    // init the queue with the initial node passes
    Elm obj; obj.node = src_node; obj.spent = 0;
    add_embassies_to_q(q, src_node, obj);

    while(!q.empty()) {
        Elm front = q.front(); q.pop();
        // printf("node:%d pass:%d spent:%d\n", front.node, front.pass, front.spent);
        if (front.node == dest_node) {
            cout << front.spent << endl;
            return 0;
        }

        add_embassies_to_q(q, front.node, front);

        unordered_set<int>::iterator it = G[front.node].begin();
        for (; it != G[front.node].end(); it++) {
            Elm new_elm;
            if (nodes[front.node].color == 0) { // adj is NON-ZERO
                if (!vis[*it] && (front.pass == nodes[*it].color || found(front.node, nodes[*it].color))) {
                    vis[*it] = true;

                    new_elm.node = *it; 
                    new_elm.pass = *it; 
                    new_elm.spent = 1+front.spent;
                    q.push(new_elm);
                }
            } else if (nodes[*it].color == 0) { // adj is ZERO
                if (vis0[*it].find(nodes[front.node].color) == vis0[*it].end()) {
                    vis0[*it].insert(nodes[front.node].color);

                    new_elm.node = *it; 
                    new_elm.pass = nodes[front.node].color; 
                    new_elm.spent = front.spent;
                    q.push(new_elm);
                }
            }
        }
    }
    cout << "-1\n";
    return 0;
}