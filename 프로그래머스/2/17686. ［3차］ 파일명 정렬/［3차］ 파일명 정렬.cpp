#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

bool cmp(string lhs, string rhs) {
    string lhs_head = "", lhs_number_str = "";
    string rhs_head = "", rhs_number_str = "";
    
    int idx = 0;
    while(1) {
        if(lhs[idx] >= '0' && lhs[idx] <= '9') break;
        lhs_head += tolower(lhs[idx]);
        idx++;
    }    
    while(lhs[idx] >= '0' && lhs[idx] <= '9' && idx < lhs.length() && lhs_number_str.length() < 5) {
        lhs_number_str += lhs[idx];
        idx++;
    }
    
    idx = 0;
    while(1) {
        if(rhs[idx] >= '0' && rhs[idx] <= '9') break;
        rhs_head += tolower(rhs[idx]);
        idx++;
    }    
    while(rhs[idx] >= '0' && rhs[idx] <= '9' && idx < rhs.length() && rhs_number_str.length() < 5) {
        rhs_number_str += rhs[idx];
        idx++;
    }
    
    int lhs_number = stoi(lhs_number_str), rhs_number = stoi(rhs_number_str);
    
    if(lhs_head == rhs_head) {
        return lhs_number < rhs_number;
    }
    else {
        return lhs_head < rhs_head;
    }
}

vector<string> solution(vector<string> files) {
    stable_sort(files.begin(), files.end(), cmp);
    
    return files;
}