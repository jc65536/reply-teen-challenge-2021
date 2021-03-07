#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream inp;
    string fn;
    cout << "File Name: ";
    cin >> fn;
    inp.open(fn);

    ofstream out;
    out.open("party.out");
    int T;
    
    inp >> T;

    for (int i = 0; i < T; i++) {
        int amount = 0;

        int N;
        inp >> N;
        for (int x = 0; x < N; x++) {
            int temp = 0;

            inp >> temp;
            if (temp > 0) {
                amount += temp;
            }
        }

        out << "Case #" << i + 1 << ": " << amount << endl;
    }
}