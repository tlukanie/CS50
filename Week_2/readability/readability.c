#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
int get_grade(int letters, int words, int sentences);

int main(void)
{
    string text = get_string("Text: ");
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);
    int grade = get_grade(letters, words, sentences);
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", grade);
    }
    return (0);
}

int count_letters(string text)
{
    int i = 0;
    int letters = 0;
    while (text[i])
    {
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        {
            letters++;
        }
        i++;
    }
    return (letters);
}

int count_words(string text)
{
    int i = 0;
    int words = 1;
    while (text[i])
    {
        if (text[i + 1] == ' ')
        {
            words++;
        }
        i++;
    }
    return (words);
}

int count_sentences(string text)
{
    int i = 0;
    int sentences = 0;
    while (text[i])
    {
        if (text[i] == '!' || text[i] == '.' || text[i] == '?')
        {
            sentences++;
        }
        i++;
    }
    return (sentences);
}


int get_grade(int letters, int words, int sentences)
{
    float grade = 0;
    float l = 0;
    l = (float)letters / (float)words * 100;
    float s = (float)sentences / (float)words * 100;
    grade = round(0.0588 * l - 0.296 * s - 15.8);
    return (grade);
}
