#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> board;

bool cmp(vector<int> &lhs, vector<int> &rhs) {
    return lhs[2] < rhs[2];
}

int find(int x) {
    if(board[x] == x) return x;
    else {
        return board[x] = find(board[x]);
    }
}

void unify(int x, int y) {
    x = find(x);
    y = find(y);
    if(x < y) board[y] = x;
    else board[x] = y;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    for(int i = 0; i < n; i++) board.push_back(i);
    sort(costs.begin(), costs.end(), cmp);
    
    for(vector<int> cost: costs) {
        if(find(cost[0]) == find(cost[1])) continue;
        unify(cost[0], cost[1]);
        answer += cost[2];
    }
    
    return answer;
}