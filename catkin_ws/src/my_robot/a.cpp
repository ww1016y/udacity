#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>

using namespace std;

#define MAX 51
int N;
int ans;

int map[MAX][MAX];
int visit[MAX][MAX][2];

int dx[] = {0,-1,1,0,0};
int dy[] = {0,0,0,1,-1};
vector <pair<int, int>> v;

int arr[9];

void solve(int index, int num) {
   
   
   if (num == 9) {
      if (arr[4] == map[0][3]){
      int k = 1;
      int point = 0;
      for (int i = 0; i < N; i++) {
         int out = 0;
         int game[4] = {0};
         while (1){
            
            int j = arr[k] ;

            if (map[i][j] == 0){
               out = out + 1;
               if (out == 3) {
                  k = k + 1;
                  if ( k > 9){
                     k = k % 9;
                  }
                  break;
               }
            }
            else if (map[i][j] == 1){
               if (game[2] == 1){
                  point = point + 1;
               }
               game[2] = game[1];
               game[1] = game[0];
               game[0] = 1;
            }
            else if (map[i][j] == 2){
               if (game[1] == 1){
                  point = point + 1;
               }
               if (game[2] == 1){
                  point = point + 1;
               }
               game[2] = game[0];
               game[1] = 1;
               game[0] = 0;
            }
            else if (map[i][j] == 3){
               if (game[0] == 1){
                  point = point + 1;
               }
               if (game[1] == 1){
                  point = point + 1;
               }
               if (game[2] == 1){
                  point = point + 1;
               }
               game[2] = 1;
               game[1] = 0;
               game[0] = 0;
            }
            else if (map[i][j] == 4){
               if (game[0] == 1){
                  point = point + 1;
               }
               if (game[1] == 1){
                  point = point + 1;
               }
               if (game[2] == 1){
                  point = point + 1;
               }
               point = point + 1;
               game[2] = 0;
               game[1] = 0;
               game[0] = 0;
            }
            k = k + 1;
            if ( k > 9){
               k = k % 9;
            }
         }
      }

      if (point > ans) ans =point;
      return;
      }
      else {
         return;
      }
   }
   
   if (index > 9) index = index % 9;
   cout << arr[num]<<' ' << num+1 << ' ' << index << '\n'; 
   arr[num+1] = index+1;
   solve(index+1,num+1);
   arr[num+1] = 0;

   solve(index+1,num);

   return;
}

int main() {

   cin >> N;
   ans = 0;

   for (int i = 0; i < N; i++) {
      for (int j = 0; j < 9; j++) {
         cin >> map[i][j];
      }
   }

   for (int i = 1; i <= 9; i++) {
      arr[1]=i;   
      solve(i, 1);
      arr[1]=0;
   }

   cout << ans;
}
