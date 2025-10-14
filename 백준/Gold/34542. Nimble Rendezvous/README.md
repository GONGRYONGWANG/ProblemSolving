# [Gold II] Nimble Rendezvous - 34542 

[문제 링크](https://www.acmicpc.net/problem/34542) 

### 성능 요약

메모리: 2020 KB, 시간: 4 ms

### 분류

수학

### 제출 일자

2025년 10월 14일 22:38:27

### 문제 설명

<p>수직선 위에 서로 다른 위치에 있는 두 점이 있다. 두 점은 아래 규칙에 따라 이동한다.</p>

<ul>
<li>단위 시간마다 두 점은 각각 왼쪽 또는 오른쪽 중 한 곳으로 이동한다. 서로 같은 방향으로 이동할 수도 있고, 다른 방향으로 이동할 수도 있음에 유의하자.</li>
<li>두 점의 처음 이동 거리는 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>1</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$1$</span></mjx-container>이고, 이동한 뒤 다음 이동 거리는 현재 이동 거리의 두 배가 된다.</li>
<li>이동 중간에 멈추거나 방향을 바꿀 수는 없다.</li>
</ul>

<p>두 점이 이동을 마친 후, 같은 위치에 있다면 두 점이 만났다고 하자. 두 점의 시작 위치가 주어질 때 두 점이 만나기 위한 최소 이동 횟수와 최소 이동 횟수로 만나는 최종 위치의 개수를 구해보자.</p>

### 입력 

 <p>첫째 줄에 두 점의 최초 위치를 나타내는 정수 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D434 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>A</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$A$</span></mjx-container>, <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D435 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>B</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$B$</span></mjx-container>가 공백으로 구분되어 주어진다. <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mo class="mjx-n"><mjx-c class="mjx-c28"></mjx-c></mjx-mo><mjx-mo class="mjx-n"><mjx-c class="mjx-c2212"></mjx-c></mjx-mo><mjx-msup><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn><mjx-script style="vertical-align: 0.393em;"><mjx-mn class="mjx-n" size="s"><mjx-c class="mjx-c39"></mjx-c></mjx-mn></mjx-script></mjx-msup><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="4"><mjx-c class="mjx-c1D434 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n"><mjx-c class="mjx-c2C"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="2"><mjx-c class="mjx-c1D435 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-msup space="4"><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn><mjx-script style="vertical-align: 0.393em;"><mjx-mn class="mjx-n" size="s"><mjx-c class="mjx-c39"></mjx-c></mjx-mn></mjx-script></mjx-msup><mjx-mo class="mjx-n"><mjx-c class="mjx-c2C"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="2"><mjx-c class="mjx-c1D434 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2260"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="4"><mjx-c class="mjx-c1D435 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n"><mjx-c class="mjx-c29"></mjx-c></mjx-mo></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mo stretchy="false">(</mo><mo>−</mo><msup><mn>10</mn><mn>9</mn></msup><mo>≤</mo><mi>A</mi><mo>,</mo><mi>B</mi><mo>≤</mo><msup><mn>10</mn><mn>9</mn></msup><mo>,</mo><mi>A</mi><mo>≠</mo><mi>B</mi><mo stretchy="false">)</mo></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$(-10^9≤A,B≤10^9, A\ne B)$</span> </mjx-container></p>

### 출력 

 <p>두 점이 만나기 위한 최소 이동 횟수와 최소 이동 횟수로 만나는 최종 위치의 개수를 공백으로 구분하여 출력한다. 만약 두 점이 영원히 만날 수 없다면 대신 <span style="color:#e74c3c;"><code>-1</code></span>을 출력한다.</p>

