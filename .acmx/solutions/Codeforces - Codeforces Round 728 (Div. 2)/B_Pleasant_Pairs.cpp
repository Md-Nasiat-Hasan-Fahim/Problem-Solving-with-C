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

//{{1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,-1},{-1,1},{1,-1}}
//{{1,2},{2,1},{2,-1},{-1,2},{-1,-2},{-2,-1},{-2,1},{1,-2}}

signed main()
{
    //freopen("","r+",stdin);
    //freopen("","w+",stdout);
    FastIO;
    int t=1;
    cin>>t;
    for(int z=1;z<=t;z++)
    {
        int n;
        cin>>n;
        int arr[2*n+2]={0};
        int cnt = 0;
        int mx = INT_MIN;
        for(int i=0;i<n;i++)
        {
            int a;
            cin>>a;
            for(int j=a;j<2*n+2;j+=a)
            {
                if(arr[j/a]!=0)
                {
                    //cout<<(i+1)<<" "<<arr[j/a]<<endl;
                    if(j==(i+1)+arr[j/a]) {cnt++;} //cout<<j<<" "<<a<<endl;}
                }
            }
            arr[a]=i+1;
        }
        cout<<cnt<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
