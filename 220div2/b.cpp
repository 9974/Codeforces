#include <stdio.h>
#include <string.h>
typedef long long ll;

const int maxn = 100000 + 10;

char s[maxn];

int main(){
    scanf("%s", s);
    int len = strlen(s);
    ll ans = 1;
    for(int i = 0;i < len; i++) {
        if(i + 1 < len && s[i]-'0' + s[i+1]-'0' == 9) {
            int j = i+1, cnt = 2;
            while(j+1 < len && s[j]-'0'+s[j+1]-'0'==9)
                cnt++, j++;
            i = j;
            if(cnt % 2 != 0)
                ans *= cnt/2+1;
        }
    }
    printf("%I64d\n", ans);
    return 0;
}
