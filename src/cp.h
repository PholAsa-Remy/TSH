#ifndef CP_H
#define CP_H
#include <dirent.h>

int fileName (char * pathName);
int cpTarInTar(char * archive, char * path, char * destination);
int cpTarInOutsideTar(char * archive, char * path, char * destination);
int cpOutsideTarInTar(char * archive, char * path, char * destination);
int cp1 (char * path, char * destination);
int cp2 (char * path, char * destination);
int cp3 (char * path, char * destination);
int cp(char ** argv);

char ** nameOfAllFileInDirectory (int fd, char * path, int archiveSize);
int cpTarInTarOptionR(char * archive, char * path, char * destination);
int cpTarInOutsideTarOptionR(char * archive, char * path, char * destination);

char ** sortInsertionBySlash (char ** tab, int size);
char ** sortTabWithDirectoryFirst(char ** tab, int sizeTab);
int numberOfFileInDirectoryOutsideTar(DIR * dirp, char * path);
void getAllFileNameFromFolderAux (DIR * dirp, char * path, int * index, char ** allEntityName);
char ** getAllFileNameFromFolder (char * path);
int cpOutsideTarInTarOptionR(char * archive, char * path, char * destination);

int cp1R (char * path, char * destination);
int cp2R (char * path, char * destination);
int cp3R (char * path, char * destination);
int cpR(char ** argv);

#endif