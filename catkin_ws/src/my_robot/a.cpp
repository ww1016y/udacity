#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>

using namespace std;

#define MAX 11
int N, C, M;
int ans;

int map[MAX][MAX];
int visit[MAX][MAX];

int dx[] = {-1,1,0,0};
int dy[] = {0,0,1,-1};
vector <pair<int, int>> v;

void check(){
	
	for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (visit[i][j] == 1){
					if (map[i][j] <= C ){
						map[i][j]
						sum = sum + map[i][j];
						profit = profit + map[i][j]*map[i][j];
					}
				}
			}
		}

}

void solve(int x, int y) {
	
	for (int i = x; i < N; i++) {
		for (int j = y; j < N-M+1; j++) {
			if (j+M-1<N){
				visit[i][j] = 2;
				check();
				visit[i][j] = 0;
			}
		}
	}

	return;
}

int main() {
	int T;
	cin >> T;
	for(int t = 0; t <T; t++){
		cin >> N >> M >> C;
		ans = 0;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N-M+1; j++) {
				if (j+M-1<N){
					visit[i][j] = 1;
					solve(i,j+M);
					visit[i][j] = 0;
				}
			}
		}
		

		cout << '#' << t+1 << ' ' << ans;
	}
}
