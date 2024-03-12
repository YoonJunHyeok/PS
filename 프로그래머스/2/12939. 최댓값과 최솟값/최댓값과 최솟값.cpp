#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    
    vector<int> v;
    stringstream ss(s);
    
    string word;
    while (getline(ss, word, ' ')){
        v.push_back(stoi(word));
    }
    
    sort(v.begin(), v.end());
    
    answer += to_string(v[0]);
    answer += " " + to_string(v[v.size() - 1]);    
    
    return answer;
}