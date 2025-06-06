# [Platinum III] Lone Rook - 24588 

[문제 링크](https://www.acmicpc.net/problem/24588) 

### 성능 요약

메모리: 5848 KB, 시간: 1732 ms

### 분류

너비 우선 탐색, 그래프 이론, 그래프 탐색

### 제출 일자

2025년 6월 6일 15:21:43

### 문제 설명

<figure style="float: right;"><img alt="" src="https://upload.acmicpc.net/9a7e9868-8fca-4162-a661-0373323e931e/-/preview/" style="width: 242px; height: 244px;">
<figcaption style="text-align:right;"><small>Rook and knight icons by <a href="https://en.wikipedia.org/wiki/Chess_piece">Cburnett</a></small></figcaption>
</figure>

<p>On a chess board of r rows and c columns there is a lone white rook surrounded by a group of opponent’s black knights. Each knight attacks 8 squares as in a typical chess game, which are shown in the figure – the knight on the red square attacks the 8 squares with a red dot. The rook can move horizontally and vertically by any number of squares. The rook can safely pass through an empty square that is attacked by a knight, but it must move to a square that is not attacked by any knight. The rook cannot jump over a knight while moving. If the rook moves to a square that contains a knight, it may capture it and remove it from the board. The black knights never move. Can the rook eventually safely move to the designated target square?</p>

<p>The figure illustrates how the white rook can move to the blue target square at the top-right corner in the first sample case. The rook captures one black knight at the bottom-right of the board on its way.</p>

### 입력 

 <p>The first line of input contains two integers r and c (2 ≤ r, c ≤ 750). Each of the next r lines describes one row of the board using c characters: the letter ‘<code>R</code>’ represents the white rook, a ‘<code>K</code>’ represents a black knight, a dot ‘<code>.</code>’ represents an empty square, and the letter ‘<code>T</code>’ represents the white rook’s target square. There is exactly one ‘<code>R</code>’, exactly one ‘<code>T</code>’, and at least one ‘<code>K</code>’ on the board. It is guaranteed that the white rook starts in a square that is not attacked by any knight. The target square may be attacked by a knight, in which case the knight must be captured before the rook can safely move to the target square.</p>

### 출력 

 <p>Output <code>yes</code> if the white rook can move to the target square, or <code>no</code> otherwise.</p>

