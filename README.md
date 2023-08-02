# Hangman in C

My first "serious" program

Made in: 04/12/2020

## HANGMAN

Replicate the hangman game.

Create an infinite loop where, initially, you ask for an input from the stdin to the user.

The user can enter three numbers ---> 1 (start game) 2 (enter word) 3 (end game)

If the user inputs 2, they should be able to enter a word to guess.

This means you have to be able to dynamically save all the words entered by the user (they can enter words until there's available memory, after which you should notify that there's no more memory). If they press 1, start the game. At that point, your code should randomly choose a word among those entered by the user previously (I recommend associating a number with each word) and then display the hidden word on the stdout, like this:

If the randomly generated word is "ballad" you should print - + - - + -

Then, you should ask the user to enter a letter (remember, only one letter, otherwise, it becomes a mess). If they enter a correct letter, you should update the hidden string as follows:


If they enter 'b' print b + - - + -

The user has a maximum of 4 hp, if they enter a letter that is not present, print "The letter is not present" and deduct an hp. If the user guesses the word or runs out of lives, end the game and return to the menu. The program should not terminate until the user inputs 3.
