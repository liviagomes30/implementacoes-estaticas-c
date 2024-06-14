#define MAXPILHA 40

/*
Operações com Pilha:
    criação da pilha (informar a capacidade no caso de implementação sequencial - vetor);
    empilhar (push) - o elemento é o parâmetro nesta operação;
    desempilhar (pop);
    mostrar o topo;
    verificar se a pilha está vazia (isEmpty);
    verificar se a pilha está cheia (isFull - implementação sequencial - vetor). 
    exibir pilha
*/


struct TpPilha
{
	int TOPO;
	char PILHA[MAXPILHA];	
};


void Inicializar(TpPilha &P)
{
	P.TOPO = -1; // ao incrementar o topo, vai para a posição 0
}

void PUSH(TpPilha &P, char Elemento) //EMPILHAR
{
	P.PILHA[++P.TOPO] = Elemento;
}
	

char POP(TpPilha &P) // DESEMPILHAR
{
	return P.PILHA[P.TOPO--]; // só decrementa depois de retornar quem está no topo 
}

char ElementoTopo(TpPilha P) // Descobrir quem está no topo
{
	return P.PILHA[P.TOPO];
}

char PilhaCheia(int topo) // retornar 0 para não. OBS: utilização de char ao invés de inteiro pois ocupa menos memória
{
//	if(topo == MAXPILHA-1)
//		return 1;
//	return 0;

	return topo == MAXPILHA-1;
}

char PilhaVazia(int topo)
{
//	if(topo == -1)
//		return 1;
//	return 0;

	return topo == -1;
}

void ExibirPilha(TpPilha P) // passando cópia da pilha, então está detruindo a cópia
{
	while(!PilhaVazia(P.TOPO))
		printf("\n%c", POP(P)); // o último elemento colocado vai ser o primeiro a aparecer
}

