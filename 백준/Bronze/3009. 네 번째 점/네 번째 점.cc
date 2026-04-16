#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

int main() {
	int a, b;
	vector <int> v1 = { 0 };
	cin >>a >> b;
	v1.push_back(a);
	v1.push_back(b);
	vector <int> v2 = { 0 };
	cin >> a >> b;
	v2.push_back(a);
	v2.push_back(b);
	vector <int> v3 = { 0 };
	cin >> a >> b;
	v3.push_back(a);
	v3.push_back(b);
	vector <int> v4 = { 0 };

	if (v1[1] == v2[1]) { v4.push_back(v3[1]); }
	else if (v1[1] == v3[1]) { v4.push_back(v2[1]); }
	else { v4.push_back(v1[1]); }

	if (v1[2] == v2[2]) { v4.push_back(v3[2]); }
	else if (v1[2] == v3[2]) { v4.push_back(v2[2]); }
	else { v4.push_back(v1[2]); }

	cout << v4[1] << " " << v4[2];
}