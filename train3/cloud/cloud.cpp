#include <bits/stdc++.h>
using namespace std;

ifstream in("cloud-in.txt");
ofstream out("cloud-out.txt");

int N, P;
vector<long long> cp;

long long sum(int l, int r);

void solve() {
    in >> N >> P;
    cp.resize(N);
    for (int i = 0; i < N; i++) {
        in >> cp[i];
        if (i > 0)
            cp[i] += cp[i - 1];
    }

    // sum of values in [l, r] = cp[r] - cp[l - 1] (if l == 0 then just cp[r])
    int l = 0, r = 0;
    long long minWaste = cp[N - 1];
    int bestL = 0, bestR = N - 1;

    while (l <= r && r <= N - 1) {
        while (r <= N - 1 && sum(l, r) < P) {
            r++;
        }

        if (r == N && sum(l, r) < P)
            break;

        long long waste = sum(l, r) - P;
        if (waste < minWaste) {
            minWaste = waste;
            bestL = l;
            bestR = r;
        }
        l++;
    }

    out << bestL << " " << bestR;
}

long long sum(int l, int r) {
    if (l == 0)
        return cp[r];
    else
        return cp[r] - cp[l - 1];
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
