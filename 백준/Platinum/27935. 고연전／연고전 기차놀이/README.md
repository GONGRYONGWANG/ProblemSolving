# [Platinum III] 고연전/연고전 기차놀이 - 27935 

[문제 링크](https://www.acmicpc.net/problem/27935) 

### 성능 요약

메모리: 9096 KB, 시간: 20 ms

### 분류

자료 구조, 덱, 덱을 이용한 구간 최댓값 트릭, 다이나믹 프로그래밍, 덱을 이용한 다이나믹 프로그래밍, 누적 합

### 제출 일자

2025년 8월 19일 18:56:02

### 문제 설명

<p>고려대학교와 연세대학교의 정기전인 고연전이 끝난 뒤 참살이길에 고려대와 연세대 학생들이 총 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>명 모였다. 참살이길은 좁기 때문에 이들은 일렬로 서 있으며, 이들의 배열은 고려대생은 <span style="color:#e74c3c;"><code>K</code></span>, 연세대생은 <span style="color:#e74c3c;"><code>Y</code></span>로 표현된 길이 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>의 문자열로 주어진다.</p>

<p>이들은 고연전 뒷풀이의 주요 행사 중 하나인 “기차놀이”를 위해 몇 개의 연속된 기차로 나뉘어야 한다. "기차"란 연속한 학생들을 모아 놓은 것으로, 전체 행렬을 몇 개의 기차로 분할할 것이다.뒷풀이는 고려대와 연세대 학생의 친목을 위한 행사이므로, 양교의 활발한 교류를 위해 각 기차에는 고려대 학생들과 연세대 학생들의 숫자가 최대 1명까지 차이 나도록 기차를 나누도록 한다.</p>

<p>그런데 기차가 너무 많으면 이동이 어려울 수 있으므로 전체 행렬을 최소 개수의 기차로 나누려고 한다. 또한 한 기차의 길이가 너무 길면 참살이길의 교통이 혼잡해질 수 있으므로 각 기차의 길이는 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D43F TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>L</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$L$</span></mjx-container>을 넘지 않도록 하려고 한다.</p>

<p>이때 고려대와 연세대 학생들의 일렬 배치가 주어질 때, 위 조건을 만족하면서 전체 행렬을 나눌 수 있는 최소 기차 수를 구하시오.</p>

### 입력 

 <p>첫 줄에 기차 행렬의 사람 수 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>, 각 기차의 최대 길이 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D43F TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>L</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$L$</span></mjx-container>이 공백으로 구분되어 주어진다.</p>

<p>두 번째 줄에는 기차 행렬이 길이 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>의 문자열로 주어진다. 이때 <span style="color:#e74c3c;"><code>K</code></span>는 고려대생을, <span style="color:#e74c3c;"><code>Y</code></span>는 연세대생을 의미한다.</p>

### 출력 

 <p>각 기차의 길이가 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D43F TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>L</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$L$</span></mjx-container>을 넘지 않으면서 전체 기차 행렬을 분할할 수 있는 최소 기차 수를 출력한다.</p>

