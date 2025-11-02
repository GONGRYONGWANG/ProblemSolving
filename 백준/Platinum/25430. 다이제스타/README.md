# [Platinum V] 다이제스타 - 25430 

[문제 링크](https://www.acmicpc.net/problem/25430) 

### 성능 요약

메모리: 16888 KB, 시간: 104 ms

### 분류

그래프 이론, 정렬, 최단 경로, 데이크스트라

### 제출 일자

2025년 11월 2일 14:45:14

### 문제 설명

<blockquote>
<p>??? : 자 얘들아 이건 다이제스타 쓰면 돼, 다이제스타.</p>

<p>준혁 : 다이제스타가 뭐야? (검색한다)</p>

<p>준혁 : 아하! 다이제는 과자 이름이구나. 그럼 스타는 뭐지?</p>

<p>진호 : 스타크래프트 좋아하시잖아~</p>
</blockquote>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/47e14ba0-a6ef-4b45-9743-509359a3b4d3/-/preview/" style="width: 300px; height: 300px;"></p>

<p>스타크래프트의 저그들은 커널을 가지고 있다. 커널은 1부터 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>까지 번호가 붙어 있으며 커널들은 길이가 있는 양방향 연결통로를 통해 연결되어 있다. </p>

<p>저그들은 이 연결통로를 이용하여 시작 커널부터 끝 커널까지 자신들의 주식인 다이제를 운반한다. 저그들은 다이제를 운반할때 항상 전에 이동했던 연결통로보다 더 길이가 긴 연결통로를 이용해야만 한다. 그리고 이러한 이동방법 중 총 이동 거리가 가장 짧은 경로를 이용한다. 만약 한번도 연결통로를 이용한 적이 없다면, 아무 연결통로나 이용 할 수 있다.</p>

<p>저그들은 이 이동 방법을 다이제스타라고 부르기로 했다.</p>

<p>준혁이와 진호는 다이제스타가 어떤 방식으로 이루어지는지 궁금해졌다. 준혁이와 진호를 위해 다이제스타를 구현해보자.</p>

### 입력 

 <p>첫째 줄에 커널의 개수 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>과 연결통로의 개수 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D440 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>M</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$M$</span></mjx-container>가 주어진다. <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mo class="mjx-n"><mjx-c class="mjx-c28"></mjx-c></mjx-mo><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="4"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="4"><mjx-c class="mjx-c35"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn><mjx-mo class="mjx-n"><mjx-c class="mjx-c2C"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="2"><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn><mjx-mo class="mjx-n"><mjx-c class="mjx-c2C"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="2"><mjx-c class="mjx-c31"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="4"><mjx-c class="mjx-c1D440 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="4"><mjx-c class="mjx-c31"></mjx-c><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn><mjx-mo class="mjx-n"><mjx-c class="mjx-c2C"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="2"><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn><mjx-mo class="mjx-n"><mjx-c class="mjx-c29"></mjx-c></mjx-mo></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mo stretchy="false">(</mo><mn>1</mn><mo>≤</mo><mi>N</mi><mo>≤</mo><mn>50</mn><mo>,</mo><mn>000</mn><mo>,</mo><mn>1</mn><mo>≤</mo><mi>M</mi><mo>≤</mo><mn>100</mn><mo>,</mo><mn>000</mn><mo stretchy="false">)</mo></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$(1 ≤ N ≤ 50,000, 1 ≤ M ≤ 100,000)$</span> </mjx-container></p>

<p>두번째 줄부터 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D440 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>M</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$M$</span></mjx-container>개의 줄에 연결통로를 통해 연결되어 있는 두 커널과 연결통로의 길이가 주어진다. 연결통로의 길이는 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-msup><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn><mjx-script style="vertical-align: 0.393em;"><mjx-mn class="mjx-n" size="s"><mjx-c class="mjx-c37"></mjx-c></mjx-mn></mjx-script></mjx-msup></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><msup><mn>10</mn><mn>7</mn></msup></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$10^7$</span></mjx-container>보다 작거나 같은 양의 정수이다.</p>

<p>입력의 마지막 줄에는 시작 커널의 번호와 끝 커널의 번호가 입력된다.</p>

### 출력 

 <p>첫째 줄에 운반을 완료했을 때 저그들의 총 이동 거리를 출력해라. 만약 저그들이 커널을 통해 운반을 완료하는 것이 불가능할 경우 <code>DIGESTA</code>를 출력해야 한다.</p>

