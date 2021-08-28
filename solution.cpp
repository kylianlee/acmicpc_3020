//
// Created by Kylian Lee on 2021/08/28.
//
#include <iostream>
#include <vector>
#define INF 1000000

using namespace std;

int main(){
  int N, H;
  cin >> N >> H;
  vector<int> stalagmite(H + 1, 0), stalactite(H + 1, 0);
  for (int i = 0; i < N; ++i) {
    int temp;
    cin >> temp;
    if(i % 2 == 0)
      stalagmite[temp]++;
    else
      stalactite[temp]++;
  }
  for(int i = H; i > 1; i--){
    stalagmite[i - 1] += stalagmite[i];
    stalactite[i - 1] += stalactite[i];
  }
  int min = INF, cnt;
  for (int i = 1; i < H + 1; ++i) {
    if(min > stalagmite[i] + stalactite[H + 1 - i]){
      min = stalagmite[i] + stalactite[H + 1 - i];
      cnt = 1;
    }
    else if(min == stalagmite[i] + stalactite[H + 1 - i])
      cnt++;
  }

  cout << min << ' ' << cnt << endl;
  return 0;
}
