#include<iostream>
#include<stdio.h>
#include<queue>
#include<vector>

#define MAX 101

using namespace std;

int N, K, L;
int ap[MAX][MAX];
vector <pair<int, int>> v;
vector <pair<int, int>> snake;
int ans;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void solve() {

	snake.push_back(make_pair(1,1));

/*	if (ap[1][2] == 1) {
		ap[1][2] = 0;
		snake[0].second = 2;
		snake.push_back(make_pair(1, 1));
	}
	else {
	
		snake[0].second = 2;
	}
	*/
	//ans = ans + 1;

	int k = 0;
	int dir = 0;

	while (1) {
		
		int end_flag = 0;
		int add_flag = 0;

		

		if (k<v.size() && ans == v[k].first ) {
			
			dir = dir + v[k].second;
			if (dir > 3) dir = 0;
			else if (dir < 0) dir = 3;
			
			int nx = snake[0].first + dx[dir];
			int ny = snake[0].second + dy[dir];
			
			if (nx <= 0 || ny <= 0 || nx > N || ny > N) { ans = ans + 1; break; }

			for (int i = 1; i < snake.size(); i++) {
				if (nx == snake[i].first && ny == snake[i].second) end_flag = 1;
			}

			if (ap[nx][ny] == 1) add_flag = 1;
			
			if (end_flag == 1) { ans = ans + 1; break; }
			else {

				int next_x = snake[0].first;
				int pre_save_x = snake[0].first;
				int next_y = snake[0].second;
				int pre_save_y = snake[0].second;
				snake[0].first = nx;
				snake[0].second = ny;
				for (int i = 1; i < snake.size(); i++) {
					pre_save_x = snake[i].first;
					pre_save_y = snake[i].second;

					snake[i].first = next_x;
					snake[i].second = next_y;

					next_x = pre_save_x;
					next_y = pre_save_y;
				}
				if (add_flag == 1) {
					snake.push_back(make_pair(next_x, next_y));
					add_flag = 0;
				}
					
				k = k + 1;
				ans = ans + 1;
			}
		}
		else {
	//		cout << "a";
			int nx = snake[0].first + dx[dir];
			int ny = snake[0].second + dy[dir];
	//		cout << "a";
			if (nx <= 0 || ny <= 0 || nx > N || ny > N) { ans = ans + 1; break; }
//			cout << "a";
		//	cout << nx << ' ' << ny << '\n';

			for (int i = 1; i < snake.size(); i++) {
			//	cout << snake[i].first << ' ' << snake[i].second << '\n';
				if (nx == snake[i].first && ny == snake[i].second) {
					
					end_flag = 1;
				}
			}
		//	cout <<  '\n';

			if (ap[nx][ny] == 1) add_flag = 1;

			if (end_flag == 1) { ans = ans + 1; break; }
			else {

				int next_x = snake[0].first;
				int pre_save_x = snake[0].first;
				int next_y = snake[0].second;
				int pre_save_y = snake[0].second;
				snake[0].first = nx;
				snake[0].second = ny;
				for (int i = 1; i < snake.size(); i++) {
					pre_save_x = snake[i].first;
					pre_save_y = snake[i].second;

					snake[i].first = next_x;
					snake[i].second = next_y;

					next_x = pre_save_x;
					next_y = pre_save_y;
					
				}
				if (add_flag == 1) {
					snake.push_back(make_pair(next_x, next_y));
					add_flag = 0;
				}
				ans = ans + 1;
			}
		}
	}
}


int main() {

	cin >> N;
	cin >> K;

	for (int i = 0; i < K; i ++) {
		int x, y;
		cin >> x >> y;
		ap[x][y] = 1;
	}
	cin >> L;

	for (int i = 0; i < L; i++) {
		int t;
		char dir;
		cin >> t >> dir;
		if (dir == 'D') { //오른쪽
			v.push_back(make_pair(t,1));
		}
		else if (dir == 'L') { //오른쪽
			v.push_back(make_pair(t, -1));
		}
	}

	solve();

	cout << ans;

	return 0;
}
