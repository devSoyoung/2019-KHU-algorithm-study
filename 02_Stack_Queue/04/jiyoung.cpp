#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> working_days(progresses.size()); // 각 기능이 완성될 때까지 걸리는 날
    for(int i=0; i< working_days.size();i++){ // working_days 계산
        working_days[i]=ceil((100-progresses[i])/(float)speeds[i]);
    }
    int pri_working_days=working_days[0]; // 주요(앞의) 기능의 working_days
    int cnt=1;
    for(int i=1; i< working_days.size();i++){
        if(working_days[i]>pri_working_days){ //pri_func_working_days보다 오래걸리면 앞의 기능 먼저 배포
            answer.push_back(cnt);
            pri_working_days=working_days[i];
            cnt=1;
        }
        else
            cnt++;
    }
    answer.push_back(cnt); // 마지막 남은 기능들 배포
    
    return answer;
}