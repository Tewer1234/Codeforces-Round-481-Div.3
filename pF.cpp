#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <bits/stdc++.h>
#include <iomanip>
#include <vector>
#include <map>
#include <queue>
#include <set>
#define ll long long int 
#define pb push_back
using namespace std;
typedef pair<int,int> pp;
ll ary[1000000],ans[1000000];
vector <ll> nodes[1000000];
struct node{
  ll pos,val;
};
node t[1000000];
bool comp (node a,node b){
  if (a.val<b.val) return true;
  else if (a.val==b.val and a.pos<b.pos) return true;
  else return false;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n,q,x,y;
  map <ll,ll> mp;
  cin>>n>>q;
  t[0].pos=0;
  t[0].val=LLONG_MAX;
  for (int i=1;i<=n;i++){
    cin>>ary[i];
    t[i].pos=i;
    t[i].val=ary[i];
    mp[t[i].val]++;
  }
  sort(t+1,t+n+1,comp);
  
  for (int i=1;i<=q;i++){
    cin>>x>>y;
    nodes[x].pb(y);
    nodes[y].pb(x);
    if (ary[x]<ary[y]) ans[y]--;
    if (ary[x]>ary[y]) ans[x]--;
  }
  // for (int i=1;i<=n;i++) cout<<t[i].val<<" ";
  // cout<<"\n";
  // for (int i=1;i<=n;i++) cout<<ans[i]<<" ";
  // cout<<"\n";
  
  for (int i=1;i<=n;i++){
    ll l=0,r=n,mid,temp=0;
    while (l<=r){
      mid = (l+r)/2;
      if (t[mid].val<=ary[i]){
        l = mid+1;
        temp=mid;
      }else{
        r = mid-1;
      }
    }
    // cout<<temp<<"\n";
    ans[i]=ans[i]+temp-1-(mp[ary[i]]-1);
  }
  // 
  for (int i=1;i<=n;i++) {
    if (ans[i]<0) cout<<0<<" ";
    else cout<<ans[i]<<" ";
  }
  return 0;
}
