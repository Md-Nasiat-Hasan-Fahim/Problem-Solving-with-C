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

struct node{
    int l,r,d;
};

signed main()
{
    //freopen("","r+",stdin);
    //freopen("","w+",stdout);
    FastIO;
    int Master0fTheSEA=1;
    cin>>Master0fTheSEA;
    for(int tttttttt=1;tttttttt<=Master0fTheSEA;tttttttt++)
    {
        int n;
        cin>>n;
        vector<int>vec(n);
        for(int i=0;i<n;i++) cin>>vec[i];
        int cnt = 0;
        vector<node>abc;
        auto tem = vec;
        sort(all(tem));
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                if(vec[j]==tem[i])
                {
                    if(i!=j)
                    {
                        cnt++;
                        abc.pb({i+1,j+1,j-i});
                        int tp = vec[j];
                        int tq = vec[i];
                        for(int k=i+1;k<=j;k++)
                        {
                            int tm = vec[k];
                            vec[k]=tq;
                            tq=tm;
                        }
                        vec[i]=tp;
                    }
                    break;
                }
            }
        }
        cout<<cnt<<endl;
        for(int i=0;i<cnt;i++) cout<<abc[i].l<<" "<<abc[i].r<<" "<<abc[i].d<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
