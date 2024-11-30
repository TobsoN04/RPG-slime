#include <Windows.h>
#include <functional>
#include <iostream>
#include <cstring>
#include <locale.h>
#include <wchar.h>
#include <time.h>
#include <stdlib.h>
using namespace std;

class slime{
	
	public:
		int vida;
		string nome;
		int ataque;
		int mortes = 0;
		int vidamax;
		int recompensa = vidamax*2;
		slime(){
		}
};

class srosa: public slime{
	
	public:
		string nome = "Slime Rosa";
		int vidamax=3;
		int vida = vidamax;
		int recompensa = vidamax*2;
		srosa(){
		}
};

class sverde: public slime{
	
	public:
		string nome = "Slime Verde";
		int vidamax=4;
		int vida = vidamax;
		int recompensa = vidamax*2;
		sverde(){
		}
};

class sazul: public slime{
	
	public:
		string nome = "Slime Azul";
		int vidamax=5;
		int vida = vidamax;
		int recompensa = vidamax*2;
		sazul(){
		}
};

int turno=1;
int dinheiro=1;
int vidapj = 10;
slime inimigo;
srosa slime_rosa;
sverde slime_verde;
sazul slime_azul;
bool fuga = false;
bool vivo = true;
bool battle_end = false;
int mortet = 1;

int randint(int start, int end){
	int recompensa;
	recompensa = rand()% (end - (start))+(start);
	return recompensa;
}
void sleep(int seconds){
	Sleep(seconds * 1000);
}

void dlinha(int a = 100){
	string dotobas=string(a, '=');
	cout << dotobas << "\n";
}

void titulo(string Msg){
	int a = Msg.length();
	dlinha(a*2);
	cout << Msg << "\n";
	dlinha(a*2);
}

int main(){
	srand(time(NULL));
	setlocale(LC_ALL,"");
	slime slimeRos;
	slimeRos.vida = 15;
	slimeRos.nome = "slime rosa";

	while (1){
		cout << "\n";		
		
		titulo("Seja bem vindo ao RPG das slimes v.1.1!");
		cout << "[1] Tutorial" << "\n";
		cout << "[2] Iniciar aventura" << "\n";
		dlinha(78);
		int escolha;
		
		while (1){
			cout << "Digite 1 para ver o tutorial e 2 para iniciar a aventura" << "\n";
			cin >> escolha;
			
			if (escolha == 1||escolha == 2){
				break;
			}			
		}

		if(escolha == 1){
			const char *proposito="Você controlará um aventureiro cujo objetivo é matar slimes para conseguir dinheiro. Seu objetivo atual é "
"juntar 50 moedas, assim você não precisará se preocupar tão cedo com dinheiro. A aventura pode ser dividida"
"em 2 situações diferentes: as telas de batalha e as telas de descanso. Nas telas de batalha você receberá "
"informações sobre a slime que você estará enfrentando, assim como as opções de atacar ou fugir. A fuga pode"
"falhar, e o ataque tem chance de errar. Todo ataque acertado diminuirá em 1 a vida da slime, mas preste "
"atenção, toda vez que um turno se passar a slime também te atacará. Toda vez que uma batalha acabar você "
"receberá uma recompensa e entrará na tela de descanso. Nas telas de descanso você recuperará uma quantidade "
"aleatória de vida, mas gastará 1 moeda. Você terá também a opção de acessar o menu, no menu você poderá "
"fazer 3 coisas: acessar o Bestiário, ver seus status (vida e dinheiro) ou sair do menu. Caso acesse o "
"Bestiário, receberá informações de quantas slimes de cada tipo você matou, assim como dados sobre as slimes "
"(caso já tenho matado alguma). Lembre-se: fugir irá te retornar à tela de descanso!"
"Aproveite o jogo!";
			cout << proposito;
		}
		else if(escolha == 2){
			break;
		}
	};

	string nome;
	cout << "Escolha um nome para seu personagem" << "\n";
	cin >> nome;

	if(nome == "Danton"){
		cout << "Boa escolha!" << "\n";
	}
	else if(nome == "Raul"){
		cout << "Bem vindo ao jogo, governo, espero que aproveite" << "\n";
	}
	else if(nome == "André"){

	cout << "Espero que o jogo satisfaça a Igreja" << "\n";
	}
	else if(nome == "Arthur")
		cout << "Colega neófito, você recebeu o jogo? Espero que goste" << "\n";
	else if(nome == "Tobias")
		cout << "Espero que o jogo agrade o grande Blob" << "\n";
	else if(nome == "Stalin")
		cout << "Saudações, stalin, espero que aproveite o jogo.\nEu poderia ter escrito alguns blogs para a Arcádia ao invés de fazer isso..." << "\n";
	else if(nome == "Renan")
		cout << "Prossiga, símio"<< "\n";
	else if(nome == "Dias")
		cout << "Já leu Douluo Dalu?"<< "\n";
	else if(nome == "Isadora"){
		while (1){
			cout << "Favor, sair"<< "\n";
			string tobias1;
			cin >> tobias1;				
		}
	}
	else{
		cout << "Bem vindo ao jogo, " << nome <<"\n";
	}
	
	sleep(1);
	cout << nome << " caminha calmamente pelas planícies procurando por uma slime" << "\n";
	sleep(1);
	cout << "." << "\n";
	sleep(1);
	cout << "." << "\n";
	sleep(1);
	cout << "." << "\n";
	sleep(1);
	cout << "Você encontrou uma slime rosa é sua primeira slime, então você não terá a opçãoo de fugir";
	cout << "\n";
	sleep(2);

	srosa sleim;
		
	while (1){
		titulo("Tela de Batalha");
		cout << "Turno " << turno << "\n";
		cout << sleim.nome << ", " << sleim.vida << " de vida" << "\n";
		cout << nome << ", " << vidapj << " de vida" << "\n";
		dlinha(30);
		cout << ' ';
			
		while (1){
			int acao;
			cout << "Aperte 1 para atacar" << "\n"; cin >> acao;
			if (acao == 1)
				break;
			else
				cout << "ERRO! Insira um número válido" << "\n";
			sleep(1);
			
		}
			
		int sorteio;
		sorteio = randint(0,2);
		
		if (sorteio !=0){
			cout << nome << " acertou a slime" << "\n";
			sleim.vida -=1;
		}
		else{
			cout << "A slime desviou" << "\n";
		}

		if (sleim.vida == 0){
			cout << nome << " derrotou sua primeira slime" << "\n";
			break;
		}

		sleep(1);
		cout << '\n';
		cout << "Turno da slime" << "\n";
		sleep(1);
		sorteio =randint(0,5 - sleim.vida);
		if (sorteio == 0){
			vidapj -= 1;
			cout << "Ouch! A slime te acertou" << "\n";
		}
		else{
			cout << nome <<" desviou da slime!" << "\n";
		}
		sleep(1);
		cout << '\n';
		turno ++;
	}
	
	int recompensa;
	recompensa = rand()% (sleim.recompensa - (sleim.recompensa -3))	+ (sleim.recompensa - 3);
	dinheiro += recompensa;
	cout << nome << " ganhou " << recompensa << " moedas!" << "\n";
		
	while (1){

		// Hora de baianar
		while (1){
			titulo("Tela de descanso");
			int sorteio = randint(1, 4);
			if (sorteio == 1){
				cout << nome << " descansa no gramado após a batalha" << "\n";
			}
			else if (sorteio == 2){
				cout << nome << " volta para casa para descansar" << "\n";
			}
			else if (sorteio == 3){
				cout << nome << " aplica ervas medicinais em si " << "\n" << "+ 1 de vida!" << "\n";
			}
			else if (sorteio == 4){
				cout << nome << " tropeçou num pedalo de ouro enquanto voltava para casa!" << "\n";
				dinheiro += 4;
			}
			
			sorteio = randint(2, 3);
			vidapj += sorteio;
			cout << "Após descansar " << nome << " recuperou " << sorteio << " de vida!" << "\n";
			sleep(2);
			
			if (vidapj > 10)
				vidapj = 10;
			
			while (1){
				cout << "\n";
				cout << "[1] Abrir menu || [2] Batalhar" << "\n";
				int acao;
				cout << "Aperte 1 para abrir o menu e 2 para voltar para batalha " << "\n";
				cin >> acao;

				if (acao == 1){
					sleep(1);

					while (1){
						titulo("Menu");
						cout << "[1] Status || [2] Bestiário || [3] Sair do Menu" << "\n";
						
						int acao2;
						cin >> acao2;
						cout << "Aperte 1 para ver os status, 2 para abrir o Bestiário ou 3 para sair " << "\n";
						if (acao2 == 1){
							cout << "Status" << "\n" << "Vida máxima: 10" << "\n" << "Vida: " << vidapj << "\n" << "Dinheiro: " << dinheiro << " moedas" << "\n" << "Pronto para voltar ao menu? " << "\n";
						}
						else if(acao2 == 2){
							cout << "\n";
							titulo("Bestiário");
							if (mortet >= 1){
								cout << "Slimes são seres gelatinosos e territoriais que habitam nosso mundo. Caso você enfureçaa uma slime\ntome cuidado, especialmente se for uma slime azul!" << endl;
							}
							else
								cout << "??????????????" << endl;
							if (mortet >= 3){
								cout << "Segundo nossos especialistas, quanto mais vida a slime tem mais forte ela é, então slimes que estiverem\ncom vida alta são especialmente perigosas!" << endl;
							}
							else
								cout << "??????????????" << endl;
							int acao3;
							cout << "Pronto para voltar ao menu?" << "\n";
							cin >> acao3;
						}
						else if(acao2 == 3){
							break;
						}						
					}					
				}

				else if (acao == 2){
					sleep(1);
					break;
				}

				else{
					cout << "ERRO! Insira um número válido" << "\n";
					sleep(1);
				}			
			}
			
			break;	
		}

		// Escolha do inimigo
		int sorteio = randint(0, 3);
		if (sorteio == 0){
			inimigo.vida = slime_rosa.vida;
			inimigo.nome = slime_rosa.nome;
			inimigo.recompensa = slime_rosa.recompensa;
		}
		else if(sorteio == 1){
			inimigo.vida = slime_verde.vida;
			inimigo.nome = slime_verde.nome;
			inimigo.recompensa = slime_verde.recompensa;
		}
		else{
			inimigo.vida = slime_azul.vida;
			inimigo.nome = slime_azul.nome;
			inimigo.recompensa = slime_azul.recompensa;
		}

		// Mensagem random de caminhada
		sorteio = randint(0, 2);
		if (sorteio == 0)
			cout << nome << " caminha calmamente pelas planícies procurando uma slime" << "\n";
		else if(sorteio == 1)
			cout << nome << " caça vorazmente por mais uma slime" << "\n";	
		else
			cout << nome << " sobe uma colina em busca de slimes" << "\n";
		

		// A Wild Slime appears
		sleep(1);
		cout << "." << "\n";
		sleep(1);
		cout << "." << "\n";
		sleep(1);
		cout << "." << "\n";
		sleep(1);
		cout << nome << " encontrou uma " << inimigo.nome << "! Se prepare para a batalha!" << "\n";
		sleep(2);
		cout << "\n";

		// While de batalha
		while (1){

			titulo("Tela de Batalha");
			cout << "Turno " << turno << "\n";
			cout << inimigo.nome << " " << inimigo.vida << " de vida" << "\n";
			cout << nome << " " << vidapj << " de vida" << "\n";
			dlinha(30);
			cout << "[1] Atacar || [2] Fugir" << "\n";
			dlinha(30);
			cout << "\n";

			// Battle Action
			int battle_action;
			while (1){				
				cout << "Aperte 1 para atacar ou 2 para fugir" << "\n";
				cin >> battle_action;	

				// Choosen Action	
				if (battle_action == 1) { // Tatakae
					sorteio = randint(0, 1);
					if (sorteio == 0){
						inimigo.vida -= 1;
						cout << nome << " acertou a slime!" << "\n";					
						
					}
					else {
						cout << "A slime desviou" << "\n";
					}
					break;
				}
				else if(battle_action == 2) { // Nigero
					sorteio = randint(0, 2);
					if (sorteio !=0){
						fuga = true;
						cout << "Você tentará fugir após o turno da slime" << "\n";
						break;
					}
				}
				else {	
					cout << "ERRO! Insira um número válido" << "\n";
				}
			}


			// Checagens 
			if (inimigo.vida <= 0){
				inimigo.mortes++;
				battle_end = true;
				break;
			}	


			sleep(1); // Desnecessário

			// Turno do Slime
			sorteio = randint(0, 5 - inimigo.vida);
			if (sorteio == 0){
				vidapj -= 1;
				cout << "Ouch! A slime te acertou" << "\n";
				if (vidapj <= 0){
					vivo = false;
					sleep(1);
					break;
				}
			}
			else{
				cout << nome << " desviou da slime!" << "\n";
			}			

			sleep(1);
			cout << "\n";

			// Tentativa de fuga
			if (battle_action == 2 && fuga){
				cout << nome << " fugiu com sucesso!" << "\n";
				sleep(1);
				break;
			}
			else if (battle_action == 2 && fuga == false){
				cout << nome << " não conseguiu fugir e foi acertado no caminho!" << "\n" << "-1 de vida!" << "\n";
				vidapj -= 1;
				if (vidapj == 0){
					vivo = false;
					sleep(1);
					break;
				}
			}

			// Fim do Turno
			turno ++;
		}

		//Checagens finais
		if (!vivo) break;
				
		// Nao terminou a batalha com fuga
		if (!fuga && inimigo.vida == 0){
			int recompensa = randint(inimigo.recompensa -3, inimigo.recompensa);
			dinheiro += recompensa;
			cout << nome << " ganhou " << recompensa << " moedas!" << "\n";
			mortet ++;
			if (dinheiro >= 50) {
				break;
			}	
			sleep(1);
		}
		else if(fuga){
			cout << "Você voltará para a tela de descanso em breve." << "\n";
			fuga = false;
			sleep(2);	
		}
	}

	// GAMEOVER CASO ESTEJA MORTO
	if (!vivo){
		cout << "Você morreu, tente novamente!" << "\n";
		sleep(1);
	}
	else{
		cout << "Você conseguiu 50 de dinheiro e completou o objetivo do jogo, parabéns!" << endl;
	}

	// cout << "CHEGOU NO INFERNO" << endl;
	cout << "\n FIM DE JOGO" << "\n";

	return 0;
}
