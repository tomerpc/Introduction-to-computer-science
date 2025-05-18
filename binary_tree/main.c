/******************************************
 * Name: Tomer Cohen
 *Student ID: 209200658
 *Sumbit ID: cohentol
 *Excercise name: ex_6
 ******************************************/

//include the BinTree header file
#include "BinTree.h"

int main()
{
    //declare the main variables
    int pick,pick1;
    int flag=0;
    int on=1;
    int preOrder=1;
    int inOrder=2;
    int postOrder=3;
    int nothingHappen=0;
    int afterTwentyYears=nothingHappen;
    int allJews=1;
    int males=2;
    int females=3;
    int mosheIsEightyYearsOld=1;
    int treeIsEmpty=2;
    int throwingNile=nothingHappen;
    //pointer to the root
    BinTree* root=NULL;
    //pointer to the pointer to the root(used to add child)
    BinTree** pointToRoot=&root;
    //print the menu
    //while loop for the menu
    while (flag !=on)
    {
        printMenu();
        //scan the pick for the menu
        scanf("%d", &pick);
        switch (pick)
        {
            //case 1-new child
            case 1:
                //call the add child function
                addChild(pointToRoot);

                /*add twenty years to the tree and return int
                 * to indicate what happen*/

                afterTwentyYears= generic_int_function
                        (root, (int (*)(void *)) twentyYearsLater);
                //break of case 1
                break;
            //case 2- throw males to the nile
            case 2:

                /*throw to nile by the generic function
                 * and return int to indicate what happen*/

                throwingNile=generic_int_function(root, (int (*)(void *))throwToNile);

                //if  for case that tree is empty after throwing to nile
                if(throwingNile==treeIsEmpty)
                {
                    //make the root NULL
                    root=NULL;
                    //make throwing to throw to nile nothing for next times.
                    throwingNile=nothingHappen;
                }

                /*add twenty years to the tree and return int
                 * to indicate what happen*/

                afterTwentyYears= generic_int_function
                        (root, (int (*)(void *)) twentyYearsLater);
                //break of case 2
                break;
            case 3:
                //print the order menu
                printOrderMenu();
                //scan the pick
                scanf("%d", &pick1);
                //case 1-preorder
                if (pick1==preOrder)
                {
                    //call the finding moshe pre-order by the generic function
                    generic_int_function(root, (int (*)(void *)) findMoshePreOrder);
                    /*add twenty years to the tree and return int
                    * to indicate what happen*/

                    afterTwentyYears= generic_int_function
                            (root, (int (*)(void *)) twentyYearsLater);
                }
                //case 2- in order
                else if (pick1==inOrder)
                {
                    //call the finding moshe in order by the generic function
                    generic_function(root, (void *)findMosheInOrder);

                    /*add twenty years to the tree and return int
                    * to indicate what happen*/

                    afterTwentyYears= generic_int_function
                            (root, (int (*)(void *)) twentyYearsLater);
                }
                //case 3- post order
                else if (pick1 ==postOrder)
                {
                    //call the finding moshe post order by the generic function
                    generic_function(root,(void(*)(void *))findMoshePostOrder);

                    /*add twenty years to the tree and return int
                   *to indicate what happen*/

                    afterTwentyYears= generic_int_function
                            (root, (int (*)(void *)) twentyYearsLater);
                }
                //last case-wrong pick
                else
                {
                    //print wrong message
                    printf("wrong order!\n");

                    /*add twenty years to the tree and return int
                    * to indicate what happen(happen even if wrong pick)*/

                    afterTwentyYears= generic_int_function
                            (root, (int (*)(void *)) twentyYearsLater);
                }
                //break of case 3
                break;
            case 4:
                printOrderMenu();
                scanf("%d", &pick1);
                //case 1=pre-order
                if (pick1==preOrder)
                {
                    //call the print function by the generic function
                    generic_function
                    (root, (void (*)(void *)) printChildrenPreOrder);

                    /*add twenty years to the tree and return int
                     * to indicate what happen*/

                    afterTwentyYears= generic_int_function
                            (root, (int (*)(void *)) twentyYearsLater);
                }
                //case 2- in order
                else if (pick1==inOrder)
                {
                    //call the print function by the generic function
                    generic_function
                    (root, (void (*)(void *)) printChildrenInOrder);

                    /*add twenty years to the tree and return int
                     * to indicate what happen*/

                    afterTwentyYears= generic_int_function
                            (root, (int (*)(void *)) twentyYearsLater);
                }
                //case 3- post-order
                else if (pick1 ==postOrder )
                {
                    //call the print function by the generic function
                    generic_function
                    (root, (void (*)(void *)) printChildrenPostOrder);

                    /*add twenty years to the tree and return int
                     * to indicate what happen*/

                    afterTwentyYears= generic_int_function
                            (root, (int (*)(void *)) twentyYearsLater);
                }
                //last case-wrong pick
                else
                {
                    //print the wrong message
                    printf("wrong order!\n");

                    /*add twenty years to the tree and return int
                     * to indicate what happen*/

                    afterTwentyYears= generic_int_function
                            (root, (int (*)(void *)) twentyYearsLater);
                }
                //break of case 4
                break;
            case 5:
                //prints the menu(to pick what to count)
                printf("please choose what you want to calculate:\n"
                       "(1) All jews\n"
                       "(2) Male\n"
                       "(3) Female\n");
                scanf("%d", &pick1);
                //first pick-all jews count
                if (pick1==allJews)
                {
                    //call the count function by the generic function
                    generic_function
                    (root, (void (*)(void *)) printNumberOfAllJews);

                    /*add twenty years to the tree and return int
                     * to indicate what happen*/

                    afterTwentyYears= generic_int_function
                            (root, (int (*)(void *)) twentyYearsLater);
                }
                //first pick-males count
                else if (pick1==males)
                {
                    //call the count function by the generic function
                    generic_function(root, (void (*)(void *)) countMales);

                    /*add twenty years to the tree and return int
                     * to indicate what happen*/

                    afterTwentyYears= generic_int_function
                            (root, (int (*)(void *)) twentyYearsLater);
                }
                //first pick-females count
                else if (pick1 == females)
                {
                    //call the count function by the generic function
                    generic_function(root, (void (*)(void *)) countFemales);

                    /*add twenty years to the tree and return int
                     * to indicate what happen*/

                    afterTwentyYears= generic_int_function
                            (root, (int (*)(void *)) twentyYearsLater);
                }
                //break of case 5
                break;
            //case 6-Exit the program
            case 6:
                //call the free israel program to free the memory
                generic_function(root, (void (*)(void *)) freeisrael);
                //turn on the flag to stop the while loop
                flag=on;
                //break of case 3
                break;
            //default case-wrong pick(not between 1-6)
            default:
                //print the wrong message
                printf("wrong choose please choose again\n");

                /*add twenty years to the tree and return int
                * to indicate what happen*/

                afterTwentyYears= generic_int_function
                        (root, (int (*)(void *)) twentyYearsLater);
                //break of default case
                break;
        }
        //end of switch case

        //if loop for printing '\n' only if moshe is not eighty(as requested).
        if(afterTwentyYears != mosheIsEightyYearsOld&& flag!=on)
        {
            printf("\n");
        }
        //if  for case that tree is empty after growing by 20 years
        if(afterTwentyYears == treeIsEmpty)
        {
            //make the variable nothing for next times.
            afterTwentyYears=nothingHappen;
            //make the root NULL
            root=NULL;
        }
        //if case when moshe is eighty years old(need to close the program).
        if (afterTwentyYears == mosheIsEightyYearsOld)
        {
            //call the "freeisrael" program by the generic function
            generic_function(root, (void (*)(void *)) freeisrael);
            //make the flag 'on' to end the while loop and close the program.
            flag=on;
        }
    }
    //end of while loop
}
