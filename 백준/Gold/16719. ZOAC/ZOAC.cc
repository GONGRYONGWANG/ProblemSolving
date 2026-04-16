#include <iostream>
#include <vector>
#include <string>
using namespace std;
string input;
vector<char> output;
void ZOAC(int s, int e) {
	char minV = '[';
	int min_i = 0;
	for (int i = s; i < e; i++) {
		if (input[i] < minV) {
			minV = input[i];
			min_i = i;
		}
	}
	output[min_i] = minV;
	for (int i = 0; i < output.size(); i++) {
        if(output[i]!='['){
            cout << output[i];
        }
    }
	cout << '\n';
	if (min_i + 1 != e) ZOAC(min_i + 1, e);
	if (min_i != s) ZOAC(s, min_i);
	return;
}
int main() {
	cin >> input;
	output.resize(input.length(),'[');
	ZOAC(0, input.length());
}