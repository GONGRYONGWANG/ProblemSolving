# [Silver I] 졸업 사진 - 23349 

[문제 링크](https://www.acmicpc.net/problem/23349) 

### 성능 요약

메모리: 2168 KB, 시간: 0 ms

### 분류

자료 구조, 해시를 사용한 집합과 맵, 구현, 정렬, 문자열, 트리를 사용한 집합과 맵

### 제출 일자

2024년 8월 12일 21:09:21

### 문제 설명

<p>한국항공대학교에는 올해 새로 들어온 큰 비행기가 있다.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/5abddd70-fd4e-427d-a8ab-ef1e01ad1622/-/preview/" style="width: 661px; height: 400px;"></p>

<p style="text-align: center;">항공대학교 본관 옆 A300 모형</p>

<p>올해 졸업식에 참가하는 모든 사람은 비행기가 보이게 사진을 찍고싶어하지만, 졸업식은 하루뿐이라 모든 사람이 원하는 장소와 시간에 촬영할 수 없다.</p>

<p>따라서 학교에서는 최대한 많은 사람이 촬영할 수 있도록 미리 졸업식 전날 원하는 장소와 시간대를 제출받아 예상되는 혼잡 장소와 시간대를 공지하기로 하였다.</p>

<p>제출은 다음과 같은 값을 가진다.</p>

<ul>
	<li>학생 이름(name): 제출한 학생의 이름이다. 공백을 포함하지 않는 영어 소문자로 구성된 10자 이하의 한 단어로 구성된다. 만약 한 학생이 여러 번 제출한 경우, 가장 첫 번째 제출 이외의 제출들은 모두 무시한다.</li>
	<li>장소(place): 학생이 촬영하기를 원하는 장소이다. 공백을 포함하지 않는 영어 소문자로 구성된 20자 이하의 한 단어로 구성된다.</li>
	<li>시간대(time): 학생이 촬영하기를 원하는 시간대이다. 공백으로 구분된 두 개의 시각으로 주어지며, 시각은 <mjx-container class="MathJax" jax="CHTML" style="font-size: 101.8%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c35"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn><mjx-mo class="mjx-n"><mjx-c class="mjx-c2C"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="2"><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>50</mn><mo>,</mo><mn>000</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$50,000$</span></mjx-container> 이하의 양의 정수로 주어진다. 첫 번째 시각은 촬영 시작 시각, 두 번째 시각은 촬영 종료 시각을 나타낸다. 단, 종료 시각이 시작 시각보다 항상 크다.</li>
</ul>

<p>제출된 장소와 시간대의 목록을 이용해 학교가 혼잡 장소와 시간대를 공지하는 방법은 다음과 같다.</p>

<ol>
	<li>가장 많은 사람이 제출한 (장소, 시간대) 쌍을 선택한다.</li>
	<li>만약 <mjx-container class="MathJax" jax="CHTML" style="font-size: 101.8%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>1</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$1$</span></mjx-container>번에 해당하는 구간이 여러 개라면, 사전 순으로 가장 앞에 오는 장소를 선택한다. 사전 순의 기준은 아스키 코드 순이다. 예를 들어 구간 배열 ['ab', 'a', 'aa', ba']를 정렬한 배열은 ['a', 'aa', 'ab', 'ba']가 된다.</li>
	<li>만약 <mjx-container class="MathJax" jax="CHTML" style="font-size: 101.8%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c32"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>2</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$2$</span></mjx-container>번에서 고른 장소에 가장 많이 제출된 시간대가 여러 개라면, 가장 빠른 시간대를 고른다.</li>
</ol>

### 입력 

 <p>첫째 줄에 제출 수 <mjx-container class="MathJax" jax="CHTML" style="font-size: 101.8%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>이 주어진다. (<mjx-container class="MathJax" jax="CHTML" style="font-size: 101.8%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>1</mn><mo>≤</mo></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$1 \le $</span></mjx-container> <mjx-container class="MathJax" jax="CHTML" style="font-size: 101.8%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container> <mjx-container class="MathJax" jax="CHTML" style="font-size: 101.8%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mo class="mjx-n"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="4"><mjx-c class="mjx-c31"></mjx-c><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mo>≤</mo><mn>100</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$ \le 100$</span></mjx-container>)</p>

<p>다음 <mjx-container class="MathJax" jax="CHTML" style="font-size: 101.8%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>개의 줄에 제출의 정보 name, place, time 가 한 줄에 하나씩 주어진다. 이때 빈 문자열은 입력으로 주어지지 않는다.</p>

<p>입력에서 주어지는 장소(place)의 종류는 최대 <mjx-container class="MathJax" jax="CHTML" style="font-size: 101.8%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>10</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$10$</span></mjx-container>가지이다.</p>

### 출력 

 <p>첫째 줄에 학교가 공지할 것으로 예상되는 혼잡 (장소, 시간대) 쌍을 공백으로 구분하여 출력한다. 이때 시간대는 조건을 만족하는 가장 긴 시간대를 의미한다.</p>

