#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, S, aux, contador;
    cin >> N >> M;
    
    bool bandera = false;
    
    int A[N + 1], B[M];
    A[0] = 0;
    
    for(int i = 1; i<=N; i++)
        cin >> A[i];
    for(int j = 0; j < M; j++)
        cin >> B[j];
    S = (int)sqrt(N);
    
    for(int k = 0; k < M; k++){
        aux = 0;
        contador = 0;
        bandera = false;
        while(A[aux] < B[k] && aux < N){
            aux += S;
            contador++;
        }
        if(A[aux] == B[k]){
            cout << contador << "\n";
            bandera = true;
        }else{
            aux -= S;
            contador++;
            
            while(A[aux] < B[k]){
                aux++;
                contador++;
            }
            if(A[aux] == B[k]){
                cout << contador << "\n";
                bandera = true;
            }
        }
        if(bandera == false)
            cout << -1 << "\n"; 
        
    }
    return 0;
}