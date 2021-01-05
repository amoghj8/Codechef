#include <bits/stdc++.h>
using namespace std;

#define REP_n(i,n) for(int i=1;i<=n;i++)
#define REP_m(i,m) for(int i=1;i<=m;i++)

int t,n,m, johnSum, jackSum;
priority_queue <int, vector<int>, greater<int> > johnPQ;
priority_queue <int, vector<int>> jackPQ;

int findSteps() {
    int steps = 0;
    while(!johnPQ.empty() && !jackPQ.empty()) {
        int johnTop = johnPQ.top();
        int jackTop = jackPQ.top();
        johnSum = johnSum - johnTop + jackTop;
        jackSum = jackSum - jackTop + johnTop;
        jackPQ.pop();johnPQ.pop();
        jackPQ.push(johnTop);
        johnPQ.push(jackTop);
        steps++;
        if(johnSum>jackSum)
            return steps;
        if(steps==n)
            break;
    }
    return steps;
}
        
int main() {
    cin >> t;
    while(t--) {
        cin >> n >> m;
        johnPQ = {};
        jackPQ = {};
        johnSum = jackSum = 0;
        REP_n(i,n) {
            int temp;
            cin >> temp;
            johnSum+=temp;
            johnPQ.push(temp);
        }
        REP_m(i,m) {
            int temp;
            cin >> temp;
            jackSum+=temp;
            jackPQ.push(temp);
        }
        if(johnSum>jackSum) {
            cout << 0 << endl;
            continue;
        }
        int steps = findSteps();
        if(jackSum<johnSum) {
            cout << steps << endl;
        }
        else {
            cout << -1 << endl;
        }
    }
	return 0;
}
