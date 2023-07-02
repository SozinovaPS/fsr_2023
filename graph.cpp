#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    string name;
    cin>>name;
    ifstream fin(name);
    int Vn, En;
    fin >> Vn >> En;
    int v, w, i, j, t;
    
    vector <int> vert(Vn, 0);
    vector <vector<int>> A(Vn, vert);
    vector <int> V(Vn, 0);
    
    for (i = 0; i < En; i++){
        fin >> v >> w;
        A[v][v] = 1;
        A[v][w] = 1;
        A[w][v] = 1;
        A[w][w] = 1;
    }

    int k = 1;
    int flag;
    
    for (i = 0; i < Vn; i++){
        if (V[i] != 0){
            continue;
        }
        
        V[i] = k;
       
        for (j = i + 1; j < Vn; j++){
            if (A[i][j] == 0 && V[j] == 0){
                flag = 1;
                break;
            }
        }
        
        while (flag){
            flag = 0;
            for (j = i + 1; j < Vn - 1; j++){
                if (A[i][j] == 0 && V[j] == 0) {
                    break;    
                }
            }
            if (j == Vn) break;
            V[j] = k;
            for (t = 0; t < Vn; t++){
                if (A[i][t] + A[j][t] == 1){
                    A[i][t] = 1;
                }
            }
            for (j = i + 1; j < Vn; j++){
                if (A[i][j] == 0 && V[j] == 0){
                    flag = 1;
                    break;
                }
            }
        }
        k++;
        flag = 0;
    }
    
//    for (i = 0; i < Vn; i++)
//        cout << V[i] << endl;
    
    cout<<"Colors' number: " <<k-1;
    fin.close();

    return 0;
}
