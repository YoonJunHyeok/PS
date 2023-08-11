#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    
    map<string, int> total_report;
    map<string, vector<string>> report_list;
    for(string id : id_list) {
        total_report[id] = 0;
        vector<string> tmp;
        report_list[id] = tmp;
    }
    
    for(string str : report) {
        string usr1 = str.substr(0, str.find(" "));
        string usr2 = str.substr(str.find(" ") + 1, str.length());
        
        vector<string> tmp = report_list[usr1];
        
        if(find(tmp.begin(), tmp.end(), usr2) != tmp.end()) continue;
        
        total_report[usr2]++;  
        tmp.push_back(usr2);
        report_list.erase(usr1);
        report_list[usr1] = tmp;
    }
    
    for(string id : id_list) {
        vector<string> list = report_list[id];
        int mail = 0;
        for(string report_id : list) {
            if(total_report[report_id] >= k) mail++;
        }
        answer.push_back(mail);
    }
    
    return answer;
}