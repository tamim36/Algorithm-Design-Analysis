#include <bits/stdc++.h>
using namespace std;
int make;
#define max 100
int coin[] = {5, 8 , 10, 15, 18};
int dp[6][max];

int call (int i, int amount)
{
    if(i>=5){
        if (amount == 0) return 1;
        else return 0;
    }
    if(dp[i][amount] != -1) return dp[i][amount];
    int ret1 = 0, ret2 = 0;
    if (amount - coin[i] >= 0) ret1 = call(i, amount - coin[i]);
    ret2 = call(i+1, amount);
    return dp[i][amount] = ret1+ret2;
}

int main ()
{
    memset(dp, -1, sizeof(dp));
    while(cin >> make){
        cout << call(0, make) << endl;
    }
    return 0;
}
