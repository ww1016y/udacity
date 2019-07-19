#include <stdio.h>
#include <iostream>
#include <queue>
#include <string.h>
#include <vector>
#define MAX 11
using namespace std;
int map[MAX][MAX][8];
int M,A;
int user[2][101];
vector<pair<int, int>> user1;
vector<pair<int, int>> user2;
vector<pair<int, int>> BC;
vector<pair<int, int>> BC_info;
int power[8];

void cover(int a, int b, int i, int c, int d){
	
	int visit[MAX][MAX];
	memset(visit,0,sizeof(visit));
	queue<pair<int, int>> q;
	q.push(make_pair(a,b));
	visit[a][b] = 0;

	while(!q.empty()){
		int x =q.front().first;		
		int y =q.front().second;
		q.pop();
		for(int j=0; j<4; j++){
			int nx = x +dx[j];
			int ny = y +dy[j];
			if (nx < 1 || ny < 1 || nx > 10 || ny > 10) {
				continue;
			}
			if (visit[x][y] + 1 > c){
				continue;
			}
			visit[nx][ny] = visit[x][y] + 1;
			map[nx][ny][i] = d;
		}
	}

}

void trajectory(){

	int u1x =1; int u1y =1; int u2x=10; int u2y = 10;
	user1.push_back(make_pair(u1x,u1y));
	user2.push_back(make_pair(u1y,u2y));

	for (int i = 0; i <= 1; i++) {
	    	for (int j = 0; j <= M; j++) {
			if (user[i][j] == 0) {
				if (i == 0) {
					user1.push_back(make_pair(u1x,u1y));
				}
				else if (i == 1) {
					user2.push_back(make_pair(u2x,u2y));
				}
			}
			else if (user[i][j] == 1) { // 상우하좌
				if (i == 0) {
					u1x = u1x - 1;
					user1.push_back(make_pair(u1x,u1y));
				}
				else if (i == 1) {
					u2x = u2x - 1;
					user2.push_back(make_pair(u2x,u2y));
				}
			}
			else if (user[i][j] == 2) { 
				if (i == 0) {
					u1y = u1y + 1;
					user1.push_back(make_pair(u1x,u1y));
				}
				else if (i == 1) {
					u2y = u2y + 1;
					user2.push_back(make_pair(u2x,u2y));
				}
			}
			else if (user[i][j] == 3) { 
				if (i == 0) {
					u1x = u1x + 1;
					user1.push_back(make_pair(u1x,u1y));
				}
				else if (i == 1) {
					u2x = u2x + 1;
					user2.push_back(make_pair(u2x,u2y));
				}
			}
			else if (user[i][j] == 4) { 
				if (i == 0) {
					u1y = u1y - 1;
					user1.push_back(make_pair(u1x,u1y));
				}
				else if (i == 1) {
					u2y = u2y - 1;
					user2.push_back(make_pair(u2x,u2y));
				}
			}
		}
	}

}

int main() {
    int t;
    scanf("%d", &t);
    for (int tc = 1; tc <= t; tc++) {
        
        scanf("%d %d ", &M, &A);
	memset(user,0,sizeof(user));
	user1.clear(); user2.clear(); BC.clear(); BC_info.clear();

	for (int i = 0; i <= 1; i++) {
	    	for (int j = 0; j <= M; j++) {
			scanf("%d", &user[i][j]);	    
		}
	}

        trajectory();
	
	for (int i = 0; i < A; i++) {
	    int a,b,c,d;
	    scanf("%d %d %d %d ", &a, &b, &c, &d);
	    BC.push_back(make_pair(a,b));	    
	    BC_info.push_back(make_pair(c,d));
        }
	
	for (int i = 0; i < A; i++) {
		cover(BC[i].first,BC[i].second,i,BC_info[i].first,BC_info[i].second);	  
        }	
	
	int res1[8]; int index1 = 0; int sum =0;
	memset(res1,0,sizeof(res1));

	for (int i = 0; i <= M; i++) {
		for (int j =0; j<A; j++){
			if (map[user1[i].first][user1[i].second][j] != 0) {
				index1 = j;
				for (int j =0; j<A; j++){
					if (map[user2[i].first][user2[i].second][j] != 0) {
						if ( index1 == j) {
							temp = map[user1[i].first][user1[i].second][j];
						}
						else temp = map[user1[i].first][user1[i].second][j] + map[user2[i].first][user2[i].second][j];
					}
					if (res1[i] < temp) res1[i] =temp;
				}
			}
		}
	}
	for (int i =0; i<=M; i++) {
		sum = sum+res1[i];
	}

        printf("#%d %d\n", tc, sum);
    }
}

