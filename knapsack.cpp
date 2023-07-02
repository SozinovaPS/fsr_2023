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
    long long N, W; 
    fin >> N >> W;
    long long p, w, i, j;
    
    vector <long long> weight(W);
    vector <long long> price(N);
    
    for (i = 0; i < N; i++){
        fin >> p >> w;
        price[i] = p;
        weight[i] = w;
    }
    vector<long long> cap(W+1, 0);
    vector<vector<long long>> A(N+1, cap);
    
    
    for (i = 1; i <= N; i++){
        for (j = 0; j <= W; j++){
            if (weight[i] <= j) {
                int prev = A[i - 1][j];
				int form = A[i - 1][j - weight[i]] + price[i];
				A[i][j] = max(prev, form);
                }
			else {
			    A[i][j] = A[i - 1][j];
			} 	
        }
    }
    
    
    //for (i = 0; i < N; i++){
    //    for(j = 0; j <= W; j++){
    //        cout<< A[i][j]<<endl;
    //    }
    //}
    
    cout<<"Total value: "<<A[N][W];

    fin.close();

    return 0;
}
