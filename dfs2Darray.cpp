/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

template <typename T>

void display(T m){
    cout << endl;
    for (auto v: m){
        for (auto i:v){
            cout << i << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

void dfs(
    vector<vector<int>> matrix, 
    int row, int col, 
    vector<vector<bool>> seen, 
    vector<int> values)
{
    
}

int main()
{
    vector<vector<int>> matrix;
    vector<vector<bool>> seen;
    vector<int> values;
    int count = 0;
    
    // Initializing the matrix
    for (int i = 0; i < 4; i++){
        vector<int> temp;
        for (int j = 0; j < 5; j++){
            temp.push_back(++count);
        }
        matrix.push_back(temp);
    }
    for (int i = 0; i < 4; i++){
        vector<bool> temp;
        for (int j = 0; j < 5; j++){
            temp.push_back(false);
        }
        seen.push_back(temp);
    }
    
    // Display the matrix
    display<vector<vector<int>>>(matrix);
    display<vector<vector<bool>>>(seen);
    
    return 0;
}
