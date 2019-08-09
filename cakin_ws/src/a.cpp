#include <stdio.h>
#include <iostream>
#include <queue>
#include <string.h>
#include <vector>
#include <algorithm>
#define MAX 16
using namespace std;
int map[MAX][MAX];
int visit[MAX];
int N;

//int dx[4] = {0,1,0,-1};
//int dy[4] = {1,0,-1,0};
int ans;

void solve(int index, int count_num){
	
	if (index == N) {
		int temp1 = 0;
		int temp2 = 0;
		int res = 0;
		for (int i = 0; i < N; i++) {
			if (visist[i] == 1) {
				for (int j = 0; j < N; j++) {
					if (visist[j] == 1) {
						temp1 = temp1+ map[i][j];
					}
				}
			}
			else if (visist[i] == 0)  {
				for (int j = 0; j < N; j++) {
					if (visist[j] == 1) {
						temp2 = temp2+ map[i][j];
					}
				}
			}						
		}
		res = temp1 - temp2;
		if (res < 0) res = -res;
		if ( res < ans ) ans = res;
	}	

	if (count_num > 0) {
		visit[index] = 1;
		solve(index+1,count_num-1);
		visit[index] = 0;
	}
	
	solve(index+1,count_num);
}

int main() {
    int t;
    scanf("%d", &t);
    for (int tc = 1; tc <= t; tc++) {
        
	memset(map,0,sizeof(map));
	ans =987654321; 
        scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

        solve(0,N/2);
	
        printf("#%d %d", tc, ans);
    }
}

