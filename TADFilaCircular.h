#define MAXFILA 10

struct TpFila{
	int INICIO,FIM,CONT; // cont faz o controle de qtde de elementos
	char FILA[MAXFILA];
};

void Inicializar(TPFila &F){
	INICIO = 0;
	CONT = 0;
	F.FIM = -1;
}

// verificar se esta cheio somente no cpp
void Inserir(TpFila &F, char Elem){
	if(F.FIM==MAXFILA-1)
		F.FIM = 0;
	else
		F.FIM++;
	F.FILA[F.FIM] = Elem;
	F.CONT++;
}

void Retirar(TpFila &F){
	char elemento;
	elemento = F.FILA[F.INICIO++];
	if(F.INICIO == MAXFILA-1)
		F.INICIO=0;
	F.CONT--;
	return elemento;
}

char ElementoInicio(TpFila F){
	return F.FILA[F.INICIO];
}

char ElementoFim(TpFila F){
	return F.FILA[F.FIM];
}

int Cheia(int cont){
	return cont == MAXFILA-1;
}

int Vazia(int cont){
	return cont == 0;
}

void ExibirFila(TpFila F){
	while(!FilaVazia(F.INICIO, F.FIM))
		printf("\t%c", Retirar(F));
}
