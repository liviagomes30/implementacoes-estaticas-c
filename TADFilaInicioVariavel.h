#define MAXFILA 10

struct TpFilaInicioVar{
	int INICIO,FIM;
	char FILA[MAXFILA];
};

void FIVInicializar(TpFilaInicioVar &F){
	INICIO = 0;
	F.FIM = -1;
}

void FIVEnfileirar(TpFilaInicioVar &F){
	for(int i = F.INICIO; i <= F.FIM; i++)
		F.FILA[i - F.INICIO] = F.FILA[i];
	
	F.FIM -= F.INICIO;
	F.INICIO = 0;
}


void FIVInserir(TpFilaInicioVar &F, char Elem){
	if(F.FIM == MAXFILA - 1 && F.INICIO > 0)
		FIVEnfileirar(F);
		
	F.FILA[++F.FIM] = Elem;
}


void Retirar(TpFilaInicioVar &F){
	return F.FILA[F.INICIO++];
}

char FIVElementoInicio(TpFilaInicioVar F){
	return F.FILA[F.INICIO];
}

char FIVElementoFim(TpFilaInicioVar F){
	return F.FILA[F.FIM];
}

int FIVCheia(int inicio, int fim){
	return (inicio == 0 && fim == MAXFILA -1); 
}

int FIVVazia(int inicio, int fim){
	return (inicio > fim); 
}

void FIVExibir(TpFilaInicioVar F){
	while(!FilaVazia(F.INICIO, F.FIM))
		printf("\t%c", FIVRetirar(F));
}
