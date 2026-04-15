#include <iostream>
#include <set>
using namespace std;

// Function to print a set
void printSet(string name, set<int> s) {
    cout << name << ": ";
    for (int val : s) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    // Predefined sets
    set<int> A = {1, 2, 3, 4, 5};
    set<int> B = {3, 4, 6, 7};

    set<int> unionSet, intersectionSet, differenceSet;

    // -------- UNION --------
    unionSet = A;
    unionSet.insert(B.begin(), B.end());

    // -------- INTERSECTION --------
    for (int val : A) {
        if (B.find(val) != B.end()) {
            intersectionSet.insert(val);
        }
    }

    // -------- DIFFERENCE (A - B) --------
    for (int val : A) {
        if (B.find(val) == B.end()) {
            differenceSet.insert(val);
        }
    }

    // -------- OUTPUT --------
    cout << "Set Operations using C++ STL\n\n";

    printSet("Set A", A);
    printSet("Set B", B);

    cout << endl;
    printSet("Union (A ∪ B)", unionSet);
    printSet("Intersection (A ∩ B)", intersectionSet);
    printSet("Difference (A - B)", differenceSet);

    return 0;
}