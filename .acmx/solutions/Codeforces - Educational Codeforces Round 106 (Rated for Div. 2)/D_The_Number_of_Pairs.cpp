#include<bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false), cin.tie(0)
#define endl '\n'
//#define int long long
#define all(x) x.begin(),x.end()
#define pb push_back
#define YES cout<<"YES\n"
#define NO cout<<"NO\n"
#define check(x) cout << (#x) << " is " << (x) << endl;
const int MAXN = 2e7+15;

int c,d,x;

int spf[MAXN];


void sieve()
{
    spf[1] = 1;
    for (int i = 2; i < MAXN; i++)
        spf[i] = i;
    for (int i = 4; i < MAXN; i += 2)
        spf[i] = 2;
 
    for (int i = 3; i * i < MAXN; i+=2) {
        if (spf[i] == i) {
            for (int j = i * i; j < MAXN; j += i+i)
                if (spf[j] == j)
                    spf[j] = i;
        }
    }
}

int div(int x)
{
    int ct = 0;
    while(x!=1)
    {
        int op = spf[x];
        while(x!=1&&x%op==0) x/=spf[x];
        ct++;
    }
    return 1LL<<ct;
}

int abc(int y)
{
    int xy = x/y;
    if((xy+d)%(c)) return 0;
    int m = (xy+d)/(c);
    //cout<<m<<endl;
    //cout<<y<<" "<<c*m<<" "<<div(c*m)<<endl;
    return div(m);
}



signed main()
{
    //freopen("","r+",stdin);
    //freopen("","w+",stdout);
    //FastIO;
    int Master0fTheSEA=1;
    sieve();
    scanf("%d",&Master0fTheSEA);
    //cin>>Master0fTheSEA;
    for(int tttttttt=1;tttttttt<=Master0fTheSEA;tttttttt++)
    {
        scanf("%d %d %d",&c,&d,&x);
        //cin>>c>>d>>x;
        int cnt = 0;
        for(int i=1;i*i<=x;i++)
        {
            if(x%i==0)
            {
                cnt+=abc(i)+(i*i!=x)*abc(x/i);
            }
        }
        printf("%d\n",cnt);
        //cout<<cnt<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
