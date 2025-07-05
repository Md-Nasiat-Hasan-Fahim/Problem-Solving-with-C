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
int w,h;

bool is_valid(int x, int y)
{
    return x>-1&&x<=w&&y>-1&&y<=h;
}

signed main()
{
    //freopen("","r+",stdin);
    //freopen("","w+",stdout);
    FastIO;
    int t=1;
    cin>>t;
    for(int z=1;z<=t;z++)
    {
        cin>>w>>h;
        int x1,y1,x2,y2,tw,th;
        cin>>x1>>y1>>x2>>y2>>tw>>th;
        int mn = INT_MAX;
        if(is_valid(x1,y2+th)) mn = 0;
        else if(is_valid(x1,y1-th+h-y2)) mn = min(mn,th-h+y2);
        //cout<<"1 "<<mn<<endl;
        if(is_valid(x1-tw,y1)) mn = 0;
        else if(is_valid(x2-x1+tw,y1)) mn = min(mn,tw-x1);
        //cout<<"2 "<<mn<<endl;
        if(is_valid(x1,y1-th)) mn = 0;
        else if(is_valid(x1,y2-y1+th)) mn = min(mn,th-y1);
        //cout<<"3 "<<mn<<endl;
        if(is_valid(x2+tw,y1)) mn = 0;
        else if(is_valid(x1-tw+w-x2,y1)) mn = min(mn,tw-w+x2);
        if(mn!=INT_MAX) cout<<mn<<endl;
        else cout<<"-1\n";
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
