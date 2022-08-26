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
ll ary[1000000],letters[1000000];
ll psum[1000000];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n,m;
  cin>>n>>m;
  for (int i=1;i<=n;i++) cin>>ary[i];
  for (int j=1;j<=m;j++) cin>>letters[j];
  
  for (int i=1;i<=n;i++){
    psum[i]=psum[i-1]+ary[i];
  }
  
  for (int i=1;i<=m;i++){
    ll l=1,r=n,mid,dorm=1;
    while (l<=r){
      mid=(l+r)/2;
      if (psum[mid]>=letters[i]){
        dorm=mid;
        r=mid-1;
      }else{
        l=mid+1;
      }
    }
    cout<<dorm<<" "<<letters[i]-psum[dorm-1]<<"\n";
  }
  return 0;
}
