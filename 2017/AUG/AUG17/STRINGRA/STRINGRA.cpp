//Copyright : Udit Pal Singh, IIT Roorkee
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <string>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <unordered_map>
#include <sstream>
#include <utility>
#include <iterator>
using namespace std;
#define ll long long  int
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep1(i,n) for(ll i=1;i<=n;i++)
#define rep2(i,a,b,c) for(ll i=a;i<=b;i+=c)
#define si(x) scanf("%d",&x)
#define sd(x) scanf("%lf",&x)
#define sf(x) scanf("%f",&x)
#define sll(x) scanf("%lld",&x)
#define pi pair<ll,ll>
#define pii pair<pi,ll>
#define f first
#define mp make_pair
#define mod 1000000007
#define s second
#define pb push_back
#define maxn 100005
#define INF 1000000005
#define NIL 0
#define source 100001
#define sink 100002 
#define one 1ll
#define block 317
//std::ios::sync_with_stdio(false);
vector<vector<ll> > adj(maxn);
ll arr[maxn], n, m, k;
bool visit[maxn], en[maxn];
pi edge[maxn];

bool comp(pi a, pi b)
{
    if(a.f != b.f)return (a.f < b.f);
    return (a.s < b.s); 
}
bool check()
{
    rep(i, m-1)
    {
        if(edge[i].f == edge[i+1].f && edge[i].s == edge[i+1].s) return 0;
    }
    return 1;
}
bool go()
{
    if( !check() ) return 0;
    rep1(i, n)
    {
        ll pos = 0, c = 0;
        rep(j, k+1) visit[j] = 0;
        if(arr[i] == 0) return 0;
        rep(j, adj[i].size())
        {
            if(arr[adj[i][j]] != 0)
            {
                visit[arr[adj[i][j]]] = 1;
            }
            else 
            {
                c++;
                if(c > 1) return 0;
                pos = adj[i][j];
            }
        }
        c = 0;
        ll pos2 = 0;
        rep1(j, k)
        {
            if(!visit[j] && !en[j]){
              c++;
              pos2 = j;
            }
        }
        if(c > 1 || c == 0) return 0;
        if(pos2 != arr[i]) return 0;
        if(pos == 0){
          en[pos2]=1;
        }
        else
        {
            arr[pos] = arr[i];
        }
    }
    return 1;
}

int main()
{
    ll t;
    sll(t);
    while(t--)
    {
        memset(arr, 0, sizeof(arr));
        memset(en, 0, sizeof(en));
        rep(i, maxn) adj[i].clear();
        sll(n);
        sll(m);
        rep(i,m)
        {
            sll(edge[i].f);
            sll(edge[i].s);
        }
        sort(edge, edge+m, comp);
        rep(i, m)
        {
            adj[edge[i].f].pb(edge[i].s);
        }
        k = adj[0].size();
        rep(i, k)
        {
            arr[adj[0][i]] = i+1;
        }
        if(go())
        {
            rep1(i,n) printf("%lld ", arr[i]);
            printf("\n");
        }
        else printf("-1\n");
    }
    return 0;
}
 
 
