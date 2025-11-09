# [Gold II] 큐브 채우기 - 34727 

[문제 링크](https://www.acmicpc.net/problem/34727) 

### 성능 요약

메모리: 2020 KB, 시간: 12 ms

### 분류

애드 혹, 게임 이론

### 제출 일자

2025년 11월 8일 20:16:21

### 문제 설명

<p><strong>동국이</strong>와 <strong>아코</strong>는 $N \times N \times N$ 의 정육면체 격자 보드에서 게임을 한다. 보드는$N^3$개의 칸으로 이루어져 있으며, 각 칸은 좌표 $(x,y,z)$로 나타낸다.게임은 다음과 같은 규칙으로 진행된다.</p>

<ul>
<li>두 사람은 번갈아 가며 <strong>십자 블록</strong>을 놓는다.</li>
<li><strong>십자 블록</strong>은 정육면체 7개가 십자 형태로 붙어 있는 모양이다. 즉, 어떤 좌표 $(x,y,z)$를 중심으로 할 때 $[    (x,y,z),    (x\pm 1,y,z),    (x,y\pm 1,z),    (x,y,z\pm 1)  ]$의 칸을 차지한다.</li>
<li><strong>십자 블록</strong>은 일부분이라도 보드 밖으로 나가면 안 되며, 다른 <strong>십자 블록</strong>과 겹칠 수 없다.</li>
<li>더 이상 <strong>십자 블록</strong>을 놓을 수 없는 사람이 패배한다.</li>
</ul>

<p><strong>아코</strong>가 먼저 시작한다. 두 사람이 모두 최선의 전략을 취한다고 할 때, <strong>아코</strong>가 이길 수 있는지 판정하라.</p>


<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/50f23798-fb56-483c-b423-693205ec2f26/-/preview/" style="max-width: 60%; height: auto;"></p>

<p style="text-align: center;">해당 그림은 이 게임에서 사용하는 <strong>십자 블록</strong>의 모습이다.</p>

### 입력 

 <p>첫 번째 줄에는 테스트 케이스 $T$가 주어진다. $(1 \le T \le 100\,000)$</p>

<p>각 테스트 케이스의 첫째 줄에 정육면체 격자 보드의 변의 길이 $N$이 주어진다. $(3 \le N \le 100\,000)$</p>

### 출력 

 <p>각 테스트 케이스마다 <strong>아코</strong>가 승리할 수 있다면 $1$을, 승리할 수 없다면 $0$을 출력한다.</p>

