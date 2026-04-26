# [Platinum V] 푸앙이와 별 - 24396 

[문제 링크](https://www.acmicpc.net/problem/24396) 

### 성능 요약

메모리: 69964 KB, 시간: 344 ms

### 분류

자료 구조, 그래프 이론, 그래프 탐색, 집합과 맵, 너비 우선 탐색, 트리를 사용한 집합과 맵

### 제출 일자

2026년 4월 27일 02:37:15

### 문제 설명

<p>중앙대학교의 자랑스러운 청룡 푸앙이는 자신만의 별을 가지고 있다. <em>N</em>개의 꼭짓점과 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mfrac><mjx-frac><mjx-num><mjx-nstrut></mjx-nstrut><mjx-mrow size="s"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n"><mjx-c class="mjx-c28"></mjx-c></mjx-mo><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n"><mjx-c class="mjx-c2212"></mjx-c></mjx-mo><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c></mjx-mn><mjx-mo class="mjx-n"><mjx-c class="mjx-c29"></mjx-c></mjx-mo></mjx-mrow></mjx-num><mjx-dbox><mjx-dtable><mjx-line></mjx-line><mjx-row><mjx-den><mjx-dstrut></mjx-dstrut><mjx-mn class="mjx-n" size="s"><mjx-c class="mjx-c32"></mjx-c></mjx-mn></mjx-den></mjx-row></mjx-dtable></mjx-dbox></mjx-frac></mjx-mfrac></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mfrac><mrow><mi>N</mi><mo stretchy="false">(</mo><mi>N</mi><mo>−</mo><mn>1</mn><mo stretchy="false">)</mo></mrow><mn>2</mn></mfrac></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$\frac{N(N - 1)}{2}$</span></mjx-container>개의 간선으로 이루어진 별은 무방향 완전 그래프이기 때문에 아름다운 모양을 띤다.</p>

<p>푸앙이는 모든 꼭짓점 간의 거리가 1이라는 사실에 매료되었다. 그러나 푸앙이를 싫어하는 명진이는 푸앙이의 별의 간선들 중 몇 개를 잘라버렸다. 푸앙이는 좌절했지만, 새로운 별에도 매력을 느끼기 위해 꼭짓점 간의 거리를 계산하기로 했다. 푸앙이를 도와 꼭짓점 간의 거리를 계산해주자!</p>

### 입력 

 <p>첫째 줄에 별을 이루는 꼭짓점의 개수 <em>N</em>(2 ≤ <em>N</em> ≤ 300,000)과 명진이가 간선을 자르는 연산을 수행한 횟수 <em>M</em>(1 ≤ <em>M</em> ≤ 300,000)이 주어진다.</p>

<p>이후 <em>M</em>개의 줄에 걸쳐 정수 <em>A<sub>i</sub></em>와 <em>B<sub>i</sub></em>(1 ≤ <em>A<sub>i</sub></em>, <em>B<sub>i</sub></em> ≤ <em>N</em>, <em>A<sub>i</sub></em> ≠ <em>B<sub>i</sub></em>)가 주어지며, 다음과 같은 의미를 가진다.</p>

<ul>
	<li><em>A<sub>i</sub></em>번과 <em>B<sub>i</sub></em>번 꼭짓점을 잇는 간선을 자른다. 그런 간선이 이미 잘려 있다면 무시한다.</li>
</ul>

### 출력 

 <p>첫째 줄부터 <em>N</em>개의 줄에 걸쳐, <em>i</em>번 줄엔 1번 정점으로부터 <em>i</em>번 정점까지의 최단 거리를 출력한다. 경로가 존재하지 않는 경우에는 -1을 출력한다.</p>

