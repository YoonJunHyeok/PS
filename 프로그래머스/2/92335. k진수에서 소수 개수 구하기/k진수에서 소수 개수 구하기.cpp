#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool check(long long num) {
    if(num == 1) return false;
    
    for(long long idx = 2; idx * idx <= num; idx++) {
        if(num % idx == 0) {
            return false;
        }
    }
    
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    
    vector<int> v;
    while(n > 0) {
        v.push_back(n % k);
        n /= k;
    }
    reverse(v.begin(), v.end());
    
    vector<long long> num;
    long long tmp = 0;
    for(int a: v){
        if(a == 0) {
            if(tmp != 0) {
                num.push_back(tmp);
                tmp = 0;
            }
        }
        else {
            tmp = tmp * 10 + a;
        }
    }
    if(tmp != 0) num.push_back(tmp);
    
    for(long long a: num) {
        if(check(a)) answer++;
    }  
    
    return answer;
}