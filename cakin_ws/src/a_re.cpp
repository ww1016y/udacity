//미네랄 2933
#include <stdio.h>
#include <iostream>
#include <queue>
#include <string.h>
#include <vector>
#include <algorithm>
#define MAX 101
using namespace std;
int map[MAX][MAX];
int R, C, N;
int mineral[MAX];
int dx[4] = {0,1,0,-1}; // 1,2,3,4 상 하 좌 우
int dy[4] = {1,0,-1,0};
int ans;
int num[6];
int v[6][4];

void solve(){

	for (int index = 1; index<=N ; index++) {
		if (index % 2 == 1) {
			for (int j = 1; j <= C; j++) {
				if (map[R-mineral[index]+1][j] == 1){
					map[R-mineral[index]+1][j] = 0;
					break;
				}
				else continue;		
			}	
		}
		else if (index % 2 == 0) {
			for (int j = C; j >= 1; j--) {
				if (map[R-mineral[index]+1][j] == 1){
					map[R-mineral[index]+1][j] = 0;
					break;
				}
				else continue;		
			}	
		}
		///////////////////////////////////////////
		int visit[MAX][MAX] = {0};
		int count = 0;
		for (int i = 1; i <= R; i++) {
			for (int j = 1; j <= C; j++) {
				if (map[i][j] == 1 && visit[i][j] == 0) {
					count = count + 1;
					queue <pair<int, int>> q;
					q.push(make_pair(i,j));
					visit[i][j] = count;
					while(!q.empty()){
						int x = q.front().first;
						int y = q.front().second;
						q.pop();
						for (int k = 0; k<4; k++){
							int nx = x + dx[k];
							int ny = y + dy[k];
							if (nx < 1 || ny < 1 || nx > R || ny > C || map[nx][ny] == 0 || visit[nx][ny] != 0){
								continue;
							}
							if (map[nx][ny] == 1 ){
								q.push(make_pair(nx,ny));
								visit[nx][ny] = count;
							}
						}
					}			
				}
			}
		}
		int check[100000]={0}; 
		for (int j = 1; j <= C; j++) {
			if (visit[1][j] != 0){
				check[visit[1][j]] = 1;
			}		
		}
		int point = 0;
		for (int c = 1; c <= count ; c++){
			if (check[c] == 0){
				point = c;
			}
		}

		int m[MAX]= {0};
		for (int j = 1; j <= C; j++) {
			for (int i = R; i >= 1; i--) {
				if (visit[i][j] == point){
					 m[j]=i;
					 break;
					}
				}
		}

		int change = 0;
		int flag = 0;
		int move_val = 101;
		for (int j = 1; j <= C; j++) {	
			int k = 1;
			if (m[j] > 0)	{
				while (1) {
					if (m[j]+k == R && map[m[j]+k][j] == 0){
						
						break;
					}
					else if (m[j]+k <= R && map[m[j]+k][j] == 1){
						k = k- 1;					
						break;
					}
					k = k + 1;
				}			
			}
			int temp = k;
			if ( temp < move_val ) move_val =temp;
		}

		int t[MAX][MAX]={0};
		for (int i = R; i >= 1; i--) {
			for (int j = 1; j <= C; j++) {
				t[i][j] = map[i][j];
			}
		}

		for (int i = R; i >= 1; i--) {
			for (int j = 1; j <= C; j++) {
				if (visit[i][j] == point){
					map[i+move_val][j] = t[i][j];
				}
			}
		}
	}

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (map[i][j] == 0) cout << '.';
			else if (map[i][j] == 1) cout << 'x';
		}
		cout << '\n';
	}
}

int main() {
    int t=1;
    //scanf("%d", &t);
    for (int tc = 1; tc <= t; tc++) {
	
	ans = 0; 
    scanf("%d %d", &R, &C);
	
	for (int i = R; i >= 1; i--) {
		for (int j = 1; j <= C; j++) {
			char a;
			cin >> a;
			if (a == '.') map[i][j] = 0;
			if (a == 'x') map[i][j] = 1;
		}
	}
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		cin >> mineral[i] ; 	
	}
	
	solve();
        	
   // printf("%d", ans);
    }
}
