#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

#define MAX 11
int N,M;
int ans;
int ox, oy, rx, ry, bx, by;
int map[MAX][MAX];
int visit[MAX][MAX];
int check[MAX][MAX][MAX][MAX];
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };

void copy(int a[][MAX], int b[][MAX]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			a[i][j] = b[i][j];
		}
	}
}

void solve(int index) {

	if (index > 10) {
		
		return;
	}
	
	for (int i = 0; i < 4; i++) {
		int nrx = rx;
		int nry = ry;
		int nbx = bx;
		int nby = by;

		while (1) {
			nrx = nrx + dx[i];
			nry = nry + dy[i];

			if (nrx < 1 || nry < 1 || nrx >= N -1 || nry >= M-1 || map[nrx][nry] == 1) {
				nrx = nrx - dx[i];
				nry = nry - dy[i];
				break;
			}
		}
		while (1) {
			nbx = nbx + dx[i];
			nby = nby + dy[i];

			if (nbx < 1 || nby < 1 || nbx >= N - 1 || nby >= M - 1 || map[nbx][nby] == 1) {
				nbx = nbx - dx[i];
				nby = nby - dy[i];
				break;
			}
		}

		if (nrx==nbx && nry == nby && nrx == ox && nry == oy) {
			continue;
		}
		else if (nrx == nbx && nry == nby ){
			if (i == 0) {
				if (ry < by) {
					nry = nry - 1;
				}
				else {
					nby = nby - 1;
				}
			}
			else if (i == 1) {
				if (rx < bx) {
					nrx = nrx - 1;
				}
				else {
					nbx = nbx - 1;
				}
			}
			else if (i == 2) {
				if (ry < by) {
					nby = nby + 1;
				}
				else {
					nry = nry + 1;
				}
			}
			else if (i == 3) {
				if (rx < bx) {
					nbx = nbx + 1;
				}
				else {
					nrx = nrx + 1;
				}
			}
		
		}

		if (nrx == ox && nry == oy) {
			if (index < ans) ans = index;
			return;
		}
		else if (nbx == ox && nby == oy) {
			continue;
		}

		if (check[nrx][nry][nbx][nby] == 1) {
			continue;
		}
		else {

			rx = nrx;
			ry = nry;
			bx = nbx;
			by = nby;

			check[nrx][nry][nbx][nby] = 1;
			solve(index + 1);
			check[nrx][nry][nbx][nby] = 0;
		}

	}
	return;
}

int main() {

	cin >> N >> M;
	ans = 987654321;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			char a;
			cin >> a;

			if (a == '#') {
				map[i][j] = 1;
			}
			else if (a == '.') {
				map[i][j] = 0;
			}
			else if (a == 'O') {
				map[i][j] = 2;
				ox = i;
				oy = j;
			}
			else if (a == 'R') {
				map[i][j] = 3;
				rx = i;
				ry = j;
			}
			else if (a == 'B') {
				map[i][j] = 4;
				bx = i;
				by = j;
			}
		}
	}
	check[rx][ry][bx][by] = 1;
	solve(1);

	if (ans == 987654321) {
		ans = -1;
	}
	cout << ans;
}
