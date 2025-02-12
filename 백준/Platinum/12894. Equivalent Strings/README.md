# [Platinum III] Equivalent Strings - 12894 

[문제 링크](https://www.acmicpc.net/problem/12894) 

### 성능 요약

메모리: 3236 KB, 시간: 16 ms

### 분류

분할 정복

### 제출 일자

2025년 2월 12일 13:33:40

### 문제 설명

<p>같은 길이를 가진 두 개의 문자열 a, b에 대해 아래 둘 중에 하나에 해당하면 우리는 이를 equivalent하다고 부른다.</p>

<ol>
	<li>두 문자열이 완전히 같다.</li>
	<li>a를 같은 길이의 a1, a2로 나누고, b를 같은 길이의 b1, b2로 나누었을 때 다음 둘 중 하나를 만족한다.
	<ol>
		<li>a1은 b1과 equivalent하고, a2는 b2와 equivalent하다.</li>
		<li>a1은 b2와 equivalent하고, a2는 b1과 equivalent하다.</li>
	</ol>
	</li>
</ol>

<p> 두 문자열 a, b가 주어졌을 때 equivalent한지 판별해보자.</p>

### 입력 

 <p>첫 줄에 문자열 a, 두 번째 줄에 문자열 b가 주어진다. 각 문자열의 길이는 1보다 크거나 같고 200,000보다 작거나 같다. 모든 문자는 26개의 알파벳 소문자로만 이루어 진다. 주어지는 문자열 a, b의 길이는 동일하다.</p>

### 출력 

 <p>a, b가 equivalent하다면 “YES”, 아니라면 “NO”를 출력한다.</p>

