#include<iostream>
using namespace std;
#define endl "\n"
//ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

#include<vector>
#include<algorithm>


int n;
int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	cin >> n;
	vector<int> v;
	int tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());
	int p1 = 0;
	int p2 = n - 1;
	
	int x;
	cin >> x;
	int count = 0;
	int sum;
	while (p1 < p2) {
		sum = v[p1] + v[p2];
		if (sum == x) {
			count++; p1++; p2--; 
		}
		else if (sum > x) {
			p2--;
		}
		else {
			p1++;
		}
	}
	cout << count;



	return 0;
}








