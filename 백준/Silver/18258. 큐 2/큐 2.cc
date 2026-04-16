#include<iostream>
using namespace std;
#define endl "\n"

#include<cstring>

template <typename T>
class queue {
private:
public:
	T arr[2000000]; 
	int _size = 0;
	int _front = 0;

	void push(int x) {
		arr[_front+_size] = x;
		_size++;
		return;
	}
	T pop() {
		if (_size == 0) { return -1; }
		auto tmp = arr[_front];
		_size--;
		_front++;
		return tmp;
	}	
	int size() {
		return _size;
	}
	bool empty() {
		if (_size == 0) {
			return 1;
		}
		return 0;
	}
	T front() {
		if (_size == 0) { return -1; }
		return arr[_front];
	}
	T back() {
		if (_size == 0) { return -1; }
		else return arr[_front + _size - 1];
	}

};

int main(){
	queue<int> Q;
    int n;
    scanf("%d\n",&n);
    for(int i=0;i<n;i++){
        char a[11];
        scanf("%s",a);
        if(!strcmp(a,"push")){
            int x;
            scanf("%d",&x);
            Q.push(x);
        }
        else if(!strcmp(a,"pop")){
                printf("%d\n",Q.pop());
        }
        else if(!strcmp(a,"size")){
                printf("%d\n",Q.size());
        }
        else if(!strcmp(a,"empty")){
                printf("%d\n",Q.empty());
        }
        else if(!strcmp(a,"front")){
                printf("%d\n",Q.front());
        }
        else if(!strcmp(a,"back")){
                printf("%d\n",Q.back());
        }
    }
}
