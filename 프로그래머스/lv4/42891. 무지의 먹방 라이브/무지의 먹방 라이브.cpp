#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool timeCmp(pair<int, int> lhs, pair<int, int> rhs) {
    // 섭취하는데 걸리는 시간이 커지는 순으로
    return lhs.second < rhs.second;
}

bool idxCmp(pair<int, int> lhs, pair<int, int> rhs) {
    // idx 커지는 순으로 정렬
    return lhs.first < rhs.first;
}

// -> 여기까지는 떠올림, 구체적인 구현 못함.

int solution(vector<int> food_times, long long k) {
    int answer = 0;
    int numOfFoods = food_times.size();
    
    vector<pair<int, int>> foods;
    for(int idx = 0; idx < numOfFoods; idx++) {
        foods.push_back({idx + 1, food_times[idx]});
    }
    sort(foods.begin(), foods.end(), timeCmp);
    
    int leftOver = numOfFoods; // 남은 음식 개수
    int eaten = 0; // 이미 먹은 양 
    // -> *누적해서 더해주는 것이 아니라, 이전에 먹은 음식을 다 섭취하는데 걸리는 시간만 생각하면 됨.*
    for(int idx = 0; idx < numOfFoods; idx++) {
        pair<int, int> cur = foods[idx];
        long long timeNeed = (long long)(cur.second - eaten) * leftOver;
        if(timeNeed == 0) {
            leftOver--;
            continue;
        }
        else if(timeNeed <= k) {
            k -= timeNeed;
            eaten = cur.second;
            leftOver--;
        }
        else if(timeNeed > k) {
            break;
        }
    }
    
    if(leftOver <= 0) {
        return -1;
    }
    
    k %= leftOver;
    sort(foods.begin(), foods.end(), idxCmp);
    
    for(int idx = 0; idx < numOfFoods; idx++) {
        if(foods[idx].second - eaten <= 0) continue;
        if(k == 0) {
            answer = foods[idx].first;
            break;
        }
        k--;        
    }
    
    return answer;
}