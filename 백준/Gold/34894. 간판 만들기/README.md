# [Gold V] 간판 만들기 - 34894 

[문제 링크](https://www.acmicpc.net/problem/34894) 

### 성능 요약

메모리: 5000 KB, 시간: 40 ms

### 분류

다이나믹 프로그래밍

### 제출 일자

2025년 12월 7일 13:47:58

### 문제 설명

<p>UOSPC를 홍보하기 위해, 로비에 LED 문자 모듈을 일렬로 이어 붙인 전광판을 설치했다. 전광판의 모듈은 왼쪽부터 순서대로 총 $N$개이며, $i$번째 모듈이 표시할 수 있는 문자는 $S_i$이며 $S_i$는 <span style="color:#e74c3c;"><code>U</code></span>, <span style="color:#e74c3c;"><code>O</code></span>, <span style="color:#e74c3c;"><code>S</code></span>, <span style="color:#e74c3c;"><code>P</code></span>, <span style="color:#e74c3c;"><code>C</code></span> 중 하나이다.</p>

<p>이 중 일부 모듈만 켜서 <span style="color:#e74c3c;"><code>UOSPC</code></span> 문구를 만들 것이다. 이때 모듈의 순서는 바꿀 수 없으며 $i$번째 모듈을 킬 때 $a_i$만큼의 비용이 든다. </p>

<p>UOSPC를 표시하기 위한 총 비용의 최솟값을 구해보자. 구체적으로, $S_{i_1}=$<span style="color:#e74c3c;"><code>U</code></span>, $ S_{i_2}=$<span style="color:#e74c3c;"><code>O</code></span>, $S_{i_3}=$<span style="color:#e74c3c;"><code>S</code></span>, $S_{i_4}=$<span style="color:#e74c3c;"><code>P</code></span>, $S_{i_5}=$<span style="color:#e74c3c;"><code>C</code></span>, $1\leq i_1<i_2<i_3<i_4<i_5 \leq N$인 $i_1, i_2, i_3, i_4, i_5$에 대해 $a_{i_1}+a_{i_2}+a_{i_3}+a_{i_4}+a_{i_5}$의 최솟값을 구하는것과 같다. 만들 수 없다면 <span style="color:#e74c3c;"><code>-1</code></span>을 출력한다.</p>

### 입력 

 <p>첫째 줄에 정수 $N$이 주어진다. $(5\leq N \leq 300\,000)$</p>

<p>둘째 줄에 <span style="color:#e74c3c;"><code>U</code></span>, <span style="color:#e74c3c;"><code>O</code></span>, <span style="color:#e74c3c;"><code>S</code></span>, <span style="color:#e74c3c;"><code>P</code></span>, <span style="color:#e74c3c;"><code>C</code></span>로만 이뤄진 문자열 $S$가 주어진다. $(|S|=N)$</p>

<p>셋째 줄에 $a_1, a_2, \cdots , a_N$가 공백으로 구분되어 주어진다. $(1\leq a_i \leq 10^9)$</p>

### 출력 

 <p>첫째 줄에 비용의 최솟값을 출력한다. 만약 문구를 만드는 것이 불가능하다면 <span style="color:#e74c3c;"><code>-1</code></span>을 출력한다.</p>

