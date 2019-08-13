#include <stdio.h>
#include <iostream>
#include <queue>
#include <string.h>
#include <vector>
#include <algorithm>
#define MAX 15
using namespace std;
int map[MAX][MAX];
int visit[MAX][MAX];
int N, W, H;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int ans;

void remap(){

	for (int i = 0; i < W; i++) {
		for (int j = H-1; j >=0; j--) {
			if(map[j][i]>0) {
				q.push(map[j][i]);
			}			
		}
		for (int j = H-1; j >=0; j--) {
			if (!q.empty()){
				map[j][i] = q.front();	
				q.pop();
			}		
		}

	}
}

void boom(int x, int y){
	int val = map[x][y];
	map[x][y] = 0;
	for (int i =0; i<4; i++){
		for (int j = 1 ; j < val ; j++) {
			int nx = x + j*dx[i];
			int ny = y + j*dy[i];
			if (nx<0 || ny < 0 || nx >= N || ny >= N || map[nx][ny] == 0) continue;
			boom(nx,ny);
		}
	}
}

void solve(int index){
	
	int temp[MAX][MAX]= {0};

	if (index == N) {
		int count = 0;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				if (map[i][j] > 0) count = count + 1;
			}
		}
		if (ans > count) ans = count;

	}

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			temp[i][j] = map[i][j];
		}
	}

	for (int i = 0; i < W; i++) {
		for (int j = 0; j < H; j++) {
			if (map[j][i] == 1) {
				map[j][i] = 0;
				solve(index+1);
				for (int i = 0; i < H; i++) {
					for (int j = 0; j < W; j++) {
						map[i][j] = temp[i][j];
					}
				}
			}				
			else if (map[j][i] > 1) {
				boom(j,i);
				remap();
				solve(index+1);

				for (int i = 0; i < H; i++) {
					for (int j = 0; j < W; j++) {
						map[i][j] = temp[i][j];
					}
				}
			}			
		}
	}
}

int main() {
    int t;
    scanf("%d", &t);
    for (int tc = 1; tc <= t; tc++) {
        
	memset(map,0,sizeof(map));
	ans =987654321; 
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

