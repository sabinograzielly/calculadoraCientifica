//defini��o do tipo
struct no {
    int elem;
    struct no *prox;
};
struct pilha {
    struct no *topo;
};

//cabe�alho das fun��es
void inicializaPilha(struct pilha *P);
short pilhaVazia (struct pilha *P);
void push (struct pilha *P, int elem);
int pop (struct pilha *P);
int dimensaoStr(char *Str);
int caractere(char *Str, int pos);
