# [Platinum III] 구슬 옮기기 - 32349 

[문제 링크](https://www.acmicpc.net/problem/32349) 

### 성능 요약

메모리: 3388 KB, 시간: 288 ms

### 분류

이분 매칭

### 제출 일자

2024년 9월 22일 15:52:46

### 문제 설명

<p>한서는 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D43B TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>H</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$H$</span></mjx-container>행 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D44A TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>W</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$W$</span></mjx-container>열의 구슬 보드판을 가지고 있다. 이 보드판의 각 칸에는 구슬이 올려져 있을 수 있으며, 구슬이 놓인 칸은 <span style="color:#e74c3c;"><code>1</code></span>로, 비어 있는 칸은 <span style="color:#e74c3c;"><code>0</code></span>으로 표시된다. 보드판의 초기 상태가 주어지면, 한서는 구슬을 적당히 옮겨서 원하는 모양을 만들려고 한다. 대신 한서는 구슬을 옮기는 것이 매우 귀찮기 때문에 가능한 최소한의 움직임으로 옮기려고 한다.</p>

<p>한서가 구슬을 한 번 움직일 때 다음 세 가지 행동 중 하나를 할 수 있다.</p>

<ol>
	<li>구슬을 상하좌우 4방향으로 인접한 빈 칸으로 옮긴다. 단, 구슬을 보드판의 바깥으로는 옮길 수 없다.</li>
	<li>원하는 칸에 있는 구슬을 제거하여 저장한다. 구슬을 저장할 수 있는 개수에는 제한이 없으며, 완성한 시점에서는 저장한 구슬이 없어야 한다.</li>
	<li>저장한 구슬 중 하나를 원하는 빈 칸에 놓는다.</li>
</ol>

<p>한서가 원하는 모양을 완성할 수 없다면 <span style="color:#e74c3c;"><code>-1</code></span>을 출력하고, 완성할 수 있다면 최소한으로 구슬을 움직인 횟수를 출력하라.</p>

### 입력 

 <p>첫 번째 줄에 보드판의 가로 길이 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D44A TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>W</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$W$</span></mjx-container>와 세로 길이 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D43B TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>H</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$H$</span></mjx-container>가 주어진다. <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mo class="mjx-n"><mjx-c class="mjx-c28"></mjx-c></mjx-mo><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="4"><mjx-c class="mjx-c1D44A TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n"><mjx-c class="mjx-c2C"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="2"><mjx-c class="mjx-c1D43B TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="4"><mjx-c class="mjx-c31"></mjx-c><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn><mjx-mo class="mjx-n"><mjx-c class="mjx-c29"></mjx-c></mjx-mo></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mo stretchy="false">(</mo><mn>1</mn><mo>≤</mo><mi>W</mi><mo>,</mo><mi>H</mi><mo>≤</mo><mn>100</mn><mo stretchy="false">)</mo></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$(1 ≤ W, H ≤ 100)$</span></mjx-container> </p>

<p>두 번째 줄부터 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D43B TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>H</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$H$</span></mjx-container>개의 줄에 걸쳐 구슬 보드판의 초기 상태가 주어진다. 각 칸은 <span style="color:#e74c3c;"><code>0</code></span>(빈 칸) 또는 <span style="color:#e74c3c;"><code>1</code></span>(구슬이 있는 칸)로 이루어져 있다.</p>

<p><mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"> <mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D43B TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-c2B"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="3"><mjx-c class="mjx-c32"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>H</mi><mo>+</mo><mn>2</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$H+2$</span></mjx-container> 번째 줄부터 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D43B TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>H</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$H$</span></mjx-container>개의 줄에 걸쳐 한서가 만들고 싶어 하는 모양이 주어진다. 각 칸은 <span style="color:#e74c3c;"><code>0</code></span>(구슬이 없어야 하는 칸) 또는 <span style="color:#e74c3c;"><code>1</code></span>(구슬이 있어야 하는 칸)으로 이루어져 있다.</p>

### 출력 

 <p>한서가 원하는 모양을 완성할 수 있는 최소한의 구슬 움직임 횟수를 출력한다.</p>

<p>만약 원하는 모양을 완성하는 것이 불가능하다면, <span style="color:#e74c3c;"><code>-1</code></span>을 출력한다.</p>

