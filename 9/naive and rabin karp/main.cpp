#include <bits/stdc++.h>
#define ll int
#define d 256
using namespace std;
void sea(string a, string b, int q)
{
    int M = a.length();
    int N = b.length();
    ll i, j;
    int p = 0, t=0, h=1;

    for (i=0; i<M-1; i++)  h=(h*d)%q;

    for (i = 0; i < M; i++)
    {
        p = (d*p + a[i])%q;
        t = (d*t + b[i])%q;
    }

    for (i = 0; i <= N - M; i++)
    {
        if (p==t)
        {
            for (j = 0; j < M; j++)
            {
                if (b[i+j] != a[j]) break;
            }
            if (j == M)
                cout<<"Found at index "<<i<<endl;
        }
        if (i<N-M )
        {
            t = (d*(t - b[i]*h) + b[i+M])%q;

            if (t<0) t=(t+q);
        }
    }

}

void naive(string a, string b)
{
    int  m = a.length();
    int  n = b.length();
    bool poss = true;
    for(ll i=0; i<= (n-m); i++)
    {
        poss = true;
        st = i;
        en = i+m-1;
        for(ll j=0; j<m; j++)
        {
            if(b[i+j]!=a[j]){
                poss = false;
                break;
            }
        }
        if (poss){
            cout<<"Found string at index "<<i<<endl;
        }

    }
}
int main()
{
    string a, b;
    cin>>a>>b;
    //naive(a, b);
    ll q= 101;
    sea(a, b, q);
    return 0;
}
