# [Platinum I] 도서실카펫 - 2601 

[문제 링크](https://www.acmicpc.net/problem/2601) 

### 성능 요약

메모리: 34840 KB, 시간: 112 ms

### 분류

자료 구조, 느리게 갱신되는 세그먼트 트리, 세그먼트 트리, 스위핑

### 제출 일자

2025년 7월 1일 17:34:37

### 문제 설명

<p>우리 학교는 다른 학교가 부러워하는 도서실을 가지고 있다. 장서를 다량 보유하고 있을 뿐 아니라 전자도서를 볼 수 있는 컴퓨터도 여러 대 설치되어 있고, 바닥에는 카펫이 깔려있다. 최근 도서실의 가구배치를 새로 하게 되었는데, 가구가 놓여있던 자리에는 얼룩이 져서 아주 보기가 흉하였다. 그래서 새로산 카펫 한 장으로 얼룩진 부분을 가리기로 하였다.</p>

<p>도서실은 직사각형 모양이고, 얼룩진 부분도 모두 직사각형 모양이며, 변은 도서실 벽과 평행하다. 새 카펫은 정사각형이다. 이 정사각형 카펫을 도서실의 벽과 평행하도록 놓는데, 완전히 가려지는 얼룩의 수를 최대화 하고자 한다.</p>

<p>예를 들어, 다음 그림과 같이 얼룩이 위치하고 있다고 하자. 점선으로 표시된 여분의 카펫으로 완전히 가릴 수 있는 얼룩의 최대 수는 4개가 되고, 이러한 카펫의 위치는 유일하지 않을 수 있다.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/f258b2aa-c198-4498-83da-39ba9396301d/-/preview/" style="width: 267px; height: 205px;"></p>

<p>이러한 카펫으로 완전히 가려지는 최대 얼룩의 수를 구하는 프로그램을 작성하시오.</p>

### 입력 

 <p>모든 사각형의 좌표는 1,000,000 보다 작은 음이 아닌 정수이고 가로 세로의 길이는 1,000,000 보다 작은 양의 정수이다. 얼룩 직사각형은 서로 겹치지 않지만 접할 수는 있다. 얼룩 직사각형과 카펫 정사각형은 당연히 도서실 직사각형에 완전히 포함된다. 얼룩 직사각형의 수는 최대 100,000개이다.</p>

<p>첫째 줄에는 도서실 직사각형의 왼쪽 위 꼭지 점과 오른쪽 아래 꼭지 점의 좌표가 주어진다. 둘째 줄에는 카펫 정사각형의 가로 길이가 주어진다. 셋째 줄에는 얼룩의 수가 주어지고, 넷째 줄부터는 얼룩 직사각형들의 왼쪽 위 꼭지 점과 오른쪽 아래 꼭지 점의 좌표가 주어진다.</p>

### 출력 

 <p>첫 줄에 여분의 카펫으로 완전히 가릴 수 있는 얼룩의 최대 수를 출력한다.</p>

