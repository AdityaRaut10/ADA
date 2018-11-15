#include<bits/stdc++.h>
#define NO_OF_CHARS 256

using namespace std;

void build(string pat, int TF[][NO_OF_CHARS])
{
    int i, lps = 0, x;
    int m = pat.length();
    for (x =0; x < NO_OF_CHARS; x++) TF[0][x] = 0;

    TF[0][(int)pat[0]] = 1;

    for (i = 1; i<= m; i++)
    {
        for (x = 0; x < NO_OF_CHARS; x++)
            TF[i][x] = TF[lps][x];

        TF[i][(int)pat[i]] = i + 1;

        if (i < m)
          lps = TF[lps][(int)pat[i]];
    }
}

void dfa(string pat, string txt)
{
    int m = pat.length();
    int n = txt.length();
    int cou=0;
    int TF[m+1][NO_OF_CHARS];

    build(pat, TF);
    int i, j=0;

    for (i = 0; i < n; i++)
    {
       j = TF[j][(int)txt[i]];
       if(j==m){
            ++cou;
        cout<<"pattern found at index "<<i-m+1<<endl;
       }
    }
    if(cou==0) cout<<"Not found Anywhere\n";
}
int main()
{
    string pat, txt;
    cout<<"Pattern\tText\n";
    cin>>pat>>txt;

    cout<<endl;

    dfa(pat, txt);

    return 0;
}
