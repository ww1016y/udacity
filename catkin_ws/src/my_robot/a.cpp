#include <stdio.h>
#include <iostream>
#include <queue>
#include <string.h>
#include <vector>
#include <algorithm>
#define MAX 20
using namespace std;
int map[MAX][MAX];
int m[MAX][MAX];
int N, M;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int ans;

void remap(){

	for (int i = 0; i < W; i++) {
		queue <int> q;
		for (int j = H-1; j >= 0; j++) {
			if (map[j][i] > 0){
				q.push(map[j][i]);	
			}
		}
		for (int j = H-1; j >= 0; j++) {
			if (!q.empty){
				map[j][i] = q.front();	
				q.pop();
			}
		}
	}
}

void copymap(int a[][], int b[][]){

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			b[i][j] = a[i][j];
		}
	}
}

void boom(int x, int y){
	
	int len = map[x][y];
	map[x][y] = 0;
	if (len == 1){
		map[x][y] = 0;
		return;
	}
	else {
		for(int i =0; i<4; i++){
			for (int j = 1; j < len; j++  ){
				int nx = x+j*dx[i];
				int ny = y+j*dy[i];
				if (nx<0 || ny < 0 || nx >= H || ny >= W || map[nx][ny] == 0) continue;
								
				boom(nx,ny);
			}
		}
	}
}

void solve(int index){
	
	if (index == N ){
		int count = 0 ;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				if (map[i][j] > 0) {
					count = count + 1;
				}
			}
		}
		if (count > ans) ans = count;
		return;
	}

	copymap(map,m);

	for (int i = 0; i < W; i++) {
		for (int j = 0; j < H; j++) {
			if (map[j][i] > 0) {
				boom(j,i);
				remap();
				solve(index+1);
				copymap(m,map);
				break;
			}
		}
	}
}

int main() {
    int t;
    scanf("%d", &t);
    for (int tc = 1; tc <= t; tc++) {
        
	memset(map,0,sizeof(map));
	ans = 0; 
        scanf("%d %d %d", &N, &W, &H);

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> map[i][j];
		}
	}

	solve(0);
	
        printf("#%d %d", tc, ans);
    }
}
