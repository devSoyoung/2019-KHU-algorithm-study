#include string
#include vector
#include map
#include iostream
using namespace std;

/*
	STL map 이용해서 풀었음. 
*/

string solution(vectorstring participant, vectorstring completion) {
    string answer = "";
    map<string, int> m;

    for(int i=0; i<completion.size();i++){
        if(m.find(completion[i])==m.end())// not found
            m.insert(make_pair(completion[i], 1));
        else  //found
            m[completion[i]]++;  
    }
     for(int i=0; i<participant.size();i++){
         m[participant[i]]--;
         if( m[participant[i]],  0)
            return participant[i];
     }
 return answer;
}
