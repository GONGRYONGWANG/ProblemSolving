#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int N = 0;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < i; j++)
            cout << " ";

        for (int j = 0; j < 2 * (N - i) - 1; j++)
            cout << "*";

        cout << endl;
    }
    
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < N-i-2; j++)
            cout << " ";

        for (int j = 0; j < 2 * (i+2) - 1; j++)
            cout << "*";

        cout << endl;
    }
}