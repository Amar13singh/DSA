#include<bits/stdc++.h>
using namespace std;


class GraphMatrix {
private:
    int n;
    vector<vector<int>> mat;

public:
    GraphMatrix(int nodes) {
        n = nodes;
        mat.assign(n, vector<int>(n, 0));
    }

    void print() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << mat[i][j] << " ";
            }
            cout << "\n";
        }
    }
};