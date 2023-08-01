/*
7) “IMPICCATO” [MOLTO DIFFICILE]

Replicare il gioco dell’impiccato.
Fare un ciclo infinito dove, inizialmente, si chiede un input dallo stdin all’utente.
L’utente può inserire tre numeri ---> 1 (inizia partita) 2(inserisci parola) 3(concludi)
se l’utente digita 2 deve essere in grado di inserire una parola da indovinare.
Ciò vuol dire che dovete essere in grado di salvare tutte le parole inserite dall’utente dinamicamente (ne può inserire 
finchè c’è memoria disponibile dopodichè avvisate che non c’è più memoria). se preme 1 avviate il gioco. A quel punto il 
vostro codice dovrà scegliere randomicamente una parola tra quelle inserite dall’utente in precedenza (vi consiglio di 
associare ad ogni parola un numero) e , successivamente, mostrare sullo stdout la parola nascosta, ovvero:

se la parola generata randomicamente è  “palla” dovete stampare  - + - - +
a quel punto dovete chiedere all’utente di inserire una lettera  (mi raccomando solo una , altrimenti è un casino). se 
inserisce una lettera giusta dovete aggiornare la stringa nascosta
ovvero: Nel caso inserisca la p  stampate p + - - +
L’utente ha al massimo 4 vite, se inserisce una lettera non presente stampate “La lettera non è presente” e togliere una 
vita. Se l’utente indovina la parola o finisce le vite concludere la partita e tornare al menu. Finchè l’utente non digita 
3 il programma non deve terminare.

*/

///*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdint.h>

void draw(x) {

	printf("Hai perso una vita!\n");

	printf("\n");

	if (x <= 3) {
		printf("-------\n");
		printf("      |\n");
	}
	if (x <= 2) {
		printf("      O\n");

	}
	if (x <= 1) {
		printf("     -|-\n");
	}
	if (x <= 0) {
		printf("     / \\\n");
	}

	printf("\n\n");

}

void draw2() {

	printf("\n\n");

	printf("\t  _-|    |-_ \n");
	printf("\t |  |    |  |\n");
	printf("\t  --|    |-- \n");
	printf("\t     ----    \n");
	printf("\t      ||    \n");
	printf("\t      ||    \n");
	printf("\t     ----   \n");

	printf("\n\n");

}

void onetwothree(int *x) {
	int flag;
	do {
		flag = scanf("%d", x);
		if (flag == 0) {
			printf("Error 404\n");
			*x = 3;
			break;
		}
	} while (*x != 1 && *x != 2 && *x != 3);
	printf("So... You have choesen %d\n", *x);
}

void crypt(const char *word, char *word2) {

	int len = strlen(word);
	for (int i = 0; i <= len; i++) {
		if (word[i] == 97 || word[i] == 101 || word[i] == 105 || word[i] == 111 || word[i] == 117) {
			word2[i] = 43;
		}
		else if (word[i] == 0) {
			word2[i] = 0;
		}
		else {
			word2[i] = 45;
		}
	}
}

int main(void) {

	int x = 0;
	int flag;
	char word[30] = { NULL };
	char word2[30];
	char wordcmp[30];
	char *var = 0;
	int lives;
menu:
	lives = 4;
	printf("1 -> Inizia partita \n2 -> Inserisci parola \n3 -> Concludi\n");
	onetwothree(&x);

	
	while (x == 2) {

		printf("Inserire parola (Deve contenere massimo 30 caratteri):\n");
		

		flag = fscanf(stdin, "%s", &word);

		printf("La parola scelta e': %s\n", word);

		printf("1 -> Inizia partita \t 2 -> Inserisci parola \t 3 -> Concludi\n");


		onetwothree(&x);

	}
	
	if (x == 1) {

		int len = strlen(word);

		if (word == NULL || len == 0) {
			printf("Devi scegliere una parola prima di iniziare.\n");
			goto menu;
		}
		
			crypt(&word, &word2);
		


		while (1) {
			printf("Parola:\t%s\n", word2);

			printf("Inserire una lettera (Mi raccomando solo una, altrimenti e' un casino)\n");

			flag = scanf("%s", &var);

			strcpy(wordcmp, word2);
			for (int i = 0; i < len; i++) {
				//wordcmp[i] = word2[i];
				if (word[i] == var) {
					word2[i] = word[i];
				}
			}

			if (strcmp(wordcmp, word) == 0) {
				printf("You won!\n");
				draw2();
				break;
			}

			if (strcmp(wordcmp, word2) == 0) {
				lives--;
				draw(lives);
			}

			if (lives == 0) {
				printf("You lost!\n");
				break;
			}
		}
	}

	if (x != 3) {
		x = 0;
		goto menu;
	}
		
	return 0;
}
//*/