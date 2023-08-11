#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    int y, x, dy, dx, ny, nx;
    int row = park.size();
    int column = park[0].size();
    map<char, pair<int, int>> m;
    
    // 1. init
    bool flag = false;
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < column; j++) {
            if(park[i][j] == 'S') {
                tie(y, x) = {i, j};
                flag = true;
                break;
            }
        }
        if(flag) break;
    }
    m['N'] = {-1, 0};
    m['S'] = {1, 0};
    m['W'] = {0, -1};
    m['E'] = {0, 1};
    
    // 2. move
    for(string route : routes) {
        char op = route[0];
        int n = route[2] - '0';
        tie(dy, dx) = m[op];        
        tie(ny, nx) = {y, x};
        bool flag = true;
        for(int i = 0; i < n; i++) {
            ny += dy;
            nx += dx;
            if(ny < 0 || ny >= row || nx < 0 || nx >= column || park[ny][nx] == 'X') {
                flag = false;
                break;
            }
        }
        if(flag) {
         y = ny;
         x = nx;   
        }
    }
    
    // 3. save
    answer.push_back(y);
    answer.push_back(x);
    
    return answer;
}