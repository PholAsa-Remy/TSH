#include <unistd.h>
#include <stdlib.h> 
#include <stdio.h>
#include <string.h>
#include "print.h"

#define _POSIX_C_SOURCE 200112L
#define SIZE 20000

/* Create a char * that contains the PWD */
char * getPWD (){
    char * path = (char *) malloc (sizeof(char) * SIZE);
    strcpy(path,getenv("PWD"));
    return path;
}

/* Print the values of environment variable PWD */
void pwd (){
    char * path = getPWD();
    strcat(path,"\n\0");
    print(path);
    free(path);
}

/* Tell if a file is a tar, auxiliary function */
int isTar (char * name){
    int length = strlen(name);
    if (length <= 4)
        return 0;

    //Get the extention of the name
    char * extention = & name [length-4];
    if (strcmp(extention,".tar") == 0)
        return 1;
    return 0;
}

/* Tell if the path is in a tar,
   Warning ! the path will be modified so it will be unuseable after ! */
int isInTar (char * path){
    char * decompose = strtok(path, "/");
    while (decompose != NULL){
        if (isTar(decompose) == 1)
            return 1;
        decompose = strtok (NULL,"/");
    }
    return 0;
}

/* Divide the path in two, 
 * the first is the path to the tar file, 
 * the seconde is the rest (without the / just after ".tar")*/
char ** dividePathWithTar (char * path){
    char ** res = (char ** ) malloc (sizeof(char *) * 2);
    char * separateur = strstr (path,".tar");
    if (separateur == NULL){
        print("Erreur Path without tar !!!");
        return NULL;
    }
    * (separateur + 4)  = '\0';
    res[0] = path;
    res[1] = separateur + 5;
    return res;
}

int main (){
    /*char * test = malloc (sizeof(char) * 100);
    
    //strcpy (test,"a/b.tar/c/toto");
    //strcpy (test,"a/b/c/toto");

    if (isInTar(test) == 1)
        print("This Path is in a Tar");
    else
        print("This Path is NOT in a Tar");
    */
    dividePathWithTar(strcat(getPWD(),"/aaaa/bb/c.tar/dqdsqfz"));
}

