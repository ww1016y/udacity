#include <iostream>
#include <queue>
#include <string.h> // string.h 파일이 필요합니다.
#include <stdio.h>

#define MAX 20
using namespace std;

int N,M, ans;
int map[MAX][MAX];
int visit[MAX][MAX];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void cal(){
	
	int num =0;
	int res=0;
	for (int i = 1; i<=2*N-1 ; i++){
		int total = 0;	
		for (int j = 0; j<N ; j++){
			for (int k = 0; k<N ; k++){
				if(map[j][k] == 1 && visit[j][k] == i){
					res = res + M ;
					num = num + 1;
				}		
			}
		}
		total = res - (i*i + (i-1)*(i-1));
		if (total < 0) {
			continue;
		}
		else {
			if (num >ans) {
				ans = num;
				//printf("i = %d total = %d  ans = %d res = %d\n",i, total,ans,res);
			}
		}
	}
}


void bfs(int a, int b){
	
	queue<pair<int, int>> q;	
	q.push(make_pair(a,b));	
	visit[a][b] = 1;
	
	while(!q.empty()){

		int x = q.front().first;	
		int y = q.front().second;
		q.pop();		

		for (int i = 0; i<4 ; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];		
			if (nx < 0 || ny < 0 || nx> N-1 || ny > N-1 ){
				continue;
			}
			if (visit[nx][ny] > 0) continue;	
			if (visit[nx][ny] > N-1) continue;	
			q.push(make_pair(nx,ny));
			visit[nx][ny] = visit[x][y] +1;	
		}		
	}
}

int main(){
	int Test;
	cin >> Test ; 
	for(int t = 1 ; t<=Test; t++){
		cin >> N >> M ;
		memset(map,0,sizeof(map));
		ans =0;

		for (int i = 0; i<N ; i++){
			for (int j = 0; j<N ; j++){
				cin >> map[i][j] ;					
			}
		}

		for (int i = 0; i<N ; i++){
			for (int j = 0; j<N ; j++){
				memset(visit,0,sizeof(visit));
				bfs(i,j);	
				cal();				
			}
		}
		cout << '#' << t << ' '<< ans ;
	}
}
