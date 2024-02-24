#include<iostream>
#include<vector>
#include <algorithm>
#define endl "\n"
using namespace std;

int n;
vector<int> v;
vector<pair<double,double>> Max;

int MAX(int idx, int type) {

	if (idx == n) {
		return 0;
	}


	if (type == 0) {  // idx included
		if(Max[idx].first==0.5){
			Max[idx].first = v[idx] + max(MAX(idx + 1, 0), 0);
		}
		return Max[idx].first;
	}
	else if(type == 1) { // idx not included
		if (Max[idx].second == 0.5) {
			Max[idx].second = max(MAX(idx + 1, 0), MAX(idx + 1, 1));
		}
		return Max[idx].second;
	}

}
int main() {
	cin >> n;

	int tmp;
	pair <double, double > p;
	p.first = 0.5;
	p.second = 0.5;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		v.push_back(tmp);
		Max.push_back(p);
	}
	int result = max(MAX(0, 0), MAX(0, 1));
	if (result == 0) {
		result = v[0];
		for (int i = 0; i < n; i++) {
			if (v[i] > result) { result = v[i]; }
		}
	}
	cout << result;
}