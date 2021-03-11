#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<long long> vll;
typedef vector<int> vi;

ifstream in("scheduler-in.txt");
ofstream out("scheduler-out.txt");

int N, K, M;
vi P;
vi S;
vll m; // number of tasks each machine can do

bool possible(ll t) {
    for (int i = 0; i < N; i++) {
        m[i] = (t - P[i]) / S[i];
    }
    sort(m.begin(), m.end());
    reverse(m.begin(), m.end());
    ll sum = 0;
    for (int i = 0; i < K && sum < M; i++) {
        sum += m[i];
    }
    return sum >= M;
}

void solve() {
    in >> N >> K >> M;
    P.resize(N);
    S.resize(N);
    m.resize(N);
    for (int i = 0; i < N; i++) {
        in >> P[i] >> S[i];
    }

    ll tmax = 100000ll * 1000000000ll; // smallest possible
    ll tmin = 0;    // largest not possible

    while (tmax - tmin > 1) {
        ll tmid = (tmax + tmin) / 2;
        if (tmid == tmin) break;
        if (possible(tmid)) {
            tmax = tmid;
        } else {
            tmin = tmid;
        }
    }

    out << tmax;
}

int main() {
    int T;
    in >> T;
    for (int i = 0; i < T; i++) {
        out << "Case #" << i + 1 << ": ";
        solve();
        out << endl;
    }
}
