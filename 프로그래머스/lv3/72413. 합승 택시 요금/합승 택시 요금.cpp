#include <bits/stdc++.h>

using namespace std;

const int INF = 999999;

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;
    
    // initialize
    vector<vector<int>> m(n+1, vector<int> (n+1, INF));
    for(vector<int> fare: fares) {
        m[fare[0]][fare[1]] = fare[2];
        m[fare[1]][fare[0]] = fare[2];
    }
    for(int i = 1; i <= n; i++) m[i][i] = 0;
    
    // floyd-warshall
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(m[i][k] + m[k][j] < m[i][j]) {
                    m[i][j] = m[i][k] + m[k][j];
                }
            }
        }
    }
    
    answer = m[s][a] + m[s][b];
    for(int k = 1; k <= n; k++){
        answer = min(answer, m[s][k] + m[k][a] + m[k][b]);
    }
    
    return answer;
}