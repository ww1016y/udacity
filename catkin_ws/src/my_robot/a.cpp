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
int check1_max = 0;
int check2_max = 0;

void check1(int sum1, int profit1, int num){//재귀로만들기
	
	if (profit1 > check1_max) check1_max = profit1;
	if (num == M) return;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visit[i][j] == 1){
				if (map[i][j]+sum1 <= C ){
					check(sum1 + map[i][j],profit1 + map[i][j]*map[i][j],num+1 );
				}
				else if (map[i][j] <= C ){
					check(map[i][j],profit1 + map[i][j]*map[i][j],num+1 );
				}	
			}
		}
	}
}

void check2(int sum1, int profit1, int num){//재귀로만들기
	
	if (profit1 > check2_max) check2_max = profit1;
	if (num == M) return;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visit[i][j] == 2){
				if (map[i][j]+sum1 <= C ){
					check(sum1 + map[i][j],profit1 + map[i][j]*map[i][j],num+1 );
				}
				else if (map[i][j] <= C ){
					check(map[i][j],profit1 + map[i][j]*map[i][j],num+1 );
				}	
			}
		}
	}
}

void solve(int x, int y) {
	
	for (int i = x; i < N; i++) {
		for (int j = y; j < N-M+1; j++) {
			if (j+M-1<N){
				for (int k = 0; k<M; k++){
						visit[i][j+k] = 2;
					}
					
				check1_max = 0;
				check2_max = 0;
				
				check1(0,0,0);
				check2(0,0,0);
				
				if (check1_max + check2_max > ans) ans = check1_max + check2_max;
				
				for (int k = 0; k<M; k++){
						visit[i][j+k] = 0;
					}
			}
		}
		y=1;
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
					
					for (int k = 0; k<M; k++){
						visit[i][j+k] = 1;
					}
					solve(i,j+M);
					for (int k = 0; k<M; k++){
						visit[i][j+k] = 0;
					}
				}
			}
		}
		

		cout << '#' << t+1 << ' ' << ans;
	}
}
