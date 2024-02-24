#include<iostream>
using namespace std;
#define endl "\n"
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define INF 1e9
#include<vector>
#include<algorithm>
#include<utility>
#include<queue>
int N, K;
struct cmp1 {
    bool operator()(pair<int, int> a, pair<int, int> b) {
        return a.first > b.first;
    }
};
struct cmp2 {
    bool operator()(pair<int, int> a, pair<int, int> b) {
        return a.second < b.second;
    }
};
priority_queue<pair<int, int>, vector<pair<int, int>>, cmp1> jew;
priority_queue<pair<int, int>, vector<pair<int, int>>, cmp2> Q;

vector<int> bags;
int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

    cin >> N >> K;

    int weight, value;
    for (int i = 0; i < N; i++) {
        cin >> weight >> value;
        jew.push({ weight,value });
    }

    int c;
    for (int i = 0; i < K; i++) {
        cin >> c;
        bags.push_back(c);
    }

    sort(bags.begin(), bags.end());
    long long total = 0;
    for (int i = 0; i < K; i++) {
        int capacity = bags[i];
        while (!jew.empty() && jew.top().first <= capacity) {
            Q.push(jew.top());
            jew.pop();
        }
        if (Q.empty()) {
            continue;
        }
        total += Q.top().second;
        Q.pop();
    }
    cout << total;
    return 0;
}
