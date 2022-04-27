#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

string get_text(void);
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);


int main(void)
{
    string text = get_text();//get text from user
    int letters = count_letters(text);//count letters
    int words = count_words(text);//count words
    int sentences = count_sentences(text);//count sentences

    float L = (float) letters / (float) words * 100;
    float S = (float) sentences / (float) words * 100;
    float index = 0.0588 * L - 0.296 * S - 15.8;
    index = round(index);//round to nearest integer

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        //print do resultado, (int) converte o resultado para inteiro.
        printf("Grade %i\n", (int) index);
    }
}
//função que retorna o texto digitado pelo usuário
string get_text(void)
{
    string text = get_string("Text: ");
    printf("%s\n", text);
    return text;
}
//função que conta as letras do texto
int count_letters(string text)
{
    int letters = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] >= 'a' && text[i] <= 'z')
        {
            letters++;
        }
        else if (text[i] >= 'A' && text[i] <= 'Z')
        {
            letters++;
        }
    }
    return letters;
}
//função que conta as palavras do texto
int count_words(string text)
{
    int words = 1;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == ' ')
        {
            words++;
        }
    }
    return words;
}
//função que conta as sentenças do texto
int count_sentences(string text)
{
    int sentences = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }
    return sentences;
}

