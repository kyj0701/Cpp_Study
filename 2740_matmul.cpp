#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main(void)
{
    vector<int> l;
    int q;
    int N, M, K;
    
    // Matrix A input
    cin >> N;
    cin >> M;
    vector<vector<int>> A(N, vector<int>(M,0));

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cin >> q;
            A[i][j] = q;
        }
    }

    // Matrix B input
    cin >> M;
    cin >> K;
    vector<vector<int>> B(K, vector<int>(M,0));

    for(int i = 0; i < M; i++)
    {
        for(int j = 0; j < K; j++)
        {
            cin >> q;
            B[j][i] = q;
        }
    }

    // A x B result matrix
    vector<vector<int>> res(N, vector<int>(K,0));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < K; j++)
        {
            res[i][j] = inner_product(A[i].begin(), A[i].end(), B[j].begin(), 0);
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < K; j++)
        {
            cout << res[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}