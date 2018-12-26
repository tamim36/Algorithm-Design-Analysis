//Minimum number of coins to make specific values

#include <bits/stdc++.h>
using namespace std;

int minNumCoin(int coins[], int sz, int values)
{
    int table[values+1];
    memset(table, 999999, sizeof(table));
    table[0] = 0;

    for (int i=1; i<=values; i++){
        for (int j=0; j<sz; j++){
            if(coins[j] <= i){
                int sub_res = table[i-coins[j]];
                if (sub_res != 999999 && sub_res+1 < table[i])
                    table[i] = sub_res+1;
            }
        }
    }
    return table[values];
}

int main ()
{
    int coins[] = {1,2, 3};
    int values;
    int sz = sizeof(coins)/sizeof(coins[0]);
    cin >> values;
    int minCoin = minNumCoin(coins,sz, values);
    cout << minCoin << endl;
    return 0;
}
