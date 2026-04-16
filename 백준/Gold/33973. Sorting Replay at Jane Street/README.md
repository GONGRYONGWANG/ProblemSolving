# [Gold I] Sorting Replay at Jane Street - 33973 

[문제 링크](https://www.acmicpc.net/problem/33973) 

### 성능 요약

메모리: 50000 KB, 시간: 1116 ms

### 분류

수학, 정렬, 조합론

### 제출 일자

2026년 04월 17일 02:59:42

### 문제 설명

<p style="text-align: center;"><img alt="" src=""></p>

<blockquote>
<p>Electronic exchanges play an important role in the world financial system, acting as focal points where actors from across the world meet to trade with each other.</p>

<p>But building an exchange is a difficult technical challenge, requiring high transaction rates, low, deterministic response times, fairness, and reliability.</p>
</blockquote>

<p>Jane Street의 백테스트 시스템은 과거 거래 기록을 기반으로 전략을 재현하고 검증한다. 백테스트 시스템은 거래 기록을 특정 기준값에 따라 반복해서 정렬한다.</p>

<p>하지만 일부 정렬 알고리즘은 안정 정렬이 아니기 때문에 동일한 입력에 대해서도 정렬 결과가 다를 수 있다. 불안정 정렬은 안정 정렬보다 속도가 빠른 대신 기준값이 같은 원소의 상대 순서를 보장하지 않기 때문이다. 불안정 정렬의 이런 특성은 전략 재현의 일관성을 해치므로, 당신은 이 시스템의 리스크 검증 팀 일원으로서 주어진 정렬 쿼리 시퀀스에 따라 가능한 최종 정렬 결과의 개수를 계산하는 업무를 부여받았다!</p>

<p>길이가 $N$인 배열 $N$개가 주어진다. 각 배열은 과거 거래 기록 하나를 의미한다.</p>

<p>$N$개의 과거 거래 기록을 다음과 같은 정렬 쿼리를 이용해 $Q$번 정렬한다.</p>

<ul>
	<li>$1$ $i$: $N$개의 배열을 직전에 정렬된 상태에서 $i$번째 원소의 값을 기준으로 <strong>불안정 정렬</strong>을 시행한다. $(1 \le i \le N)$</li>
	<li>$2$ $i$: $N$개의 배열을 직전에 정렬된 상태에서 $i$번째 원소의 값을 기준으로 <strong>안정 정렬</strong>을 시행한다. $(1 \le i \le N)$</li>
</ul>

<p>쿼리가 누적해서 수행됨에 유의하여라.</p>

<p>배열의 $i$번째 원소란 배열의 $i$번째 위치(1-based index)에 있는 값을 의미한다. 예를 들어 배열 $[7, 3, 5]$의 $1$번째 값은 $7$이다.</p>

<p>$Q$번의 정렬 이후 가능한 정렬 결과의 개수를 $998 \, 244 \, 353$로 나눈 나머지를 계산해 보자!</p>

<p>단, 입력으로 동일한 배열이 여러 번 등장하더라도 서로 구분되는 배열로 취급한다.</p>

### 입력 

 <p>첫째 줄에 배열의 개수 $N$과 쿼리의 개수 $Q$가 공백으로 구분되어 주어진다. $(1 \le N \le 2 \, 000;$ $1 \le Q \le 2 \, 000)$</p>

<p>둘째 줄부터 $N$개의 줄에 걸쳐 $N$개의 원소를 가진 배열 $N$개가 초기 순서대로 주어진다. 즉, $i+1$번째 줄에 $i$번째 배열 $A_i$의 각 원소 $A_{i,1}$, $A_{i,2}$, $\cdots$, $A_{i,N}$이 공백으로 구분되어 주어진다. $(0 \le A_{i,j} \le 10^6;$ $1 \le j \le N)$</p>

<p>$N+2$번째 줄부터 $Q$개의 줄에 걸쳐 쿼리가 주어진다.</p>

<p>입력으로 주어지는 모든 수는 정수이다.</p>

### 출력 

 <p>가능한 정렬된 결과물의 개수를 $998 \, 244 \, 353$으로 나눈 나머지를 출력한다.</p>

