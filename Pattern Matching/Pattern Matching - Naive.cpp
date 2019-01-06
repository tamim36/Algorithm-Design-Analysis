#include <bits/stdc++.h>
using namespace std;

void patternMatch(string txt, string pat)
{
    int flag = 0;
    int lenP = pat.length();
    int lenT = txt.length();

    for (int i=0; i<=lenT-lenP; i++){
        for (int j=0; j<lenP; j++){
            if (txt[i+j] == pat[j])
                flag++;
            else
                flag = 0;
        }
        if (flag == lenP)
            cout << "pattern found at position " << i+1 << endl;
    }
}

int main()
{
    string txt = "worHello world";
    string pat = "wor";
    patternMatch(txt, pat);
    return 0;
}
