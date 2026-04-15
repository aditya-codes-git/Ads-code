#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Function to calculate sum of frequencies from i to j
int sumFreq(vector<int> &freq, int i, int j) {
    int sum = 0;
    for (int k = i; k <= j; k++) {
        sum += freq[k];
    }
    return sum;
}

// Function to find optimal cost of BST
int optimalBST(vector<int> &keys, vector<int> &freq, int n) {
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // Base case: single key
    for (int i = 0; i < n; i++) {
        dp[i][i] = freq[i];
    }

    // Build table for chains of length 2 to n
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;

            // Try making each key as root
            for (int r = i; r <= j; r++) {
                int left = (r > i) ? dp[i][r - 1] : 0;
                int right = (r < j) ? dp[r + 1][j] : 0;

                int cost = left + right + sumFreq(freq, i, j);

                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                }
            }
        }
    }

    return dp[0][n - 1];
}

int main() {
    // Example data (as given in assignment)
    vector<int> keys = {10, 12};
    vector<int> freq = {34, 50};

    int n = keys.size();

    cout << "Keys: ";
    for (int k : keys) cout << k << " ";

    cout << "\nFrequencies: ";
    for (int f : freq) cout << f << " ";

    cout << "\n\nOptimal BST Cost: " 
         << optimalBST(keys, freq, n);

    return 0;
}