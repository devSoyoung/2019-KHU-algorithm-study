#include <string>
#include <vector>
using namespace std;

long long solution(int N) {
    if (N == 1) {
        return 4;
    }
    
    long long answer = 0;
    vector<long long> tiles = { 1, 1 };
    for (int i = 2; i < N; i++) {
        // 앞의 두 값 이용해서 새 값 추가하기
        tiles.push_back(tiles[i - 2] + tiles[i - 1]);
    }
    return 2 * (tiles[N - 1] + tiles[N - 2] + tiles[N - 1]);
}