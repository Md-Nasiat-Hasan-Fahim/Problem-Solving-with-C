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
        vector<int>vec(n),ara(n);
        for(int i=0;i<n;i++) cin>>vec[i];
        int cnt = 0;
        for(int i=1;i<n;i++)
        {
            int x = vec[i-1];
            int y = vec[i];
            bool flag = false;
            for(int j=34,k=34;j>-1&&k>-1;)
            {
                j--;k--;
                while(j>-1&&!((1LL<<j)&x)) j--;
                while(k>-1&&!((1LL<<k)&y)) k--;
                if(j==-1) break;
                if(k==-1)
                {
                    cnt++;
                    ara[i]++;
                    break;
                }
                if(k+ara[i]>j+ara[i-1])
                {
                    break;
                }
                else if(k+ara[i]<j+ara[i-1])
                {
                    if(flag)
                    {
                        cnt++;
                        ara[i]++;
                        break;
                    }
                    int xy = j+ara[i-1]-k+ara[i];
                    cnt+=xy;
                    ara[i]+=xy;
                }
                if(k+ara[i]==j+ara[i-1]) flag = true;
                // cout<<k<<" "<<ara[i]<<" "<<j<<" "<<ara[i-1]<<" "<<cnt<<endl;
            }
            //cout<<i<<" "<<cnt<<endl;
        }
        cout<<cnt<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
