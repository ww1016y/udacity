#include <stdio.h>
#include <iostream>
#include <queue>
#include <string.h>
#include <vector>
#define W_MAX 12
#define H_MAX 15
using namespace std;
int map[H_MAX][W_MAX];
int ex[H_MAX][W_MAX];


int N, W, H;

void boom(int j, int i){

	int x = j;
	int y = i;

	int until=ex[j][i];
	ex[j][i] = 0;
	for (int k = 0; k<4; k++){
		for (int l =0; l<until-1; l++){
			x = x + dx[k];
			y = y + dy[k];
			if (ex[x][y] > 0){
				boom(x,y);
			}

		}
	}
}

void rearrange(){

	for (int i = 0; i < W; i++) {
	    	for (int j = 0; j < H; j++) {
			if ( ex[j][i] > 0) {
				for (int k = j+1; k < H; k++) {
					if ( ex[k][i] == 0) {
						ex[k][i]  = ex[j][i];			
					}	   
				}   				
			}			
		}
	}
}

void solve(int count, int temp[]){

	if (count == 4) {

		return;
	}

	for (int i = 0; i < W; i++) {
	    	for (int j = 0; j < H; j++) {
			if ( temp[j][i] > 0) {
				
				for (int a = 0; a < H; a++) {
				    	for (int b = 0; b < W; b++) {
						ex[i][j] = temp[a][b];	    
					}
				}
				boom(j,i);

				rearrange();
			

				for (int a = 0; a < H; a++) {
				    	for (int b = 0; b < W; b++) {
						temp[i][j] = ex[a][b];	    
					}
				}



				solve(count+1,temp);
	
			}	   
		}
	}

}

int main() {
    int t;
    scanf("%d", &t);
    for (int tc = 1; tc <= t; tc++) {
        
        scanf("%d %d %d", &N, &W, &H);
	
	memset(map, 0, sizeof(map));
	int temp[H_MAX][W_MAX];

	for (int i = 0; i < H; i++) {
	    	for (int j = 0; j < W; j++) {
			scanf("%d", &map[i][j]);
			temp[i][j] = map[i][j];	    
		}
	}

        solve(1,temp);

        printf("#%d %d\n", tc, sum);
    }
}

