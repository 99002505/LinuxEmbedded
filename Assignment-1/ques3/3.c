#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE * file;
    char path[100];
    char ch;
    int char_numb, word_numb, line_numb;
    
    file = fopen("file1.txt", "r");
    if (file == NULL)
    {
        printf("\nUnable to open file.\n");
        printf("Please check if file exists and you have read privilege.\n");

        exit(EXIT_FAILURE);
    }

    char_numb = word_numb = line_numb = 0;
    while ((ch = fgetc(file)) != EOF)
    {
        char_numb++;

        /* Check new line */
        if (ch == '\n' || ch == '\0')
            line_numb++;

        /* Check word_num */
        if (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\0')
            word_numb++;
    }
    if (char_numb > 0)
    {
        word_numb++;
        line_numb++;
    }
    printf("\n");
    printf("Total char_numb = %d\n", char_numb);
    printf("Total word_numb     = %d\n", word_numb);
    printf("Total line_numb     = %d\n", line_numb);

    fclose(file);

    return 0;
}
