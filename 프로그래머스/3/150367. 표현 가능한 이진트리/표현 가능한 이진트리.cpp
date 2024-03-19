#include <string>
#include <vector>

using namespace std;

string to_decimal(long long num) {
    string res = "";
    while(num > 0) {
        res = to_string(num % 2) + res;
        num /= 2;
    }
    
    return res;
}

string to_full_decimal(string dec) {
    int cur_len = dec.length();
    int tobe_len = 2;
    while(tobe_len - 1 < cur_len) {
        tobe_len *= 2;
    }
    
    string zeros = "";
    for(int i = 0; i < tobe_len - 1 - cur_len; i++) {
        zeros += "0";
    }
    
    return zeros + dec;
}

bool is_all_zeros(string str) {
    for(char c: str) {
        if(c != '0') return false;
    }
    return true;
}

int check(string fullDec) {
    int len = fullDec.length();
    if(len == 1) return 1;
    
    int mid = len / 2;
    string left = fullDec.substr(0, mid);
    string right = fullDec.substr(mid + 1);
    
    if(fullDec[mid] == '1') return check(left) && check(right);
    else return is_all_zeros(left) && is_all_zeros(right);
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    
    for(long long num: numbers) {
        string dec = to_decimal(num);
        string fullDec = to_full_decimal(dec);
        answer.push_back(check(fullDec));
    }    
    
    return answer;
}