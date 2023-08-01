/*
"HANGMAN" [VERY DIFFICULT]

Replicate the hangman game.
Create an infinite loop where, initially, you ask for an input from the stdin to the user.
The user can enter three numbers ---> 1 (start game) 2 (enter word) 3 (end game)
If the user inputs 2, they should be able to enter a word to guess.
This means you have to be able to dynamically save all the words entered by the user (they can enter words until there's available memory, after which you should notify that there's no more memory). If they press 1, start the game. At that point, your code should randomly choose a word among those entered by the user previously (I recommend associating a number with each word) and then display the hidden word on the stdout, like this:

If the randomly generated word is "ball," you should print - + - - +
Then, you should ask the user to enter a letter (remember, only one letter, otherwise, it becomes a mess). If they enter a correct letter, you should update the hidden string as follows:

If they enter 'b,' print b + - - +
The user has a maximum of 4 lives, if they enter a letter that is not present, print "The letter is not present" and deduct a life. If the user guesses the word or runs out of lives, end the game and return to the menu. The program should not terminate until the user inputs 3.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdint.h>

void draw(x) {

	printf("You lost an hp!\n");

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
	printf("So... You have chosen %d\n", *x);
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
	printf("1 -> Start game \n2 -> Insert word \n3 -> Close\n");
	onetwothree(&x);

	while (x == 2) {
		printf("Insert word (Max 30 characters):\n");

		flag = fscanf(stdin, "%s", &word);

		printf("The chosen word is: %s\n", word);
		printf("1 -> Start game \t 2 -> Insert word \t 3 -> Close\n");

		onetwothree(&x);
	}
	
	if (x == 1) {
		int len = strlen(word);

		if (word == NULL || len == 0) {
			printf("Choose a word to start.\n");
			goto menu;
		}
		
			crypt(&word, &word2);

		while (1) {
			printf("Word:\t%s\n", word2);

			printf("Insert a letter (Just one or it will mess everything up)\n");

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
