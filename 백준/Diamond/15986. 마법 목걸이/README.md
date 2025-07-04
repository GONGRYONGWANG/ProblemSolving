# [Diamond V] 마법 목걸이 - 15986 

[문제 링크](https://www.acmicpc.net/problem/15986) 

### 성능 요약

메모리: 47336 KB, 시간: 320 ms

### 분류

자료 구조, 그리디 알고리즘, 세그먼트 트리, 희소 배열

### 제출 일자

2025년 6월 20일 04:23:13

### 문제 설명

<p>현욱은 여행 중에 어느 유적지에서 유물을 훔쳐 왔는데, 그 때 훔친 유물들 중에는 마법 구슬을 꿰어서 만든 특별한 목걸이가 있었다. 이 목걸이를 이루고 있는 마법 구슬에는 각각 정수가 하나씩 적혀 있다.</p>

<p> 마법 구슬은 구슬에 적힌 수가 뭐냐에 따라 구슬의 소유자에게 특별한 능력을 부여한다. 이때 적힌 수가 1인 경우 착용자의 머리를 좋게 만들어 주는데, 내일 당장 소프트콘 대회에 참가해야 하는 현욱은 대회에서 최대한 좋은 성적을 얻기 위해 자신이 가진 마법 목걸이의 구슬을 적절히 융합시켜서 모든 마법 구슬에 적힌 수가 1이면서, 구슬의 개수가 최대한 많게 만들려고 한다.</p>

<p>마법 목걸이는 끈으로 묶여 있을 때는 안정적인 상태라 구슬에 적힌 숫자에 변화를 줄 수 없다. 하지만 목걸이의 어느 한 부분을 끊어서 일자로 만들 경우 서로 인접한 마법 구슬들은 새로운 마법 구슬 하나로 융합시킬 수 있는데, 이때 새롭게 만들어진 마법 구슬에 적힌 정수는 융합에 사용된 마법 구슬들의 최대 공약수가 된다.</p>

<p>현욱은 목걸이를 어떻게 자르느냐에 따라 얻을 수 있는 1이 적힌 마법 구슬의 최대 개수가 어떻게 변화하는지가 궁금해졌다. 현욱을 도와 이를 구하는 프로그램을 작성해보자.</p>

### 입력 

 <p>첫째 줄에 구슬의 개수 <em>N</em>이 주어진다. </p>

<p>둘째 줄에는 각각의 마법 구슬에 적힌 수 <em>a<sub>1</sub></em>, <em>a<sub>2</sub></em>, ... ,<em>a<sub>N</sub></em>(1 ≤<em> a<sub>i</sub></em> ≤ 10<sup>18</sup>)이 공백을 사이에 두고 주어진다. <em>a<sub>1</sub></em>과 <em>a<sub>N</sub></em>은 서로 인접해 있다.</p>

### 출력 

 <p><em>N</em>줄에 걸쳐, 주어진 목걸이를 각각의 위치에서 잘랐을 때 모든 마법 구슬에 적힌 수가 1이면서 그 개수가 가장 많게 했을 때 가능한 개수를 출력한다. 그런 경우를 만들 수 없다면 0을 출력한다.</p>

