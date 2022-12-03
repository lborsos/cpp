#include <fstream>
#include <algorithm>
#include <string>
using namespace std;
ifstream cin("wordlist.in");
ofstream cout("wordlist.out");

int x[200], n, k=2, heureka=0;
std::string word_in[200], abc="abcdefghijklmnopqrstuvwxyz", words="";

int verify()
{
    words="";
    for (int i=1; i<=k; i++) words += word_in[x[i]-1];
    if (abc.size()!=words.size()) return 0;
    for (int i=0; i<abc.size(); ++i) {
        int count = std::count(words.begin(), words.end(), word_in[i]);
        if (count !=1) return 0;
    }
    heureka = 1;
    return 1;
}

void print()
{
    if (verify()) {
        cout << k;
        for (int i=1; i<=k; i++)
            cout << x[i] << "\n";
    }
}

void back(int pas)
{
    if (!heureka) {
        for (int i=x[pas-1]+1; i<=n-k+pas; ++i)
        {
            x[pas] = i;
            if (pas<k) back(pas+1);
            else print();
        }
    }
}

int main()
{
    cin >> n;
    for (int i=0; i<n; ++i) cin >> word_in[i];
//    n=5;
    k=2;
    back(1);
    return 0;
}
