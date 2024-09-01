// template: https://github.com/GONGRYONGWANG/ProblemSolving/blob/main/template.txt
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<string>
#include<vector>
#include<utility>
#include<list>
#include<queue>
#include<stack>
#include<deque>
#include<set>
#include<unordered_set>
#include<map>
#include<unordered_map>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<cstdlib>
#include<ctime> // srand(time(0))
#include<regex> // 정규표현식
#include<random> // rand
#include<complex> // complex number
#include<numeric>
#include<cassert>
#include <climits>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef complex<double> cpx;
#define pq priority_queue
#define endl "\n"
const ll INF = 1e18 + 7;
const int inf = 1e9 + 7;
const long double pi = 3.14159265358979323846;
const string debug = "output: ";


struct VectorHasher { // unordered_set<vector<int>,VectorHasher>
    size_t operator()(const vector<int>& V) const {
        size_t hash = V.size();
        for (auto& i : V) {
            hash ^= i + 0x9e3779b9 + (hash << 6) + (hash >> 2);
        }
        return hash;
    }
};
struct PiiHasher { // unordered_set<pii, PiiHasher>
    size_t operator()(const pii& x) const {
        return hash<long long>()(((long long)x.first) ^ (((long long)x.second) << 32));
    }
};


ll gcd(ll a, ll b) {
    if (a < b) swap(a, b);
    while (b != 0) {
        ll  n = a % b;
        a = b;
        b = n;
    }
    return a;
}
ll lcm(ll a, ll b) {
    ll g = gcd(a, b);
    return a / g * b;
}
ll xgcd(ll a, ll b) {
    ll r1 = a; ll r2 = b;
    ll s1 = 1; ll s2 = 0;
    ll t1 = 0; ll t2 = 1;
    while (1) {
        ll q = r1 / r2;
        ll r = r1 - q * r2;
        ll s = s1 - q * s2;
        ll t = t1 - q * t2;
        if (r == 0) return s2;
        r1 = r2; r2 = r;
        s1 = s2; s2 = s;
        t1 = t2; t2 = t;
    }
}


ll powmod(ll x, ll n, ll mod) {
    if (n == 0) return 1;
    if (n % 2) return x * powmod(x, n - 1, mod) % mod;
    ll half = powmod(x, n / 2, mod);
    return half * half % mod;
}

ll modinv(ll x, ll mod) { // when mod is primenum
    return powmod(x, mod - 2, mod);
}

//const ll Fsize = 1;
//ll F[Fsize];
ll factorial(ll x) {
    ll ret = 1;
    //ret = F[x]; //
    return ret;
}

//ll modI[Fsize];  ll modIF[Fsize];
ll modinvfactorial(ll x) {
    ll ret = 1;
    //ret = modIF[x]; //
    return ret;
}

ll combination(ll n, ll r, ll mod) {
    if (r == 0 || n == r) return 1;
    return factorial(n) * modinvfactorial(n - r) % mod * modinvfactorial(r) % mod;
}


ll ccw(pll a, pll b, pll c) {
    ll ret = (b.first - a.first) * (c.second - a.second) - (c.first - a.first) * (b.second - a.second);
    if (ret > 0) return 1;
    else if (ret == 0) return 0;
    else return -1;
}

bool intersect(pll A, pll B, pll C, pll D) { // 선분 교차 판정 A-B , C-D
    if (A > B) swap(A, B);
    if (C > D) swap(C, D);

    ll l1 = ccw(A, B, C) * ccw(A, B, D);
    ll l2 = ccw(C, D, A) * ccw(C, D, B);

    if (l1 == 0 && l2 == 0) {
        return A <= D && C <= B;
    }
    return l1 <= 0 && l2 <= 0;
}


struct MF { // Dinic O(V^2*E)
    struct Edge {
        int to, rev;
        long long flow, cap;
        Edge(int to, int rev, long long cap) : to(to), rev(rev), flow(0), cap(cap) {}
    };

    int n;
    vector<vector<Edge>> adj; // get이후 edge vector를 이용해서 trace, cap<=flow인 간선은 continue하며 bfs.
    vector<int> level, ptr;

    MF(int n) : n(n), adj(n), level(n), ptr(n) {}

    void addEdge(int u, int v, long long cap, bool directed = true) {
        if (cap == 0) return;
        adj[u].emplace_back(v, adj[v].size(), cap);
        if(!directed) adj[v].emplace_back(u, adj[u].size() - 1, cap);
        else adj[v].emplace_back(u, adj[u].size() - 1, 0); 
    }

    bool bfs(int source, int sink) {
        fill(level.begin(), level.end(), -1);
        level[source] = 0;
        queue<int> q;
        q.push(source);

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (Edge& e : adj[node]) {
                if (level[e.to] == -1 && e.flow < e.cap) { // 잔여 용량이 있는 간선을 찾음
                    level[e.to] = level[node] + 1;
                    q.push(e.to);
                }
            }
        }
        return level[sink] != -1;
    }

    long long dfs(int node, int sink, long long pushed) {
        if (pushed == 0) return 0;
        if (node == sink) return pushed;

        for (int& cid = ptr[node]; cid < adj[node].size(); cid++) {
            Edge& e = adj[node][cid];
            if (level[e.to] != level[node] + 1 || e.flow == e.cap) continue;

            long long tr = dfs(e.to, sink, min(pushed, e.cap - e.flow));
            if (tr == 0) continue;

            e.flow += tr;
            adj[e.to][e.rev].flow -= tr;
            return tr;
        }
        return 0;
    }

    long long get(int source, int sink) {
        long long flow = 0;
        while (bfs(source, sink)) {
            fill(ptr.begin(), ptr.end(), 0);
            while (long long pushed = dfs(source, sink, LLONG_MAX)) {
                flow += pushed;
            }
        }
        return flow;
    }

};
struct MCMF { // SPFA O(VEf) - Practically Ef
    struct Edge {
        int to, rev;
        long long cap, flow, cost;
        Edge(int to, int rev, long long cap, long long cost) : to(to), rev(rev), cap(cap), flow(0), cost(cost) {}
    };

    int n;
    vector<vector<Edge>> adj;
    vector<long long> dist;
    vector<int> parent, parentEdge;
    vector<bool> inQueue;
    int source, sink;

    MCMF(int n) : n(n), adj(n), dist(n), parent(n), parentEdge(n), inQueue(n), source(-1), sink(-1) {}

    void setSource(int s) {
        source = s;
    }

    void setSink(int t) {
        sink = t;
    }

    void addEdge(int u, int v, long long cap, long long cost, bool directed = true) {
        if (cap == 0) return;
        adj[u].emplace_back(v, adj[v].size(), cap, cost);
        adj[v].emplace_back(u, adj[u].size() - 1, 0, -cost); // 역방향 간선
        if (!directed) {
            adj[v].emplace_back(u, adj[u].size(), cap, cost);
            adj[u].emplace_back(v, adj[v].size() - 1, 0, -cost);
        }
    }

    bool spfa() {
        fill(dist.begin(), dist.end(), LLONG_MAX);
        fill(inQueue.begin(), inQueue.end(), false);
        queue<int> q;
        dist[source] = 0;
        inQueue[source] = true;
        q.push(source);

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            inQueue[u] = false;

            for (int i = 0; i < adj[u].size(); ++i) {
                Edge& e = adj[u][i];
                if (e.flow < e.cap && dist[u] + e.cost < dist[e.to]) {
                    dist[e.to] = dist[u] + e.cost;
                    parent[e.to] = u;
                    parentEdge[e.to] = i;

                    if (!inQueue[e.to]) {
                        inQueue[e.to] = true;
                        q.push(e.to);
                    }
                }
            }
        }

        return dist[sink] != LLONG_MAX;
    }

    pair<long long, long long> get(int _source = -1, int _sink = -1) {
        if (_source != -1) {
            setSource(_source);
            setSink(_sink);
        }
        long long maxFlow = 0, minCost = 0;

        while (spfa()) {
            long long flow = LLONG_MAX;

            for (int u = sink; u != source; u = parent[u]) {
                Edge& e = adj[parent[u]][parentEdge[u]];
                flow = min(flow, e.cap - e.flow);
            }

            for (int u = sink; u != source; u = parent[u]) {
                Edge& e = adj[parent[u]][parentEdge[u]];
                e.flow += flow;
                adj[u][e.rev].flow -= flow;
                minCost += flow * e.cost;
            }

            maxFlow += flow;
        }

        return { maxFlow, minCost };
    }
};
struct BiMatch { // Hopcroft-Karp O(E*sqrtV)
    int n, m; // n: left side vertices, m: right side vertices
    vector<vector<int>> adj; // adjacency list
    vector<int> pairU, pairV, dist;
    // pairU 또는 pairV를 출력해서 매칭 결과를 print 가능.

    BiMatch(int n, int m) : n(n), m(m), adj(n + 1), pairU(n + 1), pairV(m + 1), dist(n + 1) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    bool bfs() {
        queue<int> q;
        for (int u = 1; u <= n; u++) {
            if (pairU[u] == 0) { // If u is free (not matched)
                dist[u] = 0;
                q.push(u);
            }
            else {
                dist[u] = INT_MAX;
            }
        }

        dist[0] = INT_MAX;
        while (!q.empty()) {
            int u = q.front();
            q.pop();

            if (dist[u] < dist[0]) {
                for (int v : adj[u]) {
                    if (dist[pairV[v]] == INT_MAX) { // If pairV[v] is not yet visited
                        dist[pairV[v]] = dist[u] + 1;
                        q.push(pairV[v]);
                    }
                }
            }
        }

        return dist[0] != INT_MAX; // If there's an augmenting path
    }

    bool dfs(int u) {
        if (u != 0) {
            for (int v : adj[u]) {
                if (dist[pairV[v]] == dist[u] + 1 && dfs(pairV[v])) {
                    pairV[v] = u;
                    pairU[u] = v;
                    return true;
                }
            }
            dist[u] = INT_MAX;
            return false;
        }
        return true;
    }

    int get() {
        fill(pairU.begin(), pairU.end(), 0);
        fill(pairV.begin(), pairV.end(), 0);
        int matching = 0;

        while (bfs()) {
            for (int u = 1; u <= n; u++) {
                if (pairU[u] == 0 && dfs(u)) {
                    matching++;
                }
            }
        }

        return matching;
    }

};
struct Hungarian { // O(N^3)
    int n;  // 문제의 크기 (n x n 행렬)
    vector<vector<long long>> cost;  // 비용 행렬
    vector<long long> u, v;  // 레이블 
    vector<int> p, way;// 경로 추적
    vector<int> matchResult;   // 최종 매칭 결과 (작업자 -> 작업)

    Hungarian(int n) : n(n), cost(n, vector<long long>(n, 0)), u(n + 1, 0), v(n + 1, 0), p(n + 1, 0), way(n + 1, 0), matchResult(n, -1) {}

    void addEdge(int i, int j, long long weight) {
        cost[i][j] = weight;
    }

    long long get() {
        for (int i = 1; i <= n; i++) {
            vector<long long> minv(n + 1, LLONG_MAX);
            vector<bool> used(n + 1, false);
            int j0 = 0;
            p[0] = i;

            do {
                used[j0] = true;
                int i0 = p[j0];
                long long delta = LLONG_MAX;
                int j1;

                for (int j = 1; j <= n; j++) {
                    if (!used[j]) {
                        long long cur = cost[i0 - 1][j - 1] - u[i0] - v[j];
                        if (cur < minv[j]) {
                            minv[j] = cur;
                            way[j] = j0;
                        }
                        if (minv[j] < delta) {
                            delta = minv[j];
                            j1 = j;
                        }
                    }
                }

                for (int j = 0; j <= n; j++) {
                    if (used[j]) {
                        u[p[j]] += delta;
                        v[j] -= delta;
                    }
                    else {
                        minv[j] -= delta;
                    }
                }

                j0 = j1;
            } while (p[j0] != 0);

            do {
                int j1 = way[j0];
                p[j0] = p[j1];
                j0 = j1;
            } while (j0 != 0);
        }

        // 매칭 결과 저장
        for (int j = 1; j <= n; j++) {
            matchResult[p[j] - 1] = j - 1;
        }

        return -v[0];  // 최저 비용 반환
    }

    void trace() {
        for (int i = 0; i < n; i++) {
            cout << i + 1 << " " << matchResult[i] + 1 << endl;
        }
    }

};
struct GeneralMatch { // Micali-Vazirani O(E*sqrt(V)*(log*V)). reference: https://github.com/ggawryal/MV-matching/tree/main

    GeneralMatch(int n) : n(n), adj(n) {}

    void addEdge(int a, int b, bool directed = false) {
        adj[a].push_back(Edge(b, (int)adj[b].size()));
        if (!directed) {
            adj[b].push_back(Edge(a, (int)adj[a].size() - 1));
        }
    }

    //disjoint set union data structure
    struct DSU {
        vector<int> link;
        vector<int> directParent;
        vector<int> size;
        vector<int> groupRoot;


        void reset(int n) {
            link = vector<int>(n);
            size = vector<int>(n, 1);
            iota(link.begin(), link.end(), 0);
            groupRoot = link;
            directParent = vector<int>(n, -1);
        }

        int find(int a) {
            return link[a] = (a == link[a] ? a : find(link[a]));
        }

        int operator[](const int& a) {
            return groupRoot[find(a)];
        }

        void linkTo(int a, int b) {
            assert(directParent[a] == -1);
            assert(directParent[b] == -1);
            directParent[a] = b;
            a = find(a);
            b = find(b);
            int gr = groupRoot[b];
            assert(a != b);

            if (size[a] > size[b])
                swap(a, b);
            link[b] = a;
            size[a] += size[b];
            groupRoot[a] = gr;
        }

    };

    enum EdgeType { NotScanned, Prop, Bridge };
    struct Edge {
        int to;
        int other;
        EdgeType type;
        Edge(int _to, int _other, EdgeType _type = NotScanned) : to(_to), other(_other), type(_type) {}
    };

    int n; //IN: nuber of vertices
    vector<vector<Edge> > adj; //IN: graph as neighbours list
    vector<int> mate; //OUT: vertex which is matched with given, or -1 is unmatched

    vector<vector<int> > predecessors;
    vector<int> ddfsPredecessorsPtr;
    vector<int> removed;
    vector<int> evenlvl, oddlvl;
    DSU bud;

    int globalColorCounter; //resets to 1 after each iteration
//colors for bridges are numbered (2,3), (4,5), (6,7) ...
//to check if vertices belong to same petal check if color1/2 == color2/2
//color^1 is the other color for single ddfs run

    vector<int> color;
    vector<vector<pair<int, int> > > childsInDDFSTree; //{x, bud[x] at the moment when ddfs started}; may also contain other color vertices which previously were its childs 
    vector<pair<pii, pii> > myBridge; // bridge, bud[bridge]


    int minlvl(int u) { return min(evenlvl[u], oddlvl[u]); }

    int tenacity(pii edge) {
        if (mate[edge.first] == edge.second)
            return oddlvl[edge.first] + oddlvl[edge.second] + 1;
        return evenlvl[edge.first] + evenlvl[edge.second] + 1;
    }

    /*
    tries to move color1 down, updating colors, stacks and childs in ddfs tree
    also adds each visited vertex to support of this bridge
    */
    int ddfsMove(vector<int>& stack1, const int color1, vector<int>& stack2, const int color2, vector<int>& support) {
        int u = stack1.back();
        for (; ddfsPredecessorsPtr[u] < predecessors[u].size(); ddfsPredecessorsPtr[u]++) {
            int a = predecessors[u][ddfsPredecessorsPtr[u]];
            int v = bud[a];
            assert(removed[a] == removed[v]);
            if (removed[a])
                continue;
            if (color[v] == 0) {
                stack1.push_back(v);
                support.push_back(v);
                childsInDDFSTree[u].push_back({ a,v });
                color[v] = color1;
                return -1;
            }
            else if (v == stack2.back())
                childsInDDFSTree[u].push_back({ a,v });
        }
        stack1.pop_back();

        if (stack1.size() == 0) {
            if (stack2.size() == 1) { //found bottleneck
                color[stack2.back()] = 0;
                return stack2.back();
            }
            //change colors
            assert(color[stack2.back()] == color2);
            stack1.push_back(stack2.back());
            color[stack1.back()] = color1;
            stack2.pop_back();
        }
        return -1;
    }


    //returns {r0, g0} or {bottleneck, bottleneck}
    pair<int, int > ddfs(pii e, vector<int>& out_support) {
        vector<int> Sr = { bud[e.first] }, Sg = { bud[e.second] };
        if (Sr[0] == Sg[0])
            return { Sr[0],Sg[0] };

        out_support = { Sr[0], Sg[0] };
        int newRed = color[Sr[0]] = ++globalColorCounter, newGreen = color[Sg[0]] = ++globalColorCounter;
        assert(newRed == (newGreen ^ 1));

        for (;;) {
            //if found two disjoint paths
            if (minlvl(Sr.back()) == 0 && minlvl(Sg.back()) == 0)
                return { Sr.back(),Sg.back() };

            int b;
            if (minlvl(Sr.back()) >= minlvl(Sg.back()))
                b = ddfsMove(Sr, newRed, Sg, newGreen, out_support);
            else
                b = ddfsMove(Sg, newGreen, Sr, newRed, out_support);
            if (b != -1)
                return { b,b };
        }
    }

    queue<int> removedVerticesQueue;

    void removeAndPushToQueue(int u) { removed[u] = 1; removedVerticesQueue.push(u); }

    void flip(int u, int v) {
        if (removed[u] || removed[v] || mate[u] == v) return;//flipping only unmatched edges
        removeAndPushToQueue(u);
        removeAndPushToQueue(v);
        mate[u] = v;
        mate[v] = u;
    }

    bool openingDfs(int cur, int bcur, int b) {
        if (bcur == b) {
            augumentPath(cur, bcur);
            return true;
        }
        for (auto a : childsInDDFSTree[bcur]) {
            if ((a.second == b || color[a.second] == color[bcur]) && openingDfs(a.first, a.second, b)) {
                augumentPath(cur, bcur);
                flip(bcur, a.first);
                return true;
            }
        }
        return false;
    }

    void augumentPath(int u, int v, bool initial = false) {
        if (u == v) return;
        if (!initial && minlvl(u) == evenlvl[u]) { //simply follow predecessors
            assert(predecessors[u].size() == 1); //u should be evenlevel (last minlevel edge is matched, so there is only one predecessor)
            int x = predecessors[u][0]; //no need to flip edge since we know it's matched

            int idx = 0;
            while (bud[predecessors[x][idx]] != bud[x]) {
                idx++;
                assert(idx < (int)predecessors[x].size());
            }
            u = predecessors[x][idx];
            assert(!removed[u]);
            flip(x, u);
            augumentPath(u, v);
        }
        else { //through bridge
            auto u3 = myBridge[u].first.first, v3 = myBridge[u].first.second, u2 = myBridge[u].second.first, v2 = myBridge[u].second.second;
            if ((color[u2] ^ 1) == color[u] || color[v2] == color[u]) {
                swap(u2, v2);
                swap(u3, v3);
            }

            flip(u3, v3);
            bool openingDfsSucceed1 = openingDfs(u3, u2, u);
            assert(openingDfsSucceed1);

            int v4 = bud.directParent[u];
            bool openingDfsSucceed2 = openingDfs(v3, v2, v4);
            assert(openingDfsSucceed2);
            augumentPath(v4, v);
        }
    }

    bool bfs() {
        vector<vector<int> > verticesAtLevel(n);
        vector<vector<pii> > bridges(2 * n + 2);
        vector<int> removedPredecessorsSize(n);

        auto setLvl = [&](int u, int lev) {
            if (lev & 1) oddlvl[u] = lev; else evenlvl[u] = lev;
            verticesAtLevel[lev].push_back(u);
        };

        for (int u = 0; u < n; u++)
            if (mate[u] == -1)
                setLvl(u, 0);

        bool foundPath = false;
        for (int i = 0; i < n && !foundPath; i++) {
            for (auto u : verticesAtLevel[i]) {
                for (auto& e : adj[u]) {
                    if (e.type == NotScanned && (oddlvl[u] == i) == (mate[u] == e.to)) {
                        if (minlvl(e.to) >= i + 1) {
                            e.type = Prop;
                            adj[e.to][e.other].type = Prop;

                            if (minlvl(e.to) > i + 1)
                                setLvl(e.to, i + 1);
                            predecessors[e.to].push_back(u);
                        }
                        else {
                            e.type = Bridge;
                            adj[e.to][e.other].type = Bridge;
                            if (tenacity({ u,e.to }) < inf) {
                                bridges[tenacity({ u,e.to })].push_back({ u,e.to });
                            }
                        }
                    }
                }
            }

            for (auto b : bridges[2 * i + 1]) {
                if (removed[bud[b.first]] || removed[bud[b.second]])
                    continue;
                vector<int> support;
                auto ddfsResult = ddfs(b, support);
                pair<pii, pii> curBridge = { b,{bud[b.first], bud[b.second]} };
                /*even when we found two disjoint paths, we create fake petal, with bud in the end of second path
                the support of this bridge will be these two pathes and some other vertices, which have bases on this paths, so we will remove them and this will not affect corectness
                using this trick, we can simply call augumentPath on these two ends - the first end is just above fake bud, so it will augument exactly the path we need
                the only problem is that some vertices in this support will be uncorrectly classified as inner/outer, so we need to pass initial=true flag to fix this case*/
                for (auto v : support) {
                    if (v == ddfsResult.second) continue; //skip bud
                    myBridge[v] = curBridge;
                    bud.linkTo(v, ddfsResult.second);

                    //this part of code is only needed when bottleneck found, but it doesn't mess up anything when called on two paths 
                    setLvl(v, 2 * i + 1 - minlvl(v));
                    for (auto f : adj[v])
                        if (evenlvl[v] > oddlvl[v] && f.type == Bridge && tenacity({ v,f.to }) < inf && mate[v] != f.to)
                            bridges[tenacity({ v,f.to })].push_back({ v,f.to });
                }

                if (ddfsResult.first != ddfsResult.second) {
                    augumentPath(ddfsResult.first, ddfsResult.second, true);
                    foundPath = true;
                    while (!removedVerticesQueue.empty()) {
                        int v = removedVerticesQueue.front();
                        removedVerticesQueue.pop();
                        for (auto e : adj[v])
                            if (e.type == Prop && minlvl(e.to) > minlvl(v) && !removed[e.to] && ++removedPredecessorsSize[e.to] == predecessors[e.to].size())
                                removeAndPushToQueue(e.to);
                    }
                }
            }
        }
        return foundPath;
    }

    //just for testing purposes
    void checkGraph() {
        for (int i = 0; i < n; i++)
            assert(mate[i] == -1 || mate[mate[i]] == i);
    }


    int mvMatching() {
        mate = vector<int>(n, -1);
        do {
            for (auto& a : adj)
                for (auto& e : a)
                    e.type = NotScanned;

            predecessors = vector<vector<int> >(n);
            ddfsPredecessorsPtr = color = removed = vector<int>(n);
            evenlvl = oddlvl = vector<int>(n, inf);
            childsInDDFSTree = vector<vector<pii> >(n);
            globalColorCounter = 1;
            bud.reset(n);
            myBridge = vector<pair<pii, pii> >(n);
        } while (bfs());
        checkGraph(); // debuging
        return maxMatching();
    }

    int maxMatching() {
        return (n - count(mate.begin(), mate.end(), -1)) / 2;
    }

    void trace() {
        //mate이용
        return;
    }


};

struct TwoSat { // for SCC and TwoSat.
    int n;
    vector<vector<int>> g, gr; // gr is the reversed graph
    vector<int> scc_id, topological_order, answer; // scc_id[v]: ID of the SCC containing node v
    vector<bool> visited;

    TwoSat() {}

    TwoSat(int _n) { init(_n); }

    void init(int _n) {
        n = _n;
        g.assign(2 * n, vector<int>());
        gr.assign(2 * n, vector<int>());
        scc_id.resize(2 * n);
        visited.resize(2 * n);
        answer.resize(2 * n);
    }

    // Can be used conveniently for SCC tasks by using the edge function only. The drawback is double memory usage.
    void add_edge(int u, int v) { 
        g[u].push_back(v);
        gr[v].push_back(u);
    }

    // For the following three functions
    // int x, bool val: if 'val' is true, we take the variable to be x. Otherwise we take it to be x's complement.

    // At least one of them is true
    void add_clause_or(int i, int j, bool f = true, bool g = true) {
        if (i < 0) f = !f;
        if (j < 0) g = !g;
        i = abs(i); j = abs(j);
        add_edge(i + (f ? n : 0), j + (g ? 0 : n));
        add_edge(j + (g ? n : 0), i + (f ? 0 : n));
    }

    // Only one of them is true
    void add_clause_xor(int i, int j, bool f = true, bool g = true) {
        if (i < 0) f = !f;
        if (j < 0) g = !g;
        i = abs(i); j = abs(j);
        add_clause_or(i, f, j, g);
        add_clause_or(i, !f, j, !g);
    }

    // Both of them have the same value
    void add_clause_and(int i, int j, bool f = true, bool g = true) {
        if (i < 0) f = !f;
        if (j < 0) g = !g;
        i = abs(i); j = abs(j);
        add_clause_xor(i, !f, j, g);
    }

    // Topological sort
    void dfs(int u) {
        visited[u] = true;

        for (const auto& v : g[u])
            if (!visited[v]) dfs(v);

        topological_order.push_back(u);
    }

    // Extracting strongly connected components
    void scc(int u, int id) {
        visited[u] = true;
        scc_id[u] = id;

        for (const auto& v : gr[u])
            if (!visited[v]) scc(v, id);
    }

    // Returns true if the given proposition is satisfiable and constructs a valid assignment
    bool satisfiable() {
        fill(visited.begin(), visited.end(), false);

        for (int i = 0; i < 2 * n; i++)
            if (!visited[i]) dfs(i);

        fill(visited.begin(), visited.end(), false);
        reverse(topological_order.begin(), topological_order.end());

        int id = 0;
        for (const auto& v : topological_order)
            if (!visited[v]) scc(v, id++);

        // Constructing the answer
        for (int i = 0; i < n; i++) {
            if (scc_id[i] == scc_id[i + n]) return false;
            answer[i] = (scc_id[i] > scc_id[i + n] ? 1 : 0);
        }

        return true;
    }
};

//int dx[4] = { -1,0,1,0 }; 
//int dy[4] = { 0,-1,0,1 };
//int dx[8] = { -1,-1,-1,0,0,1,1,1 };
//int dy[8] = { -1,0,1,-1,1,-1,0,1 };

/////////////////////////////////////////////////////////////////////////////////////

int arr[10];
vector<int> E[10];

void solve() {
    int N;
    cin >> N;
    int total = 0;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        total += arr[i];
    }

    for (int i = 0; i < N; i++) {
        int k;
        cin >> k;
        while (k--) {
            int x;
            cin >> x;
            x -= 1;
            E[i].push_back(x);
        }
    }

    int ans = inf;

    for (int i = 1; i < (1 << N); i++) {
        if (!(i & 1)) continue;
        vector<bool> visited(N, false);
        queue<int> q;
        q.push(0);
        int ret = 0;
        visited[0] = true;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            ret += arr[cur];
            for (int nx : E[cur]) {
                if (!(i & (1 << nx))) continue;
                if (visited[nx]) continue;
                q.push(nx);
                visited[nx] = true;
            }
        }
        int x = -1;
        for (int j = 0; j < N; j++) {
            if (!(i & (1 << j))) x = j;
        }

        if (x != -1) {
            q.push(x);
            visited[x] = true;
            while (!q.empty()) {
                int cur = q.front();
                q.pop();
                for (int nx : E[cur]) {
                    if (i & (1 << nx)) continue;
                    if (visited[nx]) continue;
                    q.push(nx);
                    visited[nx] = true;
                }
            }
        }

        bool b = true;
        for (int j = 0; j < N; j++) {
            if (!visited[j]) b = false;
        }
        if (b) ans = min(ans, abs(total - 2 * ret));
    }

    if (ans == inf) cout << -1;
    else cout << ans;




}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 1;
    //cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
