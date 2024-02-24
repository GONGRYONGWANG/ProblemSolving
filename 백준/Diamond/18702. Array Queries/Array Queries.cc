//구현 2. mmap/write 이용
#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <unistd.h>
using namespace std;

/////////////////////////////////////////////////////////////////////////////////////////////
/*
 * Author : jinhan814
 * Date : 2021-05-06
 * Source : https://blog.naver.com/jinhan814/222266396476
 * Description : FastIO implementation for cin, cout. (mmap ver.)
 */
constexpr int SZ = 1 << 20;

class INPUT {
private:
    char* p;
    bool __END_FLAG__, __GETLINE_FLAG__;
public:
    explicit operator bool() { return !__END_FLAG__; }
    INPUT() {
        struct stat st; fstat(0, &st);
        p = (char*)mmap(0, st.st_size, PROT_READ, MAP_SHARED, 0, 0);
    }
    bool IsBlank(char c) { return c == ' ' || c == '\n'; }
    bool IsEnd(char c) { return c == '\0'; }
    char _ReadChar() { return *p++; }
    char ReadChar() {
        char ret = _ReadChar();
        for (; IsBlank(ret); ret = _ReadChar());
        return ret;
    }
    template<typename T> T ReadInt() {
        T ret = 0; char cur = _ReadChar(); bool flag = 0;
        for (; IsBlank(cur); cur = _ReadChar());
        if (cur == '-') flag = 1, cur = _ReadChar();
        for (; !IsBlank(cur) && !IsEnd(cur); cur = _ReadChar()) ret = 10 * ret + (cur & 15);
        if (IsEnd(cur)) __END_FLAG__ = 1;
        return flag ? -ret : ret;
    }
    string ReadString() {
        string ret; char cur = _ReadChar();
        for (; IsBlank(cur); cur = _ReadChar());
        for (; !IsBlank(cur) && !IsEnd(cur); cur = _ReadChar()) ret.push_back(cur);
        if (IsEnd(cur)) __END_FLAG__ = 1;
        return ret;
    }
    double ReadDouble() {
        string ret = ReadString();
        return stod(ret);
    }
    string getline() {
        string ret; char cur = _ReadChar();
        for (; cur != '\n' && !IsEnd(cur); cur = _ReadChar()) ret.push_back(cur);
        if (__GETLINE_FLAG__) __END_FLAG__ = 1;
        if (IsEnd(cur)) __GETLINE_FLAG__ = 1;
        return ret;
    }
    friend INPUT& getline(INPUT& in, string& s) { s = in.getline(); return in; }
} _in;

class OUTPUT {
private:
    char write_buf[SZ];
    int write_idx;
public:
    ~OUTPUT() { Flush(); }
    explicit operator bool() { return 1; }
    void Flush() {
        write(1, write_buf, write_idx);
        write_idx = 0;
    }
    void WriteChar(char c) {
        if (write_idx == SZ) Flush();
        write_buf[write_idx++] = c;
    }
    template<typename T> int GetSize(T n) {
        int ret = 1;
        for (n = n >= 0 ? n : -n; n >= 10; n /= 10) ret++;
        return ret;
    }
    template<typename T> void WriteInt(T n) {
        int sz = GetSize(n);
        if (write_idx + sz >= SZ) Flush();
        if (n < 0) write_buf[write_idx++] = '-', n = -n;
        for (int i = sz; i --> 0; n /= 10) write_buf[write_idx + i] = n % 10 | 48;
        write_idx += sz;
    }
    void WriteString(string s) { for (auto& c : s) WriteChar(c); }
    void WriteDouble(double d) { WriteString(to_string(d)); }
} _out;

/* operators */
INPUT& operator>> (INPUT& in, char& i) { i = in.ReadChar(); return in; }
INPUT& operator>> (INPUT& in, string& i) { i = in.ReadString(); return in; }
template<typename T, typename std::enable_if_t<is_arithmetic_v<T>>* = nullptr>
INPUT& operator>> (INPUT& in, T& i) {
    if constexpr (is_floating_point_v<T>) i = in.ReadDouble();
    else if constexpr (is_integral_v<T>) i = in.ReadInt<T>(); return in; }

OUTPUT& operator<< (OUTPUT& out, char i) { out.WriteChar(i); return out; }
OUTPUT& operator<< (OUTPUT& out, string i) { out.WriteString(i); return out; }
template<typename T, typename std::enable_if_t<is_arithmetic_v<T>>* = nullptr>
OUTPUT& operator<< (OUTPUT& out, T i) {
    if constexpr (is_floating_point_v<T>) out.WriteDouble(i);
    else if constexpr (is_integral_v<T>) out.WriteInt<T>(i); return out; }

/* macros */
#define fastio 1
#define cin _in
#define cout _out
#define istream INPUT
#define ostream OUTPUT
/////////////////////////////////////////////////////////////////////////////////////////////
#pragma warning(disable:4996) 
#include<iostream>
#include<cstdio>
#include<string>
#include<sstream>
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
#include<cstdlib>
#include<ctime>
#include<regex>
#include<random>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef unsigned int uint;
#define pq priority_queue
#define endl "\n"
#define inf 1e9
//int dx[4] = { 1,-1,0,0 };
//int dy[4] = { 0,0,1,-1 };
//int dx[8] = { 1,1,1,-1,-1,-1,0,0 };
//int dy[8] = { 1,0,-1,1,0,-1,1,-1 };

ll INF = (ll)(1 << 63);

struct treeNode {
    treeNode() {}
    treeNode(ll sum, ll mn, ll mx) : sum(sum), mn(mn), mx(mx) {}
    ll sum, mn, mx;
};

int N, M;
ll arr[100001];
treeNode tree[400000];
ll lazy1[400000];
ll lazy2[400000];

treeNode merge(treeNode t1, treeNode t2) {
    return { t1.sum + t2.sum, min(t1.mn, t2.mn), max(t1.mx, t2.mx) };
}


treeNode makeTree(int node, int start, int end) {
    if (start == end) {
        return tree[node] = { arr[start],arr[start],arr[start] };
    }
    else {
        int mid = (start + end) / 2;
        return tree[node] = merge(makeTree(node * 2, start, mid), makeTree(node * 2 + 1, mid + 1, end));
    }
}

void lazyProp(int node, int start, int end) {
    if (lazy2[node] == INF) {
        if (lazy1[node] == 0) return;
        tree[node].mx += lazy1[node];
        tree[node].mn += lazy1[node];
        tree[node].sum += (ll)(end - start + 1) * lazy1[node];
        if (start != end) {
            lazy1[node * 2] += lazy1[node];
            lazy1[node * 2 + 1] += lazy1[node];
        }
    }
    else {
        tree[node].mn = tree[node].mx = lazy1[node] + lazy2[node];
        tree[node].sum = (ll)(end - start + 1) * tree[node].mn;
        if (start != end) {
            lazy1[node * 2] = lazy1[node];
            lazy2[node * 2] = lazy2[node];
            lazy1[node * 2 + 1] = lazy1[node];
            lazy2[node * 2 + 1] = lazy2[node];
        }
    }
    lazy1[node] = 0; lazy2[node] = INF; return;
}

void add(int node, int start, int end, int left, int right, int val) {
    lazyProp(node, start, end);
    if (left > end || right < start) return;
    else if (left <= start && right >= end) {
        lazy1[node] = val;
        lazyProp(node, start, end);
        return;
    }
    else {
        int mid = (start + end) / 2;
        add(node * 2, start, mid, left, right, val);
        add(node * 2 + 1, mid + 1, end, left, right, val);
        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
        return;
    }
}

void sqr(int node, int start, int end, int left, int right) {
    lazyProp(node, start, end);
    if (left > end || right < start) return;
    else if (left <= start && right >= end) {
        if ((int)sqrt(tree[node].mn) == (int)sqrt(tree[node].mx)) {
            lazy2[node] = (int)sqrt(tree[node].mn);
            lazyProp(node, start, end);
            return;
        }
        else if (tree[node].mn + 1 == tree[node].mx) {
            lazy1[node] = (int)sqrt(tree[node].mn) - tree[node].mn;
            lazyProp(node, start, end);
            return;
        }
    }
    int mid = (start + end) / 2;
    sqr(node * 2, start, mid, left, right);
    sqr(node * 2 + 1, mid + 1, end, left, right);
    tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    return;
}

ll getSum(int node, int start, int end, int left, int right) {
    lazyProp(node, start, end);
    if (left > end || right < start) return 0;
    if (left <= start && right >= end)return tree[node].sum;
    int mid = (start + end) / 2;
    return getSum(node * 2, start, mid, left, right) + getSum(node * 2 + 1, mid + 1, end, left, right);
}

void init() {
    cin >> N;
    cin >> M;
    fill(lazy1, lazy1 + 400001, 0);
    fill(lazy2, lazy2 + 400001, INF);
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
}

void solve() {
    init();
    makeTree(1, 1, N);
    int a, l, r;
    ll c;
    while (M--) {
        cin >> a >> l >> r;
        switch (a) {
        case 3:
            cin >> c;
            add(1, 1, N, l, r, c);
            break;
        case 1:
            sqr(1, 1, N, l, r);
            break;
        case 2:
            cout << getSum(1, 1, N, l, r) << endl;
            break;
        }
    }
    return;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}