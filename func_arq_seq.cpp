#include <conio.h>
#include <iostream>
#include <string.h>

using namespace std;

//variaveis do menu
char opcao='N';
char conf;


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
    cout<<"\t\t\t7 - Segundo Menu\n\n";
    cout<<"\t\t\t8 - Adicionar novo Apresentador\n\n";
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

void menu2(){
	int opcao;
    system("cls"); //LIMPA A TELA
	cout<<"\t\t\t\tMENU - CADASTROS:\n\n";
    cout<<"\t\t\t\t\t1 - Cadastrar Cidades\n\n";
    cout<<"\t\t\t\t\t2 - Mostrar Cidades\n\n";
    cout<<"\t\t\t\t\t3 - Cadastrar Apresentadores\n\n";
    cout<<"\t\t\t\t\t4 - Mostrar Apresentadores\n\n";
    cout<<"\t\t\t\t\t5 - Cadastrar eventos\n\n";
    cout<<"\t\t\t\t\t6 - Mostrar Eventos\n\n";
    cout<<"\t\t\t\t\t7 - \n\n";
    cout<<"\t\t\t\t\t8 - Voltar para Menu Principal\n\n";
    
    cout<<"\t\t\t\tEscolha a opcao: ";
	opcao=getch();//pega a batida do teclado do usuario
	
	
	int sair = 0;
	
		//menu2();
		switch (opcao) {
		  case '1' : {  hello(); break; }
		  //case '2' : {  ; break; }
		  //case '3' : {  ; break;}
		  //case '4' : {  ; break; }
		  //case '5' : {  ; break; }
		  //case '6' : {  ; break; }
		  //case '7' : {  ; break; } // mostra todos itens ja cadastrados
		  case '8' : { menu();  break;	 }
		  
		  default : { cout<<"\n\nOpcao invalida. Tecle algo para continuar...";
		              getch(); }
		}
   
}



void sair(){
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
	for(int i = 0; i < 3; i++){
		cout<<"\n\t\tCidade ["<<i+1<<"]"<<endl;
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

void addApresentador(Apresentador antiga[],int &y){
	system("cls");
	//cout<<"Tamanho lista apresentador"<<y; // tamanho da lista esta entrnado
	//Apresentador temporario[1];
	//Apresentador novo[y +1];
		cout<<"\n\t\tDigite codigo do apresentador: ";
		cin>>antiga[y].codigo;
		cout<<"\n\t\tDigite nome do apresentador: ";
		cin>>antiga[y].nome;
		y++;
	
	
/*	for(int i = y; i < y+1; i++){
	
		
	}*/
	
	
	
	
	
	
	getch();
}


int main(){
	/*declaracao dos vetores*/
	Cidade listaCidades[100]; int lengCidade = 0;
    Apresentador listaApresentadores[100]; int lengApre = 0;
    Participante listaParticipantes[100]; int lengPart = 0;
    Evento listaEventos[100]; int lengEvent = 0;
    
	
	
	
    while (opcao != 'S'){
		opcao = menu();  // recebe o retorno da função menu()
		switch (opcao) {
		  case '1' : { lerCidades(listaCidades,2,lengCidade); break; }
		  case '2' : { mostrarCidades(listaCidades, lengCidade); break; }
		  case '3' : { lerApresentadores(listaApresentadores,2,lengApre); break;}
		  case '4' : { mostrarApresentadores(listaApresentadores,lengApre); break; }
		  case '5' : { lerEventos(listaEventos,2,lengEvent); break; }
		  case '6' : { mostrarEventos(listaEventos,lengEvent); break; }
		  case '7' : { menu2(); break; } // mostra todos itens ja cadastrados
		  case '8' : { addApresentador(listaApresentadores,lengApre);break; }
		  case '9' : { sair();  break;	 }
		  
		  default : { cout<<"\n\nOpcao invalida. Tecle algo para continuar...";
		              getch(); }
		}
   }   
   
   /*
   
   char escolha;
   cout<<"\n\n\t\tEscolha o menu";
   cout<<"\n\n\t\t1 - Menu de Cadastros";
   cout<<"\n\n\t\t2 - Menu de Adicoes";
   escolha = getch();
   
   switch(escolha){
   	case '1' : {
		menu(); break;
	   }
	   
	case '2' : {
		menu2(); break;
	}
   }
   
   cout<<escolha;*/
   
    
    
    

    
    
    
}
