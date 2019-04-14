#include <iostream>
#include <conio.h>
#include <Windows.h>
using namespace std;

//configura��es 
#define MAP_W 20
#define MAP_H 20
#define TAM_SNACK 100

bool gameOver;							// variavel booleana para sinalizar o fim de jogo

const int width = MAP_W;				// largura do campo
const int height = MAP_H;				// altura do campo
int x, y, fruitX, fruitY, score;		// coordenadas da cobra, coordenadas da fruta, pontua��o
int tailX[TAM_SNACK], tailY[TAM_SNACK];	// coordenada do rabo da cobra;
int nTail;								// numero do rabo da cobra

/*	
				<-- Variavel importante. -->
	serve para enumerar as coordenadas mais tarde chamadas em um switch
*/
enum eDirection{ STOP = 0, LEFT, RIGHT, UP, DOWN };

eDirection dir; //instancia, na variavel dir;

//fun��o que dar inicio ao jogo.
void Setup() {
	gameOver = false;			//O jogo come�a
	dir = STOP;					//status de parado.
	x = rand() % width;			//inicio das coordenadas de x
	y = rand() % height;		//inicio das coordendas de y
	fruitX = rand() % width;	//coordenada da fruta aleatoria
	fruitY = rand() % height;	//coordenada da fruta aleatoria
	score = 0;					//pontua��o zerada
}

//fun��o que desenha todos os elementos visuais do jogo
void Draw() {
	system("cls");//limpa tela.
	//Cria o mapa
	for (int i = 0; i < width+2; i++) {
		cout << "\xDF";//parte superior do quadrado
	}
	cout << "\n";
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (j == 0) {
				cout << "\xDB";//lateral esquerda do mapa
			}
			if (i == y && j == x) {
				//defini��o de onde esta a cobra.
				//quando i � igual as coordenadas de y e x
				cout << "\xFE";
			}
			else if(i == fruitY && j == fruitX)
			{
				//quando i e j s�o iguais as coordenadas da fruta, o programa exibe a fruta
				cout << "\xF8";
			}
			else {
				/*
				quando i e j deixa de ser igual as coordenadas da fruta � porque as coordenadas
				de x e y s�o iguais as coordenadas de fruta, e a fruta foi redefinda pelo rand().
				*/
				bool print = false;//verifica nas coordenadas tem uma parte da cobra
				for (int k = 0; k < nTail; k++) {
					/*
					quando o nTail for maior que 0, � quando uma fruta foi comida.
					as coordenadas da coobra s�o definidas como abaixo.
					
					OBS: isso apenas desenha o corpo da cobra nas coordenadas da fruta.
					*/
					if (tailX[k] == j && tailY[k] == i) {
						cout << "\xFE";//desenha o rabo
						print = true;
					}
				}
				// se nao tiver uma parte da cobra coloque espa�o vazi
				if (!print) {
					cout << " ";
				}
			}
			if (j == (width - 1)) {
				cout << "\xDB"; //lateral direitado mapa
			}
		}
		cout << endl;
	}
	for (int i = 0; i < width+2; i++) {
		cout << "\xDF"; //parte inferior do mapa
	}
	cout << endl;
	cout << "score" << score;//exibe a pontua��o
}

//fun��o que recebe as entradas do jogador
void Input() {
	//fun��o que define todo funcionamento
	//a fun��o _kbhit() faz com que sempre que uma tecla for precionado tudo dentro do if
	//seja feito. o _getch() � uma fun��o que algarda um valor para prosseguir
	if (_kbhit()) {
		switch (_getch()) {
		case 'a':
			dir = LEFT;
			break;

		case 'd':
			dir = RIGHT;
			break;

		case 'w':
			dir = UP;
			break;

		case 's':
			dir = DOWN;
			break;

		case 'x':
			gameOver = true;
			break;
		}
	}
}

//fun��o que calcula a logica do jogo
void Logic() {
	int prevX = tailX[0];
	int prevY = tailY[0];
	int prev2X, prev2Y;
	tailX[0] = x;
	tailY[0] = y;

	//bubble sort, organiza os elementos que constitui o corpo da cobra
	for (int i = 1; i < nTail; i++) {
		
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;

	}
	//permite o decremento ou incremento de x ou y para que a posi��o da cobra possa variar
	switch (dir)
	{
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	default:
		break;
	}

	//se a coordenada da cobra utrapassa o limite do campo � gameover
	if (x > width || x < 0 || y > height || y < 0) {
		gameOver = true;
	}
	//se a cobra bater em si mesma � gameover
	for (int i = 0; i < nTail; i++) {
		if (tailX[i] == x && tailY[i] == y) {
			gameOver = true;
		}
	}
	/*
	quando as coordenadas da cobra forem iguais as da fruta, entao a fruta recebe um valor aleatorio
	e a cobra aumenta de tamanho
	*/
	if (x == fruitX && y == fruitY) {
		score += 10;				//incremento da pontua��o.
		fruitX = rand() % width;	//nova coordenada aleatoria para a fruta.
		fruitY = rand() % height;	//nova coordenada aleatoria para a fruta.
		nTail++;					//o tamanho da cobra aumenta.
	}
}

int main() {
	Setup();		//come�a o jogo
	while (!gameOver) {
		Sleep(100);	//espera um tempo para reduzir a velocidade do jogo
		Draw();		//exibe o mapa e todos os elementos graficos
		Input();	//recebe os valores WASD
		Logic();	//calcula a parte logica do jogo
	}
	return 0;
}