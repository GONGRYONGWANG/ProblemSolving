# [Gold V] MEXMEX - 35413 

[문제 링크](https://www.acmicpc.net/problem/35413) 

### 성능 요약

메모리: 2028 KB, 시간: 16 ms

### 분류

애드 혹, 해 구성하기, 많은 조건 분기

### 제출 일자

2026년 4월 8일 23:32:42

### 문제 설명

<p>$\textrm{MEX}$는 집합에 포함되지 않은 가장 작은 음이 아닌 정수를 찾는 함수이다. 예를 들어 $\textrm{MEX}(\{0,1,3,4\})=2$이고, $\textrm{MEX}(\{1,2,4\})=0$이다.</p>

<p>ibasic은 길이가 $N$이고 음이 아닌 정수로 구성된 수열 $A$에 대해 $\textrm{MEXMEX}$ 함수를 다음과 같이 정의하였다. $$\textrm{MEXMEX}(A)=\textrm{MEX}(\{\textrm{MEX}(\{A_l,A_{l+1},\dots,A_r\})\mid 1\le l\le r\le N\})$$</p>

<p>즉, $\textrm{MEXMEX}(A)$는 수열 $A$의 모든 연속 부분수열에 대해, 각 부분수열의 모든 원소로 구성된 집합의 $\textrm{MEX}$ 함수를 취한 값을 구하고, 그 값들의 집합에 대해 다시 $\textrm{MEX}$ 함수를 취한 값이다.</p>

<p>ibasic을 위해 $\textrm{MEXMEX}(A)=K$가 되는 길이가 $N$인 수열 $A$를 구해주자.</p>

### 입력 

 <p>첫 번째 줄에 두 정수 $N$, $K$가 공백으로 구분되어 주어진다. $(1\le N\le 2\times 10^5;$ $0\le K\le N+1)$</p>

### 출력 

 <p>첫 번째 줄에 조건을 만족하는 수열 $A_1, A_2, \dots, A_N$을 공백으로 구분하여 출력한다. $(0\le A_i\le 2^{31}-1)$</p>

<p>단, 조건을 만족하는 수열이 존재하지 않는다면 <span style="color:#e74c3c;"><code>-1</code></span>을 대신 출력한다. 가능한 수열이 여러 가지라면 그중 아무거나 하나를 출력한다.</p>

