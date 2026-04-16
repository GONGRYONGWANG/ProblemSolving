# [Silver V] 레몬 게임 - 34248 

[문제 링크](https://www.acmicpc.net/problem/34248) 

### 성능 요약

메모리: 2020 KB, 시간: 8 ms

### 분류

그리디 알고리즘

### 제출 일자

2026년 04월 17일 02:59:42

### 문제 설명

<p>우현이는 <strong>레몬 게임</strong>을 즐겨 한다. 이 게임의 규칙은 다음과 같다.</p>

<ol>
<li>처음에 $N$개의 레몬이 일렬로 놓여 있다. $i$번째 레몬에는 $A_i$가 적혀 있다. $A_i$는 $1$ 또는 $2$이다.</li>
<li>연속된 한 개 이상의 레몬 중, 레몬에 적힌 수의 합이 $3$이 되는 구간을 하나 골라 구간에 포함된 모든 레몬을 모두 제거한다.</li>
<li>더 이상 제거할 수 있는 레몬이 없을 때까지 $2$번 과정을 반복한다.</li>
</ol>

<p>아래 그림은 한 예시 과정을 보여준다.</p>

<p style="text-align: center;"><img alt="" src="" style="height: 435px; width: 600px;"></p>

<p>주어진 모든 레몬을 제거할 수 있는지 판별하라.</p>

### 입력 

 <p>입력은 다음과 같은 형식으로 주어진다.</p>

<blockquote>
<p>$N$</p>

<p>$A_1 \ A_2 \ \cdots \ A_N$</p>
</blockquote>

### 출력 

 <p>첫째 줄에 모든 레몬을 제거할 수 있으면 <span style="color:#e74c3c;"><code>Yes</code></span>, 그렇지 않으면 <span style="color:#e74c3c;"><code>No</code></span>를 출력한다.</p>

