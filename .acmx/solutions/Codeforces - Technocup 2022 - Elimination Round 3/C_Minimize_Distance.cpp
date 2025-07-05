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

int abc(int k, vector<int> &vec)
{
    if(vec.size()==0) return 0;
    sort(all(vec));
    int cnt = 0;
    int n = vec.size();
    cnt+=vec[n-1];
    int i = n-k-1;
    for(;i>-1;)
    {
        cnt+=2*vec[i];
        i-=k;
    }
    return cnt;
}

signed main()
{
    //freopen("","r+",stdin);
    //freopen("","w+",stdout);
    FastIO;
    int Master0fTheSEA=1;
    cin>>Master0fTheSEA;
    for(int tttttttt=1;tttttttt<=Master0fTheSEA;tttttttt++)
    {
        vector<int>vec1,vec2;
        int n,k;
        cin>>n>>k;
        for(int i=0;i<n;i++)
        {
            int a;
            cin>>a;
            if(a<0) vec1.pb(-a);
            else vec2.pb(a);
        }
        int cnt = abc(k,vec1)+abc(k,vec2);
        if(vec1.size()&&vec2.size())
        if(vec1.back()<vec2.back()) cnt+=vec1.back();
        else cnt+=vec2.back();
        cout<<cnt<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
