# [Platinum V] 대구과학고등학교 - 30397 

[문제 링크](https://www.acmicpc.net/problem/30397) 

### 성능 요약

메모리: 2576 KB, 시간: 4 ms

### 분류

그리디 알고리즘, 정렬

### 제출 일자

2025년 3월 15일 22:47:20

### 문제 설명

<p>대구과학고등학교 학생들은 내기를 좋아한다. 이번에는 이안이와 예환이가 서로의 공부를 위해 시험 성적으로 내기를 하려고 한다. 어떤 과목에서 점수를 비교해서 점수가 높은 사람은 공부를 아주 열심히 했으니 100원을 받고, 점수가 낮은 사람은 공부를 안한 벌금으로 50원을 낸다. 만약 점수가 같다면 둘다 공부를 열심히 했다고 치고 20원씩 받기로 했다.</p>

<p>그런데 여기서 맹점이 하나 있다. 이안이는 예환이와 학교가 다르기 때문에 예환이는 이안이가 어떤 과목 시험을 쳤는지 잘 모른다. 그래서 이안이는 공부를 열심히 한 척을 하기 위해 최대한 많은 과목에서 예환이를 이길 수 있도록 과목 간 점수를 바꾸고자 한다. 예를 들어 시험을 친 과목이 3과목이고 이안이가 받은 점수가 10점, 100점, 50점이고 예환이가 받은 점수가 50점, 80점, 40점이라면 이안이는 내기를 두 번 이기고 한 번 질 수 있다.</p>

<p>이안이가 얻는 돈이 최대가 되도록 도와주자.</p>

### 입력 

 <p>첫 번째 줄에 시험을 본 과목의 수 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>이 주어진다.</p>

<p>두 번째 줄에는 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container> 과목에 대한 이안이의 점수들이 공백으로 구분되어 주어지고, 세 번째 줄에는 예환이의 점수들이 공백으로 구분되어 주어진다.</p>

### 출력 

 <p>이안이가 받을 수 있는 돈의 최댓값을 출력한다. 이안이가 공부를 너무 안 했을 경우 벌금만 낼 수 있어 답이 음수인 경우가 존재함을 유의하라.</p>

