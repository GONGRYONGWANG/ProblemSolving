# [Gold I] 감정 압축 - 35299 

[문제 링크](https://www.acmicpc.net/problem/35299) 

### 성능 요약

메모리: 13024 KB, 시간: 8 ms

### 분류

구현, 다이나믹 프로그래밍

### 제출 일자

2026년 2월 22일 13:31:40

### 문제 설명

<p>래환이는 하루가 끝날 때마다 자신의 감정을 노트에 적는 것을 즐긴다. 그날의 감정이 전반적으로 기뻤다면 <span style="color:#e74c3c;"><code>:)</code></span>, 그렇지 않았다면 <span style="color:#e74c3c;"><code>:(</code></span>를 적는다.</p>

<p>그렇게 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>일간 감정을 계속 적다보니 노트에 빈 공간이 없어지기 시작했고, 이전 기록을 압축시켜 정리할 필요성을 느꼈다. 래환이는 연속된 날들의 감정이 동일하면 <span style="color:#e74c3c;"><code>:)</code></span> 또는 <span style="color:#e74c3c;"><code>:(</code></span> 뒤에 연속된 날의 수를 적기로 했다. 예를 들어 <span style="color:#e74c3c;"><code>:):):)</code></span>는 <span style="color:#e74c3c;"><code>:)3</code></span>으로 적고, <span style="color:#e74c3c;"><code>:(:(:):)</code></span>는 <span style="color:#e74c3c;"><code>:(2:)2</code></span>로 적는다. 단, 감정이 하루만 지속되는 경우에는 뒤에 <span style="color:#e74c3c;"><code>1</code></span>을 적지 않고 <span style="color:#e74c3c;"><code>:)</code></span> 또는 <span style="color:#e74c3c;"><code>:(</code></span>만 적는다. 따라서 <span style="color:#e74c3c;"><code>:):(:(:):)</code></span>는 <span style="color:#e74c3c;"><code>:):(2:)2</code></span>로 적는다.</p>

<p>하지만 감당이 안 될 정도로 많은 기록 때문에 래환이는 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c30"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>0</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$0$</span></mjx-container>개 이상 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D43E TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>K</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$K$</span></mjx-container>개 이하의 감정을 반대로 뒤집음으로써 정리된 문자열의 길이를 최소화하려 한다. <span style="color:#e74c3c;"><code>:)</code></span>를 뒤집으면 <span style="color:#e74c3c;"><code>:(</code></span>가 되고, <span style="color:#e74c3c;"><code>:(</code></span>를 뒤집으면 <span style="color:#e74c3c;"><code>:)</code></span>가 된다. 이때 래환이는 감정의 전체적인 흐름은 살려두기 위해 뒤집은 이후에도 <span style="color:#e74c3c;"><code>:)</code></span>과 <span style="color:#e74c3c;"><code>:(</code></span>의 개수가 변하지 않도록 한다.</p>

<p>래환이가 감정 기록을 어떻게 깔끔하게 정리할지 알아맞히는 프로그램을 작성하시오.</p>

### 입력 

 <p>첫 번째 줄에 감정 기록을 나타내는 길이 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c32"></mjx-c></mjx-mn><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>2</mn><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$2N$</span></mjx-container>의 문자열 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D446 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>S</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$S$</span></mjx-container>가 주어진다.</p>

<p>두 번째 줄에 정수 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D43E TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>K</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$K$</span></mjx-container>가 주어진다.</p>

### 출력 

 <p>감정 기록 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D446 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>S</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$S$</span></mjx-container>를 압축시켜 정리했을 때 만들어지는 문자열의 최소 길이를 출력한다.</p>

