#include <stdio.h>
#include <string.h>
#include <stdlib.h> //srand() and rand()
#include <ctype.h>  //to use toupper
#include <time.h>   //time(NULL)

const char *words[] = {"WANA", "SKARDU", "KHARIAN", "BHAWALPUR", "GUJRAT"};

const int numsOfwords = sizeof(words) / sizeof(words[0]);

const char *PickRandomWord()
{
    srand(time(NULL));
    int randomIndex = rand() % numsOfwords;
    return words[randomIndex];
}

void DrawHangman(int mistakes)
{

    printf("\n");

    switch (mistakes)
    {

    case 0:
        printf("  +---+\n");
        printf("  |   |\n");
        printf("      |\n");
        printf("      |\n");
        printf("      |\n");
        printf("      |\n");
        printf("=========\n");
        break;
    case 1:
        printf("  +---+\n");
        printf("  |   |\n");
        printf("  O   |\n");
        printf("      |\n");
        printf("      |\n");
        printf("      |\n");
        printf("=========\n");
        break;
    case 2:
        printf("  +---+\n");
        printf("  |   |\n");
        printf("  O   |\n");
        printf("  |   |\n");
        printf("      |\n");
        printf("      |\n");
        printf("=========\n");
        break;
    case 3:
        printf("  +---+\n");
        printf("  |   |\n");
        printf("  O   |\n");
        printf(" /|   |\n");
        printf("      |\n");
        printf("      |\n");
        printf("=========\n");
        break;
    case 4:
        printf("  +---+\n");
        printf("  |   |\n");
        printf("  O   |\n");
        printf(" /|\\  |\n");
        printf("      |\n");
        printf("      |\n");
        printf("=========\n");
        break;
    case 5:
        printf("  +---+\n");
        printf("  |   |\n");
        printf("  O   |\n");
        printf(" /|\\  |\n");
        printf(" /    |\n");
        printf("      |\n");
        printf("=========\n");
        break;
    case 6:
        printf("  +---+\n");
        printf("  |   |\n");
        printf("  O   |\n");
        printf(" /|\\  |\n");
        printf(" / \\  |\n");
        printf("      |\n");
        printf("=========\n");
        break;
    default:
        printf("Invalid number of mistakes.\n");
        break;
    }
}

int main()
{
    const char *word = PickRandomWord();
    int wordlength = strlen(word);
    char str[wordlength + 1];
    char guess;
    int mistakes = 0;
    int correct = 0;
    int spaceleft = wordlength;
    int chances = 6;

    memset(str, '_', wordlength);
    str[wordlength] = '\0';

    printf("WELCOME TO THE HANGMAN GAME !\n");
    printf("YOU HAVE %d CHANCES : \n", chances);
    DrawHangman(mistakes);

    while (mistakes < chances && spaceleft > 0)
    {
        printf("Current Word:%s\n", str);

        printf("Enter the character : ");
        scanf(" %c", &guess);

        guess = toupper(guess);

        correct = 0;

        for (int i = 0; word[i] != '\0'; i++)
        {
            if (word[i] == guess && str[i] == '_')
            {
                str[i] = guess;
                correct = 1;
                spaceleft--;
            }
        }
        if (!correct)
        {
            mistakes++;
            system("cls");
            printf("WRONG ANSWER ! YOU HAVE %d CHANCES LEFT.\n", chances - mistakes);
            DrawHangman(mistakes);
        }
        if (spaceleft == 0)
        {
            printf("CONGRATULATIONS ! YOU HAVE GUESSED THE WORD : %s", word);
            break;
        }
        if (mistakes == chances)
        {
            printf("OOPS ! GAME OVER.\n");
            printf("THE CORRECT WORD IS : %s", word);
        }
    }
    return 0;
}
