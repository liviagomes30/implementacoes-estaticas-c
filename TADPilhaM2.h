/*

CASO 2:
	"n" pilhas
	Caso 1 n�o especifica previamente o tamanho de cada pilha
	No caso 2 determina previamente o tamanho de cada pilha -> ex1
	
*/


#define MAXPILHA 10

struct TpPilhaM2
{
	int TOPO[MAXPILHA], BASE[MAXPILHA];
	char Pilha[MAXPILHA];
};

// qtde = quantidade de pilhas que ser�o utilizadas, tamanho l�gico das pilhas
// exemplo: total de 10 espa�os, 3 pilhas -> cada pilha vai ocupar 3 espa�os e o �ltimo restante n�o ser� utilizado
// BASE [0,3,6] -> onde cada pilha come�a
// TOPO [-1, 2, 5] -> uma posi��o antes do in�cio da outra pilha
// Para estar cheia, base = 3 e o topo = 2 (1� pilha)
// Para identificar que a �ltima pilha est� cheia, � interessante colocar valor na base para identificar -> BASE[0,3,6,9] e TOPO[-1,2,5,8]


void Inicializar(TpPilhaM2 &PM, int qtde){
	int qtdeElemen;
	qtdeElemen = MAXPILHA / qtde;
	for(int i = 0; i <= qtde; i++){
		PM.BASE[i] = i*qtdeElemen;
		PM.TOPO[i] = PM.BASE[i] -1;
	}
}

// pilha 0, 1 e 2

void PUSH(TpPilhaM2 &PM, char Elemen, int NP){
	PM.Pilha[++PM.TOPO[NP]] = Elemen;
}

char POP(TpPilhaM2 &PM, int NP){
	return PM.Pilha[PM.TOPO[NP]--];
}

char ElementoTopo(TpPilhaM2 PM, int NP){
	return PM.Pilha[PM.TOPO[NP];
}

char PMVazia(TpPilhaM2 PM, int NP){
	return PM.TOPO[NP] < PM.BASE[NP];
}

// topo do lado da base da pr�x pilha
char PMCheia(TpPilhaM2 PM, int NP){
	return PM.TOPO[NP] + 1 == PM.BASE[NP+1];
}

void ExibePilha(TpPilhaM2 PM, int NP){
	while(!PMVazia(PM, NP))
		printf("\n%c", POP(PM,NP));
}
