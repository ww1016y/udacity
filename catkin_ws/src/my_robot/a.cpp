#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 11

int map[MAX][MAX];
int visit[MAX][MAX][MAX][MAX];
int ans;
int N, M;
int rx, ry, bx, by, ox, oy;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int flag;

void solve(int a, int b, int c, int d, int index) {


	if (a == c && b == d && a == ox && b == oy) {
		ans = -1;
		return;
	}
	else if (a != c && b != d && a == ox && b == oy) {
		ans = index-1;
		flag = 1;
		return;
	}
	if (index > 10) {
		ans = -1;
		return;
	}

	if (flag == 0) {
		for (int i = 0; i < 4; i++) {
			int rrx = a;
			int rry = b;
			int bbx = c;
			int bby = d;

			while (1) {
				rrx = rrx + dx[i];
				rry = rry + dy[i];
				if (rrx <= 0 || rry <= 0 || rrx >= N - 1 || rry >= M - 1 || map[rrx][rry] == 1) {
					break;
				}
			}
			while (1) {
				bbx = bbx + dx[i];
				bby = bby + dy[i];
				if (bbx <= 0 || bby <= 0 || bbx >= N - 1 || bby >= M - 1 || map[bbx][bby] == 1) {
					break;
				}
			}

			//같은 위치 체크
			if (rrx == bby && rry == bby && rrx != ox && rry != oy) {
				if (i == 0) {
					if (rry < bby) rry = rry - 1;
					else bby = bby - 1;
				}
				else if (i == 1) {
					if (rrx < bbx) rrx = rrx - 1;
					else bbx = bbx - 1;
				}
				else if (i == 2) {
					if (rry < bby) rry = rry + 1;
					else bby = bby + 1;
				}
				else if (i == 3) {
					if (rrx < bbx) rrx = rrx + 1;
					else bbx = bbx + 1;
				}
			}

			if (visit[rrx][rry][bbx][bby] == 1) {
				continue;
			}
			visit[rrx][rry][bbx][bby] = 1;
			solve(rrx, rry, bbx, bby, index + 1);
			visit[rrx][rry][bbx][bby] = 0;
		}
	}
	
	
}

int main() {
	int T = 1;
	cin >> T;

	for (int t = 0; t < T; T++) {
		ans = 0;
		cin >> N >> M;
		
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
				else if (a == 'B') {
					map[i][j] = 2;
					bx = i;
					by = j;
				}
				else if (a == 'R') {
					map[i][j] = 3;
					rx = i;
					ry = j;
				}
				else if (a == 'O') {
					map[i][j] = 4;
					ox = i;
					oy = j;
				}
			}
		}
		visit[rx][ry][bx][by] = 1;
		solve(rx,ry,bx,by,1);

	}

	cout << ans;
}
