#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;
#define MAX 11
int N,M;
int ans;
int map[MAX][MAX];
int visit[MAX][MAX];
int num_map[MAX][MAX];
int i_count = 0;
int link[6][6];
//int visit[MAX][MAX];
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
vector<pair<int,int>> v[6];

void dfs(int start_x, int start_y, int l, int sum){
	//cout << start_x << ' '<<  start_y << ' '<< '\n';
	int fin_flag = 0;
	for (int i = 1; i < i_count; i++) {
		if (link[0][i] == 0){
			fin_flag = 1;	
			break;
		}
	}
	if (fin_flag == 0) {
		if (sum < ans) ans = sum;
		return;
	}

	for (int i = start_x; i < i_count; i++) {
		for (int j = start_y; j < v[i].size(); j++) {
			//cout << i << ' '<<  j << ' '<< '\n';
			
			
			for(int k = l; k<4; k++){
				int d_count = 0;
				int flag = 0;
				int nx = v[i][j].first;
			int ny = v[i][j].second;	
			int temp = num_map[nx][ny];
				while(1){
					nx = nx + dx[i];
					nx = ny + dy[i];
					d_count = d_count + 1;
					if(num_map[nx][ny]>0 && num_map[nx][ny] != temp){			
						flag = 1;
						break;
					}
					else if(num_map[nx][ny] == temp){
							
						break;
					}
					else if ( nx >= N || ny >=M || nx < 0 || ny <0){
						break;
					}		
				}
				
				if (d_count >= 2 && flag == 1){
					if(link[temp][num_map[nx][ny]] == 0){
						link[temp][num_map[nx][ny]] = 1;	
						link[num_map[nx][ny]][temp] = 1;
						for(int g =0; g<i_count;g++){
							if( link[temp][g]== 1){
								link[num_map[nx][ny]][g] = 1;
								link[g][num_map[nx][ny]] = 1;
							}
						}

						dfs(i,j,k+1,sum+d_count);
					}	
				}
			}
			l=0;
		}
		start_y=0;
	}

}

void bfs(int x, int y){
	
	queue<pair<int,int>> q;
	q.push(make_pair(x,y));
	i_count = i_count + 1;
	num_map[x][y] = i_count;
	v[i_count-1].push_back(make_pair(x,y));

	while(!q.empty()){
		
		int nx = q.front().first;
		int ny = q.front().second;
		q.pop();

		for(int i = 0; i<4; i++){
			int nnx = nx + dx[i];
			int nny = ny + dy[i];

			if(map[nnx][nny]==1 && visit[nnx][nny] == 0){
				q.push(make_pair(nnx,nny));
				num_map[nnx][nny] = i_count;
				visit[nnx][nny] = 1 ;
				v[i_count-1].push_back(make_pair(nnx,nny));
			}
		}
	}
}

int main() {
	int T=1;
	//cin >> T ;
	for(int t =0; t <T ; t++){
		cin >> N >> M ;
		ans = 0;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> map[i][j];
			}
		}
	
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] == 1 && visit[i][j] == 0){
					bfs(i,j);
				}
			}
		}
		
		dfs(0,0,0,0);	
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cout << num_map[i][j];
			}
			cout << '\n';	
		}

		//cout << '#' << t+1 << ' ' << ans << '\n';	
	}
}
