#include <stdio.h>
#include <iostream>
#include <queue>
#include <string.h>
#include <vector>
#include <algorithm>
#define MAX 20
using namespace std;
int map[MAX][MAX];
int visit[MAX];
int N;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int ans;

void solve(int x, int y){
		
	if (map[x][y])


	for(int i =0; i<4; i++){
		int nx = x+dx[i];
		int ny = y+dy[i];

	}
}

int main() {
    int t;
    scanf("%d", &t);
    for (int tc = 1; tc <= t; tc++) {
        
	memset(map,0,sizeof(map));
	ans =0; 
        scanf("%d", &N, %M);

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

