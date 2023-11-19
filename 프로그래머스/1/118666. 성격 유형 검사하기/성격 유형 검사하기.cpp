#include <string>
#include <vector>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    int result[4] = { 0 }; // R, C, J, A
    char options[4][2] = { {'R', 'T'}, {'C', 'F'}, {'J', 'M'}, {'A', 'N'} }; 
    
    for(int i = 0; i < survey.size(); i++) {
        int idx, PM; // plus or minus
        
        if(survey[i] == "RT" || survey[i] == "TR") idx = 0;
        else if(survey[i] == "FC" || survey[i] == "CF") idx = 1;
        else if(survey[i] == "MJ" || survey[i] == "JM") idx = 2;
        else idx = 3;
        
        if(survey[i] == "RT" || survey[i] == "CF" || survey[i] == "JM" || survey[i] == "AN") PM = 1;
        else PM = -1;
        
        if(choices[i] == 1) result[idx] += PM * 3;
        else if(choices[i] == 2) result[idx] += PM * 2;
        else if(choices[i] == 3) result[idx] += PM * 1;
        else if(choices[i] == 4) result[idx] += 0;
        else if(choices[i] == 5) result[idx] -= PM * 1;
        else if(choices[i] == 6) result[idx] -= PM * 2;
        else result[idx] -= PM * 3;
    }
    
    for(int i = 0; i < 4; i++) {
        if(result[i] >= 0) answer += options[i][0];
        else answer += options[i][1];
    }
    
    return answer;
}