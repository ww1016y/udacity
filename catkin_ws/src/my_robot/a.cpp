#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

#define MAX 21
int N;
int ans;

int map[MAX][MAX];
int visit[MAX][MAX];

void copy(int a[][MAX], int b[][MAX]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			a[i][j] = b[i][j];
		}
	}
}

void solve(int index) {

	if (index == 1) {
	
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] > ans) {
					ans = map[i][j];
				}
				cout << map[i][j];
			}
			cout << '\n';
		}

		return;
	}

	int temp[MAX][MAX] = {0};
	copy(temp, map);
	cout << index << '\n';
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			
			//cout << temp[i][j];
		}
		//cout << '\n';
	}
	//cout << '\n';
	for (int k = 0; k < 4; k++) {
		
		if (k == 0) {
			for (int i = 0; i < N; i++) {
				queue <int> q;
				for (int j = N - 1 ; j >= 0; j--) {
					if (map[i][j] > 0) {
						q.push(map[i][j]);
					}
				}
				int temp = q.size();
				int pre = 0;
				
				for (int j = 0; j < temp; j ++) {
					if (pre == 0) {
						pre = q.front();
						q.pop();
						if (j == temp - 1) {
							q.push(pre);
						}
					}
					else {
						int num = q.front();
						q.pop();
						if (pre == num) {
							q.push(num * 2);
							pre = 0;
						}
						else {
							
							if (j == temp - 1) {
								q.push(pre);
								q.push(num);
							}
							else {
								q.push(pre);
							}
							pre = num;
						}
					}
				}
				for (int j = N - 1; j >= 0; j--) {
					if (!q.empty()) {
						map[i][j] = q.front();
						q.pop();
					}
					else {
						map[i][j] = 0;
					}
				}
			}
			
			solve(index + 1);
		}
		else if (k == 1) {
			for (int i = 0; i < N; i++) {
				queue <int> q;
				for (int j = N - 1; j >= 0; j--) {
					if (map[j][i] > 0) {
						q.push(map[j][i]);
						
					}
				}
				int temp = q.size();
				int pre = 0;

				for (int j = 0; j < temp; j++) {
					if (pre == 0) {
						pre = q.front();
						q.pop();
						if (j == temp - 1) {
							q.push(pre);
						}
					}
					else {
						int num = q.front();
						q.pop();
						if (pre == num) {
							q.push(num * 2);
							pre = 0;
						}
						else {

							if (j == temp - 1) {
								q.push(pre);
								q.push(num);
							}
							else {
								q.push(pre);
							}
							pre = num;
						}
					}
				}
				for (int j = N - 1; j >= 0; j--) {
					if (!q.empty()) {
						map[j][i] = q.front();
						
						q.pop();
					}
					else {
						map[j][i] = 0;
					}
				}
			}
			solve(index + 1);
		}
		else if (k == 2) {
			for (int i = 0; i < N; i++) {
				queue <int> q;
				for (int j = 0; j <N; j++) {
					if (map[i][j] > 0) {
						q.push(map[i][j]);
					}
				}
				int temp = q.size();
				int pre = 0;

				for (int j = 0; j < temp; j++) {
					if (pre == 0) {
						pre = q.front();
						q.pop();
						if (j == temp - 1) {
							q.push(pre);
						}
					}
					else {
						int num = q.front();
						q.pop();
						if (pre == num) {
							q.push(num * 2);
							pre = 0;
						}
						else {

							if (j == temp - 1) {
								q.push(pre);
								q.push(num);
							}
							else {
								q.push(pre);
							}
							pre = num;
						}
					}
				}
				for (int j = 0; j < N; j++) {
					if (!q.empty()) {
						map[i][j] = q.front();
						q.pop();
					}
					else {
						map[i][j] = 0;
					}
				}
			}

			solve(index + 1);
		}
		else if (k == 3) {
			for (int i = 0; i < N; i++) {
				queue <int> q;
				for (int j = 0; j < N; j++) {
					if (map[j][i] > 0) {
						q.push(map[j][i]);

					}
				}
				int temp = q.size();
				int pre = 0;

				for (int j = 0; j < temp; j++) {
					if (pre == 0) {
						pre = q.front();
						q.pop();
						if (j == temp - 1) {
							q.push(pre);
						}
					}
					else {
						int num = q.front();
						q.pop();
						if (pre == num) {
							q.push(num * 2);
							pre = 0;
						}
						else {

							if (j == temp - 1) {
								q.push(pre);
								q.push(num);
							}
							else {
								q.push(pre);
							}
							pre = num;
						}
					}
				}
				for (int j = 0; j < N; j++) {
					if (!q.empty()) {
						map[j][i] = q.front();

						q.pop();
					}
					else {
						map[j][i] = 0;
					}
				}
			}
			solve(index + 1);
		}
		copy(map, temp);
	}
		
	return;
}

int main() {

	cin >> N;
	ans = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	
	solve(0);
	cout << ans;
}
