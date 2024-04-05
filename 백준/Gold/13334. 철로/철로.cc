//#pragma warning(disable:4996) 
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define inf 1e18


bool compare(pii a, pii b) {
    return a.second < b.second;
}

struct cmp {
    bool operator()(pii a, pii b) {
        return a.first > b.first;
    }
};

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int N;
    cin >> N;
    vector<pii> line;
    int h, o;
    for (int i = 0; i < N; i++) {
        cin >> h >> o;
        if (h > o) {
            swap(h, o);
        }
        line.push_back({ h,o });
    }
    sort(line.begin(), line.end(), compare);

    int d;
    cin >> d;

    int ans = 0;
    priority_queue<pii,vector<pii>,cmp> pq;
    int e = line[0].second; int idx = 1;
    pq.push(line[0]);
    while (1) {
        while (pq.empty() || e - pq.top().first <= d) {
            pq.push(line[idx]);
            e = max(e, line[idx].second);
            idx++;
            if (idx == N) break;
        }
        int size = pq.size();
        if (idx == N) {
            if (e - pq.top().first > d) {
                size -= 1;
            }
            ans = max(ans, size);
            break;
        }
        ans = max(ans, size - 1);
        while (!pq.empty() && e - pq.top().first > d) {
            pq.pop();
        }
    }
    cout << ans;
    return 0;
}
