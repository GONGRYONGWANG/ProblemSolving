# [Platinum IV] 클-린드롬 부분 문자열 - 33968 

[문제 링크](https://www.acmicpc.net/problem/33968) 

### 성능 요약

메모리: 72672 KB, 시간: 672 ms

### 분류

문자열, 해싱, 매내처

### 제출 일자

2025년 5월 22일 19:53:12

### 문제 설명

<p>팰린드롬 문자열들을 열심히 관찰하던 지훈이는 팰린드롬 문자열이 너무 더럽다고 생각하였고, 이름부터 훨씬 깨끗한 클-린드롬 문자열을 다음과 같이 정의하였다.</p>

<ul>
	<li>어떤 문자열 $T$를 길이가 $K$인 연속된 문자열 조각들로 남김없이 나눌 수 있고, 이들 조각들을 순서대로 나열한 배열이 팰린드롬이면, $T$를 $K$-린드롬이라고 한다.</li>
</ul>

<p>예를 들어, 문자열 <code><span style="color:#e74c3c;">abcdxycdab</span></code>는 <code><span style="color:#e74c3c;">ab</span></code>, <code><span style="color:#e74c3c;">cd</span></code>, <code><span style="color:#e74c3c;">xy</span></code>, <code><span style="color:#e74c3c;">cd</span></code>, <code><span style="color:#e74c3c;">ab</span></code>와 같이 길이가 $2$인 문자열 조각들로 나눌 수 있고, 이 조각들의 배열이 팰린드롬이 되므로 <code><span style="color:#e74c3c;">abcdxycdab</span></code>는 $2$-린드롬이다.</p>

<p>이때 배열 $A[1\cdots N]$가 팰린드롬이라는 것은, $1 \le i \le N$인 모든 $i$에 대해 $A[i]=A[N+1-i]$를 만족하는 것을 의미한다.</p>

<p>문자열 $S$가 주어질 때, 각 $K$에 대해 $S$의 비어 있지 않은 부분 문자열 중 $K$-린드롬인 것의 개수를 구해보자!</p>

### 입력 

 <p>첫째 줄에 문자열 $S$의 길이를 나타내는 정수 $N$이 주어진다. $(1 \le N \le 3\,000)$</p>

<p>둘째 줄에 알파벳 소문자들로 이루어진 문자열 $S$가 주어진다.</p>

### 출력 

 <p>$1 \le K \le N$인 각 $K$에 대해, $K$번째 줄에 $S$의 비어 있지 않은 부분 문자열 중 $K$-린드롬인 것의 개수를 출력한다.</p>

