#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    
    vector<int> idx;
    for(int i = 0; i < dungeons.size(); i++) idx.push_back(i);
    
    do{
        int cur_hp = k;
        int tmp_count = 0;
        for(int i = 0; i < idx.size(); i++) {
            int num = idx[i];
            if(cur_hp < dungeons[num][0]) break;
            cur_hp -= dungeons[num][1];
            tmp_count++;
        }
        answer = max(answer, tmp_count);
    }while(next_permutation(idx.begin(), idx.end()));
    
    return answer;
}