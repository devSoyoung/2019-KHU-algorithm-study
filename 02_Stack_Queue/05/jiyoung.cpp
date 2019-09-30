#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

int solution(string arrangement) {
    int answer = 0;
    int stick_num = 0;
  //  stack<int> s;
    
    for(int i=0; i<arrangement.size();i++){
        if(arrangement[i]=='('){
            stick_num++;
        }
        else{ // ')'
            if(arrangement[i-1]=='(') {// () -> 레이저
                stick_num--;
                answer+=stick_num; //stick_num만큼 자름
            }
            else{ // 쇠막대기
                stick_num--;
                answer++; // stick의 끝의 잘린 부분
            }
        }
    }
    return answer;
}