#include <string>
#include <vector>

// #include <algorithm>


using namespace std;

void swap(vector<string>& vt, int a, int b) 
{
    string temp = vt[a];
    vt[a] = vt[b];
    vt[b] = temp;
}


// 답지로 본 결과에는 앞에 sorting을 이용하여 속도를 올림.

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";

    //sort(participant.begin(), participant.end());
    //sort(completion.begin(), completion.end());
    
    for (int i = 0 ; i < completion.size(); i++ )
    {
        for (int j = i ; j < participant.size(); j++)
        {
            if (completion[i] == participant[j])
            {
                swap(participant, i, j);
            }
        }
    }
    answer = participant.back();
    return answer;
}