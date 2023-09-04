#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>

using namespace std;

int N;
vector<pair<int, int>> tree;
map<int, int> nodeX;

bool cmp(vector<int> lhs, vector<int> rhs) {
    if(lhs[1] == rhs[1]) return lhs[0] < rhs[0];
    else return lhs[1] > rhs[1];
}

void setTree(int parentIdx, int childIdx) {
    int parentX = nodeX[parentIdx];
    int childX = nodeX[childIdx];
    if(parentX > childX) {
        if(tree[parentIdx].first == -1) tree[parentIdx].first = childIdx;
        else setTree(tree[parentIdx].first, childIdx);
    }
    else { // parentX < childX
        if(tree[parentIdx].second == -1) tree[parentIdx].second = childIdx;
        else setTree(tree[parentIdx].second, childIdx);
    }
}

void preorder(vector<int> *cur, int curIdx) {
    cur->push_back(curIdx + 1);
    if(tree[curIdx].first != -1) preorder(cur, tree[curIdx].first);
    if(tree[curIdx].second != -1) preorder(cur, tree[curIdx].second);
}

void postorder(vector<int> *cur, int curIdx) {
    if(tree[curIdx].first != -1) postorder(cur, tree[curIdx].first);
    if(tree[curIdx].second != -1) postorder(cur, tree[curIdx].second);
    cur->push_back(curIdx + 1);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    N = nodeinfo.size();
    for(int i = 0; i < N; i++) {
        tree.push_back({-1, -1});
        nodeinfo[i].push_back(i);
        nodeX[i] = nodeinfo[i][0];
    }
    sort(nodeinfo.begin(), nodeinfo.end(), cmp);
    
    int parentIdx = nodeinfo[0][2];
    for(int i = 1; i < N; i++) {
        int childIdx = nodeinfo[i][2];
        setTree(parentIdx, childIdx);
    }
    
    vector<int> tmp1;
    preorder(&tmp1, parentIdx);
    answer.push_back(tmp1);
    
    vector<int> tmp2;
    postorder(&tmp2, parentIdx);
    answer.push_back(tmp2);
    
    return answer;
}