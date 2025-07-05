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
    cin>>Master0fTheSEA;
    for(int tttttttt=1;tttttttt<=Master0fTheSEA;tttttttt++)
    {
        int n,k;
        cin>>n>>k;
        vector<pair<int,int>>vec;
        for(int i=0;i<n;i++)
        {
            int a;
            cin>>a;
            vec.pb({a,i});
        }
        int i = k-1;
        while(i>-1)
        {
            vector<pair<int,int>>temp;
            for(int j=0;j<vec.size();j++)
            {
                if((vec[j].first&(1<<i))||(!(vec[j].first&(1<<i)))) temp.pb(vec[j]);
            }
            cout<<(1<<i)<<" "<<temp.size()<<endl;
            if(temp.size()>1) vec = temp;
            i--;
        }
        //for(auto [x,y]:vec) cout<<x<<" "<<y<<endl;
        int x = (vec[0].first&vec[1].first);
        int y = 0;
        for(int i = 0;i<k;i++)
        {
            int xy = (1LL<<i);
            if(!(x&xy)) y=(y|xy);
        }
        cout<<vec[0].second+1<<" "<<vec[1].second+1<<" "<<y<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
