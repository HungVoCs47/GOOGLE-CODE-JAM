#include <bits/stdc++.h>
using namespace std;
#define range(i, m, n) for(int i = m; i < n; i++)
#define husk(i, m, n) for(int i = m; i > n; i--)
int tt;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> tt;
  range(tc, 1, tt + 1) {
    cout << "Case #" << tc << ": ";
    int r, c;
    cin >> r >> c;
    deque<pair<int, int> > cur;
    vector<vector<int> > grid(r, vector<int>(c));
    vector<vector<int> > dep(r, vector<int>(c, -1));
    string s;
    range(i, 0, r) {
      cin >> s;
      range(j, 0, c) {
        grid[i][j] = s[j] - '0';
        if(grid[i][j]) {
          cur.push_back({i,j});
          dep[i][j] = 0;
        }
      }
    }
    if(cur.size()>=r*c-1) {
      cout<<0<<endl;
      continue;
    }
    int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
    while(cur.size()){
      pair<int,int>u=cur.front();
      int x = u.first,y=u.second;
      cur.pop_front();
      range(i,0,4) {
        int a=x+dx[i],b=y+dy[i];
        if(min(a, b) < 0 || a >= r || b >= c || ~dep[a][b]) continue;
        dep[a][b] = dep[x][y] + 1;
        cur.push_back({a, b});
      }
    }
    int lo = 0, hi = r + c;
    while(hi-lo>1) {
      int mid = (lo + hi) >> 1;
      int l_pos = INT_MIN, r_pos = INT_MAX;
      int l_neg = INT_MIN, r_neg = INT_MAX;
      range(i,0,r) {
        range(j,0,c) {
          if(dep[i][j] > mid) {
            r_pos=min(r_pos,mid+i+j);
            l_neg=max(l_neg,i-j-mid);
            r_neg=min(r_neg,mid+i-j);
            l_pos=max(l_pos,i+j-mid);
          }
        }
      }
      bool ok = false;
      range(x,0,r) {
        range(y,0,c) {
          ok |= (x+y<=r_pos && x+y>=l_pos && x-y<=r_neg && x-y>=l_neg);
          if(ok){
            break;
          }
        }
        if(ok) break;
      }
      if(ok) hi = mid;
      else lo = mid;
    }
    cout << hi << endl;
  }
  return 0;
}



/*
#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
const int INF = 0x3f3f3f3f;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t, kase = 0; cin >> t; while (t--) {
        cout << "Case #" << ++kase << ": ";
        int r, c; cin >> r >> c;
        vector<vector<char> > G(r, vector<char>(c));
        vector<vector<int> > D(r, vector<int>(c, -1));
        queue<pii> Q;
        for (int i = 0 ; i < r ; i++) {
            for (int j = 0 ; j < c ; j++) {
                cin >> G[i][j];
                if (G[i][j] == '1') {
                    Q.push({i, j});
                    D[i][j] = 0;
                }
            }
        }
        int ans = INF;
        for (int x = 0 ; x < r ; x++) {
            for (int y = 0 ; y < c ; y++) {
                vector<vector<int> > d = D;
                queue<pii> q = Q; q.push({x, y});
                d[x][y] =0;
                int maxV = 0;
                while (q.size()) {
                    pii p = q.front(); q.pop();
                    for (int _d = 0 ; _d < 4 ; _d++) {
                        pii nt = {p.F + dx[_d], p.S + dy[_d]};
                        if (nt.F < 0 || nt.F >= r || nt.S < 0 || nt.S >= c)
                            continue;
                        if (~d[nt.F][nt.S])
                            continue;
                        d[nt.F][nt.S] = d[p.F][p.S] + 1;
                        maxV = max(maxV, d[nt.F][nt.S]);
                        q.push(nt);
                    }
                }
                ans = min(ans, maxV);
            }
        }
        cout << ans << '\n';
    }
}
*/
