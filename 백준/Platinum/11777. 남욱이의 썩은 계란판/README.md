# [Platinum II] 남욱이의 썩은 계란판 - 11777 

[문제 링크](https://www.acmicpc.net/problem/11777) 

### 성능 요약

메모리: 33420 KB, 시간: 904 ms

### 분류

그래프 이론, 최대 유량, 최소 비용 최대 유량

### 제출 일자

2025년 7월 9일 21:57:19

### 문제 설명

<p>남욱이는 계란을 N ×N크기의 계란판에 담아 판다. 신선도를 생명으로 여기는 남욱이는 각 계란을 썩음의 정도를 나타내는 썩음도로 표시한다. (썩음도가 클수록 더 썩은 계란이다.) 하지만 남욱이는 최근 열애를 하는 나머지 계란들이 방치돼 썩어버렸다. 남욱이는 어쩔 수 없이 K개의 가림판으로 썩은 계란들을 다음과 같은 규칙으로 가려서 계란판의 썩음도 합을 낮추려한다.</p>

<ul>
	<li>각 가림판은 가로 혹은 세로로 인접한 두 계란을 가린다.</li>
	<li>가림판은 겹쳐질 수는 없지만, 닿을 수는 있다.</li>
	<li>모든 가려지지않은 계란들의 썩음도가 최소가 되도록 해야한다.</li>
</ul>

<p>남욱이에게 규칙을 만족하면서 보이는 모든 계란의 썩음도 합을 얼만큼 낮출 수 있는지 알려주자.</p>

### 입력 

 <p>첫째 줄에는 계란판의 크기 N (1 ≤ N ≤ 2,000)와 가림판의 개수 K (1 ≤ K ≤ 8) 이 주어지며, 둘째 줄 부터 N + 1줄까지 각 줄마다 N개의 각 계란의 썩음도 F ( 0 ≤ F ≤ 1,000)가 주어진다.</p>

### 출력 

 <p>첫째 줄에 규칙을 만족하도록 보이는 모든 계란의 썩음도 합의 최솟값을 출력한다.</p>

