#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector <int> A;
    vector <int> B;
    int N,M,K;
    
    cin >> N>>M;
    
    int tmp;
    for (int i=0;i <N*M;i++){
        cin >> tmp;
        A.push_back(tmp);
    }
    cin >> M >> K;
    for(int i=0;i<M*K;i++){
        cin>>tmp;
        B.push_back(tmp);
    }
    for(int i=0; i<N;i++){
        for(int j=0;j<K;j++){
            tmp=0;
            for(int k=0;k<M;k++){
                tmp+=A[M*i+k]*B[K*k+j];
            }
            printf("%d ",tmp);
        }
        cout<<endl;
    }
    return 0;
}