#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    
    map<string, int> m1;
    map<int, string> m2;
    for(int i = 0; i < players.size(); i++) {
        m1.insert({players[i], i});
        m2.insert({i, players[i]});
    }
    
    for(string name1 : callings) {
        auto it1 = m1.find(name1);
        int rank1 = it1->second;
        int rank2 = rank1 - 1;
        auto it2 = m2.find(rank2);
        string name2 = it2->second;
        
        m1[name1] = rank2;
        m1[name2] = rank1;
        m2[rank1] = name2;
        m2[rank2] = name1;
    }
    
    for(auto it : m2) {
        answer.push_back(it.second);
    }
    
    return answer;
}