#include <conio.h>
#include <iostream>
#include <string.h>
//#include <ncurses.h>

using namespace std;

/*lista de structs*/
struct Cidade{
    int codigo;
    char nome[50];
    char uf[3];
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
    cout<<"\t\t______________________________________\n\n";
    cout<<"\t\t|\t4 - Exibir Cidades\n\n";
    cout<<"\t\t|\t5 - Exibir Apresentadores\n\n";
    cout<<"\t\t|\t6 - Exibir Eventos\n\n";
    cout<<"\t\t|\t7 - Exibir Participantes\n\n";
    cout<<"\t\t______________________________________\n\n";
    cout<<"\t\t|\t8 - Menu Secundario -->\n\n";
    cout<<"\t\t|\t9 - Sair do programa\n\n";
    
    cout<<"\t\tEscolha a opcao: ";
	op=toupper(getch());//pega a batida do teclado do usuario
	
	return op;	
}
/*validacao de chave estrangeira(busca binaria)*/
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
		cout<<"\n\t\tCidade: "<<lista[meio].nome<<" uf: "<<lista[meio].uf<<endl;
		return 1;
	}else{
		cout<<"\n\t\tx---- Codigo de cidade nao localizado. Insira o codigo de uma cidade valida ----x"<<endl;
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
		cout<<"\n\t\tx---- Codigo de apresentador nao localizado. Insira o codigo de um apresentador valido ----x"<<endl;
		return 0;
		
	}
	getch();
	
}

int buscarEvento(struct Evento lista[], int tam, int procurado,int &indexEvento){
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
		
		cout<<"\n\t\tEvento: "<<lista[meio].descricao;
		
		//qtdePessoas = lista[meio].qtdeParticipantes;
		//qtdLimite = lista[meio].limiteParticipantes;
		indexEvento = meio;
		
		/*
			//validando se existem vagas
		if((lista[meio].qtdeParticipantes + 1) > lista[meio].limiteParticipantes){
		cout<<"Nao ha vagas";
		return 2;
		
			}else{
				cout<<"\n\t\tReservado";
				lista[meio].qtdeParticipantes++;
				return 1;
				getch();		
			}	*/	
	}else{
		cout<<"\n\t\tx---- Codigo de evento nao localizado. Insira o codigo de um evento valido ----x"<<endl;
		return 0;		
	}	
	
}

int buscarParticipante(struct Participante lista[], int tam, int procurado, int &indexParticipante){
	
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
		cout<<"\n\t\tNome: "<<lista[meio].nome<<endl;
		indexParticipante = meio;
		
				
	}else{
		cout<<"\n\t\tx---- Codigo de participante nao localizado. Insira o codigo de um participante valido ----x"<<endl;
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
	cout<<"\n\t\t===========CADASTRANDO CIDADES===========";	
	for(int i = 0; i < n; i++){
		
		cout<<"\n\n\t-------------Cidade ["<<i+1<<"]-------------";
		cout<<"\n\tDigite codigo da cidade: ";
		cin>>lista[i].codigo;
		cin.ignore();
		
		
		if(lista[i].codigo ==0){
			lista[i].codigo = 1;
			break;			
		}else{
			cout<<"\n\tDigite nome da cidade: ";
			//cin>>lista[i].nome;
			gets(lista[i].nome);
			cout<<"\n\tDigite uf da cidade: ";
			//cin>>lista[i].uf;
			gets(lista[i].uf);
			//cin.ignore();
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
		cout<<"\n\t\t===========LISTA DE CIDADES===========";
		for(int i = 0; i < tam;i++){
			cout<<"\n\t_______________________________________";
			cout<<"\n\tCodigo: "<<lista[i].codigo<<" | Cidade: "<<lista[i].nome<<" | uf: "<<lista[i].uf;
		}
	}
	getch();
	
}

void lerApresentadores(Apresentador lista[],int n, int &ctrl){
	system("cls"); //LIMPA A TELA	
	cout<<"\n\t\t===========CADASTRANDO APRESENTADORES===========";
	for(int i = 0; i < n; i++){
		cout<<"\n\n\t-------------Apresentador ["<<i+1<<"]-------------\n";
		cout<<"\n\tDigite codigo do apresentador: ";
		cin>>lista[i].codigo;
		cin.ignore();
		
		if(lista[i].codigo ==0){
			lista[i].codigo =1;
			break;			
		}else{
			cout<<"\n\tDigite nome do apresentador: ";
			gets(lista[i].nome);
			//cin>>lista[i].nome;
			
		}
		
		
		ctrl++;		
	}	
	getch;
}

void mostrarApresentadores(Apresentador lista[],int tam){
	system("cls"); //LIMPA A TELA
	if(tam == 0){
		cout<<"\n\t\tLista de apresentadores vazia.";
	} else{
		cout<<"\n\t\t===========LISTA DE APRESENTADORES===========";
		for(int i = 0; i < tam;i++){
			cout<<"\n\t_______________________________________";
			cout<<"\n\tCodigo: "<<lista[i].codigo<<" | Nome: "<<lista[i].nome;
			
		}
	}
	getch();	
}

void lerEventos(Evento lista[],int n, int &ctrl){
	system("cls"); //LIMPA A TELA	
	cout<<"\n\t\t===========CADASTRANDO EVENTOS===========";
	for(int i = 0; i < n; i++){
		cout<<"\n\n\t-------------Evento ["<<i+1<<"]-------------\n";
		cout<<"\n\tDigite codigo do evento: ";
		cin>>lista[i].codigo;
		cin.ignore();
		
		if(lista[i].codigo ==0){
			lista[i].codigo = 1;
			break;
			
		}else{
			
		cout<<"\n\tDigite descricao do evento: ";
		//cin>>lista[i].descricao;	
		gets(lista[i].descricao);	
		cout<<"\n\tDigite limite de participantes: ";
		cin>>lista[i].limiteParticipantes;
		cin.ignore();
		cout<<"\n\tDigite valor do ingresso: ";
		cin>>lista[i].precoUnitario;
		cin.ignore();
		
		
		/*chaves estrangeiras*/
		cout<<"\n\tDigite codigo da Cidade: ";
		cin>>lista[i].codigo_cidade;
		cin.ignore();
		
		cout<<"\n\tDigite codigo do Apresentador: ";
		cin>>lista[i].codigo_apresentador;
		cin.ignore();
			
		}
		
		
		
		
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
		cout<<"\n\t\t===========LISTA DE EVENTOS===========";
		for(int i = 0; i < tam;i++){
			cout<<"\n\t_________________________________________________________________________________________________________________________________________";
			cout<<"\n\tCodigo: "<<lista[i].codigo<<" | Descricao: "<<lista[i].descricao<<" | Qtde Participantes: "<<lista[i].qtdeParticipantes<<
			" | Limite participantes: "<<lista[i].limiteParticipantes<<" | Preco ingresso: "<<lista[i].precoUnitario<<
			" | Codigo Cidade: "<<lista[i].codigo_cidade<<" | Codigo Apresentador: "<<lista[i].codigo_apresentador;
			
		}
	}
	getch();
	
}


void lerParticipantes(struct Participante lista[],int n, int &contador){
	system("cls");
	cout<<"\n\t\t===========CADASTRANDO DE PARTICIPANTES===========";
	
	for(int i =0; i < n; i++){
		cout<<"\n\n\t-------------Participante ["<<i+1<<"]-------------\n";
		cout<<"\n\tDigite codigo do participante: ";
		cin>>lista[i].codigo;
		cin.ignore();
		
		if(lista[i].codigo ==0){
			lista[i].codigo = 1;
			break;
		}else{
			cout<<"\n\tDigite nome do participante: ";
			//cin>>lista[i].nome;
			gets(lista[i].nome);
			
		}
		
		
		//cout<<"\n\tDigite codigo do evento que deseja participar: ";
		//cin>>lista[i].codigo_evento;		
		/*funcao de validacao*/
		contador++;
	}	
}

void mostrarParticipantes(struct Participante lista[], int tam){
	system("cls");
	if(tam ==0){
		cout<<"\n\t\tLista de participantes vazia.";		
	}else{
		cout<<"\n\t\t===========LISTA DE PARTICIPANTES===========";
		for(int i = 0; i < tam;i++){
			cout<<"\n\t_________________________________________________";
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
	
		cout<<"\n\t\t=============INCLUSAO DE NOVO APRESENTADOR=============";
		
		cout<<"\n\t\tDigite codigo do apresentador: ";
		cin>>temporario[j].codigo;
		cin.ignore();
		cout<<"\n\t\tDigite nome do apresentador: ";
		//cin>>temporario[j].nome;
		gets(temporario[j].nome);
		contT = 1;
		
		
	for(;i < contador && j < contT;k++){
		if(sequencial[i].codigo < temporario[j].codigo){
			atualizado[k].codigo = sequencial[i].codigo;
			strcpy(atualizado[k].nome,sequencial[i].nome);			
			//cout<<"\n\tItem transferido de sequencial para atualizado: "<<sequencial[i].codigo;
			i++;			
		}else{
			atualizado[k].codigo = temporario[j].codigo;
			strcpy(atualizado[k].nome,temporario[j].nome);			
			j++;			
			//cout<<"\n\tItem transferido de temporario para atualizado"<<temporario[j].codigo;
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
	
	
	/*cout<<"\n\n\tLista atualizada, gerada dentro da funcao";
	for(int x = 0; x < k;x++){
		cout<<"\n\t\t\tCodigo: "<<atualizado[x].codigo<<" | Nome: "<<atualizado[x].nome;			
		}
		
	cout<<"\n\n\t\tTransferindo de atualizado para sequencial....";*/
		
		
	/*ATUALIZADO >> PRINCIPAL(main)*/
	for(int x = 0; x < contador;x++){
		sequencial[x].codigo = atualizado[x].codigo;
		strcpy(sequencial[x].nome, atualizado[x].nome);			
	}
	
	//cout<<"\n\n\tValores transferidos para vetor principal!!!";
	cout<<"\n\n\n\t\tNovo apresentador incluso!";
getch();
}

void addEvento(Evento sequencial[],int &contador,/*chaves estrangeiras*/Cidade lista[],int tam,Apresentador listaApre[], int tamApre){
	system("cls");
	
	Evento temporario[1]; int contT = 0;
	Evento atualizado[100]; int contA = 0;
	
	int i = 0, j = 0, k = 0;  //sequencial, temporario, atualizado
	
		cout<<"\n\t\t=============INCLUSAO DE NOVO EVENTO=============";
		
		cout<<"\n\t\tDigite codigo do evento: ";
		cin>>temporario[j].codigo;
		cin.ignore();
		cout<<"\n\t\tDigite a descricao do evento: ";
		//cin>>temporario[j].descricao;
		gets(temporario[j].descricao);
		cout<<"\n\t\tDigite limite de participantes: ";
		cin>>temporario[j].limiteParticipantes;
		cin.ignore();
		cout<<"\n\t\tDigite valor do ingresso: ";
		cin>>temporario[j].precoUnitario;
		cin.ignore();
		
		/*------------------------------------VALIDAÇÃO DO CODIGO DA CIDADE*/
		
		int codCidadeValidar;
		int localizouCidade;		
		do{
			cout<<"\n\t\tDigite codigo da cidade: ";
			cin>>codCidadeValidar;
			cin.ignore();
			localizouCidade = buscarCidade(lista,tam,codCidadeValidar);			
		}while(localizouCidade != 1);		
		temporario[j].codigo_cidade = codCidadeValidar;
		
		/*------------------------------------VALIDAÇÃO DO CODIGO DO APRESENTADOR*/
		
		int codApresentadorValidar;
		int localizouApresentador;
		do{
			cout<<"\n\t\tDigite codigo do apresentador: ";
			cin>>codApresentadorValidar;
			cin.ignore();
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
			//cout<<"\n\tItem transferido de sequencial para atualizado: "<<sequencial[i].codigo;
			i++;			
		}else{
			atualizado[k].codigo = temporario[j].codigo;
			strcpy(atualizado[k].descricao, temporario[j].descricao);
			atualizado[k].limiteParticipantes = temporario[j].limiteParticipantes;
			atualizado[k].precoUnitario = temporario[j].precoUnitario;
			atualizado[k].codigo_cidade = temporario[j].codigo_cidade;
			atualizado[k].codigo_apresentador = temporario[j].codigo_apresentador;						
			j++;			
			//cout<<"\n\tItem transferido de temporario para atualizado"<<temporario[j].codigo;
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
	
	
	/*cout<<"\n\n\tLista atualizada, gerada dentro da funcao";
	for(int x = 0; x < k;x++){
		cout<<"\n\t\t\tCodigo: "<<atualizado[x].codigo<<" | Descricao: "<<atualizado[x].descricao;			
		}
		
	cout<<"\n\n\t\tTransferindo de atualizado para sequencial....";*/
		
		
	/*ATUALIZADO >> PRINCIPAL(main)*/
	for(int x = 0; x < contador;x++){
		sequencial[x].codigo = atualizado[x].codigo;
		strcpy(sequencial[x].descricao, atualizado[x].descricao);
		sequencial[x].limiteParticipantes = atualizado[x].limiteParticipantes;
		sequencial[x].precoUnitario = atualizado[x].precoUnitario;
		sequencial[x].codigo_cidade = atualizado[x].codigo_cidade;
		sequencial[x].codigo_apresentador = atualizado[x].codigo_apresentador;
						
	}
	//cout<<"\n\n\tValores transferidos para vetor principal!!!";
	cout<<"\n\n\n\t\tNovo evento incluso!";
getch();
}

void addCidade(Cidade sequencial[], int &contador){
	system("cls");
	
	Cidade temporario[1]; int contT = 0 ;
	Cidade atualizado[100]; int contA = 0;
	
	int i = 0, j = 0, k = 0;  //sequencial, temporario, atualizado
	
		cout<<"\n\t\t=============INCLUSAO DE NOVA CIDADE=============";
		
		cout<<"\n\t\tDigite codigo da cidade: ";
		cin>>temporario[j].codigo;
		cin.ignore();
		cout<<"\n\t\tDigite nome da cidade: ";
		//cin>>temporario[j].nome;
		gets(temporario[j].nome);
		cout<<"\n\t\tDigite uf da cidade: ";
		//cin>>temporario[j].uf;
		gets(temporario[j].uf);
		contT = 1;
		
		
	for(;i < contador && j < contT;k++){
		if(sequencial[i].codigo < temporario[j].codigo){
			atualizado[k].codigo = sequencial[i].codigo;
			strcpy(atualizado[k].nome,sequencial[i].nome);	
			strcpy(atualizado[k].uf,sequencial[i].uf);		
			//cout<<"\n\tItem transferido de sequencial para atualizado: "<<sequencial[i].codigo;
			i++;			
		}else{
			atualizado[k].codigo = temporario[j].codigo;
			strcpy(atualizado[k].nome,temporario[j].nome);	
			strcpy(atualizado[k].uf,temporario[j].uf);
					
			j++;			
			//cout<<"\n\tItem transferido de temporario para atualizado"<<temporario[j].codigo;
		}		
	}	
	
	while(i < contador){
		atualizado[k].codigo = sequencial[i].codigo;
		strcpy(atualizado[k].nome, sequencial[i].nome);	
		strcpy(atualizado[k].uf, sequencial[i].uf);		
		i++;
		k++;				
	}
	
	while(j < contT){
		atualizado[k].codigo = temporario[j].codigo;
		strcpy(atualizado[k].nome,temporario[j].nome);
		strcpy(atualizado[k].uf,temporario[j].uf);
		j++;
		k++;		
	}
	
	contador = k;
	
	
	/*cout<<"\n\n\tLista atualizada, gerada dentro da funcao";
	for(int x = 0; x < k;x++){
		cout<<"\n\t\t\tCodigo: "<<atualizado[x].codigo<<" | Nome: "<<atualizado[x].nome;			
		}
		
	cout<<"\n\n\t\tTransferindo de atualizado para sequencial....";*/
		
		
	/*ATUALIZADO >> PRINCIPAL(main)*/
	for(int x = 0; x < contador;x++){
		sequencial[x].codigo = atualizado[x].codigo;
		strcpy(sequencial[x].nome, atualizado[x].nome);	
		strcpy(sequencial[x].uf, atualizado[x].uf);			
	}
	
	//cout<<"\n\n\tValores transferidos para vetor principal!!!";
	cout<<"\n\n\n\t\tNova cidade inclusa!";
getch();
}

void addParticipante(Participante sequencial[], int &contador){
	system("cls");
	
	Cidade temporario[1]; int contT = 0 ;
	Cidade atualizado[100]; int contA = 0;
	
	int i = 0, j = 0, k = 0;  //sequencial, temporario, atualizado
	
		cout<<"\n\t\t=============INCLUSAO DE NOVO PARTICIPANTE=============";
		
		cout<<"\n\t\tDigite codigo do participante: ";
		cin>>temporario[j].codigo;
		cin.ignore();
		cout<<"\n\t\tDigite nome do participante: ";
		//cin>>temporario[j].nome;
		gets(temporario[j].nome);		
		contT = 1;
		
		
	for(;i < contador && j < contT;k++){
		if(sequencial[i].codigo < temporario[j].codigo){
			atualizado[k].codigo = sequencial[i].codigo;
			strcpy(atualizado[k].nome,sequencial[i].nome);					
			//cout<<"\n\tItem transferido de sequencial para atualizado: "<<sequencial[i].codigo;
			i++;			
		}else{
			atualizado[k].codigo = temporario[j].codigo;
			strcpy(atualizado[k].nome,temporario[j].nome);				
			j++;			
			//cout<<"\n\tItem transferido de temporario para atualizado"<<temporario[j].codigo;
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
	
	
	/*cout<<"\n\n\tLista atualizada, gerada dentro da funcao";
	for(int x = 0; x < k;x++){
		cout<<"\n\t\t\tCodigo: "<<atualizado[x].codigo<<" | Nome: "<<atualizado[x].nome;			
		}
		
	cout<<"\n\n\t\tTransferindo de atualizado para sequencial....";*/
		
		
	/*ATUALIZADO >> PRINCIPAL(main)*/
	for(int x = 0; x < contador;x++){
		sequencial[x].codigo = atualizado[x].codigo;
		strcpy(sequencial[x].nome, atualizado[x].nome);				
	}
	
	//cout<<"\n\n\tValores transferidos para vetor principal!!!";
	cout<<"\n\n\n\t\tNovo participante incluso!";
getch();
	
}

void inscricaoEvento(struct Evento listaEve[], int contEve, struct Participante listaPart[], int contPart,struct Cidade listaCidade[],int tamCid,struct Apresentador listAp[],int tamAp){
	system("cls");
	cout<<"\n\t\t===========INSCRICAO EM EVENTO===========";
	
	int codEvento;	
	int localizouEvento;	
	int indexEvento;
	
	int qtdeParts;
	int qtdeLimite;
	/*
	return 0 = Evento nao localizado
	return 1 = Evento localizado
	*/
	/*---LOCALIZA CODIGO DE EVENTO NA TABELA EVENTO---*/
	do{
		cout<<"\n\n\t\tDigite o codigo do evento que gostaria de Participar: ";
		cin>>codEvento;
		localizouEvento= buscarEvento(listaEve,contEve,codEvento,indexEvento);	
	}while(localizouEvento == 0);
	buscarCidade(listaCidade,tamCid,listaEve[indexEvento].codigo_cidade);
	buscarApresentador(listAp,tamAp,listaEve[indexEvento].codigo_apresentador);
	
	
	
	int codPart;
	int localizouParticipante;	
	int indexParticipante;
	/*
	return 0 = nao localizou localizou
	return 1 = localizou participante
	*/
	/*---LOCALIZA CODIGO DE PARTICIPANTE NA TABELA PARTICIPANTE---*/
	do{
		cout<<"\n\n\t\tDigite seu codigo de participante: ";
		cin>>codPart;
		localizouParticipante = buscarParticipante(listaPart,contPart,codPart,indexParticipante);
		}while(localizouParticipante == 0);
	

	
	if((listaEve[indexEvento].qtdeParticipantes +1) > listaEve[indexEvento].limiteParticipantes){
		cout<<"\n\t\t| Nao ha mais vagas para evento selecionado |";
		
		
	}else{
		
		if(listaPart[indexParticipante].codigo_evento == codEvento){
			cout<<"\n\t\tUsuario ja esta cadastrado nesse evento";
			
		}else{
			cout<<"\n\t\t------ Reserva efetuada com sucesso ------";
			listaEve[indexEvento].qtdeParticipantes++;
			listaPart[indexParticipante].codigo_evento = codEvento;	
			
			
		}
		
			
		
	}	
	getch();
	
/*	for(int i=0; i< contEve, i++){
		
		if(listaEve[i].codigo == codEvento){
				
		}
		
	}	*/
}

void consultarEvento(struct Evento listaEventos[],int tamEvento, struct Cidade listaCidades[], int tamCid, struct Apresentador listaApre[], int tamApre ){
	system("cls");
	
	int codEvento;
	int localizou =0;
	cout<<"\n\t\t==========CONSULTA DE EVENTO POR CODIGO==========";
	cout<<"\n\t\tDigite o codigo do evento que deseja localizar: ";
	cin>>codEvento;
	
	for(int i=0; i < tamEvento;i++){
		
		if(listaEventos[i].codigo == codEvento){
			cout<<"\n\t\t____________________________________________";
			cout<<"\n\t\tDescricao Evento: "<<listaEventos[i].descricao;
			cout<<"\n\t\tQuantidade Participantes: "<<listaEventos[i].qtdeParticipantes;
			cout<<"\n\t\tLimite Participantes: "<<listaEventos[i].limiteParticipantes;
			cout<<"\n\t\tValor convite: "<<listaEventos[i].precoUnitario;
			buscarCidade(listaCidades,tamCid,listaEventos[i].codigo_cidade);
			buscarApresentador(listaApre,tamApre,listaEventos[i].codigo_apresentador);
			cout<<"\n\t\tValor total arrecadado: "<<listaEventos[i].qtdeParticipantes*listaEventos[i].precoUnitario;
			cout<<"\n\t\t____________________________________________";
			localizou = 1;		
		}
	}
	
	if(localizou == 0){
			cout<<"\n\n\tCodigo de evento não localizado.";
		}
	getch();
}

void exibirTodosEventos(struct Evento listaEventos[], int tamEvento, struct Cidade listaCidades[], int tamCidades,struct Apresentador listaApresentadores[], int tamApresentadores){
	system("cls");
	cout<<"\n\t\t============Lista de todos eventos============";
	float somaTotal = 0;
	
	for(int i = 0; i < tamEvento; i++){
		cout<<"\n\t________________________________________"<<endl;
		cout<<"\n\tCodigo: "<<listaEventos[i].codigo; cout<<"\tEvento:"<<listaEventos[i].descricao;
		buscarCidade(listaCidades,tamCidades, listaEventos[i].codigo_cidade);
		buscarApresentador(listaApresentadores,tamApresentadores,listaEventos[i].codigo_apresentador);
		cout<<"\n\tQuantidade de Participantes: "<<listaEventos[i].qtdeParticipantes;
		cout<<"\n\tValor ingresso: "<<listaEventos[i].precoUnitario;
		cout<<"\n\tValor arrecada pelo evento: "<<listaEventos[i].qtdeParticipantes * listaEventos[i].precoUnitario;
		somaTotal = somaTotal + (listaEventos[i].qtdeParticipantes * listaEventos[i].precoUnitario);
		
	}
	
	
	cout<<"\n\t________________________________________"<<endl;
	cout<<"\n\tTOTAL ARRECADADO EM TODOS EVENTOS: "<<somaTotal;



getch();
	
}

/*menu secundario*/
void menu2(struct Apresentador lista[],int &x, struct Evento eventos[], int &y,struct Cidade cidades[],int &s,struct Participante listaParts[], int &contPart){
	int func;
	while(func!=1){
    system("cls"); //LIMPA A TELA
	cout<<"\t\t\t\t============ MENU SECUNDARIO ========\n\n";
    cout<<"\t\t\t\t|\t1 - Incluir nova Cidade\n\n";
    cout<<"\t\t\t\t|\t2 - Incluir novo Apresentador\n\n";
    cout<<"\t\t\t\t|\t3 - Incluir novo Evento\n\n";
    cout<<"\t\t\t\t|\t4 - Incluir novo Participante\n\n";
    cout<<"\t\t\t\t______________________________________\n\n";
    cout<<"\t\t\t\t|\t5 - Se inscrever em evento\n\n";
    cout<<"\t\t\t\t______________________________________\n\n";         
    cout<<"\t\t\t\t|\t6 - Consultar dados de Evento \n\n";
    cout<<"\t\t\t\t|\t7 - Exibir dados de todos Eventos\n\n";
    cout<<"\t\t\t\t______________________________________\n\n";    
    cout<<"\t\t\t\t|\t8 - <-- Voltar para Menu Principal\n\n";
    
    cout<<"\t\t\t\tEscolha a opcao: ";
	
	char op=toupper(getch());//pega a batida do teclado do usuario	
	
	
	
		switch (op) {
		  case '1' : {  addCidade(cidades,s); break; }
		  case '2' : {  addApresentador(lista,x); break; }
		  case '3' : {  addEvento(eventos,y,cidades,s,lista,x); break; }
		  case '4' : {  addParticipante(listaParts,contPart); break; }
		  
		  case '5' : {  inscricaoEvento(eventos,y,listaParts,contPart,cidades,s,lista,x); break;}
		  
		  case '6' : {  consultarEvento(eventos,y,cidades,s,lista,x); break; }
		  case '7' : {  exibirTodosEventos(eventos,y,cidades,s,lista,x); break; }  
		  
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
		  case '8' : { menu2(listaApresentadores,lengApre,listaEventos,lengEvent,listaCidades,lengCidade,listaParticipantes,lengPart);break; }
		  case '9' : { sair(opcao,conf);  break;	 }
		  
		  
		  default : { cout<<"\n\nOpcao invalida. Tecle algo para continuar...";
		              getch(); }
		}
   }    
    
}
