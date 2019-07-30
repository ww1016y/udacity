#include <iostream>
#include <stdio.h>
#include <string.h>
#define MAX 20
using namespace std;
int check[101];
int map[MAX][MAX];
int visit[MAX][MAX];
int N;
int ans;
int dx[4] = {1,1,-1,-1};
int dy[4] = {1,-1,-1,1};
void solve(int start_x, int start_y, int a, int b, int start_c,int flag){
 
   for (int i = 0;i < N; i++) {
           for (int j = 0;j < N; j++) {
             printf("%d",visit[i][j]);
     }
     printf("\n");
    }
    
     printf("\n");
 if (start_x == a && start_y == b && flag == 0 ) {
  printf("d");
  int res = 0;
  for (int i = 1; i < 101; i++) {
   if (check[i] == 1 ) {
    res = res + 1;
   }
  }
  
  if (res > ans) {
   ans = res;
  }
  return; 
 }
 
 int x = a;
 int y = b;
 
 for (int c = start_c; c < 4; c++) {
     int nx = x + dx[c];
  int ny = y + dy[c];
  
  if (nx < 0 || ny < 0 || nx >= N || ny >= N || visit[nx][ny] == 1){
   continue;
  }
  if (check[map[nx][ny]] == 1) {
   continue;
  }
  visit[nx][ny] = 1;
  check[map[nx][ny]] = 1;
  solve(start_x,start_y,nx,ny,c,0); 
  visit[nx][ny] = 0; 
  check[map[nx][ny]] = 0;  
 }
 return;
        
}
int main() {
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        cin >> N ;
        ans = 0;
        memset(map,0,sizeof(map));
        
        memset(check,0,sizeof(check));
        
        for (int a = 0; a < N; a++) {
            for (int b = 0; b < N; b++) {
                cin >> map[a][b];
            }
        }
        
        for (int a = 0; a < N; a++) {
         for (int b = 0; b < N; b++) {
          memset(visit,0,sizeof(visit));
           check[map[a][b]] = 1;
    solve(a,b,a,b,0,1);
    
    check[map[a][b]] = 0;
   }
  }
        
        cout <<"#"<< i<<' '<<  ans << endl;
    }
    return 0;
}

