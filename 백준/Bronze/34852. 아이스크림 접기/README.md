# [Bronze I] 아이스크림 접기 - 34852 

[문제 링크](https://www.acmicpc.net/problem/34852) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

수학, 기하학

### 제출 일자

2025년 11월 29일 22:52:19

### 문제 설명

<p>앞면이 흰색, 뒷면이 파란색, 그리고 한 변의 길이가 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>인 정사각형 모양 종이가 있다.</p>

<p>단웅이는 이 종이를 다음과 같이 접어서 맛있는 아이스크림을 만들려고 한다.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/b2561765-3ab3-459e-8104-8903f6357c3d/-/preview/" style="max-width: 95%; height: auto;"></p>

<p>각 과정에 대한 설명은 다음과 같다.</p>

<ol>
<li>한 변의 길이가 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>인 정사각형 종이를 준비하고, 흰색 면이 앞에 오도록 놓는다.</li>
<li>왼쪽 아래 꼭짓점에 대응되는 각의 3등분선을 따라 접은선 2개를 만든다.</li>
<li>왼쪽 아래 꼭짓점과 오른쪽 모서리를 잇는 접은선을 따라 오른쪽 아래 꼭짓점을 왼쪽 위 방향으로 접는다.</li>
<li>왼쪽 아래 꼭짓점과 위쪽 모서리를 잇는 접은선을 따라 왼쪽 위 꼭짓점을 오른쪽 아래 방향으로 접는다.</li>
</ol>

<p>접기 과정을 모두 마치면 맛있는 아이스크림이 완성된다.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/12fdd11a-0a18-4652-89f3-5b4c9da58670/-/preview/" style="width: 200px; height: 277px;"></p>

<p>단웅이는 종이를 접어 아이스크림을 만든 후, 아이스크림의 크기가 궁금해졌다. 아이스크림의 크기란 완성된 모양에서 흰색 부분의 넓이로 정의한다.</p>

<p>단웅이를 도와 아이스크림의 크기를 구해주자.</p>

### 입력 

 <p>첫째 줄에 양의 정수 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>이 주어진다. (<mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="4"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-msup space="4"><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn><mjx-script style="vertical-align: 0.393em;"><mjx-mn class="mjx-n" size="s"><mjx-c class="mjx-c36"></mjx-c></mjx-mn></mjx-script></mjx-msup></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>1</mn><mo>≤</mo><mi>N</mi><mo>≤</mo><msup><mn>10</mn><mn>6</mn></msup></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$1 \leq N \leq 10^6$</span></mjx-container>)</p>

### 출력 

 <p>첫째 줄에 단웅이가 만든 아이스크림의 크기를 출력한다. 정답과의 절대/상대 오차는 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-msup><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn><mjx-script style="vertical-align: 0.393em;"><mjx-texatom size="s" texclass="ORD"><mjx-mo class="mjx-n"><mjx-c class="mjx-c2212"></mjx-c></mjx-mo><mjx-mn class="mjx-n"><mjx-c class="mjx-c36"></mjx-c></mjx-mn></mjx-texatom></mjx-script></mjx-msup></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><msup><mn>10</mn><mrow data-mjx-texclass="ORD"><mo>−</mo><mn>6</mn></mrow></msup></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$10^{-6}$</span></mjx-container>까지 허용한다.</p>

