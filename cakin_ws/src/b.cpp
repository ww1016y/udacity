#include <stdio.h>
#include <iostream>
#include <queue>
#include <string.h>
#include <vector>
#include <algorithm>
#define MAX 20
using namespace std;
int map[MAX][MAX];
int N, M;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int ans;

void solve(int a, int b){
	
	queue <pair<int, int>> q;	
	int visit[MAX][MAX];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visit[i][j] = 0;
		}
	}

	q.push(make_pair(a,b));
	visit[a][b] = 1;


	while(!q.empty()){

		int x=q.front().first;	
		int y=q.front().second;

		q.pop();

		for(int i =0; i<4; i++){
			int nx = x+dx[i];
			int ny = y+dy[i];
			if (nx<0 || ny < 0 || nx >= N || ny >= N || visit[nx][ny] != 0) continue;
			visit[nx][ny] = visit[x][y] + 1;
			q.push(make_pair(nx,ny));
		}	
		int count = 0;
		int temp_max = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (visit[i][j] != 0 && map[i][j] == 1) {
					count = count+1;
					
				}
				if (temp_max <visit[i][j] ) temp_max = visit[i][j];
			}
		}
		
		int plus = count*M - ( temp_max * temp_max + (temp_max-1)*(temp_max-1) );
		if (plus >= 0) {
			if (count > ans) ans =count;
		}
	}
}

int main() {
    int t;
    scanf("%d", &t);
    for (int tc = 1; tc <= t; tc++) {
        
	memset(map,0,sizeof(map));
	ans =0; 
        scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			solve(i,j);
		}
	}
	
        printf("#%d %d", tc, ans);
    }
}

