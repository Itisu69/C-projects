#include <stdio.h>
#include <ctype.h>

int main()
{
    char ch, og_sentence[200], term_char[100];
    int sentence_length = 0;

    printf("Enter a sentence: ");

    for (int i = 0; i < 200 && (ch = getchar() != '\n'); i++,sentence_length++)
    {
        og_sentence[i] = ch;

        if ((ch < 'A' && ch > 'Z') || (ch < 'a' && ch > 'z'))
        {
            term_char[i] = ch;
            
        }
    }

    for (int i = 0; i < 200 && (og_sentence[i]!='\n'); i++)
    {
        printf("%c",og_sentence[i]);
    }
    
    return 0;
}