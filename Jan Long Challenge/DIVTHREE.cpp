#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define REP(i,n) for(int i=1;i<=n;i++)

vi A_i(10000001,0);
int n,k,t,d;
long long int sum;
        
int main() {
    cin >> t;
    while(t--) {
        cin >> n >> k >> d;
        sum = 0;
        REP(i,n) {
            cin >> A_i[i];
            sum += A_i[i];
        }
        int contests = sum / k; 
        if(!contests) {
            cout << 0 <<endl;
        }
        else {
            cout << min(contests, d) << endl;
        }
    }
	return 0;
}
