#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

#define MAX 17
int N;
int ans;
int map[MAX][MAX];
int visit[MAX][MAX];
int check[MAX][MAX][MAX][MAX];
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };


void solve(int x, int y, int state, int index) {

	if (x == N && y == N) {
		ans = ans + 1;
		return;
	}
	
	if (state == 2) {
		int nx = x;
		int ny = y;

		if (ny + 1 <= N) {
			if (map[nx][ny + 1] == 0) {
				solve(nx, ny + 1, state, index + 1);
			}
		}

		if (nx + 1 <= N && ny + 1 <= N) {
			if (map[nx][ny + 1] == 0 && map[nx+1][ny] == 0 && map[nx+1][ny + 1] == 0) {
				solve(nx+1, ny + 1, 4, index + 1);
			}
		}
	}
	
	else if (state == 3) {
		int nx = x;
		int ny = y;

		if (nx + 1 <= N) {
			if (map[nx+1][ny] == 0) {
				solve(nx+1, ny, state, index + 1);
			}
		}

		if (nx + 1 <= N && ny + 1 <= N) {
			if (map[nx][ny + 1] == 0 && map[nx + 1][ny] == 0 && map[nx + 1][ny + 1] == 0) {
				solve(nx + 1, ny + 1, 4, index + 1);
			}
		}
	}

	else if (state == 4) {
		int nx = x;
		int ny = y;

		if (ny + 1 <= N) {
			if (map[nx][ny + 1] == 0) {
				solve(nx, ny + 1, 2, index + 1);
			}
		}
		if (nx + 1 <= N) {
			if (map[nx + 1][ny] == 0) {
				solve(nx + 1, ny, 3, index + 1);
			}
		}
		if (nx + 1 <= N && ny + 1 <= N) {
			if (map[nx][ny + 1] == 0 && map[nx + 1][ny] == 0 && map[nx + 1][ny + 1] == 0) {
				solve(nx + 1, ny + 1, 4, index + 1);
			}
		}
	}

	return;
}

int main() {

	cin >> N ;
	ans = 0;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}
	
	solve(1,2,2,0);

	cout << ans;
}
