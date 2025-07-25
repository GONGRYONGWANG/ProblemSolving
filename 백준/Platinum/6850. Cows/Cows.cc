// template: https://github.com/GONGRYONGWANG/ProblemSolving/blob/main/template.txt
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<string>
#include<cctype>
#include<vector>
#include<array>
#include<utility>
#include<list>
#include<queue>
#include<stack>
#include<deque>
#include<tuple>
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
#include <immintrin.h> // AVX, AVX2, AVX-512 // #pragma GCC optimize ("O3,unroll-loops") //#pragma GCC target ("avx,avx2,fma")
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef complex<double> cpx;
typedef long double ld;
#define pq priority_queue
#define endl "\n"
#define INF ll(4e18)
const int inf = 1e9 + 7;
const long double pi = 3.14159265358979323846;
const string debug = "output: ";
#define all(x) (x).begin(), (x).end()
#include<fstream>
ifstream fin; ofstream fout;

//int dx[4] = { -1,0,1,0 }; 
//int dy[4] = { 0,-1,0,1 }; 
//int dx[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////
int ccw(const pair<int, int>& p1, const pair<int, int>& p2, const pair<int, int>& p3) { // CCW (Counter Clockwise) 판별 함수
    long long cross = 1LL * (p2.first - p1.first) * (p3.second - p1.second) -
        1LL * (p2.second - p1.second) * (p3.first - p1.first);
    return (cross > 0) - (cross < 0); // 1: CCW, -1: CW, 0: Collinear
}

vector<pair<int, int>> convexHull(vector<pair<int, int>> points) { // 컨벡스 헐 계산 함수
    if (points.size() <= 2) return points; // 점이 2개 이하인 경우 그대로 반환

    // 좌표를 x 기준, 같으면 y 기준으로 정렬
    sort(points.begin(), points.end());

    vector<pair<int, int>> lower, upper;

    // 아래쪽 헐 계산
    for (const auto& point : points) {
        while (lower.size() >= 2 && ccw(lower[lower.size() - 2], lower[lower.size() - 1], point) <= 0) {
            lower.pop_back();
        }
        lower.push_back(point);
    }

    // 위쪽 헐 계산
    for (auto it = points.rbegin(); it != points.rend(); ++it) {
        while (upper.size() >= 2 && ccw(upper[upper.size() - 2], upper[upper.size() - 1], *it) <= 0) {
            upper.pop_back();
        }
        upper.push_back(*it);
    }

    // 마지막 점이 중복되므로 제거
    lower.pop_back();
    upper.pop_back();

    // 아래쪽과 위쪽을 합쳐 시계 방향으로 반환
    lower.insert(lower.end(), upper.begin(), upper.end());
    return lower;
}

long long doubledPolygonArea(const vector<pair<int, int>>& polygon) {
    long long area2 = 0;
    int n = polygon.size();
    for (int i = 0; i < n; ++i) {
        const auto& [x1, y1] = polygon[i];
        const auto& [x2, y2] = polygon[(i + 1) % n];
        area2 += 1LL * x1 * y2 - 1LL * x2 * y1;
    }
    return abs(area2); // 실제 넓이의 2배
}
///////////////////////////////////////////////////////////////


void solve(int tc) {
    
    int N;
    cin >> N;

    vector<pii> arr(N);
    for (int i = 0; i < N; i++) cin >> arr[i].first >> arr[i].second;

    cout << doubledPolygonArea(convexHull(arr)) / 100;



}
    


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 1;
    //cin >> T;
    //fin.open("input.txt"); fout.open("output.txt");
    for (int tc = 1; tc <= T; tc++) {
        solve(tc);
    }

    return 0;
}