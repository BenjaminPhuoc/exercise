// #pragma GCC optimize("O2,Ofast")
// #pragma GCC target("avx,avx2")
#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define ALL(x) x.begin(), x.end()
#define __Benjamin__ int main()
#define TIME 1.0 * clock() / CLOCKS_PER_SEC
#define ll long long
#define ii pair<int, int>
using namespace std;

const int MAXN = 2e5 + 5;

void solve()
{
    struct group_facet : public std::numpunct<char>
    {
    protected:
        string do_grouping() const { return "\003"; }
    };
    cout.imbue(locale(cout.getloc(), new group_facet));
    ll gross = 0;
    ll insurance = 0;
    int dependants = 0;
    int personalRed = 11'000'000;
    int dependantEach = 4'400'000;
    int socialIns = 0;
    int healthIns = 0;
    int unemIns = 0;
    int dependantRed = 0;
    ll pretax = 0;
    ll taxedInc = 0;
    vector<ll> rate(7, 0);
    cout << "Gross income: ";
    cin >> gross;
    cout << "Income for insurance payment (type -1 if pay on gross income): ";
    cin >> insurance;
    cout << "Number of dependants: ";
    cin >> dependants;
    insurance = insurance == -1 ? gross : insurance;
    socialIns = insurance > 36'000'000 ? 2'880'000 : 0.08 * insurance;
    healthIns = insurance > 36'000'000 ? 540'000 : 0.015 * insurance;
    unemIns = insurance > 93'600'000 ? 936'000 : 0.01 * insurance;
    dependantRed = dependantEach * dependants;
    pretax = gross - socialIns - healthIns - unemIns;
    taxedInc = pretax > personalRed + dependantRed ? pretax - personalRed - dependantRed : 0;
    rate[0] = clamp(taxedInc * 0.05, 0.0, 250'000.0);
    rate[1] = clamp((taxedInc - 5'000'000) * 0.1, 0.0, 500'000.0);
    rate[2] = clamp((taxedInc - 10'000'000) * 0.15, 0.0, 1'200'000.0);
    rate[3] = clamp((taxedInc - 18'000'000) * 0.2, 0.0, 2'800'000.0);
    rate[4] = clamp((taxedInc - 32'000'000) * 0.25, 0.0, 5'000'000.0);
    rate[5] = clamp((taxedInc - 52'000'000) * 0.3, 0.0, 8'400'000.0);
    rate[6] = taxedInc > 80'000'000 ? (taxedInc - 80'000'000) * 0.35 : 0;
    cout << "---------------------------------------------------------------------------\n";
    cout << setw(50) << left << "Gross income: " << gross << "\n";
    cout << setw(50) << left << "Social insurance (8%): " << socialIns << "\n";
    cout << setw(50) << left << "Health insurance (1.5%): " << healthIns << "\n";
    cout << setw(50) << left << "Unemployment insurance (1%): " << unemIns << "\n";
    cout << setw(50) << left << "Pre-tax income: " << pretax << "\n";
    cout << setw(50) << left << "Personal tax reduction: " << personalRed << "\n";
    cout << setw(50) << left << "Dependants tax reduction: " << dependantRed << "\n";
    cout << setw(50) << left << "Taxed income: " << taxedInc << "\n";
    cout << setw(50) << left << "Personal income tax (*): " << accumulate(ALL(rate), 0LL) << "\n";
    cout << setw(50) << left << "Net income: " << gross - accumulate(ALL(rate), 0LL) << "\n";
    cout << "---------------------------------------------------------------------------\n";
    cout << "(*) Personal income tax details: \n";
    cout << "Taxable levels                Tax rates                     Payments\n";
    cout << setw(30) << left << "To 5M VND" << setw(30) << left << "5%" << rate[0] << "\n";
    cout << setw(30) << left << "Over 5M VND to 10M VND" << setw(30) << left << "10%" << rate[1] << "\n";
    cout << setw(30) << left << "Over 10M VND to 18M VND" << setw(30) << left << "15%" << rate[2] << "\n";
    cout << setw(30) << left << "Over 18M VND to 32M VND" << setw(30) << left << "20%" << rate[3] << "\n";
    cout << setw(30) << left << "Over 32M VND to 52M VND" << setw(30) << left << "25%" << rate[4] << "\n";
    cout << setw(30) << left << "Over 52M VND to 80M VND" << setw(30) << left << "30%" << rate[5] << "\n";
    cout << setw(30) << left << "Over 80M VND" << setw(30) << left << "35%" << rate[6] << "\n";
    cout << "\n";
}

__Benjamin__
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(NULL);
    // cout.tie(NULL);
    // freopen("draft.inp", "r", stdin);
    // freopen("draft.out", "w", stdout);
    // int t;
    // cin >> t;
    // while (t--)
    solve();
    cout << "Time elapsed: " << TIME << "s.\n";
    return 0;
}