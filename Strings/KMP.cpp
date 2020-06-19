#include <string>
#include <iostream>

using namespace std;

void computeLPS(string pattern, int m, int* lps) {
    int len = 0;
    int i = 1;

    lps[0] = 0;

    while (i < m) {
        if(pattern[i] == pattern[len]) {
            lps[i] = len+1;
            len++;
            i++;
        }
        else {
            if(len != 0) {
                len = lps[len-1];
            }
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

int KMP(string txt, string pattern) {
    int n = txt.length();
    int m = pattern.length();

    int lps[m];

    computeLPS(pattern, m, lps);

    int i = 0;
    int j = 0;

    while(i < n) {
        if(txt[i] == pattern[j]) {
            i++;
            j++;
        }
        else {
            if(j != 0) j = lps[j-1];
            else i++;
        }
        if (j == m) {
            cout << i-j << endl;
            j = lps[j-1];
        }
    }
}

int main() {
    KMP("onionionspl", "onions");
    return 0;
}