#include <iostream>
#include <chrono>



// Responsável por inicializar a memoria no metodo Top-Down
void init(int* memoria, int n){
	
	for(int i = 1; i <= n; i++){

		memoria[i] = 0;
	}
	memoria[1] = 1;
	memoria[2] = 1;

} 


/* Verificamos se existe na memoria
 * Caso nao vamos calculando até chegar o caso base	*/
int fibTopDown(int n, int* memoria){

	if (memoria[n] == 0) {
		memoria[n] = fibTopDown(n - 1, memoria) + fibTopDown(n - 2, memoria);
	}
	return memoria[n];
}


/* Inicializamos os cassos bases e vamos do caso base até n
 * estamos subindo a arvore, ex: para n = 6
 * memoria[3] = memoria[2] + memoria[1]
 * memoria[3] = 2
 * memoria[4] = memoria[3] + memoria[2]
 * memoria[4] = 3
 * memoria[5] = memoria[4] + memoria[3]
 * memoria[5] = 5
 * memoria[6] = memoria[5] = memoria[4]
 * memoria[6] = 8 */


int fibBottomUp(int n, int* memoria){
	memoria[1] = 1;
	memoria[2] = 1;
	for(int i = 3; i <= n; i++){

		memoria[i] = memoria[i - 1] + memoria[i - 2];
	}

	return memoria[n];
}
int main(){
	
	int n;

	std::cout << "Digite um valor de n para calcular fibonnaci: ";
	std::cin >> n;
	int choice;
	std::cout << "Escolha o metodo (1) para topDown e (2) para bottom up: ";
	std::cin >> choice;

	int* memoria = NULL;
	memoria = new int[n + 1];
	int resposta = 0;
	
	auto start = std::chrono::high_resolution_clock::now();
	if(choice == 1){

		init(memoria, n);
		resposta = fibTopDown(n, memoria);
	}
	else if(choice == 2) {

		resposta = fibBottomUp(n, memoria);
	}
	auto end = std::chrono::high_resolution_clock::now() - start;
	long long time = std::chrono::duration_cast<std::chrono::microseconds>(end).count();

	std::cout << "A resposta eh: " << resposta << std::endl;
	std::cout << "O tempo foi: " << time << std::endl;


}
