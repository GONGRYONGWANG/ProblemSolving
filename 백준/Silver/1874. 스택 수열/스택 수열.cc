#include<iostream>
#include<stack>
 
int main() {
    char sol[200050];
    int solptr(0);
    int n, x, max(0);
    std::cin >> n;
 
    std::stack<int> s;
    while (n--) {
        std::cin >> x;
        if (x>max) {
            for (int i = max + 1;i <= x;i++) {
                s.push(i);
                sol[solptr++] = '+';
            }
        }
        else
            if (s.top() != x) {
                std::cout << "NO";
                return 0;
            }
        s.pop();
        sol[solptr++] = '-';
        if (max < x) max = x;
    }
    for (int i = 0;i < solptr;i++) std::cout << sol[i] << "\n";
 
    return 0;
}
