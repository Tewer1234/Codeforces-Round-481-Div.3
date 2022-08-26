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
int ary[1000000];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n,ans=0,cnt=0,st=0,ed=0,forbid=1;
  string s;
  cin>>n>>s;
  for (int i=0;i<s.size();i++){
    if (s[i]=='x'){
      cnt++;
      if (cnt>=3){
        forbid=0;
        cnt--;
        ans++;
      }
    }else cnt=0;
  }
  if (!forbid) cout<<ans;
  else cout<<0;
  return 0;
