#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < n; i++)
#define repi(i,a,n) for(int i = a; i < n; i++)

void lis(vector<pair<int,int>> const& a,vector < pair <int,int> > const& org) {
    int n = a.size(),span = org.size();
    vector<int> d(n, 1), p(n, -1);
    rep(i,n){
        rep(j,i){
            if ((a[j].first < a[i].first) && (a[j].second < a[i].second) && (d[i] < d[j] + 1)) {
                d[i] = d[j] + 1;
                p[i] = j;
            }
        }
    }

    int ans = d[0], pos = 0;
    repi(i,1,n){
        if (d[i] > ans) {
            ans = d[i];
            pos = i;
        }
    }

    vector<pair <int,int> > subseq;
    while (pos != -1) {
        subseq.push_back(make_pair(a[pos].first,a[pos].second));
        pos = p[pos];
    }
    //print(subseq);
    int N = subseq.size();
    vector <int> rev;
    rep(i,N){
      rep(j,span){
        if(subseq[i].first == org[j].first && subseq[i].second == org[j].second){
          rev.push_back(j);
          break;
        }
      }
    }
    reverse(rev.begin(),rev.end());
    cout << N << endl;
    rep(i,N){
      cout << rev[i]+1 << " ";
    }
}



int main(){
  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,W,H;
    cin >> n >> W >> H;
    vector <pair <int,int> > v,org;
    rep(i,n){
      int we,he;
      cin >> we >> he;
      if(he > H && we > W){
        v.push_back(make_pair(he,we));
      }
        org.push_back(make_pair(he,we));
    }
    if(v.size() == 0) cout << 0;
    else {
      sort(v.begin(),v.end());
      lis(v,org);
    }
    return 0;
  }
