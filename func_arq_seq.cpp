#include <conio.h>
#include <iostream>

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
	cout<<"\t\tOpcoes:\n\n";
    cout<<"\t\t\t1 - Cadastrar cidades\n\n";
    cout<<"\t\t\t2 - Mostrar cidades\n\n";
    cout<<"\t\t\t3 - \n\n";
    cout<<"\t\t\t4 - \n\n";
    cout<<"\t\t\t5 - \n\n";
    cout<<"\t\t\t6 - \n\n";
    cout<<"\t\t\t7 - \n\n";
    cout<<"\t\t\t8 - Sair do programa\n\n";
    
    cout<<"\t\tEscolha a opcao: ";
	op=toupper(getch());//pega a batida do teclado do usuario
	
	return op;	
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
	for(int i = 0; i < n; i++){
		cout<<"\n\t\tCidade ["<<i+1<<"]\n";
		cout<<"\n\tDigite codigo da cidade: ";
		cin>>lista[i].codigo;
		cout<<"\n\tDigite nome da cidade: ";
		cin>>lista[i].nome;
		cout<<"\n\tDigite UF da cidade: ";
		cin>>lista[i].UF;
		ctrl++;		
	}	
	
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


int main(){
	/*declaracao dos vetores*/
	Cidade listaCidades[100]; int lengCidade = 0;
    Apresentador listaApresentadores[100];
    Participante listaParticipantes[100];
    Evento listaEventos[100];
	
	
	
    while (opcao != 'S'){
		opcao = menu();  // recebe o retorno da função menu()
		switch (opcao) {
		  case '1' : { lerCidades(listaCidades,2,lengCidade); break; }
		  case '2' : { mostrarCidades(listaCidades, lengCidade); break; }
		  //case '3' : { removerInicio(); break;}
		  //case '4' : { removerFinal(); break; }
		  //case '5' : { buscarAlterar(); break; }
		  //case '6' : { media(); break; }
		  //case '7' : { mostrar(); break; } // mostra todos itens ja cadastrados
		  case '8' : { sair();  break;	 }
		  
		  default : { cout<<"\n\nOpcao invalida. Tecle algo para continuar...";
		              getch(); }
		}
   }
    

    
    
    
    
    
    
    
}
