/******************************************
 * Name: Tomer Cohen
 *Student ID: 209200658
 *Sumbit ID: cohentol
 *Excercise name: ex_6
 ******************************************/

#ifndef UNTITLED3_BINTREE_H
#define UNTITLED3_BINTREE_H
//including the libraries we can use
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//struct declare
typedef struct BinTree BinTree;
//task function declaration
void moshe_task(void* val);
void child_task(void *val);
//generic functions declaration
void generic_function(BinTree* root, void(*task)(void*));
int generic_int_function(BinTree* root, int(*task)(void*));
//printing menu declaration
void printMenu();
void printOrderMenu();
//first mission function declaration
void addChild(BinTree** root);
//second mission function declaration
int throwToNile(BinTree* root);
//third mission function declaration
void findMoshePreOrder(BinTree *pointer);
void findMosheInOrder(BinTree *pointer);
void findMoshePostOrder(BinTree *pointer);
//fourth mission function declaration
void printChildrenInOrder(BinTree* root);
void printChildrenPreOrder(BinTree* root);
void printChildrenPostOrder(BinTree* root);
//fifth mission function declaration
void printNumberOfAllJews(BinTree* root);
void countMales(BinTree* root);
void countFemales(BinTree* root);
//sixth mission declaration
void freeisrael(BinTree* root);
//add twenty years function declaration
int twentyYearsLater(BinTree *root);



#endif //UNTITLED3_BINTREE_H
