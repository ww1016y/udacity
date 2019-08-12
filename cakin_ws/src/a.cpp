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

void solve(int a, int b, int val, int index){
	
	if (index == N) {
		

	}

	if (val == 1) {

		;

	}
	else {
		for (int i =0; i<4; i++){
			for (int j = 1 ; j < val ; j++) {
				int nx = a + j*dx[i];
				int ny = b + j*dy[i];
				if (nx<0 || ny < 0 || nx >= N || ny >= N || visit[nx][ny] != 0) continue;
				boom(nx,ny);
			}
		}

		remap();
	}

	

	for (int i = 0; i < W; i++) {
		for (int j = 0; j < H; j++) {
			if (map[j][i] > 0) {
				int temp = map[j][i];			
				map[j][i] = 0;
				solve(j,i,temp,0);
				map[j][i] = temp;
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

	for (int i = 0; i < W; i++) {
		for (int j = 0; j < H; j++) {
			if (map[j][i] > 0) {
				int temp = map[j][i];			
				map[j][i] = 0;
				solve(j,i,temp,0);
				map[j][i] = temp;
			}
		}
	}
        	
        printf("#%d %d", tc, ans);
    }
}

