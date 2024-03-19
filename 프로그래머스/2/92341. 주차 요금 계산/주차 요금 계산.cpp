#include <string>
#include <vector>
#include <map>
#include <stack>
#include <cmath>

using namespace std;

int cal_minute(string tm) {
    return stoi(tm.substr(0, 2)) * 60 + stoi(tm.substr(3, 2));
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    
    map<string, int> m; // {차량번호, 이용시간}
    map<string, stack<string>> inTime; // {차량번호, 들어온 시간}
    
    for(string record: records) {
        string record_time = record.substr(0, 5);
        string car_number = record.substr(6, 4);
        string type = record.substr(11);
        
        if(type == "IN") {
            if(inTime.find(car_number) != inTime.end()) {
                inTime[car_number].push(record_time);
            }
            else {
                stack<string> tmp;
                tmp.push(record_time);
                inTime[car_number] = tmp;
            }
        }
        else {
            string last_in_time = inTime[car_number].top();
            inTime[car_number].pop();
            
            if(m.find(car_number) != m.end()) {
                m[car_number] += cal_minute(record_time) - cal_minute(last_in_time);    
            }
            else {
                m[car_number] = cal_minute(record_time) - cal_minute(last_in_time);
            }
        }
    }
    
    // stack에 남아있는 애들 
    string record_time = "23:59";
    for(auto iter: inTime) {
        if(iter.second.empty()) continue;
        
        string last_in_time = iter.second.top();
        
        m[iter.first] += cal_minute(record_time) - cal_minute(last_in_time);
    }
    
    for(auto iter: m) {
        if(iter.second <= fees[0]) {
            answer.push_back(fees[1]);
        }
        else {
            int fee = fees[1];
            int cnt = (iter.second - fees[0]) / fees[2];
            if((iter.second - fees[0]) % fees[2] != 0) cnt++;
            fee += fees[3] * cnt;
            answer.push_back(fee);
        }
    }
    
    return answer;
}