#include<iostream>
#include<string>
using namespace std;
int main() {
    string p;
    int lnz[100000], nnums=1;
    cin >> p;
    lnz[p.size()-1] = p.size();
    for(int i=p.size()-2;i>=0;i--) {
        if(p[i+1] != '0')
            lnz[i] = i+1;
        else
            lnz[i] = lnz[i+1];
    }
    for(int c=lnz[0];c<p.size();c=lnz[c]) {
        if(lnz[c]-c > c || (lnz[c]-c == c && p[c] > p[0]))
            nnums=0;
        nnums++;
    }
    cout << nnums << '\n';
    return 0;
}