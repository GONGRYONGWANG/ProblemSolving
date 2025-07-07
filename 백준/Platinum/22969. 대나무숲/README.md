# [Platinum IV] 대나무숲 - 22969 

[문제 링크](https://www.acmicpc.net/problem/22969) 

### 성능 요약

메모리: 18328 KB, 시간: 64 ms

### 분류

많은 조건 분기, 그래프 이론, 그래프 탐색, 구현, 트리

### 제출 일자

2025년 7월 7일 21:46:42

### 문제 설명

<p>정휘는 대나무를 다음과 같이 정의했다. (실제 Graph Theory에서 사용하는 용어인 Bamboo Tree와는 차이가 있다.)</p>

<ul>
	<li>대나무는 트리의 한 종류이다.</li>
	<li>가운데 길이가 3 이상인(3개 이상의 간선으로 구성된) 기둥이 있다.</li>
	<li>기둥에 속한 정점에서 양쪽으로 정점이 뻗어있을 수 있다.</li>
	<li>이때 기둥에 속한 정점에서 1개 혹은 3개 이상의 정점이 뻗어나갈 수 없다. (0개 혹은 2개만 가능하다.)</li>
	<li>모든 정점은 기둥과의 거리가 1 이하가 되어야 한다.</li>
</ul>

<p>대나무숲이란, 대나무로만 구성된 포레스트를 의미한다.</p>

<p>그래프가 주어지면 대나무숲인지 확인해보자.</p>

<p> </p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/61d21898-e5b6-464d-a7a8-dc4bf32fd097/-/preview/" style="height: 558px; width: 1000px;"></p>

<p>예제 2는 2번 정점에서 1개의 정점만 뻗어나갔기 때문에 대나무숲이 아니다.</p>

<p>예제 4는 2번 정점에서 3개의 정점이 뻗어나갔기 때문에 대나무숲이 아니다.</p>

<p>예제 5는 3번 정점에서 뻗어나간 정점 중 기둥과 거리가 2 이상인 정점이 있기 때문에 대나무숲이 아니다.</p>

<p>예제 6은 길이가 3 이상인 기둥이 존재하지 않기 때문에 대나무숲이 아니다.</p>

<p>예제 8은 포레스트가 아니다.</p>

### 입력 

 <p>첫째 줄에 정점의 개수와 간선의 개수를 의미하는 정수 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n"><mjx-c class="mjx-c2C"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="2"><mjx-c class="mjx-c1D440 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi><mo>,</mo><mi>M</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N, M$</span></mjx-container>이 공백으로 구분되어 주어진다.</p>

<p>둘째 줄부터 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D440 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>M</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$M$</span></mjx-container>개의 줄에 걸쳐, 각 간선이 연결하는 두 정점 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D462 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n"><mjx-c class="mjx-c2C"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="2"><mjx-c class="mjx-c1D463 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>u</mi><mo>,</mo><mi>v</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$u, v$</span></mjx-container>가 공백으로 구분되어 주어진다.</p>

### 출력 

 <p>입력으로 주어진 그래프가 대나무숲이라면 <code>TAK</code>, 대나무숲이 아니라면 <code>NIE</code>를 출력한다.</p>

