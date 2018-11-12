#include <bits/stdc++.h>
using namespace std;
#define MAX 100

int weight[MAX];
int cost[MAX];
int cap, profit1, profit2, n;

int dp[MAX][32];
int items, limit;

int func (int i, int w)
{
    int prof1 = 0, prof2 = 0;

    if (i == items)
        return 0;

    if (dp[i][w] != -1)
       return dp[i][w];

    if (w + weight[i] <= limit)
        prof1 = cost[i] + func(i+1, w+weight[i]);
    else
        prof2 = 0;


    prof2 = func(i+1, w);

    dp[i][w] = max(prof1, prof2);
        return dp[i][w];
    //return max(prof1, prof2);
}

int main()
{
    //freopen("Output.txt", "w", stdout);
    int c,w;
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> w >> c;
        weight[i] = w;
        cost[i] = c;
    }
    cin >> cap;

    int res = func(1, 0);
    cout << res << endl;
    return 0;
}
