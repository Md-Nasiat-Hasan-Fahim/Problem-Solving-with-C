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
        int n,pos;
        cin>>n>>pos;
        vector<int>vec(n+1);
        for(int i=0;i<n;i++) cin>>vec[i+1];
        if(vec[pos]<0)
        {
            NO;
            continue;
        }
        int cnt1[n+2]={0},cnt2[n+2]={0};
        for(int i=pos-1;i>0;i--)
        {
            cnt1[i]+=cnt1[i+1]+vec[i];
        }
        for(int i=pos+1;i<=n;i++)
        {
            cnt2[i]+=cnt2[i-1]+vec[i];
        }
        int i = pos-1, j = pos+1;
        int pr1 = pos,pr2 = pos;
        int fpq = vec[pos];
        int pq = fpq;
        bool ans = true;
        while(i>0&&j<n+1)
        {
            while(i>0&&cnt1[i]<0) i--;
            while(j<n+1&&cnt2[j]<0) j++;
            cout<<i<<" "<<j<<endl;
            if(cnt1[i+1]<cnt2[j-1])
            {
                if(cnt2[j-1]<=pq)
                {
                    while(j<n+1&&cnt2[j]>=0) j++;
                }
                else {ans = false;break;}
            }
            else
            {
                if(cnt1[i+1]<=pq)
                {
                    while(i>0&&cnt1[i]>=0) i--;
                }
                else {ans = false;break;}
            }
        }
        if(ans&&(i==0||j==n+1)) YES;
        else NO;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
