#include <iostream>
#include <iomanip>
#include <locale>

using namespace std;

//Tabuleiro
void tabuleiro(char t1, char t2, char t3, char t4, char t5, char t6, char t7, char t8, char t9){
	cout << " "<< t1 << " | " << t2 << " | " << t3 << endl;
	cout << "---|---|---" << endl;
	cout << " "<< t4 << " | " << t5 << " | " << t6 << endl;
	cout << "---|---|---" << endl;
	cout << " "<< t7 << " | " << t8 << " | " << t9 << endl;
}

//Verificar Vitória
char verificar_vitoria(char t1, char t2, char t3, char t4, char t5, char t6, char t7, char t8, char t9){


// Linhas 
if (t1 != ' ' && t1 == t2 && t1 == t3) return t1;
if (t4 != ' ' && t4 == t5 && t4 == t6) return t4;
if (t7 != ' ' && t7 == t8 && t7 == t9) return t7;
// Colunas
if (t1 != ' ' && t1 == t4 && t1 == t7) return t1;
if (t2 != ' ' && t2 == t5 && t2 == t8) return t2;
if (t3 != ' ' && t3 == t6 && t3 == t9) return t3;
//Diagonais
if (t1 != ' ' && t1 == t5 && t1 == t9) return t1;
if (t3 != ' ' && t3 == t5 && t3 == t7) return t3;
return ' ';
}

int main(){
	char t1 = ' ', t2 = ' ', t3 = ' ', t4 = ' ', t5 = ' ', t6 = ' ', t7 = ' ', t8 = ' ', t9 = ' ';
	char jogador_atual = 'X';
	
	setlocale(LC_ALL, "Portuguese");
	
	while(true){
		tabuleiro(t1, t2, t3, t4, t5, t6, t7, t8, t9);
		
		int posicao;
		cout << " Jogador " << jogador_atual << ", escolha uma posição de 1 a 9: ";
		cin >> posicao;
		
		char& posicao_ref = (posicao == 1) ? t1 : (posicao == 2) ? t2 : (posicao == 3) ? t3:
							(posicao == 4) ? t4 : (posicao == 4) ? t4 : (posicao == 5) ? t5:
							(posicao == 6) ? t6 : (posicao == 7) ? t7 : (posicao == 8) ? t8 : t9;
		
		if(posicao_ref != ' '){
			cout << "Essa posição já esta ocupada. Escolha outra"<< endl;
			continue;
		}
		//Prencher posição com o jogador atual
		posicao_ref = jogador_atual;
		char resultado = verificar_vitoria(t1, t2, t3, t4, t5, t6, t7, t8, t9);
		
		//Verificar vencedor
		if (resultado == 'X' || resultado == 'O'){
		tabuleiro(t1, t2, t3, t4, t5, t6, t7, t8, t9);
		cout << "Parabéns! Jogador " << resultado << " venceu!" << endl;
		break;
		
		} else if(resultado == 'E'){
			char resultado = verificar_vitoria(t1, t2, t3, t4, t5, t6, t7, t8, t9);
			cout << "O jogo empatou!" << endl;
			break;
		}
	
	 jogador_atual = (jogador_atual =='X' ? 'O': 'X');	
	}
	return 0;
	
}
