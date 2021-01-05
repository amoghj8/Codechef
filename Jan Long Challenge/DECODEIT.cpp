#include <bits/stdc++.h>
using namespace std;

vector<char> charSet {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p'};

int getIndex(int index) {
    int returnVal;
    switch(index) {
        case 0: returnVal = 8;
                break;
        case 1: returnVal = 4;
                break;
        case 2: returnVal = 2;
                break;
        case 3: returnVal = 1;
                break;
    }
    return returnVal;
}


int main() {
	int t;
	cin >> t;
	while(t--) {
	    int n;
	    cin >> n;
	    string str;
	    cin >> str;
	    string result = "";
	    int count = 0;
	    int temp = 0;
	    for(int i=0;i<n;i++) {
	        count++;
	        temp += (getIndex(i%4)*(str[i]-'0'));
	        if(!(count%4)){
	            result += string(1,charSet[temp]); 
	            temp = 0;
	        }
	    }
	    cout << result << endl;
	}
	return 0;
}
