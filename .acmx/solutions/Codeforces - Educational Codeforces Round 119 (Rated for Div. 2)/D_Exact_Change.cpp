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
        int n;
        cin>>n;
        vector<int>vec(n);
        int cnt = INT_MAX;
        int mx1 = INT_MIN, mx2 = INT_MIN, mx3 = INT_MIN;
        for(int i=0;i<n;i++)
        {
            cin>>vec[i];
            mx1 = max(mx1,vec[i]);
            if(vec[i]%2) mx2 = INT_MAX;
            else mx2 = max(mx2,vec[i]/2);
            if(vec[i]%3) mx3 = INT_MAX;
            else mx3 = max(mx3,vec[i]/3);
        }
        cnt = min({cnt,mx1,mx2,mx3});
        mx1 = INT_MIN,mx2 = INT_MIN;
        for(int i=0;i<n;i++)
        {
            mx2 = max(mx2,vec[i]/2);
            mx1 = max(mx1,vec[i]%2);
        }
        cnt = min(cnt,(max(1LL,mx1)+max(1LL,mx2)));
        mx1 = INT_MIN, mx3 = INT_MIN;
        for(int i=0;i<n;i++)
        {
            mx3 = max(mx3,vec[i]/3);
            mx1 = max(mx1,vec[i]%3);
        }
        cnt = min(cnt,(max(1LL,mx1)+max(1LL,mx3)));
        mx2 = INT_MIN, mx3 = INT_MIN;
        for(int i=0;i<n;i++)
        {
            if(vec[i]==1) mx2 = INT_MAX,mx3 = INT_MAX;
            if(vec[i]%2)
            {
                int kt = vec[i]/3;
                if(kt%2)
                {
                    mx3 = max(mx3,kt);
                    mx2 = max(mx2, (vec[i]-kt*3)/2);
                }
                else
                {
                    kt--;
                    mx3 = max(mx3,kt);
                    mx2 = max(mx2, (vec[i]-kt*3)/2);
                }
            }
            else
            {
                int kt = vec[i]/3;
                if(kt%2)
                {
                    kt--;
                    mx3 = max(mx3,kt);
                    mx2 = max(mx2, (vec[i]-kt*3)/2);
                }
                else
                {
                    mx3 = max(mx3,kt);
                    mx2 = max(mx2, (vec[i]-kt*3)/2);
                }
            }
        }
        cout<<mx2<<" "<<mx3<<endl;
        cnt = min(cnt,(max(1LL,mx2)+max(1LL,mx3)));
        mx1 = INT_MIN,mx2 = INT_MIN, mx3 = INT_MIN;
        for(int i=0;i<n;i++)
        {
            mx3 = max(mx3,vec[i]/3);
            int a = vec[i]%3;
            mx2 = max(mx2,a/2);
            a%=2;
            mx1 = max(mx1,a);
        }
        cout<<mx1<<" "<<mx2<<" "<<mx3<<endl;
        cnt = min(cnt,(max(1LL,mx3)+max(1LL,mx2)+max(1LL,mx1)));
        cout<<cnt<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
