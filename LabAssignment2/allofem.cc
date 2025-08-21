#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// binary search
int bsearch(int a[], int n, int key) {
    int l = 0, r = n - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (a[mid] == key) return mid;
        if (a[mid] < key) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}

// bubble sort
void bsort(int a[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (a[j] > a[j + 1]) swap(a[j], a[j + 1]);
}

// missing number in sorted array
int missing(int a[], int n) {
    int l = 0, r = n - 1, diff = a[0] - 0;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (a[m] - m != diff) r = m - 1;
        else l = m + 1;
    }
    return l + diff;
}

// string programs
string concat(string a, string b) { return a + b; }

string rev(string s) {
    reverse(s.begin(), s.end());
    return s;
}

string no_vowels(string s) {
    string t = "";
    for (char c : s)
        if (!strchr("AEIOUaeiou", c)) t += c;
    return t;
}

void sort_str(vector<string> &v) { sort(v.begin(), v.end()); }

string tolower_str(string s) {
    for (char &c : s) c = tolower(c);
    return s;
}

// sparse matrix
struct elem { int r, c, v; };
struct sparse { int rows, cols, num; vector<elem> e; };

sparse transpose(sparse s) {
    sparse t{ s.cols, s.rows, s.num, {} };
    t.e.resize(s.num);
    int k = 0;
    for (int i = 0; i < s.cols; i++)
        for (int j = 0; j < s.num; j++)
            if (s.e[j].c == i)
                t.e[k++] = { i, s.e[j].r, s.e[j].v };
    return t;
}

// count inversions
int inversions(int a[], int n) {
    int cnt = 0;
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i] > a[j]) cnt++;
    return cnt;
}

// count distinct
int distinct(int a[], int n) {
    sort(a, a + n);
    int cnt = 1;
    for (int i = 1; i < n; i++)
        if (a[i] != a[i - 1]) cnt++;
    return cnt;
}

// saddle point
void saddle(vector<vector<int>> &m) {
    int n = m.size(), c = m[0].size();
    for (int i = 0; i < n; i++) {
        int rowmin = m[i][0], col = 0;
        for (int j = 1; j < c; j++)
            if (m[i][j] < rowmin) { rowmin = m[i][j]; col = j; }
        bool ok = true;
        for (int k = 0; k < n; k++)
            if (m[k][col] > rowmin) { ok = false; break; }
        if (ok) { cout << "Saddle: " << rowmin << endl; return; }
    }
    cout << "No saddle\n";
}

int main() {
    int a[] = {11, 22, 25, 34, 64, 90}, n = 6;
    cout << "Bsearch 25 -> " << bsearch(a, n, 25) << endl;

    bsort(a, n);
    cout << "Bsort: "; for (int x : a) cout << x << " "; cout << endl;

    int b[] = {1, 2, 3, 5, 6};
    cout << "Missing: " << missing(b, 5) << endl;

    cout << "Concat: " << concat("Hello", "World") << endl;
    cout << "Rev: " << rev("Hello") << endl;
    cout << "No vowels: " << no_vowels("Hello World") << endl;

    vector<string> vs = {"banana","apple","cherry"};
    sort_str(vs); cout << "Sorted: "; for (auto &s : vs) cout << s << " "; cout << endl;

    cout << "Lower: " << tolower_str("HeLLo") << endl;

    cout << "Inversions: " << inversions(b, 5) << endl;
    cout << "Distinct: " << distinct(b, 5) << endl;

    vector<vector<int>> mat = {{1,2,3},{4,5,6},{7,8,9}};
    saddle(mat);
    return 0;
}
