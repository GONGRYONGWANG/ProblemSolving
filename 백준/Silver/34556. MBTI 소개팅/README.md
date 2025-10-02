# [Silver I] MBTI 소개팅 - 34556 

[문제 링크](https://www.acmicpc.net/problem/34556) 

### 성능 요약

메모리: 2028 KB, 시간: 0 ms

### 분류

브루트포스 알고리즘, 비트마스킹

### 제출 일자

2025년 10월 3일 03:00:25

### 문제 설명

<p>골마는 학교 축제에서 남자 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>명, 여자 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>명을 대상으로 소개팅을 진행하고 있습니다. 골마는 남녀 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>쌍을 어떤 기준으로 매칭할지 생각하다가 MBTI를 이용하려고 합니다.</p>

<p>MBTI는 성격 유형 검사로, 사람의 성격을 16가지의 유형으로 나누어 설명합니다. 성격 유형으로는 각각 I(내향)/E(외향), S(감각)/N(직관), T(사고)/F(감정), J(판단)/P(인식) 4가지가 있으며, 각 유형별 개인의 선호도를 밝혀서 4개의 선호 문자로 구성된 개인의 성격 유형을 알려줍니다. 예를 들어, 내향/감각/사고/판단이 우세하면, MBTI는 ISTJ가 됩니다.</p>

<p>그런데 골마는 <strong>MBTI 문자가 다를수록 매칭이 잘 되었다</strong>고 생각합니다. 따라서 매칭 점수는 서로 매칭된 두 사람의 MBTI에서 일치하지 않는 성격 유형의 개수로 표현됩니다.</p>

<p>예를 들어 ENTJ/ISFP와 같이 4가지가 모두 다르면 4점, ISFJ/ENFP와 같이 3가지가 다르면 3점입니다. 다른 성별끼리만 매칭할 수 있습니다.</p>

<p>골마는 모두를 최대한 행복하게 만들어주고 싶기에, 적절히 매칭시켜 매칭 점수의 합을 최대화하려고 합니다. 원하는 대로 매칭시켰을 때 <strong>매칭 점수의 합의 최댓값</strong>을 구해주세요.</p>

### 입력 

 <p>첫 줄에는 각 성별의 인원수 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>이 들어옵니다. (<mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="4"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="4"><mjx-c class="mjx-c31"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>1</mn><mo>≤</mo><mi>N</mi><mo>≤</mo><mn>10</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$1 \le N \le 10$</span></mjx-container>)</p>

<p>다음 줄에는 남자의 MBTI가 한 줄에 하나씩 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>줄에 걸쳐 주어집니다.</p>

<p>그다음 줄에는 여자의 MBTI가 한 줄에 하나씩 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>줄에 걸쳐 주어집니다.</p>

<p>MBTI는 첫 번째 글자가 <code>I</code>/<code>E</code>, 두 번째 글자가 <code>S</code>/<code>N</code>, 세 번째 글자가 <code>T</code>/<code>F</code>, 네 번째 글자가 <code>J</code>/<code>P</code> 중 하나만 들어오며 4글자입니다.</p>

### 출력 

 <p>매칭 점수의 합의 최댓값을 출력해 주세요.</p>

