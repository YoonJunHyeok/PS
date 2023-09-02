#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

unordered_map<string, int> people;
unordered_map<string, string> superior;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer(enroll.size(), 0);
    
    for(int i = 0; i < enroll.size(); i++) {
        people[enroll[i]] = i;
        superior[enroll[i]] = referral[i];
    }
    
    for(int i = 0; i < seller.size(); i++) {
        string toWho = seller[i];
        int howMuch = amount[i] * 100;
        
        while(howMuch > 0 && toWho != "-") {
            if(howMuch / 10 > 0) {
                answer[people[toWho]] += (howMuch - howMuch / 10);
                toWho = superior[toWho];
                howMuch /= 10;
            }
            else {
                answer[people[toWho]] += howMuch;
                break;
            }
        }
    }
     
    return answer;
}