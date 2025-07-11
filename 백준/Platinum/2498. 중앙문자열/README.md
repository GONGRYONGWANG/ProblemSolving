# [Platinum III] 중앙문자열 - 2498 

[문제 링크](https://www.acmicpc.net/problem/2498) 

### 성능 요약

메모리: 3424 KB, 시간: 0 ms

### 분류

그리디 알고리즘, 많은 조건 분기

### 제출 일자

2025년 6월 18일 01:43:10

### 문제 설명

<p>문자열에서 교체 연산은 문자열의 한 문자를 다른 문자로 바꾸는 연산이다. 예를 들어, 문자열 “computer”에서 4번째 문자 p를 m으로 교체하면 “commuter”가 된다. </p>

<p>같은 길이의 두 문자열 P와 Q의 거리 d(P,Q)는 P를 Q로 바꾸기 위한 교체 연산의 최소 개수로 정의된다. 예를 들어 P = “computers”, Q = “consumers”라 하면, P에서 3번째 문자 m을 n으로, 4번째 문자 p를 s로, 6번째 문자 t를 m으로 바꾸면 Q가 된다. 따라서 P와 Q 사이의 거리는 3이다. </p>

<p>A, B, C를 같은 길이의 문자열이라 하자. 이때 어떤 문자열 W의 반경 r(W)는 문자열 W와 문자열 A, B, C와의 거리 중 최댓값으로 정의된다. 즉, r(W)= max{ d(W,A), d(W,B), d(W,C) } 이다. 예를 들어, A = “computers”, B = “consumers”, C = “consensus”일 때, X = “consunsrs”라 두면, A, B, C와 X 사이의 거리는 d(X,A) = 4, d(X,B) = 2, d(X,C) = 2이므로, X의 반경 r(X)는 4이다.</p>

<p>문자열 A, B, C의 중앙문자열은 A, B, C와의 반경이 최소가 되는 문자열로 정의된다. 예를 들어, 문자열 A, B, C가 위와 같이 주어졌을 때, Y = “consuners”라 두면, Y의 반경은 3이고, 반경이 2인 문자열은 존재하지 않으므로, Y는 A, B, C의 중앙문자열이 된다.</p>

<p>영어 소문자들로만 구성된 문자열 A, B, C가 주어졌을 때, 이들의 중앙문자열을 구하는 프로그램을 작성하라.</p>

### 입력 

 <p>첫 째 줄에는 문자열 A가 주어진다. 마찬가지로 문자열 B와 C가 각각 둘째 줄과 셋째 줄에 주어진다. 세 문자열의 길이는 동일하고, 그 길이는 1 이상 100,000 이하이다.</p>

### 출력 

 <p>첫 째 줄에 중앙문자열의 반경을 출력하고 둘째 줄에 중앙문자열을 출력한다. 중앙문자열이 여러 개인 경우 하나만 출력한다.</p>

