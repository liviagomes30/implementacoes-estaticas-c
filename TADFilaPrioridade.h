#define MAXFILA 10

struct TpElemento{
	char Id;
	int Prior;
};

struct TpFilaP{
	int FIM;
	TpElemento Fila[MAXFILA];
};


void FPInicializar(TpFilaP &FP){
	FP.FIM = -1;
}

char FPVazia(int fim){
	return fim == -1;
}

char FPCheia(int fim){
	return fim == MAXFILA-1;
}

void FPInserir(TpFilaP &FP, TpElemento Elem){
	FP.Fila[++FP.FIM] = Elem;
	TpElemento aux;
	int i;
	
	i = FP.FIM;
	while(i > 0 && FP.Fila[i].Prior < FP.Fila[i-1].Prior)
	{
		aux = FP.Fila[i];
		FP.Fila[i] = FP.Fila[i-1];
		FP.Fila[i-1] = aux;
		i--;
	}	
}

TpElemento FPRetirar(TpFilaP &FP){
	TpElemento elemento = FP.FILA[0];
	for(int i = 0; i < FP.FIM; i++)
		FP.FILA[i] = FP.FILA[i+1];
	
	FP.FIM--;
	return elemento;
}

TpElemento FPElementoInicio(TpFilaP FP){
	return FP.FILA[0];
}

TpElemento FPElementoFim(TpFilaP FP){
	return FP.FILA[FP.FIM];
}

void ExibirFila(TpFilaP FP){
	TpElemento Elem;
	while(!FPVazia(FP.FIM)){
		Elem = FPRetirar(FP);
		printf("\n%c-%d",Elem.Id, Elem.Prior);
	}
}
