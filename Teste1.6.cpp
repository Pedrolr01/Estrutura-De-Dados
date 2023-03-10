#include<stdio.h>

struct No {
int valor;
No *prox;
};

struct Lista {
No *cabeca, *cauda;
int n;

Lista() {
    cabeca = cauda = NULL;
    n = 0;
}

bool vazia() { 
    return (cabeca == NULL);
}

void inserirInicio() {
    printf("\nDigite o valor: ");
    int v;
    scanf("%d", &v);
    No *novo = new No();
    novo->valor = v;
    if (vazia()) {
        novo->prox = NULL;
        cabeca = novo;
        cauda = novo;
    } else {
        novo->prox = cabeca;
        cabeca = novo;
    }
    n++;
}

void inserirInicioAteN() {
    printf("\nDigite o valor: ");
    int v;
    scanf("%d", &v);
    No *novo = new No();
    for(int i=1;i==n;i++){
        novo->valor = i;
        if (vazia()) {
            novo->prox = NULL;
            cabeca = novo;
            cauda = novo;
        } else {
            novo->prox = cabeca;
            cabeca = novo;
        }
        n++; 
    }
}

void inserirFinal() {
    printf("\nDigite o valor: ");
    int v;
    scanf("%d", &v);
    No *novo = new No();
    novo->valor = v;
    if (vazia()) {
        novo->prox = NULL;
        cabeca = novo;
        cauda = novo;
    } else {
        novo->prox = NULL;
        cauda->prox = novo;
        cauda = novo;
    }
    n++;
}

void imprimir() {
    No *aux = cabeca;
    printf("\nLista:\n");
    while (aux != NULL) {
        printf("%d ", aux->valor);
        aux = aux->prox;
    }
    printf("\n\n");
}

int mostrarTamanho(int a) {
    No *novo = new No();
    novo->valor = a;
    if (vazia()) {
        novo->prox = NULL;
        cabeca = novo;
        cauda = novo;
    } else {
        novo->prox = NULL;
        cauda->prox = novo;
        cauda = novo;
    }
}

int tamanho(){
    return n;
}

void removerInicio() {
    if (!vazia()) {
        if (tamanho() == 1) {
            No *aux = cabeca;
            cabeca = NULL;
            cauda = NULL;
            delete(aux);
        } else {
            No *aux = cabeca;
            cabeca = cabeca->prox;
            delete(aux);
        }
        n--;
    }
}

void removerTamanho(int a){
    if (!vazia()) {
        if (tamanho() == 1) {
            No *aux = cabeca;
            cabeca = NULL;
            cauda = NULL;
            delete(aux);
        } else {
            No *penultimo = cabeca;
            while (penultimo->prox != cauda) {
                penultimo = penultimo->prox;
            }
            delete(cauda);
            cauda = penultimo;
            cauda->prox = NULL;
        }
    }
}

void removerFinal() {
    if (!vazia()) {
        if (tamanho() == 1) {
            No *aux = cabeca;
            cabeca = NULL;
            cauda = NULL;
            delete(aux);
        } else {
            No *penultimo = cabeca;
            while (penultimo->prox != cauda) {
                penultimo = penultimo->prox;
            }
            delete(cauda);
            cauda = penultimo;
            cauda->prox = NULL;
        }
        
        n--;
    }
}
};

int main() {
    int repetir = 0, opcao, valor;
    Lista l;

    while(repetir == 0){
        printf("Escolha uma opcao: \n1. Inserir um valor no inicio da lista\n2. Inserir um valor no final da lista\n");
        printf("3. Inserir os valores de 1 até N na lista\n4. Inserir um penultimo valor a lista\n");
        printf("5. Remover valor do inicio da lista\n6. Remover valor do final da lista\n7. Remover N ultimos valores da lista\n");
        printf("8. Remover apenas o segundo valor da lista\n9. Mostrar o tamanho da lista\n10. Finalizar programa\n");
        scanf("%d", &opcao);
    
        switch(opcao){
            case 1:
                l.inserirInicio();
                break;
            
            case 2:
                l.inserirFinal();
                break;
            
            case 3:
                l.inserirInicioAteN();
                break;
            
            case 4:
                break;
            
            case 5:
                l.removerInicio();
                break;
                
            case 6:
                l.removerFinal();
                break;
        
            case 7:
                break;
            
            case 8:
                break;
            
            case 9:
                l.mostrarTamanho(l.n);
                break;
            
            case 10: 
                repetir = 1;
        }
    
        l.imprimir();
        if(opcao == 9){
            l.removerTamanho(opcao);
        }
    }
    
    return 0;
}
