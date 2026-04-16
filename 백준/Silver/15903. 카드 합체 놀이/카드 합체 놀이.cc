#include<iostream>
using namespace std;
#define endl "\n"
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

#include<queue>
struct cmp {
    bool operator()(long long a, long long b){
        return a>b;
    }
};
priority_queue<long long,vector<long long>, cmp > Q;
int n, m;
int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin >> n >> m;
    long long x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        Q.push(x);
    }
    long long num1, num2;
    for (int i = 0; i < m; i++) {
        num1 = Q.top();
        Q.pop();
        num2 = Q.top();
        Q.pop();
        Q.push(num1 + num2);
        Q.push(num1 + num2);
    }
    long long total = 0;
    while(!Q.empty()) {
        total += Q.top();
        Q.pop();
    }
    cout << total;
    return 0;
}