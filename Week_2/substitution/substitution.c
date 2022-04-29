#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int chiper(string argv, string plaintext);

int main(int argc, string argv[]) //teste se o usuário entrou com  o argumento
{
    if (argc != 2)
    {
        printf("missing command-line argument\n");
        return 1;
    }

    if (strlen(argv[1]) != 26) //testa se o argumento tem 26 caracteres
    {
        printf("key must contain 26 characters\n");
        return 1;
    }

    for (int i = 0; i < strlen(argv[1]); i++) //testa se o argumento é uma chave válida
    {
        if (!isalpha(argv[1][i])) //(i) Serve para negar o IF
        {
            printf("key must contain only alphabetical characters\n");
            return 1;
        }
    }
//testa se o argumento é uma chave válida(não tem caracteres repetidos)
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        int c = 0;
        for (int j = 0; j < strlen(argv[1]); j++)
        {
            if (argv[1][i] == argv[1][j])
            {
                c++;
                if (c > 1)
                {
                    printf("key must contain only unique characters\n");
                    return 1;
                }
            }
        }
    }

    string plaintext = get_string("plaintext: ");
    chiper(argv[1], plaintext); 
    return 0;
}

int chiper(string argv, string plaintext)
{
    int n = 0;
    printf("ciphertext: ");

    for (int i = 0; i < strlen(plaintext); i++)
    {
        if (plaintext[i] >= 'A' && plaintext[i] <= 'Z') // verifica se o caracter é maiusculo
        {
            n = plaintext[i] - 'A';
            printf("%c", toupper(argv[n]));

        }
        else if (plaintext[i] >= 'a' && plaintext[i] <= 'z') // verifica se o caracter é minusculo
        {
            n = plaintext[i] - 'a';
            printf("%c", tolower(argv[n]));
        }
        else // print no resto dos caracteres
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
    return 0;
}

