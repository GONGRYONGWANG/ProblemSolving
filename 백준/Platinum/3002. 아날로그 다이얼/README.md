# [Platinum II] 아날로그 다이얼 - 3002 

[문제 링크](https://www.acmicpc.net/problem/3002) 

### 성능 요약

메모리: 45968 KB, 시간: 320 ms

### 분류

자료 구조, 세그먼트 트리, 느리게 갱신되는 세그먼트 트리

### 제출 일자

2025년 7월 9일 18:47:49

### 문제 설명

<p>아날로그 다이얼이란 0부터 9까지 각 숫자 중 하나를 항상 표시하고 있는 작은 기계이다. 다이얼에는 화면에 보이는 숫자를 1 증가시킬 수 있는 버튼도 있다. (9를 1 증가시키면 0이 된다)</p>

<p>상근이는 이러한 아날로그 다이얼을 N개 가지고 있고, 모두 책상에 일렬로 올려 놓았다. 왼쪽 기계부터 1번기계이며, 가장 오른쪽 기계는 N번 기계이다. 또, 기계의 앞에 무엇인가를 작성할 수 있도록 종이 두 장을 놓았다.</p>

<p>가장 처음에 상근이는 다이얼에 보이는 숫자를 첫 번째 종이에 적는다. 그 다음 다음과 같은 행동을 M번 반복한다.</p>

<p>1. 두 정수 A와 B를 고른 다음, 첫 번째 종이에 작성한다. (1 ≤ A ≤ B ≤ N)</p>

<p>2. A번째 다이얼부터 B번째 다이얼에 적혀있는 숫자의 합을 구한 다음에 두 번째 종이에 작성한다.</p>

<p>3. A번째부터 B번째 다이얼의 버튼을 한 번씩 누른다.</p>

<p>상근이는 위와 같은 게임(?)을 모두 완료했다. 하지만, 갑자기 벽에서 정인이가 튀어나왔고, 두 번째 종이와 다이얼 N개를 모두 들고 군대로 도망가버렸다.</p>

<p>상근이는 첫 번째 종이만 가지고 있다. 두 번째 종이에 쓰여 있는 수를 모두 구하는 프로그램을 작성하시오.</p>

### 입력 

 <p>첫째 줄에 N과 M이 주어진다. (1 ≤ N ≤ 250,000, 1 ≤ M ≤ 100,000)</p>

<p>둘째 줄에는 가장 처음에 다이얼에 표시된 숫자가 주어진다. 이 숫자는 공백없이 주어진다.</p>

<p>다음 M개 줄에는 상근이가 고른 숫자인 A와 B가 주어진다. (1 ≤ A ≤ B ≤ N)</p>

### 출력 

 <p>출력은 총 M개 줄이다. 상근이가 구한 다이얼의 합을 순서대로 출력한다.</p>

