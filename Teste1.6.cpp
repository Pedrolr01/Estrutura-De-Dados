#include<stdio.h>
#include<string.h>

struct cliente{
	
	char nome[100], sexo[3];
	
	void cliente1(){
		
		strcpy(nome,"");
		strcpy(sexo,"");
	}
	void ler(){
		
		scanf("%s %s", nome, sexo);
	}
	void mostrarCliente(){
		
		printf("Nome: %s\nSexo: %s", nome, sexo);
	}
};

struct data{
	
	int dia, mes, ano, idade, idadeCliente[50];
	cliente cc, salvarCliente[50];
	
	void data1(){
		
		dia = 0;
		mes = 0;
		ano = 0;
		idade = 0;
	}
	void lerData(){
		
		scanf("%d/%d/%d", &dia, &mes, &ano);
		calcularIdade();
	}
	void mostrarData(int i){
		
		printf("Idade: %d\n", idadeCliente[i]);
	}
	void calcularIdade(){
		
		idade = 2022 - ano;
		if(mes == 1){
			
			idade = idade + 1;
		}
		else if(mes == 2){
			
			if(dia<=13){
				
				idade = idade + 1;
			}
		}
	}
	void novoCliente(int i){
			
		printf("Insira o nome e o sexo do cliente: \n");
		salvarCliente[i].ler();
		printf("\nInsira a data de nascimento do cliente: \n");
		lerData();
		idadeCliente[i]  = idade;
	}
	void mostrarClientes(int i){
		
		salvarCliente[i].mostrarCliente();
		mostrarData(i);
	}
};

int main(){
	
	int parar = 0, opcao, parar2 = 0, contador = 0;
	data dat;
	
	while(parar == 0){
		
		printf("Selecione uma opcao:\n1. Inserir Cliente\n2. Lista de Clientes\n\n");
		scanf("%d", &opcao);		
		
		switch(opcao){
			
			case 1:
				
				dat.novoCliente(contador);
				contador++;
				
				break;
			case 2:
				
				for(int i = 0; i < contador; i++){
						
					dat.mostrarClientes(i);
						
					if(i == 49){
							
						parar = 1;
					}
				}	
					break;
				}
		}
	}

