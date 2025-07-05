#include<bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false), cin.tie(0)
#define endl '\n'
#define int long long
#define all(x) x.begin(),x.end()
#define pb push_back
#define YES cout<<"YES\n"
#define NO cout<<"NO\n"
#define check(x) cout << (#x) << " is " << (x) << endl;
const int mod = 1e9+7;
int a,b;
int fibo[47];

int abc(int n)
{
    if(b>fibo[n])
    {
        b = fibo[n+1]-b+1;
        swap(a,b);
        return n-1;
    }
    else if(b<=fibo[n-1])
    {
        swap(a,b);
        return n-1;
    }
    else return -1;
}

signed main()
{
    //freopen("","r+",stdin);
    //freopen("","w+",stdout);
    fibo[0]=fibo[1]=1;
    for(int i=2;i<47;i++)
    fibo[i]=fibo[i-1]+fibo[i-2];
    FastIO;
    int t=1;
    cin>>t;
    for(int z=1;z<=t;z++)
    {
        int n;
        cin>>n>>a>>b;
        while(n>1)
        {
            n=abc(n);
        }
        if(n==-1) NO;
        else YES;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
