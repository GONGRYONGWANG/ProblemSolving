# [Diamond V] 유물 도둑 - 15984 

[문제 링크](https://www.acmicpc.net/problem/15984) 

### 성능 요약

메모리: 4124 KB, 시간: 396 ms

### 분류

너비 우선 탐색, 그래프 이론, 그래프 탐색

### 제출 일자

2025년 6월 19일 15:20:37

### 문제 설명

<p>마녀로부터 도망치는데 겨우겨우 성공한 현욱은 여행을 계속해서 이어나갔다. 여행 중에 현욱은 어떤 유적에 도착했다. 이 유적은 총 <em>N</em>개의 구역으로 이루어져있고, 각각의 구역을 잇는 <em>M</em>개의 길이 존재한다. <em>M</em>개의 길은 양방향이라 어느 방향으로든 지나다닐 수 있으며, 길을 지나가는데에는 1분의 시간이 걸린다. 모든 구역은 연결되어 있어서 서로 방문 가능하다.</p>

<p>이 유적은 한창 발굴이 진행중이고 지금으로부터 <em>K</em>분 후에 발굴이 끝날 것으로 예상하고 있다. 유적 발굴단은 각 구역마다 어떤 가치를 지닌 유물이 나올지를 미리 계산해뒀는데, 현욱은 이 정보를 몰래 입수하고는 이 중에 제일 가치 있는 유물이 있는 지역으로 가서 몰래 유물을 훔쳐가려고 한다.</p>

<p>물론 유적 발굴단 역시 이런 유물 도둑들을 경계하고 있기 때문에, 훔쳐가지 못하게 구역들을 감시하고 있다. 현욱은 최대한 안전하게 유물을 가져가고 싶기 때문에 사람들이 감시하고 있는 구역은 가지 않으려고 한다. 현욱은 이 감시 일정표를 미리 입수해뒀는데, 감시 일정표에는 총 <em>Q</em>개의 일정이 적혀있으며 각각의 일정은 <em>T<sub>i</sub></em>와 <em>X<sub>i </sub></em>값으로 구성되어있다. 이 값의 의미는 <em>T<sub>i</sub></em>분부터 1분동안 <em>X<sub>i</sub></em>구역을 감시한다는 의미이다. <em>T<sub>i</sub></em>분에 누군가가 <em>X<sub>i</sub></em> 구역을 감시하고 있다면 현욱은 그 구역에 방문할 수 없고, <em>T<sub>i </sub></em>+ 1분이 되면 다시 방문할 수 있게 된다.</p>

<p>또, 한 구역에 계속 머물고 있으면 유적 발굴단이 경계를 할 수 있기 때문에 현욱은 한 구역에 머무르지 않고 한 장소에 도착하는 즉시 다른 장소로 이동을 하려고 한다.</p>

<p>현욱은 지금 1번 구역에 있고, 정확히 <em>K</em>분이 지난 후 발굴이 끝나자마자 가장 가치가 높은 유물이 있는 지역에서 유물을 챙겨 도망가려고 한다. 현욱을 도와 감시를 피해 정확히 <em>K</em>분 후에 방문 가능한 구역들 중 유물의 가치가 가장 높은 지역의 유물 가치와 그런 지역의 개수를 구해서 출력하는 프로그램을 작성해보자.</p>

### 입력 

 <p>첫째 줄에 <em>N</em>,<em>M</em>,<em>Q</em>,<em>K</em>가 주어진다.</p>

<p>다음줄에 각 구역의 유물 가치를 나타내는 정수 <em>N</em>개가 주어진다. 각 유물의 가치는 1 이상 10<sup>9</sup> 이하의 정수이다.</p>

<p>이어서 <em>M</em>개의 줄에 <em>X<sub>i</sub></em>, <em>Y<sub>i </sub></em>(1 ≤ <em>X<sub>i</sub></em>, <em>Y<sub>i</sub></em> ≤ <em>N</em>)가 공백으로 구분되어 주어진다. 이는 구역 <em>X<sub>i</sub></em>와 <em>Y<sub>i</sub></em>를 연결하는 길이 있다는 의미이다.</p>

<p>이어서 <em>Q</em>개의 줄에 일정표의 정보 <em>T<sub>i</sub></em>, <em>X<sub>i</sub> </em>(1 ≤ <em>T<sub>i</sub></em>  ≤ <em>K</em>, <em>T<sub>i </sub></em>는 정수, 1 ≤ <em>X<sub>i </sub></em>≤ <em>N</em>)가 공백으로 구분되어 주어진다. 이는 시간 <em>T<sub>i</sub></em>부터 <em>X</em><sub><em>i </em></sub>구역을 1분동안 감시한다는 의미이다.</p>

### 출력 

 <p>첫째 줄에 정확히 <em>K</em>분 후에 도착 할 수 있는 구역중 유물의 가치가 가장 높은 구역의 유물 가치와 그러한 구역의 개수를 공백으로 구분하여 출력한다. 만약 정확히 <em>K</em>분 후에 도착 가능한 구역이 존재하지 않는다면 -1을 출력한다.</p>

