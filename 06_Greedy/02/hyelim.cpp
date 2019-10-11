#include <string>
#include <cmath>
using namespace std;

int solution(string name) {
    int answer1 = min(name[0] - 'A', 'Z' - name[0] + 1);
    int answer2 = answer1;
    
    int length = name.length();
    for(int i = 1; i < length; i++) {
        bool check = true;
        for(int j = i; j < length; j++) {
            if(name[j] != 'A') {
                check = false;
                break;
            }
        }
        if(check)
            break;
        
        answer1++;
        answer1 += min(name[i] - 'A', 'Z' - name[i] + 1);
    }
    
    for(int i = length - 1; i > 0; i--) {
        bool check = true;
        for(int j = i; j > 0; j--) {
            if(name[j] != 'A') {
                check = false;
                break;
            }
        }
        if(check)
            break;
        
        answer2++;
        answer2 += min(name[i] - 'A', 'Z' - name[i] + 1);
    }
    
    return min(answer1, answer2);
}