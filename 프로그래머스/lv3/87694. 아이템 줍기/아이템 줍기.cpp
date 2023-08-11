#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };
vector<vector<int>> board(105, vector<int>(105, 0));

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    
    for(vector<int> coords: rectangle) {
        int minX = coords[0] * 2;
        int minY = coords[1] * 2;
        int maxX = coords[2] * 2;
        int maxY = coords[3] * 2;
        
        for(int i = minX; i <= maxX; i++)
            for(int j = minY; j <= maxY; j++)
                board[i][j] = 1;
    }
    for(vector<int> coords: rectangle) {
        int minX = coords[0] * 2;
        int minY = coords[1] * 2;
        int maxX = coords[2] * 2;
        int maxY = coords[3] * 2;
        
        for(int i = minX + 1; i < maxX; i++)
            for(int j = minY + 1; j < maxY; j++)
                board[i][j] = 0;
    }
    characterX *= 2;
    characterY *= 2;
    itemX *= 2;
    itemY *= 2;
    
    queue<pair<int, int>> q;
    q.push({characterX, characterY});
    board[characterX][characterY] = 0;
    
    while(!q.empty()) {
        int curX, curY;
        tie(curX, curY) = q.front(); 
        q.pop();
        
        if(curX == itemX && curY == itemY) break;
        
        for(int dir = 0; dir < 4; dir++) {
            int nx = curX + dx[dir];
            int ny = curY + dy[dir];
            if(board[nx][ny] == 1) {
                q.push({nx, ny});
                board[nx][ny] = board[curX][curY] + 1;     
            }
        }
    }
    
    answer = board[itemX][itemY] / 2;
    
    return answer;
}