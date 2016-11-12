//
// Created by alexey on 20.10.16.
//

#include "stdio.h"
#include "stddef.h"
#include <dlfcn.h>
#include <stdlib.h>
#include "string.h"
#include "stdbool.h"


int (*someFunction)(int val);


bool initLib( char const *libName , const char *funcName ) {


    void *hdl = dlopen(libName, RTLD_LAZY);
    if (NULL == hdl)
        return false;
    someFunction = (int (*)(int))dlsym(hdl, funcName);
    if (NULL == someFunction)
        return false;
    return true;

}

int main(int argc, char *argv[]) {

    char libName[100];		// библиотека, которую мы ищем
    strcpy(libName, "./");		// в проверяющей системе не прописана текущая директория - надо добавитьв путь к библиотеке
    strcat(libName, argv[1]);


    char *funcName = argv[2];


    if (initLib(libName, funcName)) {
        int arg = atoi(argv[3]);
        printf("%d\n",someFunction(arg))  ;
    } else {
        printf("errr");
    }

    return 0;
}