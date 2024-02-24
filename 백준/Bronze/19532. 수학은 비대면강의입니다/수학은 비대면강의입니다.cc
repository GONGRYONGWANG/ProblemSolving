#include<iostream>
using namespace std;
#define endl "\n"
#define INF 1e9
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
/*
ax+by = c
dx+ ey = f

adx + bdy = cd
adx + aey = af

(bd-ae)y =cd-af


*/
int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	int a, b, c, d, e, f, x, y;
	cin >> a >> b >> c >> d >> e >> f;
	y = (c * d - a * f) / (b * d - a * e);
	if (a == 0) {
		x = (f - e * y) / d;
	}
	else {
		x = (c - b * y) / a;
	}
	cout << x << " " << y;


	return 0;
}

