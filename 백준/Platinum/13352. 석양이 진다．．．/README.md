# [Platinum IV] 석양이 진다... - 13352 

[문제 링크](https://www.acmicpc.net/problem/13352) 

### 성능 요약

메모리: 3588 KB, 시간: 28 ms

### 분류

구현, 기하학, 집합과 맵, 무작위화

### 제출 일자

2025년 10월 16일 21:25:24

### 문제 설명

<p><em>피스키퍼 리볼버로 무장한 무법자 제시 맥크리는 자신만의 방식으로 정의를 실현한다.</em></p>

<p>그랬던 맥크리가 새로운 무기를 손에 넣었다. 새로운 무기는 멈추지 않는 총알으로 한번 발사되면 적을 뚫고 지나간다. 즉, 인공지능 상대들처럼 한 줄로 서서 달려오는 적들은 맥크리의 새로운 무기를 한번만 쏘면 죽게 된다.</p>

<p>새 무기로 신나게 적들을 쏴죽이던 맥크리는 총알이 두개밖에 남지 않았다는 사실을 깨닫고 절망하기 시작했다. 그런 가운데 구원의 목소리가 들려왔으니....</p>

<p>"<em>아무도 내게서 숨진 못 해.</em>"</p>

<p>이제 맥크리는 적들의 위치를 안다. 남은 총알은 두 발, 먼저 구른 뒤에 적들을 향해 총을 한번 쏘고 다시 한 번 구른 뒤 마지막으로 한번 더 쏜다. 이 계획이 성공하면 맥크리는 모든 적을 섬멸할 수 있다. 이 작전은 과연 성공할 수 있을까?</p>

<p>맥크리는 구르는 속도가 아주 빨라서 순식간에 어디로든 굴러갈 수 있다.</p>

### 입력 

 <p>첫 번째 줄에는 적의 수 N이 입력된다. (1 ≤ N ≤ 100,000)</p>

<p>이어서 입력되는 N개의 줄에는 두개의 정수 X<sub>i</sub>  Y<sub>i</sub> 가 입력된다. i번째 적의 위치 좌표는 (X<sub>i</sub>, Y<sub>i</sub>)이다. (−10<sup>9</sup> ≤ X<sub>i</sub>, Y<sub>i</sub> ≤ 10<sup>9</sup>) 단, 같은 위치에 두 명의 적이 있을수는 없다.</p>

<p>작전 지역은 평지이므로 높이는 신경쓰지 않아도 된다.</p>

### 출력 

 <p><span style="font-family:arial,helvetica neue,helvetica,tahoma,sans-serif">맥크리는 총알 두발로 </span><span style="font-family:arial,helvetica neue,helvetica,tahoma,sans-serif">적들을 없애려 한다. </span><span style="font-family:arial,helvetica neue,helvetica,tahoma,sans-serif">이 계획의 성공 여부를 출력하라.</span></p>

<p>성공할 시 "success"를 실패할 경우 "failure"를 출력하면 된다.</p>

