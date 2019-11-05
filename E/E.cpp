#include <bits/stdc++.h> 
#define TAM 10005

using namespace std;

int main(){
	
	int n;
	string palabras[TAM];

	scanf("%d\n", &n);

	for(int i=0; i<n; i++){
		cin >> palabras[i];
	}

	sort(palabras,palabras+n);

	set <string> S;
	int respuesta=0;
	for(int i=0; i<n; i++){
		string s="";
		for(int j=0; j<palabras[i].size(); j++){
			s += palabras[i][j];
			if(S.find(s)!=S.end()){
				//cout << "*"<< s << endl;
				S.erase(s);
			}
		}
		S.insert(palabras[i]);
	}

	printf("%d\n", (int)S.size());

	return 0;
}