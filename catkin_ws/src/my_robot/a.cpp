#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector <pair<int, int> > v;
int ans=987654321;
int check[6];
int map[11][11];

void solve(int num, int sum){

	int xgame_flag = 0;
	for(int j = 0; j < v.size(); j++){
		int x = v[j].first;
		int y = v[j].second;		
		if (map[x][y] == 1){
			xgame_flag = 1;			
			break;
		}
	}
	if (xgame_flag == 0 ){
		if (sum < ans){
			ans = sum;
		}
		return;
	}	

	for(int i = 4; i >= 0; i--){
//cout << i << ' ';
		for(int j = num; j < v.size(); j++){
//cout << i << ' ' << j << '\n';
			int x = v[j].first;
			int y = v[j].second;		
			if (map[x][y] == 1){
				int flag = 0;				
				for(int k = 0; k <= i; k++){
					if (x+k >= 10 || y+k >= 10) break;				
					if (map[x+k][y] == 0) break;
					if (map[x][y+k] == 0) break;
					if (map[x+k][y+k] == 0) break;	

					if (k == i) {
//if (i==1) cout << i << ' ' << j << '\n';
						flag = 1;
					}
				}
				if (flag == 1 && check[i+1] != 0 ){
					//int temp[10][10];
					/*for(int i = 0; i < 10 ; i++){
						for(int j = 0; j < 10 ; j++){
							temp[i][j] = map[i][j];
						}
					}*/

					check[i+1] = check[i+1] - 1;
					for(int k = 0; k <= i; k++){				
						map[x+k][y] = 0;
						map[x][y+k] = 0;
						map[x+k][y+k] = 0;	
					}
					solve(num+1,sum+1);
					for(int k = 0; k <= i; k++){				
						map[x+k][y] = 1;
						map[x][y+k] = 1;
						map[x+k][y+k] = 1;	
					}
					check[i+1] = check[i+1] + 1;
				}
			}		
		}
	}	

}

int main(){	
	for(int i = 0; i < 10 ; i++){
		for(int j = 0; j < 10 ; j++){
			cin >> map[i][j];
			if (map[i][j] > 0) v.push_back((make_pair(i,j)));
		}
	}
	for(int i = 1; i<6;i++){
		check[i] = 5;
	}
	solve(0,0);


	if (ans == 987654321){
		ans = -1;
	}
	cout << ans ;
}
