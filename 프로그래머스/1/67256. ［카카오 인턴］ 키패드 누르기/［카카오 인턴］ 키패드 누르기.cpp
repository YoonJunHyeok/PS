#include <string>
#include <vector>
#include <cstdlib>

#define X first
#define Y second

using namespace std;

int dist(int ax, int ay, int bx, int by) {
    return abs(ax - bx) + abs(ay - by);
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    
    vector<pair<int, int>> dict;
    dict.push_back({3, 1});
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            dict.push_back({i, j});
        }
    }
    pair<int, int> l, r;
    l.X = 3, l.Y = 0;
    r.X = 3, r.Y = 2;
    
    for(int number: numbers) {
        pair<int, int> nxt = dict[number];
        if(number == 1 || number == 4 || number == 7) {
            l.X = nxt.X; l.Y = nxt.Y;
            answer += "L";
        }
        else if(number == 3 || number == 6 || number == 9) {
            r.X = nxt.X; r.Y = nxt.Y;
            answer += "R";
        }
        else {
            int leftDist = dist(nxt.X, nxt.Y, l.X, l.Y);
            int rightDist = dist(nxt.X, nxt.Y, r.X, r.Y);

            if((leftDist < rightDist) || ((leftDist == rightDist) && (hand == "left"))) {
                l.X = nxt.X; l.Y = nxt.Y;
                answer += "L";
            }
            else {
                r.X = nxt.X; r.Y = nxt.Y;
                answer += "R";
            }
        }
    }
    
    return answer;
}