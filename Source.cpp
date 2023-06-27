#include <iostream>
#define n 100
using namespace std;

struct registro
{
	int chave=0;
	float preco=0;
	bool teste = true;
};


struct no
{
	registro reg;
	no* proximo=NULL;
};


class fila
{
	private:
		no* nofinal;
		no* noinicio;
	public:
		fila();
		void inserir_produto(registro reg);
		registro inserir_produtoaux();
		void mostrar_produtos();
		int obter_tamanho();
		void buscar_produto();
		void remover_produto();
	friend class acesso;
};


class pilha
{
	private:
		no* notopo;
	public:
		pilha();
		void inserir_produto(registro reg);
		registro inserir_produtoaux();
		void mostrar_produtos();
		int obter_tamanho();
		void buscar_produto();
		void remover_produto();
	friend class acesso;
};


class acesso
{
	public:
		registro verifica_chave(pilha pilhatemp, fila filatemp, registro reg);
		void troca_produto_estrutura(pilha *pilhatemp, fila *filatemp, int dif);
};


float testadigitos();


int main()
{
	fila fila1;
	pilha pilha1;
	acesso acesso1;
	int menu1 = 1, menu2 = 1, menu3 = 1, menu4 = 1;
	do
	{
		cout << "Programa de filas e Pilhas sequenciais\n\n";
		cout << "Digite:\n";
		cout << "0 para sair.\n";
		cout << "1 Para gerenciar a Pilha.\n";
		cout << "2 Para gerenciar a Fila\n";
		menu1 = testadigitos();
		switch (menu1)
		{
		case 0:system("cls"); cout << "Fim do programa\n"; break;
		case 1:system("cls"); 
			while (menu2 != 0)
		{
			cout << "Gerenciado a pilha\n\n";
			cout << "digite: \n";
			cout << " 0 para voltar para o menu anterior \n";
			cout << " 1 para inserir um produto \n";
			cout << " 2 para remover um produto \n";
			cout << " 3 para ver todos os produtos \n";
			cout << " 4 para ver o tamanho da estrutura\n";
			cout << " 5 para buscar por um produto \n";
			menu2=testadigitos();
			switch (menu2)
			{
			case 0:system("cls"); break;
			case 1:system("cls"); pilha1.inserir_produto(pilha1.inserir_produtoaux()); break;
			case 2: system("cls");
				while (menu3 != 0)
				{
					cout << "Gerenciado a pilha\n\n";
					cout << "0 Para voltar para o menu anterior\n";
					cout << "1 Para remover permanentemente\n";
					cout << "2 Para realoacar o produto\n";
			
					menu3=testadigitos();
					switch (menu3)
					{
						case 0:system("cls"); break;
						case 1:system("cls"); pilha1.remover_produto(); break;
						case 2:system("cls"); while (menu4 != 0)
						{
							cout << "Gerenciando a fila\n\n";
							cout << "0 para voltar para o menu anterior.\n";
							cout << "1 para colocar o elemento removido no final da fila.\n";;
							menu4 = testadigitos();
							switch (menu4)
							{
								case 0:system("cls"); break;
								case 1:system("cls"); acesso1.troca_produto_estrutura(&pilha1, &fila1, 1);
								default:system("cls"); cout << "Entrada inserida inválida, insira uma entrada válida:\n"; break;
							}
						} menu4 = 1; break;
						default:system("cls"); cout << "Entrada inserida inválida, insira uma entrada válida:\n"; break;
					}
				} menu3 = 1; break;
			case 3:system("cls"); pilha1.mostrar_produtos(); break;
			case 4:system("cls"); menu2 = pilha1.obter_tamanho(); if (menu2 != 0) { cout << "O tamanho da fila é :" << menu2<<"\n\n"; } menu2 = 1; break;
			case 5:system("cls"); pilha1.buscar_produto(); break;
			default:system("cls"); cout << "Entrada inserida inválida, insira uma entrada válida:\n"; break;
			}
		}menu2 = 1; break;
		case 2:system("cls");
			while (menu2 != 0)
			{
				cout << "Gerenciando a fila\n\n";
				cout << "digite: \n";
				cout << " 0 para voltar para o menu anterior \n";
				cout << " 1 para inserir um produto \n";
				cout << " 2 para remover um produto \n";
				cout << " 3 para ver todos os produtos \n";
				cout << " 4 para ver o tamanho da estrutura\n";
				cout << " 5 para buscar por um produto \n";
				menu2 = testadigitos();
				switch (menu2)
				{
				case 0:system("cls"); break;
				case 1:system("cls"); fila1.inserir_produto(acesso1.verifica_chave(pilha1, fila1,fila1.inserir_produtoaux())); break;
				case 2:system("cls");
					while (menu3 != 0)
					{
						cout << "Gerenciando a fila\n\n";
						cout << "0 Para voltar para o menu anterior\n";
						cout << "1 Para remover permanentemente\n";
						cout << "2 Para realoacar o produto\n";
						menu3 = testadigitos();
						switch (menu3)
						{
						case 0:system("cls"); break;
						case 1:system("cls"); fila1.remover_produto(); break;
						case 2:system("cls");
							while (menu4 != 0)
							{
								cout << "Gerenciando a fila\n\n";
								cout << "0 para voltar para o menu anterior\n";
								cout << "1 para remover o produto do inicio da fila e colocar no topo da pilha\n";
								cout << "2 para remover o produto do inicio da fila e colocar no final da fila\n";
								menu4 = testadigitos();
								switch (menu4)
								{
								case 0:system("cls"); break;
								case 1:system("cls");acesso1.troca_produto_estrutura(&pilha1,&fila1,2); break;
								case 2:system("cls");acesso1.troca_produto_estrutura(&pilha1,&fila1,3); break;
								default:system("cls"); cout << "Entrada inserida inválida, insira uma entrada válida:\n"; break;
								}
							} menu4 = 1; break;
						default:system("cls"); system("cls"); cout << "Entrada inserida inválida, insira uma entrada válida:\n"; break;
						}
					} menu3 = 1; break;
				case 3:system("cls"); fila1.mostrar_produtos(); break;
				case 4:system("cls"); menu2 = fila1.obter_tamanho(); if (menu2 != 0) { cout << "O tamanho da fila é :" << menu2<<"\n\n"; } menu2 = 1; break;
				case 5:system("cls"); fila1.buscar_produto();break;
				default:system("cls"); cout << "Entrada inserida inválida, insira uma entrada válida:\n"; break;
				}
			}; menu2 = 1; break;
		default:system("cls"); cout << "Entrada inserida inválida, insira uma entrada válida:\n"; break;
		}
	}while (menu1 != 0);
	
	acesso1.verifica_chave(pilha1, fila1, { 1,1 });

	return 0;
};



pilha::pilha()
{
	notopo = NULL;
};

void pilha::inserir_produto(registro reg)
{
	if (reg.teste == false) { return; }
	no* nonovo = new no; nonovo->reg = reg; nonovo->proximo = NULL; no* noprox = notopo;
	if (notopo == NULL) { notopo = nonovo; cout << "Produto Inserido com sucesso!\n\n";}
	else { nonovo->proximo = notopo; notopo=nonovo; cout << "Produto Inserido com sucesso!\n\n";}
};

registro pilha::inserir_produtoaux()
{
	registro reg{ 0,0 };
	cout << "Insira a chave do produto a ser inserido:";
	cin >> reg.chave;
	cout << "Insira o preco do produto a ser inserido:";
	cin >> reg.preco;
	return reg;
};

void pilha::mostrar_produtos()
{
	if (notopo == NULL) { cout << "A pilha não possui produtos.\n\n"; return; }
	no* noprox = notopo; int i =  obter_tamanho();
	cout << "Os produtos na pilha são :\n";
	while (noprox != NULL)
	{
		
		cout <<i<<" produto, chave: " << noprox->reg.chave <<", preco: R$" << noprox->reg.preco<< endl;
		noprox = noprox->proximo;
		i--;
	}
};

int pilha::obter_tamanho()
{
	if (notopo == NULL) { cout << "A pilha não possui produtos.\n\n"; }
	no* noprox = notopo; int i = 0;
	while (noprox != NULL)
	{
		i++;
		noprox = noprox->proximo;
	}
	return i;
};

void pilha::buscar_produto()
{
	if (notopo == NULL) { cout << "A pilha não possui produtos.\n\n"; return; }
	no* noprox = notopo; registro reg = { 0,0 };
	cout << "Insira a chave do produto a ser procurado:";
	cin >> reg.chave;
	while (noprox!=NULL)
	{
		if (reg.chave == noprox->reg.chave) { break; }
		noprox = noprox->proximo;
	}
	if (noprox == NULL) { cout << "O produto com chave inserida não foi encontrado\n\n"; return; }
	cout << "Produto com chave inserida encontrado:\nchave: " << noprox->reg.chave << "\npreco: R$ " << noprox->reg.preco << endl;
};

void pilha::remover_produto()
{
	if (notopo == NULL) { cout << "A pilha não possui produtos.\n\n"; return; }
	no* notemp = notopo;
	notopo = notopo->proximo;
	delete notemp;
	cout << "Última Produto da pilha removido com sucesso!\n\n";
};

fila::fila()
{
	noinicio = NULL;
	nofinal = NULL;
};

void fila::inserir_produto(registro reg)
{
	if (reg.teste == false) { return; }
	no* nonovo = new no; nonovo->reg = reg; nonovo->proximo = NULL; no* noprox = NULL ; no* notemp = NULL;
	if (nofinal == NULL and noinicio == NULL) { nofinal = nonovo, noinicio = nonovo; cout << "Produto Inserido com sucesso!\n\n"; return; }
	if (nofinal == noinicio) { nofinal = nonovo; nofinal->proximo = noinicio; cout << "Produto Inserido com sucesso!\n\n";}
	else { nonovo->proximo = nofinal; nofinal = nonovo;cout << "Produto Inserido com sucesso!\n\n";}
};
registro fila::inserir_produtoaux()
{
	registro reg{ 0,0 };
	cout << "Insira a chave do produto a ser inserido:";
	cin >> reg.chave;
	cout << "Insira o preco do produto a ser inserido:";
	cin >> reg.preco;
	return reg;
};
void fila::mostrar_produtos()
{
	if (nofinal == NULL) { cout << "A fila não possui produtos.\n\n"; return; }
	no* noprox = nofinal; int i = obter_tamanho();
	while (noprox != NULL)
	{
		cout << i << " produto, chave: " << noprox->reg.chave << ", preco: R$" << noprox->reg.preco << endl;
		noprox = noprox->proximo;
	}
};

int fila::obter_tamanho()
{
	if (nofinal == NULL) { cout << "A pilha não possui produtos.\n\n"; }
	no* noprox = nofinal; int i = 0;
	while (noprox != NULL)
	{
		i++;
		noprox = noprox->proximo;
	}
	return i;
};

void fila::buscar_produto()
{
	if (nofinal == NULL) { cout << "A fila não possui produtos.\n"; return; }
	no* noprox = nofinal; registro reg = { 0,0 };
	cout << "Insira a chave do produto a ser procurado:";
	cin >> reg.chave;
	while (noprox != NULL)
	{
		if (reg.chave == noprox->reg.chave) { break; }
		noprox = noprox->proximo;
	}
	if (noprox == NULL) { cout << "O produto com chave inserida não foi encontrado\n\n"; return; }
	cout << "Produto com chave inserida encontrado:\nchave: " << noprox->reg.chave << "\npreco: \n" << noprox->reg.preco << endl;
};

void fila::remover_produto()
{
	if (nofinal == NULL) { cout << "A fila não possui produtos.\n\n"; return; }
	no* notemp = noinicio; no* noprox = nofinal;
	while (noprox != NULL)
	{
		if (noprox->proximo == noinicio) { break; }
		noprox = noprox->proximo;
	}
	if (nofinal != noinicio) { noprox->proximo = NULL; }
	else { nofinal = NULL; }
	noinicio = noprox;
	delete notemp;
	cout << "1 prodult removido com sucesso!\n\n";
};

registro acesso::verifica_chave(pilha pilhatemp, fila filatemp, registro reg)
{
	no* noproxfila = filatemp.nofinal; no* noproxpilha = pilhatemp.notopo;
	while (noproxfila != NULL)
	{
		if (noproxfila->reg.chave == reg.chave) { cout << "Produto de mesma chave inserida encontrado, produto não inserido\n\n"; reg.teste = false; return reg; }
		noproxfila = noproxfila->proximo;
	}
	while (noproxpilha != NULL)
	{
		if (noproxpilha->reg.chave == reg.chave) { cout << "Produto de mesma chave inserida encontrado, produto não inserido\n\n"; reg.teste = false; return reg; }
		noproxpilha = noproxpilha->proximo;
	}
	return reg;
};

void acesso::troca_produto_estrutura(pilha *pilhatempo, fila *filatempo, int dif)
{
	switch (dif)
	{
	case 1: filatempo->inserir_produto(pilhatempo->notopo->reg); pilhatempo->remover_produto(); break; //"para colocar o produto removido do topo da pilha no final da fila"
	case 2: pilhatempo->inserir_produto(filatempo->noinicio->reg); filatempo->remover_produto(); break; //"para colocar o produto removido do inicio da fila no topo da pilha"
	case 3: filatempo->inserir_produto(filatempo->noinicio->reg); filatempo->remover_produto(); break; //"para colocar o produto removido do inicio da fila no final da fila"
	case 4:break;
	}
};

float testadigitos()
{
	char string[n];
	cin >> string;
	int i = 0;
	int tamanho = 0;
	while (string[tamanho] != '\0')
	{
		tamanho++;
	}
	while (i != tamanho)
	{
		if (!((string[i] >= 48 and string[i] <= 57) || string[i] == 46)) { return -1; }
		i++;
	}
	return atof(string);
};