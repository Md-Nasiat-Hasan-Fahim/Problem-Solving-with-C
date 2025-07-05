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

vector<int>vec;

long long POW(long long n, long long r)
{
    if(r==0) return 1;
    long long res = POW(n,r/2);
    res = res*res;
    if(r%2) res*=n;
    return res;
}

int pqr(int a)
{
    int c = 0;
    while(a)
    {
        c = c*10+(a%10);
        a/=10;
    }
    return c;
}

void abc(int a, int b, int now, int c)
{
    vec.pb(a);
    if(c==18)
    {
        return;
    }
    if(now+b>=10)
    {
        return;
    }
    abc(10*a+now+b,b,now+b,c+1);
}

void abc1(int a, int b, int now, int c)
{
    vec.pb(a);
    if(c==18)
    {
        return;
    }
    if((now+b)>=10)
    {
        return;
    }
    abc1(((b+now)*POW(10,c))+a,b,now+b,c+1);
}

signed main()
{
    //freopen("","r+",stdin);
    //freopen("","w+",stdout);
    FastIO;
    int Master0fTheSEA=1;
    //cin>>Master0fTheSEA;
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            abc(j,i,j,1);
            abc1(j,i,j,1);
        }
    }
    sort(all(vec));
    //cout<<vec.size()<<endl;
    for(int tttttttt=1;tttttttt<=Master0fTheSEA;tttttttt++)
    {
        int n;
        cin>>n;
        cout<<*lower_bound(all(vec),n)<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
