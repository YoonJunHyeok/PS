#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(vector<int> &lhs, vector<int> &rhs) {
    return lhs[1] < rhs[1];
}

int solution(vector<vector<int>> routes) {
    int answer = 0;
    for(vector<int> route: routes) {
        if(route[0] > route[1]) {
            int tmp = route[0];
            route[0] = route[1];
            route[1] = tmp;
        }
    }
    sort(routes.begin(), routes.end(), cmp);
    
    int curIdx = 0;
    while (curIdx < routes.size()) {
        int endPoint = routes[curIdx][1];
        curIdx++;
        while(curIdx < routes.size() && endPoint >= routes[curIdx][0]) {
            curIdx++;
        }
        answer++;
    }
    
    return answer;
}