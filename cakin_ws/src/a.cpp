#include <stdio.h>
#include <iostream>
#include <queue>
#include <string.h>
#include <vector>
#include <algorithm>
#define MAX 100
using namespace std;
int map[MAX][MAX][2];
int visit[MAX][MAX];
int N, M, K;

int dx[4] = {1,-1,0,0}; // 1,2,3,4 상 하 좌 우
int dy[4] = {0,0,-1,1};
int ans;
vector <pair<int, int>> d;
vector <pair<int, int>> vir;

void solve(int index){

	if (index == M) {


		return;
	}

	for (int k = 0; k < K; k++) {

		if (d[k].front().first != 0) {
			int x = vir[k].front().first;
			int y = vir[k].front().second;
			
			int nx = x + dx[d[k].front().second-1];
			int ny = y + dy[d[k].front().second-1];
			if (nx == 0 || ny == 0 || nx == N -1 || ny == N-1){
				d[k].front().first = d[k].front().first/2;
				if (d[k].front().second == 1){
					d[k].front().second = 2;
				}
				else if (d[k].front().second == 2){
					d[k].front().second = 1;
				}
				else if (d[k].front().second == 3){
					d[k].front().second = 4;
				}
				else if (d[k].front().second == 4){
					d[k].front().second = 3;
				}
			}
			vir[k].front().first =nx;
			vir[k].front().second =ny;
			if (map[nx][ny][0] < d[k].front().first) {
				map[nx][ny][0] = d[k].front().first;
				map[nx][ny][1] = map[nx][ny][1]+ 1;
			}
		}
	}

	for (int i = 0 ; i<N ; i++) {
		for (int j = 0 ; j<N ; j++) {
			if (map[i][j][1] > 1){
				for (int k = 0; k < K; k++) {
					if (vir[k].front().first == i && vir[k].front().second == j && map[i][j][0] != d[k].front().first) {
						
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
	ans =0; 
        scanf("%d %d %d", &N, &M, &K);

	for (int i = 0; i < K; i++) {
		int x,y,num,dir;
		cin >> x >> y >> num >> dir;
		//map[x][y][0] = num;
		vir.push_back(make_pair(x,y));
		d.push_back(make_pair(num,dir));
	}

	solve(0);
        	
        printf("#%d %d", tc, ans);
    }
}

