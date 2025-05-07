# [Platinum III] 히히 못가 - 24515 

[문제 링크](https://www.acmicpc.net/problem/24515) 

### 성능 요약

메모리: 394156 KB, 시간: 1188 ms

### 분류

데이크스트라, 그래프 이론, 최단 경로

### 제출 일자

2025년 5월 7일 13:48:59

### 문제 설명

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/a2316711-75e0-4902-a1b7-8f2b203f8704/-/preview/" style="height: 400px; width: 400px;"><br>
 </p>

<p><mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"> <mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-cD7"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="3"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi><mo>×</mo><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N \times N$</span></mjx-container> 격자 모양의 땅에서 로미오는 가장 왼쪽 위 칸, 줄리엣은 가장 오른쪽 아래 칸에 살고 있다. 로미오는 매일 줄리엣을 만나러 가는데, 상하좌우로 인접한 칸으로 이동할 수 있고 땅 밖으로는 나갈 수 없다.</p>

<p>주변을 어슬렁거리던 솔로 부대 상원이는 로미오와 줄리엣의 만남이 마음에 들지 않는다. 수많은 솔로들의 후원으로 돈이 많은 상원이는 로미오와 줄리엣이 만날 수 없도록 주변 땅을 사버리기로 했다.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/658a1f14-0125-4490-891a-2648dbfc5d5b/-/preview/" style="height: 190px; width: 400px;"></p>

<p>땅은 몇 개의 영역으로 구분되어있고 이 영역 단위로만 땅을 살 수 있다. 각 영역의 구분을 위해 격자 칸마다 알파벳 대문자를 적어 놓았는데, 상하좌우로 인접한 두 칸의 알파벳이 같다는 것은 같은 영역에 속한 땅이라는 뜻이다. 어떤 두 칸의 알파벳이 같더라도 연결되어 있지 않다면, 다른 영역에 속할 수 있다.</p>

<p>로미오가 줄리엣을 만나는 것을 막기 위해 상원이가 최소 몇 칸의 땅을 사야 하는지 구해보자.</p>

### 입력 

 <p>첫 번째 줄에 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>이 주어진다. <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mo class="mjx-n"><mjx-c class="mjx-c28"></mjx-c></mjx-mo><mjx-mn class="mjx-n"><mjx-c class="mjx-c32"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="4"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="4"><mjx-c class="mjx-c31"></mjx-c></mjx-mn><mjx-mstyle><mjx-mspace style="width: 0.167em;"></mjx-mspace></mjx-mstyle><mjx-mn class="mjx-n"><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn><mjx-mo class="mjx-n"><mjx-c class="mjx-c29"></mjx-c></mjx-mo></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mo stretchy="false">(</mo><mn>2</mn><mo>≤</mo><mi>N</mi><mo>≤</mo><mn>1</mn><mstyle scriptlevel="0"><mspace width="0.167em"></mspace></mstyle><mn>000</mn><mo stretchy="false">)</mo></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$(2 \le N \le 1\,000)$</span> </mjx-container></p>

<p>두 번째 줄부터 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>개의 줄에 땅의 정보를 나타내는 알파벳 대문자 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>개가 주어진다. 단, 로미오와 줄리엣의 위치는 <span style="color:#e74c3c;"><code>.</code></span>으로 주어진다.</p>

### 출력 

 <p>상원이가 최소 몇 칸의 땅을 사야 하는지 출력한다.</p>

