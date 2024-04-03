#include <vector>
#include<algorithm>
using namespace std;
int kth(std::vector<int> &a, int k) {
    random_shuffle(a.begin(),a.end());
	nth_element(a.begin(),a.begin()+k-1,a.end());
	return a[k-1];
}
