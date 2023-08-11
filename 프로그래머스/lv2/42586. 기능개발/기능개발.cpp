#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    int total = progresses.size();
    int day = 0;
    int release = 0;
    for(int i = 0; i < total; i++){
        int cur_progress = progresses[i] + (speeds[i] * day);
        if (cur_progress >= 100) {
            release++;
        }
        else{
            if(release != 0) {
                answer.push_back(release);
                release = 0;
            }
            int need_day = (100 - cur_progress) / speeds[i];
            if((100 - cur_progress) % speeds[i] != 0) need_day++;
            day += need_day;
            release++;
        }
    }
    answer.push_back(release);
    
    return answer;
}