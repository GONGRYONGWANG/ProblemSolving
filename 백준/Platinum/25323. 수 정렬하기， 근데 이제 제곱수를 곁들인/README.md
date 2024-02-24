# [Platinum V] 수 정렬하기, 근데 이제 제곱수를 곁들인 - 25323 

[문제 링크](https://www.acmicpc.net/problem/25323) 

### 성능 요약

메모리: 10164 KB, 시간: 344 ms

### 분류

애드 혹, 수학, 정수론, 정렬

### 제출 일자

2022년 7월 26일 21:34:51

### 문제 설명

<p>양의 정수로 이루어진 길이가 $N$ 인 수열 $A_1,A_2,\cdots ,A_N$이 존재할 때, 다음 행동을 원하는 만큼 반복할 수 있다.</p>

<p style="text-align:center;">$1\leq i,j\leq N;i\neq j$이면서 $A_i\times A_j$가 제곱수인 $i$, $j$를 선택해, $A_i$와 $A_j$의 값을 바꾼다.</p>

<p>위 행동을 원하는 만큼 반복하여 수열 $A_1,A_2,\cdots ,A_N$을 비내림차순, 즉 $A_1\le A_2\le\cdots\le A_N$가 되도록 정렬할 수 있는지 판단하시오.</p>

### 입력 

 <p>첫 번째 줄에 $N$이 주어진다. $(1\leq N\leq 500\, 000)$</p>

<p>두 번째 줄에 정수 $A_1,A_2,\cdots ,A_N$이 공백으로 구분되어 주어진다. $(1\leq A_i\leq 10^{18})$</p>

### 출력 

 <p>위 행동을 원하는 만큼 반복하여 수열을 비내림차순으로 정렬할 수 있으면 <span style="color:#e74c3c;"><code>YES</code></span>, 아니면 <span style="color:#e74c3c;"><code>NO</code></span>를 출력하시오.</p>

