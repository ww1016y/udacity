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

void check(){//재귀로만들기
	
	int sum1 = 0;
	int profit1 = 0;
	int sum2 = 0;
	int profit2 = 0;
	for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (visit[i][j] == 1){
					if (map[i][j]+ sum1 <= C ){
						
						sum1 = sum1 + map[i][j];
						profit1 = profit1 + map[i][j]*map[i][j];
						
					}
					else (map[i][j] <= C){

						int temp = profit1 + map[i][j]*map[i][j];
						if (temp > profit1) profit1 =temp;
					}
				}

				if (visit[i][j] == 2){
					if (map[i][j]+ sum <= C ){
						
						sum = sum + map[i][j];
						profit = profit + map[i][j]*map[i][j];
						
					}
					else (map[i][j] <= C){
					
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
				check();
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
