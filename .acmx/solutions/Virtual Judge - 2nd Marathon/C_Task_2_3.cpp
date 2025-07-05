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


const int mx = 1e7+5;
int ara[mx];
vector<int>prime;

void sieve()
{
    prime.pb(2);
    for(int i=4;i<mx;i+=2) ara[i]=1;
    for(int i=3;i<mx;i+=2)
    {
        if(!ara[i])
        {
            prime.pb(i);
            if(1LL*i*i>mx) continue;
            for(int j=i*i;j<mx;j+=i)
            {
                ara[j]=1;
            }
        }
    }
}

signed main()
{
    //freopen("","r+",stdin);
    //freopen("","w+",stdout);
    FastIO;
    int Master0fTheSEA=1;
    cin>>Master0fTheSEA;
    sieve();
    for(int tttttttt=1;tttttttt<=Master0fTheSEA;tttttttt++)
    {
        int n;
        cin>>n;
        int cnt = 0;
        for(int i=0;prime[i]<=n/2;i++)
        {
            int x = n-prime[i];
            if(x<2) break;
            if(!ara[x]) cnt++;
        }
        cout<<"Case "<<tttttttt<<": ";
        cout<<cnt<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
