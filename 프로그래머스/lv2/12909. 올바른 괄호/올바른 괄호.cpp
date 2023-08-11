#include<string>
#include <iostream>
#include <queue>

using namespace std;

bool solution(string s)
{
    bool answer = true;

    queue<int> q;
    for(char c: s){
        if(c == '(') q.push(1);
        else if(c == ')') {
            if (q.empty()){
                answer = false;
                break;
            }
            else q.pop();
        }
    }
    
    if(!q.empty()) answer = false;

    return answer;
}