#include <conio.h>
#include <iostream>
#include <string.h>

using namespace std;

/*lista de structs*/
struct Cidade{
    int codigo;
    char nome[50];
    char UF[2];
};

struct Apresentador{
    int codigo;
    char nome[50];
};

struct Participante{
    int codigo;
    char nome[50];
    int codigo_evento;//chave estrangeira
};

struct Evento{
    int codigo;
    char descricao[100];
    int qtdeParticipantes;
    int limiteParticipantes;
    float precoUnitario;
    
    int codigo_cidade;//chave estrangeira
    int codigo_apresentador;//chave estrangeira
};

char menu(){
	
	char op;
    system("cls"); //LIMPA A TELA
	cout<<"\t\tMENU PRINCIPAL\n\n";
    cout<<"\t\t\t1 - Cadastrar Cidades\n\n";
    cout<<"\t\t\t2 - Mostrar Cidades\n\n";
    cout<<"\t\t\t3 - Cadastrar Apresentadores\n\n";
    cout<<"\t\t\t4 - Mostrar apresentadores\n\n";
    cout<<"\t\t\t5 - Cadastrar eventos\n\n";
    cout<<"\t\t\t6 - Mostrar Eventos\n\n";
    cout<<"\t\t\t7 - Menu de Inclusoes\n\n";
    cout<<"\t\t\t8 - \n\n";
    cout<<"\t\t\t9 - Sair do programa\n\n";
    
    cout<<"\t\tEscolha a opcao: ";
	op=toupper(getch());//pega a batida do teclado do usuario
	
	return op;	
}

void hello(){
	system("cls");
	cout<<"\n\n\t\tHello World";
	getch();
}





void sair(char &opcao, char &conf){
	system("cls");
	cout<<"\n\n\t\tDeseja finalizar o programa? S / N";
	conf=toupper(getch());
	if(conf == 'S'){
		opcao = 'S';
		cout<<"\n\n\t\t\tFinalizando programa...";
		
	}
}

void lerCidades(Cidade lista[], int n, int &ctrl){
	system("cls"); //LIMPA A TELA	
	cout<<"\t------------CADASTRANDO CIDADES------------";	
	for(int i = 0; i < n; i++){
		cout<<"\n\n\t\tCidade ["<<i+1<<"]";
		cout<<"\n\tDigite codigo da cidade: ";
		cin>>lista[i].codigo;
		cout<<"\n\tDigite nome da cidade: ";
		cin>>lista[i].nome;
		cout<<"\n\tDigite UF da cidade: ";
		cin>>lista[i].UF;
		ctrl++;		
	}	
	getch;	
	
}

void mostrarCidades(Cidade lista[],int tam){
	system("cls"); //LIMPA A TELA
	if(tam == 0){
		cout<<"\n\t\tLista de cidades vazia.";
	} else{
		for(int i = 0; i < tam;i++){
			cout<<"\n\tCodigo: "<<lista[i].codigo<<" | Cidade: "<<lista[i].nome<<" | UF: "<<lista[i].UF;
			
		}
	}
	getch();
	
}

void lerApresentadores(Apresentador lista[],int n, int &ctrl){
	system("cls"); //LIMPA A TELA	
	cout<<"\t------------CADASTRANDO APRESENTADORES------------";
	for(int i = 0; i < n; i++){
		cout<<"\n\t\tApresentador ["<<i+1<<"]\n";
		cout<<"\n\tDigite codigo do apresentador: ";
		cin>>lista[i].codigo;
		cout<<"\n\tDigite nome do apresentador: ";
		cin>>lista[i].nome;
		ctrl++;		
	}	
	getch;
}

void mostrarApresentadores(Apresentador lista[],int tam){
	system("cls"); //LIMPA A TELA
	if(tam == 0){
		cout<<"\n\t\tLista de apresentadores vazia.";
	} else{
		for(int i = 0; i < tam;i++){
			cout<<"\n\tCodigo: "<<lista[i].codigo<<" | Nome: "<<lista[i].nome;
			
		}
	}
	cout<<"\n\n\t\tTamanho da lista: "<<tam;
	getch();	
}

void lerEventos(Evento lista[],int n, int &ctrl){
	system("cls"); //LIMPA A TELA	
	cout<<"\t------------CADASTRANDO EVENTO------------";
	for(int i = 0; i < n; i++){
		cout<<"\n\t\tEvento ["<<i+1<<"]\n";
		cout<<"\n\tDigite codigo do evento: ";
		cin>>lista[i].codigo;
		cout<<"\n\tDigite descricao do evento: ";
		cin>>lista[i].descricao;
		cout<<"\n\tDigite quantidade de participantes";
		cin>>lista[i].qtdeParticipantes;
		cout<<"\n\tDigite limite de participantes";
		cin>>lista[i].limiteParticipantes;
		cout<<"\n\tDigite valor do ingresso";
		cin>>lista[i].precoUnitario;
		ctrl++;		
	}	
	getch;
	
}

void mostrarEventos(Evento lista[],int tam){
	system("cls"); //LIMPA A TELA
	if(tam == 0){
		cout<<"\n\t\tLista de eventos vazia.";
	} else{
		for(int i = 0; i < tam;i++){
			cout<<"\n\tCodigo: "<<lista[i].codigo<<" | Descricao: "<<lista[i].descricao<<" | Qtde Participantes: "<<lista[i].qtdeParticipantes<<" | Limite participantes: "<<lista[i].limiteParticipantes<<" | Preco ingresso: "<<lista[i].precoUnitario;
			
		}
	}
	getch();
	
}

void addApresentador(Apresentador sequencial[],int &contador){
	system("cls");
	
	Apresentador temporario[1]; int contT = 0 ;
	Apresentador atualizado[100]; int contA = 0;
	
	int i = 0, j = 0, k = 0;  //sequencial, temporario, atualizado
	
		cout<<"Tamanho da lista sequencial passada por parametro: "<<contador;
		
		cout<<"\n\t\tDigite codigo do apresentador: ";
		cin>>temporario[j].codigo;
		cout<<"\n\t\tDigite nome do apresentador: ";
		cin>>temporario[j].nome;
		contT = 1;
		
		
	for(;i < contador && j < contT;k++){
		if(sequencial[i].codigo < temporario[j].codigo){
			atualizado[k].codigo = sequencial[i].codigo;
			strcpy(atualizado[k].nome,sequencial[i].nome);			
			cout<<"\n\tItem transferido de sequencial para atualizado: "<<sequencial[i].codigo;
			i++;			
		}else{
			atualizado[k].codigo = temporario[j].codigo;
			strcpy(atualizado[k].nome,temporario[j].nome);			
			j++;			
			cout<<"\n\tItem transferido de temporario para atualizado"<<temporario[j].codigo;
		}		
	}	
	
	while(i < contador){
		atualizado[k].codigo = sequencial[i].codigo;
		strcpy(atualizado[k].nome, sequencial[i].nome);		
		i++;
		k++;				
	}
	
	while(j < contT){
		atualizado[k].codigo = temporario[j].codigo;
		strcpy(atualizado[k].nome,temporario[j].nome);
		j++;
		k++;		
	}
	
	contador = k;
	
	
	cout<<"\n\n\tLista atualizada, gerada dentro da funcao";
	for(int x = 0; x < k;x++){
		cout<<"\n\t\t\tCodigo: "<<atualizado[x].codigo<<" | Nome: "<<atualizado[x].nome;			
		}
		
	cout<<"\n\n\t\tTransferindo de atualizado para sequencial....";
		
		
		
	for(int x = 0; x < contador;x++){
		sequencial[x].codigo = atualizado[x].codigo;
		strcpy(sequencial[x].nome, atualizado[x].nome);			
	}
	cout<<"\n\n\tValores transferidos para vetor principal!!!";
	cout<<"\n\n\n\t\tPressione algo....";
getch();
}

void menu2(struct Apresentador lista[],int &x){
	int func;
	while(func!=1){
    system("cls"); //LIMPA A TELA
	cout<<"\t\t\t\tMENU - INCLUSOES:\n\n";
    cout<<"\t\t\t\t\t1 - Incluir novo Apresentador\n\n";
    cout<<"\t\t\t\t\t2 - Incluir novo Evento\n\n";
    cout<<"\t\t\t\t\t3 - Se inscrever em um evento\n\n";
    cout<<"\t\t\t\t\t4 - Consultar dados de Evento\n\n";
    cout<<"\t\t\t\t\t5 - Mostrar todos eventos\n\n";
    cout<<"\t\t\t\t\t6 - \n\n";
    cout<<"\t\t\t\t\t7 - \n\n";
    cout<<"\t\t\t\t\t8 - Voltar para Menu Principal\n\n";
    
    cout<<"\t\t\t\tEscolha a opcao: ";
	
	char op=toupper(getch());//pega a batida do teclado do usuario	
	
	
	
		switch (op) {
		  case '1' : {  addApresentador(lista,x); break; }
		  //case '2' : {  ; break; }
		  //case '3' : {  ; break;}
		  //case '4' : {  ; break; }
		  //case '5' : {  ; break; }
		  //case '6' : {  ; break; }
		  //case '7' : {  ; break; } // mostra todos itens ja cadastrados
		  case '8' : { func=1;menu();  break;	 }
		  
		  default : { cout<<"\n\nOpcao invalida2. Tecle algo para continuar...";
		              getch(); }
		
		
		}
   	}   	
}

int main(){
	system("color 8F");
	/*declaracao dos vetores*/
	Cidade listaCidades[100]; int lengCidade = 0;//contador
    Apresentador listaApresentadores[100]; int lengApre = 0;//contador
    Participante listaParticipantes[100]; int lengPart = 0;//contador
    Evento listaEventos[100]; int lengEvent = 0;//contador
    
	
	char opcao='N';
	char conf;	
    while (opcao != 'S'){
		opcao = menu();  // recebe o retorno da função menu()
		switch (opcao) {
		  case '1' : { lerCidades(listaCidades,5,lengCidade); break; }
		  case '2' : { mostrarCidades(listaCidades, lengCidade); break; }
		  case '3' : { lerApresentadores(listaApresentadores,5,lengApre); break;}
		  case '4' : { mostrarApresentadores(listaApresentadores,lengApre); break; }
		  case '5' : { lerEventos(listaEventos,2,lengEvent); break; }
		  case '6' : { mostrarEventos(listaEventos,lengEvent); break; }
		  case '7' : { menu2(listaApresentadores,lengApre); break; } // mostra todos itens ja cadastrados
		  //case '8' : { ;break; }
		  case '9' : { sair(opcao,conf);  break;	 }
		  
		  default : { cout<<"\n\nOpcao invalida. Tecle algo para continuar...";
		              getch(); }
		}
   }    
    
}
