#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> heights) {
    vector<int> answer(heights.size());
    for(int i=1; i< heights.size();i++){
        for(int j=i-1; j>=0 ; j--){
            if(heights[j]>heights[i]){
                answer[i]=j+1;
                break;
            }
        }
    }
    return answer;
}