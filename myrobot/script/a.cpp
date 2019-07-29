#include <stdio.h>
#include <iostream>
#include <queue>
#include <string.h>
#include <vector>
#define MAX 100
using namespace std;
int map[MAX][MAX];

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int N, M, K;
vector<pair<int, int>> virus;
vector<pair<int, int>> info;

void solve(){
	
	for (int m =0; m<M; m++) {
		int map[MAX][MAX][4];
		memset(map,0,sizeof(map));

		for (int i = 0; i < K; i++) {
			if (info[i].first == 0){
				continue;
			}
			else {
				int x = virus[i].first;
				int y = virus[i].second;

				x = x +dx[info[i].second-1];
				y = y +dy[info[i].second-1];
				virus[i].first = x;
				virus[i].second = y;
				if ( x == 0 || y == 0 || x == N-1 || y ==N-1) {
					info[i].first = info[i].first/2;
					if ( info[i].second == 1) info[i].second = 2;
					else if ( info[i].second == 2) info[i].second = 1;
					else if ( info[i].second == 3) info[i].second = 4;
					else if ( info[i].second == 4) info[i].second = 3;
				}
				else {
					map[x][y][0] = map[x][y][0] + 1;
					map[x][y][1] = map[x][y][1] + info[i].first;
					if (map[x][y][2]< info[i].first) {
						map[x][y][2]= info[i].first;
						map[x][y][3]= i;
					}
				}
			}
		}
		for (int i = 0; i<N; i++){
			for (int j = 0; j<N; j++){
				if (map[i][j][0]>2){
					for (int k = 0; k<K; k++){
						if ( k == map[i][j][3]) { 
							info[k].first = map[i][j][1];
						}					
						else if ( virus[k].first == virus[map[i][j][3]].first && virus[k].second == virus[map[i][j][3]].second ) {
							info[k].first = 0;
						}
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
        
        scanf("%d %d %d", &N, &M, &K);
	
	int max_count =0; 

	for (int i = 0; i < K; i++) {
		int a,b,c,d;
	    	scanf("%d %d %d %d", &a, &b, &c, &d);
		virus.push_back(make_pair(a,b));
		info.push_back(make_pair(c,d));
	}

        solve();
	for (int i = 0; i < K; i++) {
		max_count = max_count + info[i].first;
	}
	virus.clear();
	info.clear();
        printf("#%d %d", tc, max_count);
    }
}

