#include <stdio.h> 
#include <stdlib.h>
  
int main() 
{ 
    FILE *fiptr1, *fiptr2; 
    char filename[100], c; 
  
    printf("filename to open for reading \n"); 
    scanf("%s", filename); 
  
    // Open one file for reading 
    fiptr1 = fopen("file1.txt", "r"); 
    if (fiptr1 == NULL) 
    { 
        printf("Can't open file %s \n", filename); 
        exit(0); 
    } 
  
    printf("filename to open for writing \n"); 
    scanf("%s", filename); 
  
    // Open another file for writing 
    fiptr2 = fopen("file2.txt", "w"); 
    if (fiptr2 == NULL) 
    { 
        printf("Can't open file %s \n", filename); 
        exit(0); 
    } 
  
    // Read contents from file 
    c = fgetc(fiptr1); 
    while (c != EOF) 
    { 
        fputc(c, fiptr2); 
        c = fgetc(fiptr1); 
    } 
  
    printf("\nContents copied to %s", filename); 
  
    fclose(fiptr1); 
    fclose(fiptr2); 
    return 0; 
}
