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

struct node
{
    int x1,y1,x2,y2;
};

signed main()
{
    //freopen("","r+",stdin);
    //freopen("","w+",stdout);
    FastIO;
    int t=1;
   // cin>>t;
    for(int z=1;z<=t;z++)
    {
        node a,b;
        cin>>a.x1>>a.y1>>a.x2>>a.y2;
        cin>>b.x1>>b.y1>>b.x2>>b.y2;
        if((b.x1<=a.x1&&a.x2<=b.x2)||(b.y1<=a.y1&&a.y2<=b.y2))
        {
            int width = max(0LL,min(a.x2,b.x2)-max(a.x1,b.x1));
            int length = max(0LL,min(a.y2,b.y2)-max(a.y1,b.y1));
            cout<<(a.x2-a.x1)*(a.y2-a.y1)-width*length<<endl;
        }
        else cout<<(a.x2-a.x1)*(a.y2-a.y1)<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
