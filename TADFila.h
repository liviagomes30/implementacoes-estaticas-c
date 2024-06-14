#define MAXFILA 10

struct TpFila{
	int FIM;
	char FILA[MAXFILA];
};

void Inicializar(TpFila &F);
void Inserir(TpFila &F, char Elem);
int Retirar(TpFila &F);
int ElementoInicio(TpFila F);
int ElementoFim(TpFila F);
int FilaVazia(int fim);
int FilaCheia(int fim);
void ExibirFila(TpFila F);

void Inicializar(TPFila &F){
	F.FIM = -1;
}

char FilaVazia(int fim){
	return fim == -1;
}

char FilaCheia(int fim){
	return fim == MAXFILA-1;
}

void Inserir(TPFila &F, char Elem){
	F.FILA[++F.FIM] = Elem;
}

char Retirar(TpFila &F){
	char elemento = F.FILA[0];
	for(int i = 0; i < F.FIM; i++)
		F.FILA[i] = F.FILA[i+1];
	
	F.FIM--;
	return elemento;
}

char ElementoInicio(TpFila F){
	return F.FILA[0];
}

char ElementoFim(TpFila F){
	return F.FILA[F.FIM];
}

void ExibirFila(TpFila F){
	while(!FilaVazia(F.FIM))
		printf("\t%c", Retirar(F));
}
