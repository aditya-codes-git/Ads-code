#include <iostream>
#include <string>
using namespace std;

int main() {
    string text, pattern;

    // Input
    cout << "Enter Text: ";
    getline(cin, text);

    cout << "Enter Pattern: ";
    getline(cin, pattern);

    int n = text.length();
    int m = pattern.length();
    int count = 0;

    // Brute Force Pattern Matching
    for (int i = 0; i <= n - m; i++) {
        int j;

        for (j = 0; j < m; j++) {
            if (text[i + j] != pattern[j]) {
                break; // mismatch
            }
        }

        if (j == m) {
            cout << "Pattern found at index: " << i << endl;
            count++;
        }
    }

    // Output
    cout << "Total occurrences: " << count << endl;

    return 0;
}