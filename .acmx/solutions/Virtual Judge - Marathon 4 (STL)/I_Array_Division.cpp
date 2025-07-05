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

signed main()
{
    //freopen("","r+",stdin);
    //freopen("","w+",stdout);
    FastIO;
    int Master0fTheSEA=1;
    //cin>>Master0fTheSEA;
    for(int tttttttt=1;tttttttt<=Master0fTheSEA;tttttttt++)
    {
        int n;
        cin>>n;
        vector<int>vec(n);
        for(int i=0;i<n;i++) cin>>vec[i];
        vector<int>pos,toss;
        toss = vec;
        pos.pb(vec[0]);
        for(int i=1;i<n;i++)
        {
            pos.pb(pos[i-1]+vec[i]);
        }
        for(int i=n-2;i>-1;i--) toss[i]+=toss[i+1];
        sort(all(toss));
        if(pos[n-1]%2)
        {
            NO;
            continue;
        }
        bool ans = false;
        int cnt = pos[n-1]/2;
        if(binary_search(all(pos),cnt)) ans = true;
        for(int i=0;i<n;i++)
        {
            if(cnt-vec[i]==0 || binary_search(pos.begin(),pos.begin()+i,cnt-vec[i])) ans = true;
            if(binary_search(toss.begin(),toss.begin()+n-i-1,cnt-vec[i])) ans = true;
        }
        //cout<<binary_search(toss.end(),toss.begin(),8)<<endl;
        //for(int i=0;i<n;i++) cout<<toss[i]<<" " ; cout<<endl;
        if(ans) YES;
        else NO;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
