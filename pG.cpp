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
#define inf 1e18
using namespace std;
typedef pair<int,int> pp;
struct node{
  ll ind,pub,day,prep;
};
node ary[1005];
int used[1005],ans[1005];
bool comp(node a,node b){
  if (a.day<b.day) return true;
  else return false;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n,m,rem,flag;
  cin>>n>>m;
  for (int i=1;i<=m;i++){
    ary[i].ind=i;
    cin>>ary[i].pub>>ary[i].day>>ary[i].prep;
  }
  sort(ary+1,ary+m+1,comp);
  
  for (int i=1;i<=n;i++){
    flag=1;
    for (int j=1;j<=m;j++){
      if (!used[j] and i==ary[j].pub){
        if (i+ary[j].prep>ary[j].day){
          flag=0;
          break;
        }
      }
    }
    if (!flag){
      cout<<-1;
      break;
    }else{
      rem=ary[i].prep;
      for (int j=ary[i].pub;j<ary[i].day;j++){
        if (rem and !ans[j]){
          ans[j]=ary[i].ind;
          rem--;
        }
        // cout<<rem<<"\n";
      }
      // cout<<rem<<"\n";
      if (rem){
        flag=0;
        cout<<-1;
        break;
      }else{
        ans[ary[i].day]=m+1;
      }
    }
    // for (int j=1;j<=n;j++) cout<<ans[j]<<" ";
    // cout<<"\n";
  }
  if (flag) for (int i=1;i<=n;i++) cout<<ans[i]<<" ";
  return 0;
}

