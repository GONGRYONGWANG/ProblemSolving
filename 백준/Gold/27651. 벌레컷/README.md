# [Gold III] 벌레컷 - 27651 

[문제 링크](https://www.acmicpc.net/problem/27651) 

### 성능 요약

메모리: 9840 KB, 시간: 188 ms

### 분류

이분 탐색, 누적 합, 두 포인터

### 제출 일자

2024년 8월 29일 14:55:28

### 문제 설명

<p style="text-align: center;"><img alt="" src=""></p>

<p>크기 $N$의 $1$차원 양의 정수 배열로 이루어진 자벌레가 있다. 자벌레는 곤충이기 때문에 머리, 가슴, 배로 부위를 구분할 수 있다.</p>

<p>각 부위는 배열상에서 연속하는 구간으로 나타낼 수 있으며 배열상에서 머리는 왼쪽에, 가슴은 가운데에, 배는 오른쪽에 존재한다. 각 부위의 크기는 배열상에서 해당하는 구간의 값의 합으로 정의된다.</p>

<p>무지는 이 자벌레가 가슴이 배보다 크고 배가 머리보다 크다는 사실은 알고 있지만 어느 지점에서 머리 가슴 또한 가슴 배가 구분되는지 알지 못한다. 무지를 도와 구분될 수 있는 경우의 수를 구해주자.</p>

<p>엄밀하게는 다음 조건에 맞는 $X,Y$ 쌍의 개수를 구해주자.</p>

<p>배열에 $i$번째 원소의 값을 $A_{i}$라 할 때 $$ \sum_{i=1}^{X} A_{i} < \sum_{i=Y+1}^{N} A_{i} < \sum_{i=X+1}^{Y} A_{i}\,(1\leq X < Y < N)$$</p>

### 입력 

 <p>첫 줄에 정수 $N$이 주어진다. $\left( 3 \leq N \leq 1\,000\,000\right)$</p>

<p>두 번째 줄에 배열의 값 $A_1, A_2, \cdots, A_N$이 공백으로 구분되어 주어진다. $\left( 1 \leq A_{i} \leq 100\,000\right)$</p>

### 출력 

 <p>자벌레의 머리 가슴 배가 구분될 수 있는 경우의 수를 구해 출력하자.</p>

