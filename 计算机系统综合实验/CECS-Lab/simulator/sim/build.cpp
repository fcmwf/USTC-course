#include <stdint.h>
#include <iostream>
#include <stdio.h>
#include <assert.h>
#include "include/debug.h"

extern uint8_t pmem[];

// load a binary file into your cpu
uint64_t load_img(char *img_file){

// Lab2 TODO: load the 'img_file' to the start of pmem, and return its size
    FILE *file = fopen(img_file,"rb");
    if(file == NULL){
        printf("Failed to open file!\n");
        exit(1);
    }
    fseek(file,0,SEEK_END);
    long file_size = ftell(file);
    rewind(file);
    fread(pmem,1,file_size,file);
    fclose(file);
    return  file_size;
}