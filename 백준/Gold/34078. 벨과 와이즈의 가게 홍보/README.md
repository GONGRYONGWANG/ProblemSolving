# [Gold III] 벨과 와이즈의 가게 홍보 - 34078 

[문제 링크](https://www.acmicpc.net/problem/34078) 

### 성능 요약

메모리: 2952 KB, 시간: 20 ms

### 분류

그리디 알고리즘, 정렬, 순열 사이클 분할

### 제출 일자

2026년 04월 17일 02:59:42

### 문제 설명

<blockquote>
<p><strong><em>웅나웅나? 웅 웅나나?</em></strong></p>

<p>    — 웅나송 (CV: 이새아)</p>
</blockquote>

<p>벨과 와이즈는 Random Play라는 비디오 가게를 운영하는 <strong>아무런 비밀도 없는 아주 평범한 시민</strong>이다. 어느 날, 벨과 와이즈는 가게 홍보를 위하여 $N$ 마리의 Bangboo들이 일렬로 서있는 홍보사진을 찍으려고 한다. $i$번째 Bangboo의 키는 $a_i$로 표현되며, <strong>모든 $a_i$는 $1$ 이상 $N$ 이하의 서로 다른 정수이다.</strong></p>

<p>와이즈는 Bangboo들을 줄 세우고 사진을 찍으려고 하는데, 문제가 생겼다. $N$ 마리의 Bangboo들은 전부 수줍은 성격을 가지고 있어 남들보다 튀는 것을 싫어한다! Bangboo들은 자신이 튀지 않고 있다고 생각할 때, 기분이 <span style="color:#e74c3c;"><strong>웅나</strong></span>해진다. 튀고 있는 Bangboo는 다음과 같은 조건에 의해 결정된다.</p>

<ul>
	<li>$2 \leq i \leq N-1$을 만족하는 정수 $i$에 대하여, $i-1$, $i+1$번째 Bangboo 중 하나는 $i$번째 Bangboo보다 키가 크고, 다른 하나는 $i$번째 Bangboo보다 키가 작다면, $i$번째 Bangboo는 튀지 않는다. 그 이외의 경우, $i$번째 Bangboo는 튄다.</li>
	<li>$1$번째, $N$번째 Bangboo는 항상 튄다.</li>
</ul>

<p>벨은 $1$초마다 서로 다른 두 Bangboo의 위치를 맞바꿀 수 있다. 벨은 Bangboo들의 위치를 적절하게 바꾸어, Bangboo들이 최대한 <strong><span style="color:#e74c3c;">웅나</span></strong>하게 만들고 싶다. 또한, 사진을 최대한 빨리 찍기 위해 Bangboo들의 위치를 맞바꾸는 횟수를 최소화하려고 한다.</p>

<p>벨이 원하는 만큼 Bangboo들의 위치를 바꾸었을 때, <span style="color:#e74c3c;"><strong>웅나</strong></span>한 Bangboo들의 수의 최댓값과 최대한 많은 Bangboo들이 <span style="color:#e74c3c;"><strong>웅나</strong></span>해질 때까지 걸리는 최소 시간을 계산하라.</p>

### 입력 

 <p>첫 번째 줄에 Bangboo들의 수 $N$이 주어진다. ($3 \leq N \leq 200 \, 000$)</p>

<p>두 번째 줄에, Bangboo들의 키 $a_1, \cdots, a_N$이 주어진다. 모든 $a_i$는 서로 다르며 $1$ 이상 $N$ 이하의 정수이다.</p>

### 출력 

 <p><span style="color:#e74c3c;"><strong>웅나</strong></span>해질 수 있는 Bangboo들의 최대 수와, 최대한 많은 Bangboo가 <span style="color:#e74c3c;"><strong>웅나</strong></span>해질 때까지 걸리는 최소 시간(초)을 공백으로 구분하여 출력한다.</p>

