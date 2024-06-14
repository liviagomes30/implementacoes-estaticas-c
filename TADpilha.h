#define MAXPILHA 40

/*
Opera��es com Pilha:
    cria��o da pilha (informar a capacidade no caso de implementa��o sequencial - vetor);
    empilhar (push) - o elemento � o par�metro nesta opera��o;
    desempilhar (pop);
    mostrar o topo;
    verificar se a pilha est� vazia (isEmpty);
    verificar se a pilha est� cheia (isFull - implementa��o sequencial - vetor). 
    exibir pilha
*/


struct TpPilha
{
	int TOPO;
	char PILHA[MAXPILHA];	
};


void Inicializar(TpPilha &P)
{
	P.TOPO = -1; // ao incrementar o topo, vai para a posi��o 0
}

void PUSH(TpPilha &P, char Elemento) //EMPILHAR
{
	P.PILHA[++P.TOPO] = Elemento;
}
	

char POP(TpPilha &P) // DESEMPILHAR
{
	return P.PILHA[P.TOPO--]; // s� decrementa depois de retornar quem est� no topo 
}

char ElementoTopo(TpPilha P) // Descobrir quem est� no topo
{
	return P.PILHA[P.TOPO];
}

char PilhaCheia(int topo) // retornar 0 para n�o. OBS: utiliza��o de char ao inv�s de inteiro pois ocupa menos mem�ria
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

void ExibirPilha(TpPilha P) // passando c�pia da pilha, ent�o est� detruindo a c�pia
{
	while(!PilhaVazia(P.TOPO))
		printf("\n%c", POP(P)); // o �ltimo elemento colocado vai ser o primeiro a aparecer
}

