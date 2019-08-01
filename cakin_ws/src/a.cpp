#include <stdio.h>
#include <iostream>
#include <queue>
#include <string.h>
#include <vector>
#include <algorithm>
#define H_MAX 15
#define W_MAX 12
using namespace std;
int map[H_MAX][W_MAX];

int N, W, H;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int min_count;

void boom(int x, int y){

	int re = map[x][y];
	map[x][y] = 0;

	for (int j = 1; j < re ; j++) {
		for(int i = 0; i < 4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= H || ny >= W || map[x][y] == 0){
				continue;
			}	
			boom(nx,ny);		
		}
	}
	return;
}

void remap(){

	for (int j = 0; j < W; j++) {
		queue<int> q;			
		for (int i = H-1; i >= 0; i--) {			
			if (map[i][j] > 0) {
				q.push(map[i][j]);
			}
		}
		int temp = q.size();
		for (int k =H-1; k>=0; k--) {		
			if (!q.empty()) {
				map[k][j] = q.front();	
				q.pop();
			}
			else {
				map[k][j] = 0;
			}
		}				
	}
	return;
}

void solve(int num){
	
	if (num == N) {
		int count =0;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				if ( map[i][j] > 0) count = count +1;
			}
		}

		if (count < min_count) min_count = count;
		return;
	}

	for (int j = 0; j < W; j++) {
		for (int i = 0; i < H; i++) {
			if ( map[i][j] > 0) {
				int tempmap[H_MAX][W_MAX];

				for (int i = 0; i < H; i++) {
					for (int j = 0; j < W; j++) {
						tempmap[i][j] = map[i][j];
					}
				}

				boom(i,j);
				remap();
				solve(num+1);

				for (int i = 0; i < H; i++) {
					for (int j = 0; j < W; j++) {
						map[i][j] = tempmap[i][j];
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
	min_count =987654321; 
        scanf("%d %d %d", &N, &W, &H);

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> map[i][j];
		}
	}

        solve(1);
	
        printf("#%d %d", tc, min_count);
    }
}

