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

int neg(int b, int x)
{
    for(int i=0;i<33;i++)
    {
        int c = (1LL<<i);
        if((x&(c))&&(b&c)) b^=c;
    }
    return b;
}

int abc(int x, int xanda, int xora)
{
    int a = xora;
    a = neg(a,x);
    a = a|xanda;
    return a;
}

signed main()
{
    //freopen("","r+",stdin);
    //freopen("","w+",stdout);
    //FastIO;
    int Master0fTheSEA=1;
    //cin>>Master0fTheSEA;
    for(int tttttttt=1;tttttttt<=Master0fTheSEA;tttttttt++)
    {
        int n,k;
        cin>>n>>k;
        vector<int>vec;
        cout<<"or 1 2"<<endl;int aub;cin>>aub;
        cout<<"or 2 3"<<endl;int buc;cin>>buc;
        cout<<"or 1 3"<<endl;int auc;cin>>auc;
        cout<<"and 1 2"<<endl;int anb;cin>>anb;
        cout<<"and 2 3"<<endl;int bnc;cin>>bnc;
        cout<<"and 1 3"<<endl;int anc;cin>>anc;
        int a = ((neg(aub,buc)|auc)|(neg(anb,bnc)|anc))/2;
        int b = abc(a,anb,auc);
        cout<<a<<" "<<b<<" "<<abc(b,bnc,buc)<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
