#include<iostream>
#include<vector>
using namespace std;
int main(){
    //3d vector...
    vector<vector<vector<int>>> matrix3D;
    // int rows,columns,depth;
    int rows=3,columns=4,depth=5;
    // cout<<"Enter the number of rows: ";
    // cin>>rows;
    // cout<<"Enter the number of columns: ";
    // cin>>columns;
    // cout<<"Enter the depth: ";
    // cin>>depth;
    //resize the outer vector to the number of rows
    matrix3D.resize(rows);
    for(int i=0;i<rows;i++){
        matrix3D[i].resize(columns);
        //resize each inner vector to the number of columns
        for(int j=0;j<columns;j++){
            matrix3D[i][j].resize(depth);
        }

    }
    //fill the matrix with values
    int value=1;
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            for(int k=0;k<depth;k++){
                matrix3D[i][j][k] = value++;
                }
            }
}
//print the matrix


// Print the matrix
for (int i = 0; i < rows; i++) {
    cout << "Layer " << i + 1 << ":\n";
    for (int j = 0; j < columns; j++) {
        for (int k = 0; k < depth; k++) {
            cout << matrix3D[i][j][k] << "  ";
        }
        cout << endl;
    }
    cout << "--------------------\n";
}
return 0;
}