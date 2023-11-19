#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    for(int i = 0; i < n; i++) {
        string tmp = "";
        
        int n1 = arr1[i], n2 = arr2[i];
        
        for(int j = 0; j < n; j++) {
            if(!(n1 & 1) && !(n2 & 1)) {
                tmp = " " + tmp;
            }
            else {
                tmp = "#" + tmp;
            }
            
            n1 = n1 >> 1;
            n2 = n2 >> 1;
        }
        
        answer.push_back(tmp);
    }
    
    return answer;
}