#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, -1, 1, 0};
char dstr[4] = {'d', 'l', 'r', 'u'};
string answer = "";

int gn, gm, gr, gc, gk;

void dfs(int curX, int curY, int dist, string str) {
    if(answer != "") return;
    
    if(curX == gr && curY == gc && dist == gk) {
        answer = str;
        return;
    }
    
    if(dist >= gk) return;
    
    if(abs(gr - curX) + abs(gc - curY) > gk - dist) return;
    
    for(int dir = 0; dir < 4; dir++) {
        int nxtX = curX + dx[dir];
        int nxtY = curY + dy[dir];
        
        if(nxtX <= 0 || nxtX > gn || nxtY <= 0 || nxtY > gm) continue;
        
        dfs(nxtX, nxtY, dist + 1, str + dstr[dir]);
    }
}

string solution(int n, int m, int x, int y, int r, int c, int k) {
    int dist = abs(r - x) + abs(c - y);
    if(dist % 2 != k % 2 || dist > k) {
        return "impossible";
    }
    
    gn = n; gm = m; gr = r; gc = c; gk = k;
    
    dfs(x, y, 0, "");
    
    return answer;
}