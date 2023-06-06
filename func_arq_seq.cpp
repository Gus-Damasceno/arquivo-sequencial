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
/*Menu Principal*/
char menu(){
	
	char op;
    system("cls"); //LIMPA A TELA
	cout<<"\t\t============ MENU PRINCIPAL ========\n\n";
	cout<<"\t\t|\t0 - Cadastrar Cidades\n\n";
    cout<<"\t\t|\t1 - Cadastrar Apresentadores\n\n";
    cout<<"\t\t|\t2 - Cadastrar Eventos\n\n";
    cout<<"\t\t|\t3 - Cadastrar Participantes\n\n";
    cout<<"\t\t--------------------------------------\n\n";
    cout<<"\t\t|\t4 - Exibir Cidades\n\n";
    cout<<"\t\t|\t5 - Exibir Apresentadores\n\n";
    cout<<"\t\t|\t6 - Exibir Eventos\n\n";
    cout<<"\t\t|\t7 - Exibir Participantes\n\n";
    cout<<"\t\t--------------------------------------\n\n";
    cout<<"\t\t|\t8 - Menu de Inclusões -->\n\n";
    cout<<"\t\t|\t9 - Sair do programa\n\n";
    
    cout<<"\t\tEscolha a opcao: ";
	op=toupper(getch());//pega a batida do teclado do usuario
	
	return op;	
}
/*validacao de chave estrangeira*/
int buscarCidade(struct Cidade lista[], int tam, int procurado){
	
	int cod = procurado;
			
	int inicio = 0, final = tam;
	int meio = (inicio + final) / 2;
	
	for(; final >= inicio && cod != lista[meio].codigo; meio = (inicio + final) / 2){
		if(cod > lista[meio].codigo){
			inicio = meio +1 ;
		}else{
			final = meio -1;
		}		
	}
	if(cod == lista[meio].codigo){
		/*mostrar todos detalhes*/
		//cout<<"encontrado";
		cout<<"\n\t\tCidade: "<<lista[meio].nome<<" UF: "<<lista[meio].UF<<endl;
		return 1;
	}else{
		cout<<"\n\t\tx---- Codigo nao localizado. Insira um codigo valido ----x"<<endl;
		return 0;
		
	}
	getch();
}

int buscarApresentador(struct Apresentador lista[], int tam, int procurado){	
	int cod = procurado;
			
	int inicio = 0, final = tam;
	int meio = (inicio + final) / 2;
	
	for(; final >= inicio && cod != lista[meio].codigo; meio = (inicio + final) / 2){
		if(cod > lista[meio].codigo){
			inicio = meio +1 ;
		}else{
			final = meio -1;
		}		
	}
	if(cod == lista[meio].codigo){
		/*mostrar todos detalhes*/
		//cout<<"encontrado";
		cout<<"\n\t\tApresentador: "<<lista[meio].nome<<endl;
		return 1;
	}else{
		cout<<"\n\t\tx---- Codigo nao localizado. Insira um codigo valido ----x"<<endl;
		return 0;
		
	}
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
/*leituras e exibicao*/
void lerCidades(Cidade lista[], int n, int &ctrl){
	system("cls"); //LIMPA A TELA	
	cout<<"\t------------CADASTRANDO CIDADES------------";	
	for(int i = 0; i < n; i++){
		
		cout<<"\n\n\t\tCidade ["<<i+1<<"]";
		cout<<"\n\tDigite codigo da cidade: ";
		cin>>lista[i].codigo;
		
		if(lista[i].codigo ==0){
			lista[i].codigo = 1;
			break;			
		}else{
			cout<<"\n\tDigite nome da cidade: ";
			cin>>lista[i].nome;
			cout<<"\n\tDigite UF da cidade: ";
			cin>>lista[i].UF;
			ctrl++;			
		}
		
			
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
		cout<<"\n\tDigite limite de participantes: ";
		cin>>lista[i].limiteParticipantes;
		cout<<"\n\tDigite valor do ingresso";
		cin>>lista[i].precoUnitario;
		
		
		/*chaves estrangeiras*/
		cout<<"\n\tDigite codigo da Cidade: ";
		cin>>lista[i].codigo_cidade;
		
		cout<<"\n\tDigite codigo do Apresentador: ";
		cin>>lista[i].codigo_apresentador;
		
		
		/*funcao de validacao*/
		
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
			cout<<"\n\tCodigo: "<<lista[i].codigo<<" | Descricao: "<<lista[i].descricao<<" | Qtde Participantes: "<<lista[i].qtdeParticipantes<<
			" | Limite participantes: "<<lista[i].limiteParticipantes<<" | Preco ingresso: "<<lista[i].precoUnitario<<
			" | Codigo Cidade: "<<lista[i].codigo_cidade<<" | Codigo Apresentador: "<<lista[i].codigo_apresentador;
			
		}
	}
	getch();
	
}


void lerParticipantes(struct Participante lista[],int n, int &contador){
	system("cls");
	cout<<"\t------------CADASTRANDO DE PARTICIPANTES------------";
	
	for(int i =0; i < n; i++){
		cout<<"\n\t\tParticipante ["<<i+1<<"]\n";
		cout<<"\n\tDigite codigo do participante: ";
		cin>>lista[i].codigo;
		cout<<"\n\tDigite nome do participante: ";
		cin>>lista[i].nome;
		cout<<"\n\tDigite codigo do evento que deseja participar: ";
		cin>>lista[i].codigo_evento;		
		/*funcao de validacao*/
		contador++;
	}	
}

void mostrarParticipantes(struct Participante lista[], int tam){
	system("cls");
	if(tam ==0){
		cout<<"\n\t\tLista de participantes vazia.";		
	}else{
		for(int i = 0; i < tam;i++){
			cout<<"\n\tCodigo: "<<lista[i].codigo<<" | Nome: "<<lista[i].nome<<" | Codigo do Evento: "<<lista[i].codigo_evento;			
		}
		
	}
	getch();
}
/*inclusao indexada*/
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

void addEvento(Evento sequencial[],int &contador,/*chaves estrangeiras*/Cidade lista[],int tam,Apresentador listaApre[], int tamApre){
	system("cls");
	
	Evento temporario[1]; int contT = 0;
	Evento atualizado[100]; int contA = 0;
	
	int i = 0, j = 0, k = 0;  //sequencial, temporario, atualizado
	
		cout<<"Tamanho da lista sequencial passada por parametro: "<<contador;
		
		cout<<"\n\t\tDigite codigo do evento: ";
		cin>>temporario[j].codigo;
		cout<<"\n\t\tDigite a descricao do evento: ";
		cin>>temporario[j].descricao;
		cout<<"\n\t\tDigite limite de participantes: ";
		cin>>temporario[j].limiteParticipantes;
		cout<<"\n\t\tDigite valor do ingresso: ";
		cin>>temporario[j].precoUnitario;
		
		/*------------------------------------VALIDAÇÃO DO CODIGO DA CIDADE*/
		
		int codCidadeValidar;
		int localizouCidade;		
		do{
			cout<<"\n\t\tDigite codigo da cidade: ";
			cin>>codCidadeValidar;
			localizouCidade = buscarCidade(lista,tam,codCidadeValidar);			
		}while(localizouCidade != 1);		
		temporario[j].codigo_cidade = codCidadeValidar;
		
		/*------------------------------------VALIDAÇÃO DO CODIGO DO APRESENTADOR*/
		
		int codApresentadorValidar;
		int localizouApresentador;
		do{
			cout<<"\n\t\tDigite codigo do apresentador: ";
			cin>>codApresentadorValidar;
			localizouApresentador = buscarApresentador(listaApre,tamApre,codApresentadorValidar);			
		}while(localizouApresentador !=1);
		temporario[j].codigo_apresentador = codApresentadorValidar;
		
		
		
		contT = 1;
		
		
	for(;i < contador && j < contT;k++){
		if(sequencial[i].codigo < temporario[j].codigo){
			
			atualizado[k].codigo = sequencial[i].codigo;
			strcpy(atualizado[k].descricao,sequencial[i].descricao);
			atualizado[k].limiteParticipantes = sequencial[i].limiteParticipantes;
			atualizado[k].precoUnitario = sequencial[i].precoUnitario;
			atualizado[k].codigo_cidade = sequencial[i].codigo_cidade;
			atualizado[k].codigo_apresentador = sequencial[i].codigo_apresentador;				
			cout<<"\n\tItem transferido de sequencial para atualizado: "<<sequencial[i].codigo;
			i++;			
		}else{
			atualizado[k].codigo = temporario[j].codigo;
			strcpy(atualizado[k].descricao, temporario[j].descricao);
			atualizado[k].limiteParticipantes = temporario[j].limiteParticipantes;
			atualizado[k].precoUnitario = temporario[j].precoUnitario;
			atualizado[k].codigo_cidade = temporario[j].codigo_cidade;
			atualizado[k].codigo_apresentador = temporario[j].codigo_apresentador;						
			j++;			
			cout<<"\n\tItem transferido de temporario para atualizado"<<temporario[j].codigo;
		}		
	}	
	
	while(i < contador){
		atualizado[k].codigo = sequencial[i].codigo;
		strcpy(atualizado[k].descricao,sequencial[i].descricao);
		atualizado[k].limiteParticipantes = sequencial[i].limiteParticipantes;
		atualizado[k].precoUnitario = sequencial[i].precoUnitario;
		atualizado[k].codigo_cidade = sequencial[i].codigo_cidade;
		atualizado[k].codigo_apresentador = sequencial[i].codigo_apresentador;		
		i++;
		k++;				
	}
	
	while(j < contT){
		atualizado[k].codigo = temporario[j].codigo;
		strcpy(atualizado[k].descricao, temporario[j].descricao);
		atualizado[k].limiteParticipantes = temporario[j].limiteParticipantes;
		atualizado[k].precoUnitario = temporario[j].precoUnitario;
		atualizado[k].codigo_cidade = temporario[j].codigo_cidade;
		atualizado[k].codigo_apresentador = temporario[j].codigo_apresentador;		
		j++;
		k++;		
	}
	
	contador = k;
	
	
	cout<<"\n\n\tLista atualizada, gerada dentro da funcao";
	for(int x = 0; x < k;x++){
		cout<<"\n\t\t\tCodigo: "<<atualizado[x].codigo<<" | Descricao: "<<atualizado[x].descricao;			
		}
		
	cout<<"\n\n\t\tTransferindo de atualizado para sequencial....";
		
		
	/*TEMPORARIO >> PRINCIPAL*/	
	for(int x = 0; x < contador;x++){
		sequencial[x].codigo = atualizado[x].codigo;
		strcpy(sequencial[x].descricao, atualizado[x].descricao);
		sequencial[x].limiteParticipantes = atualizado[x].limiteParticipantes;
		sequencial[x].precoUnitario = atualizado[x].precoUnitario;
		sequencial[x].codigo_cidade = atualizado[x].codigo_cidade;
		sequencial[x].codigo_apresentador = atualizado[x].codigo_apresentador;
						
	}
	cout<<"\n\n\tValores transferidos para vetor principal!!!";
	cout<<"\n\n\n\t\tPressione algo....";
getch();
}
/*menu secundario*/
void menu2(struct Apresentador lista[],int &x, struct Evento eventos[], int &y,struct Cidade cidades[],int s){
	int func;
	while(func!=1){
    system("cls"); //LIMPA A TELA
	cout<<"\t\t\t\t============ MENU SECUNDARIO ========\n\n";
    cout<<"\t\t\t\t|\t1 - Incluir novo Apresentador\n\n";
    cout<<"\t\t\t\t|\t2 - Incluir novo Evento\n\n";
    cout<<"\t\t\t\t--------------------------------------\n\n";
    cout<<"\t\t\t\t|\t3 - Se inscrever em um evento\n\n";
    cout<<"\t\t\t\t|\t4 - Consultar dados de Evento\n\n";
    cout<<"\t\t\t\t--------------------------------------\n\n";
    cout<<"\t\t\t\t|\t5 - Mostrar todos eventos\n\n";
    cout<<"\t\t\t\t--------------------------------------\n\n";
    cout<<"\t\t\t\t|\t6 - (Teste) \n\n";
    cout<<"\t\t\t\t|\t7 - \n\n";
    cout<<"\t\t\t\t|\t8 - <-- Voltar para Menu Principal\n\n";
    
    cout<<"\t\t\t\tEscolha a opcao: ";
	
	char op=toupper(getch());//pega a batida do teclado do usuario	
	
	
	
		switch (op) {
		  case '1' : {  addApresentador(lista,x); break; }
		  case '2' : {  addEvento(eventos,y,cidades,s,lista,x); break; }
		  //case '3' : {  ; break;}
		  //case '4' : {  ; break; }
		  //case '5' : {  ; break; }
		  //case '6' : {  buscarCidade(cidades,s); break; }
		  //case '7' : {  ; break; } // mostra todos itens ja cadastrados
		  case '8' : { func=1;menu();  break;	 }
		  
		  default : { cout<<"\n\nOpcao invalida2. Tecle algo para continuar...";
		              getch(); }
		
		
		}
   	}   	
}
/*main*/
int main(){
	system("color 8F");
	
	/*declaracao dos vetores*/
	Cidade listaCidades[100]; int lengCidade = 0;//tabela + contador
    Apresentador listaApresentadores[100]; int lengApre = 0;//tabela + contador
    Participante listaParticipantes[100]; int lengPart = 0;//tabela + contador
    Evento listaEventos[100]; int lengEvent = 0;//tabela + contador
    
	
	char opcao='N';
	char conf;	
    while (opcao != 'S'){
		opcao = menu();  // recebe o retorno da função menu()
		switch (opcao) {
		  case '0' : { lerCidades(listaCidades,3,lengCidade);break;}		
		  case '1' : { lerApresentadores(listaApresentadores,3,lengApre); break; }
		  case '2' : { lerEventos(listaEventos,3,lengEvent); break; }
		  case '3' : { lerParticipantes(listaParticipantes,3,lengPart); break;}
		  case '4' : { mostrarCidades(listaCidades, lengCidade); break; }
		  case '5' : { mostrarApresentadores(listaApresentadores,lengApre); break; }
		  case '6' : { mostrarEventos(listaEventos,lengEvent); break; }
		  case '7' : { mostrarParticipantes(listaParticipantes,lengPart); break; }
		  case '8' : { menu2(listaApresentadores,lengApre,listaEventos,lengEvent,listaCidades,lengCidade);break; }
		  case '9' : { sair(opcao,conf);  break;	 }
		  
		  
		  default : { cout<<"\n\nOpcao invalida. Tecle algo para continuar...";
		              getch(); }
		}
   }    
    
}
