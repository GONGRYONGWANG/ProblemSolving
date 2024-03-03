# [Gold IV] Christmalo.win - 17452 

[문제 링크](https://www.acmicpc.net/problem/17452) 

### 성능 요약

메모리: 2024 KB, 시간: 20 ms

### 분류

정렬, 문자열

### 제출 일자

2024년 3월 3일 17:34:04

### 문제 설명

<p>세계적인 Ki-pop 열풍을 이끌고 있는 키파는 역사에 남을 새 앨범의 출시를 앞두고 고민에 빠졌다.</p>

<p><span style="font-style: italic;">제목 뭐로 하지?</span></p>

<p>키파의 앨범은 항상 같은 방법으로 만든 단어를 사용하는 전통이 있다. 전통에 따르면, 키파는 앨범에 어울리는 단어 두 개를 선택한 다음 이 단어에서 공통된 알파벳을 하나 선택하고, 앞에 올 단어에서 그 알파벳 뒤의 문자들을 지우고, 뒤에 올 단어에서는 그 알파벳 앞의 문자들을 지운 후 두 단어를 합쳐서 새로운 앨범의 제목을 정한다. 같은 알파벳이 여러 번 등장한다면 그중 원하는 것을 아무거나 선택한다.</p>

<p>예를 들어 christmas와 halloween을 선택했다면, 공통된 알파벳 a를 선택하여 christm<strong>a</strong>와 <strong>a</strong>lloween을 만들고 이 둘을 합쳐서 christm<strong>a</strong>lloween이 된다.</p>

<p>키파는 앨범에 어울리는 단어 <span style="font-style: italic;">N</span>개를 선택해 놨지만, 제목을 정하는 일은 지워지는 문자의 개수가 최소가 되게 정해 달라는 부탁과 함께 당신에게 맡겨 두고 녹음을 하러 떠났다. 키파의 성격상 당신은 키파가 돌아오기 전에 제목을 정해야 한다!</p>

### 입력 

 <p>첫째 줄에 문자열의 개수 <span style="font-style: italic;">N</span>이 주어진다. 이후 <span style="font-style: italic;">N</span>개 줄에 서로 다른 문자열 <span style="font-style: italic;">S</span><sub><span style="font-style: italic;">i</span></sub>가 주어진다. 각각의 문자열은 20개 이하의 알파벳 소문자만으로 구성되어 있다.</p>

<ul>
	<li>2 ≤ <span style="font-style: italic;">N</span> ≤ 10<sup>5</sup></li>
	<li>2 ≤ |<span style="font-style: italic;">S</span><sub><span style="font-style: italic;">i</span></sub>| ≤ 20</li>
	<li><span style="font-style: italic;">S</span><sub><span style="font-style: italic;">i</span></sub> ≠ <span style="font-style: italic;">S</span><sub><span style="font-style: italic;">j</span></sub> if <span style="font-style: italic;">i</span> ≠ <span style="font-style: italic;">j</span></li>
</ul>

### 출력 

 <p>주어진 조건에 맞게 지워진 문자의 개수를 최소로 하는 단어를 만들었을 때, 지워진 문자의 개수를 출력한다. 주어진 조건에 맞는 단어를 만들 수 없는 경우 <code>-1</code>을 출력한다.</p>

