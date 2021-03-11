#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<long long> vll;
typedef vector<int> vi;

ifstream in("scoreboard.in");
ofstream out("scoreboard.out");

struct team {
    int id, points = 0, timePenalty = 0;
    bool done[5][5] = {{0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0}};
    bool operator<(const team &t) {
        if (points == t.points) {
            if (timePenalty == t.timePenalty)
                return id < t.id;
            else
                return timePenalty < t.timePenalty;
        }
        return points > t.points;
    }
};

int N, L;
vector<team> teams;
void solve() {
    in >> N >> L;
    teams.clear();
    teams.resize(N);
    cout << teams.size() << endl;
    for (int i = 0; i < N; i++) {
        teams[i].id = i + 1;
    }

    int time, id, prob, inp, scored;
    for (int i = 0; i < L; i++) {
        in >> time >> id >> prob >> inp >> scored;
        team &t = teams[id - 1];
        if (scored && !t.done[prob - 1][inp - 1]) {
            t.points += inp * 100;
            t.timePenalty += time;
            t.done[prob - 1][inp - 1] = true;
        }
    }

    sort(teams.begin(), teams.end());
    for (team &t : teams) {
        out << t.id << " ";
    }
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
