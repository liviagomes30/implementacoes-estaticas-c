/*
Mais de uma pilha em um único espaço

CASO 1:
	Necessidade de 2 pilhas
	Um único vetor para 2 pilhas
	2 pilhas distintas
	1 topo para pilha 1 e 1 topo para a pilha 2
	Tudo em 1 lugar só
	TOPO PILHA1 = -1
	TOPO PILHA2 = MAXPILHA
	O espaço que uma pilha vai usar é o equivalente a que a outra pilha deixou de usar
	Só usa quando não tem obrigatoriedade das pilhas serem do mesmo tamanho
	
	
*/


#define MaxPilha 10

struct TpPilhaM1
{
	int TOPO1, TOPO2;
	char Pilha[MaxPilha];
};

void Inicializar(TpPilhaM1 &PM);
void PUSH(TpPilha &PM, char Elem, int NP);
char POP(TpPilhaM1 &PM, int NP);
char ElementoTopo(TpPilhaM1 &PM, int NP);
char PMVazia(int TOPO, int NP);
char PMCheia(int TOPO1, int TOPO2);
void ExibirPM(TpPilhaM1 PM, int NP);

void Inicializar(TpPilhaM1 &PM)
{
	PM.TOPO1 = -1;
	PM.TOPO2 = MaxPilha;
}

void PUSH(TpPilha &PM, char Elem, int NP)
{
	if(NP == 1)
		PM.Pilha[++PM.TOPO1] = Elem;
	else
		PM.Pilha[--PM.TOPO2] = Elem;
}

char POP(TpPilhaM1 &PM, int NP)
{
	if(NP == 1)
		return PM.Pilha[PM.TOPO1--];
	else
		return PM.Pilha[PM.TOPO2++];
}

char ElementoTopo(TpPilhaM1 &PM, int NP)
{
	if(NP == 1)
		return PM.Pilha[PM.TOPO1];
	else
		return PM.Pilha[PM.TOPO2];
}
char PMVazia(int TOPO, int NP)
{
	if(NP == 1)
		return TOPO == -1;
	return TOPO == MaxPilha;
}

char PMCheia(int TOPO1, int TOPO2)
{
	return TOPO1 == TOPO2 - 1;
}
void ExibirPM(TpPilhaM1 PM, int NP)
{
	if(NP == 1)
		while(!PMVazia(PM.TOPO1, NP))
			printf("\n%c",POP(PM, NP));
	else
		while(!PMVazia(PM.TOPO2, NP))
			printf("\n%c", POP(PM, NP));
}
