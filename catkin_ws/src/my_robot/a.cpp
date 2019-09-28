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
int link[7][7];
//int visit[MAX][MAX];
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
vector<pair<int,int>> v;

void dfs(int start,int l, int sum){
	//cout << start_x << ' '<<  start_y << ' '<< '\n';
	int fin_flag = 0;
	for (int i = 2; i <= i_count; i++) {
		if (link[1][i] == 0){
			fin_flag = 1;	
			break;
		}
	}
	if (fin_flag == 0) {
		
		if (sum < ans) {
		ans = sum;

		
		}

		return;
	}

	for (int i = start; i < v.size(); i++) {
			//cout << i << ' '<<  j << ' '<< '\n';		
		for(int k = l; k<4; k++){			
			int d_count = 0;
			int flag = 0;
			int nx = v[i].first;
			int ny = v[i].second;	
			int temp = num_map[nx][ny];
			//cout << nx << ' '<<  ny << ' '<< k << ' '<<'\n';
			while(1){
				nx = nx + dx[k];
				ny = ny + dy[k];
				d_count = d_count + 1;
					
				if(nx < N && ny<M && nx >= 0 && ny >=0 && num_map[nx][ny]>0 && num_map[nx][ny] != temp){			
					d_count = d_count - 1;	
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
					int b[7][7];
					for(int q = 0 ;q<7;q++){
						for(int w = 0 ;w<7;w++){
							b[q][w] = link[q][w];
						}
					}
					link[temp][num_map[nx][ny]] = 1;	
					link[num_map[nx][ny]][temp] = 1;
					cout<< d_count << ' ';
					//cout << "xy:"<< v[i].first << ' ' << v[i].second << ' ' <<"nxny:"<< nx << ' ' <<ny << ' '<< d_count << ' ';
					for(int g =1; g<=i_count;g++){
						if( link[temp][g]== 1 && temp!=g && num_map[nx][ny]!=g){
							link[num_map[nx][ny]][g] = 1;
							link[g][num_map[nx][ny]] = 1;
						}
					}
					if (k==3){
						dfs(i+1,0,sum+d_count);
					}
					else {
						dfs(i,k+1,sum+d_count);
					}
					for(int q = 0 ;q<7;q++){
						for(int w = 0 ;w<7;w++){
							link[q][w] = b[q][w];
						}
					}
				}	
			}
		}
		l=0;
	}
}

void bfs(int x, int y){
	
	queue<pair<int,int>> q;
	q.push(make_pair(x,y));
	i_count = i_count + 1;
	num_map[x][y] = i_count;
	v.push_back(make_pair(x,y));

	while(!q.empty()){
		
		int nx = q.front().first;
		int ny = q.front().second;
		q.pop();

		for(int i = 0; i<4; i++){
			int nnx = nx + dx[i];
			int nny = ny + dy[i];

			if(nnx < N && nny<M && nnx >= 0 && nny >=0 && map[nnx][nny]==1 && visit[nnx][nny] == 0){
				q.push(make_pair(nnx,nny));
				num_map[nnx][nny] = i_count;
				visit[nnx][nny] = 1 ;
				v.push_back(make_pair(nnx,nny));
			}
		}
	}
}

int main() {
	int T=1;
	//cin >> T ;
	for(int t =0; t <T ; t++){
		cin >> N >> M ;
		ans = 987654321;

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
		dfs(0,0,0);	

		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cout << num_map[i][j];
			}
			cout << '\n';	
		}
		if (ans ==987654321){
			ans = -1;
		}
		cout <<  ans << '\n';	
	}
}
