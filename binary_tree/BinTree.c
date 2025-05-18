/******************************************
 * Name: Tomer Cohen
 *Student ID: 209200658
 *Sumbit ID: cohentol
 *Excercise name: ex_6
 ******************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//declare the struct as asked in the exam
typedef struct BinTree {
    int id;
    char* name;
    int age;
    char gender;
    void (*task)(void* val);
    void* action;
    struct BinTree* left;
    struct BinTree* right;
} BinTree;

//declare the functions of this file
void moshe_task(void* val);
void child_task(void *val);
void addChild(BinTree** root);
void findMosheInOrder(BinTree *pointer);
void findMoshePostOrder(BinTree* pointer);
int throwToNile(BinTree* root);
BinTree* deleteMales(BinTree *root, BinTree *father);
int mosheInTree(BinTree* root, int mosheAlive);
void actionChildInOrder(BinTree* root);
void actionChildPreOrder(BinTree* root);
void actionChildPostOrder(BinTree* root);
void printChildrenInOrder(BinTree* root);
void printChildrenPreOrder(BinTree* root);
void printChildrenPostOrder(BinTree* root);
int countingChildren(BinTree *root, int counter);
int countingChildrenByGender(BinTree *root, char c, int counter);
void printNumberOfAllJews(BinTree* root);
void countMales(BinTree* root);
void countFemales(BinTree* root);
void addTwentyToAge(BinTree *root, BinTree *father);
void freeisrael(BinTree* root);
int mosheIsEighty(BinTree* root, int moshe);
int throwToNile(BinTree* root);
void add20(BinTree* root);
BinTree* deleteWhen120YearsOld(BinTree *root, BinTree *father);




//The functions that declared in the exam as requested(4)

/************************************************************************
* function name: generic_function *
* The Input: the function get BinTree pointer and a pointer to
 void function
* The output: none
* The Function operation: the function takes the BinTree input
 * and the function input and operate the function on the BinTree pointer*
*************************************************************************/

void generic_function(BinTree* root, void(*task)(void*))
{
    //operate the task on the root
    task(root);
}
//end of function

/************************************************************************
* function name: generic_int_function *
* The Input: the function get BinTree pointer and a pointer to
 int type function
* The output: the function return int value
* The Function operation: the function takes the BinTree input
 * and the function input and operate the function on the BinTree pointer*
*************************************************************************/

int generic_int_function(BinTree* root, int(*task)(void*))
{
    //operate the task on the root and return the value
    return task(root);
}
//end of function


/************************************************************************
* function name: moshe_task *
* The Input: the function get void pointer that is actually point to the
 name of the child*
* The output: the function prints the task of moshe as declared
 in the exam *
* The Function operation: the function uses the void pointer to the
 name and prints his task*
*************************************************************************/

void moshe_task(void *val)
{
    //prints the child name
    printf("%s", (char*) val);
    //prints the task message for moshe
    printf(" quiet\n" );
}
//end of function

/************************************************************************
* function name: child_task *
* The Input: the function get void pointer that is actually point to the
 name of the child*
* The output: the function prints the task of the child as declared
 in the exam *
* The Function operation: the function uses the void pointer to the
 name and prints his task*
*************************************************************************/

void child_task(void* val)
{
    //prints the child name
    printf("%s ", (char*) val);
    //print the right task message for regular child.
    printf("cry waaaa\n" );
}
//end of function

//prints menu functions(2).

/************************************************************************
* function name: printMenu*
* The Input: none*
* The output: prints the menu*
* The Function operation: the function prints the menu according to the
  right order*
*************************************************************************/

void printMenu()
{
    printf("please choose action:\n"
           "(1) A child was born\n"
           "(2) Throw into the Nile\n"
           "(3) Find Moshe\n"
           "(4) Print All\n"
           "(5) Size of jews\n"
           "(6) Exit\n");
}
//end of function

/************************************************************************
* function name: printOrderMenu*
* The Input: none*
* The output: prints the PRE/IN/POST order menu*
* The Function operation: the function print the post, pre and in
  order according to the right order*
*************************************************************************/

void printOrderMenu()
{
    printf("please choose order:\n"
           "(1) preorder\n"
           "(2) inorder\n"
           "(3) postorder\n");
}
//end of function

//mission 1 functions(2)

/************************************************************************
* function name: newChild*
* The Input: the function get int with the new id value*
* The output: none *
* The Function operation: the function use the new id value for the new
  child and malloc for new child and ask for new name and gender
  to put in the new child details than it make his action pointer
  to point to the name and the task to his task according to the name
  lastly, make his left and right pointers as NULL*
*************************************************************************/

BinTree *newChild(int id, BinTree *root)
{

    /*make the new born age as -20 because we add 20
    to the age after the opertaion*/

    int newBornAge=-20;
    int maxNameLength=11;
    int equal=0;
    BinTree* newNode;
    //allocate the new node memory
    newNode= malloc(sizeof(struct BinTree));

    /*if we could not allocate the memory
    free all the memory and exit the program*/

    if(newNode==NULL)
    {
        //operate free memory function
        freeisrael(root);
        //operate the exit as asked in the exam
        exit(1);
    }
    //make the new id as the id we got in the input
    newNode->id=id;
    //ask for the new child name
    printf("please insert child name:\n");
    //malloc
    newNode->name= malloc(sizeof(char)*maxNameLength);

    /*if we could not allocate the memory
    free all the memory and exit the program*/

    if(newNode->name==NULL)
    {
        //operate free memory function
        freeisrael(root);
        //operate the exit as asked in the exam
        exit(1);
    }
    //scan the name to the new node name
    scanf("%s", newNode->name);
    //ask for the gender of the new child
    printf("please insert child gender:\n");
    //scan the user answer to the node
    scanf(" %c", &newNode->gender);
    //make the left and the right pointers of the new node as NULL
    newNode->left=NULL;
    newNode->right=NULL;
    //make the new node age as new born age
    newNode->age=newBornAge;
    //make the action pointer point to the name
    newNode->action=newNode->name;

    /*check if the new child name is Moshe and he is 'M' and make
    his task as moshe task if he is not Moshe
    and a male make it as regular child task*/

    if(strcmp(newNode->name,"Moshe")==equal &&newNode->gender=='M')
        newNode->task=&moshe_task;
    else
        newNode->task=&child_task;
    //return the new node
    return newNode;
}
//end of function

/************************************************************************
* function name: addChild*
* The Input: the function gets the root to the root of the tree*
* The output: the function add child to the tree*
* The Function operation: the function activate the function that find
  moshe in the tree than activate the children tasks post order function
  and lastly, if moshe didnt found prints it to the user
  and if moshe exist she operate the delete males function*
*************************************************************************/

void addChild(BinTree** root)
{
    int true=1;
    int newId;
    //if root is NULL ask for new id and father it to the head of the tree
    if(*root==NULL)
    {
        //ask for new id
        printf("please enter child id:\n");
        //scan the new id
        scanf("%d", &newId);

        /*send the new id to the function that ask
         * the other details and make the new node*/

        *root = newChild(newId, (BinTree*)root);
        //return to the main
        return;
    }
    //if the root is not NULL store the root
    BinTree* father= *root;
    //ask for new id
    printf("please enter child id:\n");
    //scan the new id
    scanf("%d", &newId);
            //while loop to father the new node for the right place
            while(true)
            {

                /*if the new id we got is smaller than the father
                node id*/

                if(newId < father->id)
                {
                    //if the father left node is empty add new node there
                    if (father->left == NULL)
                    {
                        father->left = newChild(newId, (BinTree*)root);
                        return;
                    }

                    /*if the root is not empty make
                     * the father as the left node*/

                    father= father->left;
                }

                /*if the new id we got is bigger than the father
                node */

                else
                {
                    //if the father right node is empty add new node there
                    if (father->right == NULL)
                    {
                        father->right = newChild(newId, (BinTree*)root);
                        return;
                    }

                    /*if the root is not empty make
                     * the father as the right node*/

                    father= father->right;
                }
            }
            //end of while loop
}
//end of function


//mission 2 function(2)

/************************************************************************
* function name: throwToNile*
* The Input: the function get the root of the tree*
* The output: return int rootIsEmpty when the tree is NULL after deletion*
* The Function operation: the function operate the delete males
 * function and then get back the root and when it is NULL she return int
  value to indicate that*
*************************************************************************/

int throwToNile(BinTree* root)
{
    int nothingHappen=0;
    //decalre int to return it when the root is NULL
    int rootIsEmpty=2;
    //operate the delete males on the root
    root= deleteMales(root, root);
    //choose what to return according to the check if the root is NULL.
    if (root==NULL)
    {
        return rootIsEmpty;
    }
    else return nothingHappen;
}
//end of function

/************************************************************************
* function name: deleteMales*
* The Input: the function gets pointer to BinTree and pointer to his
  father node*
* The output: the runction return the node*
* The Function operation: the function works recursive to delete the
  males node post order for the left side of the tree then the right side
  and the node itself. The deletion has 2 parts one to check if the father
  is equal to root meaning the root is the head of the tree and second
  if they are not equal meaning it is another node but the head.
  Then, after this checking we have 3 situation of delete: 1. node without
  leafs- we just delete and make the father node as NULL.
  2. node with one leaf- copy his son to the node and delete the son with
  linking again. 3. node with 2 leafs- copy the smallest node that is bigger
  than the one we want to delete and delete this smallest node with linking
  his right leaf to the father
*************************************************************************/

BinTree* deleteMales(BinTree *root, BinTree *father)
{
    int equal=0;
    BinTree* saveNode;
    BinTree* fatherNode;
    //if the root is NULL return the root
    if(root==NULL)
        return root;
    //delete the left node of this node(and send this one as father).
    deleteMales(root->left, root);
    //delete the right node of this node(and send this one as father).
    deleteMales(root->right, root);

    /*start deletion if the name is not Moshe, the gender is 'M' (male) and in
    this case the father is the root meaning this is the head of the tree*/

    if (strcmp(root->name, "Moshe")!=equal &&
    root->gender == 'M' && root == father)
    {
        //first case- both leafs are NULL
        if (root->right == NULL && root->left == NULL)
        {
            //free the name memory
            free(root->name);
            //free the node memory
            free(root);
            //make the root NULL(this is the head and no child nodes).
            root=NULL;
            //return the root
            return root;
        }
        //second case- left root is NULL and right root is not NULL
        if (root->right != NULL && root->left == NULL)
        {
            //make the saveNode as the right node
            saveNode = root->right;
            //copy the name in the saveNode to the current node
            strcpy(root->name, saveNode->name);
            //make the current node age as the saveNode age
            root->age = saveNode->age;
            //make the current node id as the saveNode id
            root->id = saveNode->id;
            //make the current node gender as the saveNode gender
            root->gender = saveNode->gender;
            //make the current node task pointer as the saveNode task pointer
            root->task = saveNode->task;
            //make the current node left pointer as the saveNode left pointer
            root->left = saveNode->left;
            //make the current node right pointer as the saveNode right pointer
            root->right =saveNode->right;
            //free the saveNode name
            free(saveNode->name);
            //free the node memory
            free(saveNode);
            //return the root
            return root;
        }
        //end of if loop

        //third case- left root is not NULL and right root is NULL
        if (root->right == NULL && root->left != NULL)
        {
            //make the saveNode as the left node
            saveNode = root->left;
            //copy the name in the saveNode to the current node
            strcpy(root->name, saveNode->name);
            //make the current node age as the saveNode age
            root->age = saveNode->age;
            //make the current node id as the saveNode id
            root->id = saveNode->id;
            //make the current node gender as the saveNode gender
            root->gender = saveNode->gender;
            //make the current node task pointer as the saveNode task pointer
            root->task = saveNode->task;
            //make the current node left pointer as the saveNode left pointer
            root->left = saveNode->left;
            //make the current node right pointer as the saveNode right pointer
            root->right = saveNode->right;
            //free the saveNode name
            free(saveNode->name);
            //free the node memory
            free(saveNode);
            //return the root
            return root;
        }
        //end of if loop

        /*fourth case- both nodes left and right are not NULL
         * (in this case we go to the smallest node of the
         * bigger nodes it mean we go one node right and the
         * left until left is NULL*/

        if (root->right != NULL && root->left != NULL)
        {
            //make the saveNode as the root right node
            saveNode = root->right;
            //if the left node is NULL we can copy this node to the head
            if (saveNode->left == NULL)
            {
                //copy the name in the saveNode to the current node
                strcpy(root->name, saveNode->name);
                //make the current node age as the saveNode age
                root->age = saveNode->age;
                //make the current node gender as the saveNode gender
                root->gender=saveNode->gender;
                //make the current node id as the saveNode id
                root->id = saveNode->id;

                /*make the current node task
                 pointer as the saveNode task pointer*/

                root->task = saveNode->task;

                /*make the current node right
                 pointer as the saveNode right pointer
                 (the left node is NULL)*/

                root->right =saveNode->right;
                //free the saveNode name memory
                free(saveNode->name);
                //free the node memory
                free(saveNode);
                //return the root
                return root;
            }
            //end of if loop

            /*other case in the delete of 2 leafs is the case
             * when we have smaller nodes that the right nodes
             but they are bigger then the current node so we copy him*/

            else
            {

                /*make while loop to go to the left side and store the current
                 * node as the father node to link the node right node back*/

                while (saveNode->left != NULL)
                {
                    //make the father node as the current node
                    fatherNode = saveNode;
                    //go to the left with the save node
                    saveNode = saveNode->left;
                }
                //copy the name in the saveNode to the current node
                strcpy(root->name, saveNode->name);
                //make the current node age as the saveNode age
                root->age = saveNode->age;
                //make the current node gender as the saveNode gender
                root->gender=saveNode->gender;
                //make the current node id as the saveNode id
                root->id = saveNode->id;

                /*make the current node task
                 pointer as the saveNode task pointer*/

                root->task = saveNode->task;
                //link back the deleted node right pointer to his father
                fatherNode->left = saveNode->right;
                //free the node name we coppied
                free(saveNode->name);
                //free the node memory
                free(saveNode);
                //return the root
                return root;
            }
            //end of else loop
        }
        //end of if loop
    }
    //end of if loop

    /*start deletion if the name is not Moshe, the gender is 'M' (male) and in
    this case the father is not the root meaning this
    is not the head of the tree*/

    if(strcmp(root->name, "Moshe")!=equal
    &&root->gender=='M'&&root != father)
    {
        //first case- both leafs are NULL
        if(root->right==NULL && root->left==NULL)
        {
            //if the root id is smaller than his father id
            if(root->id < father->id)
            {
                //free the name memory
                free(root->name);
                //free the node memory
                free(root);

                /*the fact that this root id is smaller,
                 mean we delete his father left node so we make him NULL*/

                father->left=NULL;
                //return the root
                return root;
            }
            //if the root id is bigger than his father id
            else
            {
                //free the name memory
                free(root->name);
                //free the node memory
                free(root);

                /*the fact that this root id is bigger,
                 mean we delete his father right node so we make him NULL*/

                father->right=NULL;
                //return the root
                return root;
            }
        }
        //end of if loop

        //second case- left root is NULL and right root is not NULL
        if(root->right!=NULL && root->left==NULL)
        {
            //make the saveNode as the root right node
            saveNode = root->right;
            //copy the name in the saveNode to the current node
            strcpy(root->name, saveNode->name);
            //make the current node age as the saveNode age
            root->age = saveNode->age;
            //make the current node gender as the saveNode gender
            root->gender=saveNode->gender;
            //make the current node id as the saveNode id
            root->id = saveNode->id;

            /*make the current node task
            pointer as the saveNode task pointer*/

            root->task = saveNode->task;
            //make the current node right pointer as the saveNode right pointer
            root->right =saveNode->right;
            //make the current node left pointer as the saveNode left pointer
            root->left=saveNode->left;
            //free the name memory
            free(saveNode->name);
            //free the node memory
            free(saveNode);
            //return the root
            return root;
        }
        //end of if loop

        //third case- left root is not NULL and right root is NULL
        if(root->right==NULL && root->left!=NULL)
        {
            //make the saveNode as the root left node
            saveNode = root->left;
            //copy the name in the saveNode to the current node
            strcpy(root->name, saveNode->name);
            //make the current node age as the saveNode age
            root->age = saveNode->age;
            //make the current node gender as the saveNode gender
            root->gender=saveNode->gender;
            //make the current node id as the saveNode id
            root->id = saveNode->id;

            /*make the current node task
            pointer as the saveNode task pointer*/

            root->task = saveNode->task;
            //make the current node right pointer as the saveNode right pointer
            root->right =saveNode->right;
            //make the current node left pointer as the saveNode left pointer
            root->left=saveNode->left;
            //free the name memory
            free(saveNode->name);
            //free the node memory
            free(saveNode);
            //return the root
            return root;
        }
        //end of if loop

        /*fourth case- both nodes left and right are not NULL
         * (in this case we go to the smallest node of the
         * bigger nodes it mean we go one node right and the
         * left until left is NULL*/

        if(root->right!=NULL && root->left!=NULL)
        {
            //make the saveNode as the root right node
            saveNode = root->right;
            if (saveNode->left == NULL)
            {
                //copy the name in the saveNode to the current node
                strcpy(root->name, saveNode->name);
                //make the current node age as the saveNode age
                root->age = saveNode->age;
                //make the current node id as the saveNode id
                root->id = saveNode->id;

                /*make the current node task
                 pointer as the saveNode task pointer*/

                root->task = saveNode->task;
                //make the current node gender as the saveNode gender
                root->gender=saveNode->gender;

                /*make the current node right pointer as the
                saveNode right pointer*/

                root->right=saveNode->right;
                //free the name memory
                free(saveNode->name);
                //free the node memory
                free(saveNode);
                //return the root
                return root;
            }
            //end of if loop

            /*other case in the delete of 2 leafs is the case
             when we have smaller nodes that the right nodes
             but they are bigger then the current node so we copy him*/

            else
            {

                /*make while loop to go to the left side and store the current
                 * node as the father node to link the node right node back*/

                while(saveNode->left != NULL)
                {
                    //make the father node as the current node
                    fatherNode=saveNode;
                    //go to the left with the save node
                    saveNode=saveNode->left;
                }
                //copy the name in the saveNode to the current node
                strcpy(root->name, saveNode->name);
                //make the current node age as the saveNode age
                root->age=saveNode->age;
                //make the current node gender as the saveNode gender
                root->gender=saveNode->gender;
                //make the current node id as the saveNode id
                root->id=saveNode->id;

                /*make the current node task
                 pointer as the saveNode task pointer*/

                root->task=saveNode->task;
                //link back the deleted node right pointer to his father
                fatherNode->left= saveNode->right;
                //free the name memory
                free(saveNode->name);
                //free the node memory
                free(saveNode);
                //return the root
                return root;
            }
            //end of else loop
        }
        //end of if loop
    }
    //end of if loop

    //return the root if nothing happened
    return root;
}
//end of function


//mission 3 functions(7)

/************************************************************************
* function name: findMoshePreOrder*
* The Input: the function gets the root of the tree*
* The output: the function search for moshe and active
  the tasks for all the children in the tree pre order*
* The Function operation: the function activate the function that find
  moshe in the tree than activate the children tasks pre order function
  and , if moshe didnt found prints it to the user
  and  if moshe exist she operate the delete males function*
*************************************************************************/

void findMoshePreOrder(BinTree* pointer)
{
    int moshe=0;
    int notFound=0;
    //operate the function that finds moshe in the tree
    moshe=mosheInTree(pointer, moshe);
    //operate the function that activate the task of the childs pre order
    actionChildPreOrder(pointer);
    //if moshe did not found
    if (moshe==notFound)
    {
        //print the message that we didnt found moshe
        printf("Moshe Not Found!\n");
    }
    //if we found moshe operate the function that throw males to nile
    else
    {
        pointer= deleteMales(pointer, pointer);
    }
}
//end of function

/************************************************************************
* function name: findMosheInOrder*
* The Input: the function gets the root of the tree*
* The output: the function search for moshe and active
  the tasks for all the children in the tree in order*
* The Function operation: the function activate the function that find
  moshe in the tree than activate the children tasks in order function
  and lastly, if moshe didnt found prints it to the user
  and if moshe exist she operate the delete males function*
*************************************************************************/

void findMosheInOrder(BinTree* pointer)
{
    int moshe=0;
    int notFound=0;
    //operate the function that finds moshe in the tree
    moshe = mosheInTree(pointer, moshe);
    //operate the function that activate the task of the childs in order
    actionChildInOrder(pointer);
    //if moshe did not found
    if (moshe == notFound)
    {
        //print the message that we didnt found moshe
        printf("Moshe Not Found!\n");
    }
    //if we found moshe operate the function that throw males to nile
    else
    {
        pointer = deleteMales(pointer, pointer);
    }
}
//end of function




/************************************************************************
* function name: findMoshePostOrder*
* The Input: the function gets the root of the tree*
* The output: the function search for moshe and active
  the tasks for all the children in the tree post order*
* The Function operation: the function activate the function that find
  moshe in the tree than activate the children tasks post order function
  and lastly, if moshe didnt found prints it to the user
  and if moshe exist she operate the delete males function*
*************************************************************************/

void findMoshePostOrder(BinTree* pointer)
{
    int moshe=0;
    int notFound=0;
    //operate the function that finds moshe in the tree
    moshe=mosheInTree(pointer, moshe);
    //operate the function that activate the task of the childs post order
    actionChildPostOrder(pointer);
    //if moshe did not found
    if (moshe==notFound)
    {
        //print the message that we didnt found moshe
        printf("Moshe Not Found!\n");
    }
    //if we found moshe operate the function that throw males to nile
    else
    {
        pointer= deleteMales(pointer, pointer);
    }
}
//end of function



/************************************************************************
* function name: MosheInTree*
* The Input: the function gets the root of the tree, and int to check if
  if moshe alive in the tree*
* The output: the function return 1 if moshe is in the tree and
 * 0 if moshe didnt found in the tree*
* The Function operation: the function works recursive post order: checks
 first for the left root then the right root than check itself
 if moshe found it return 1 and if he didn't found return 0*
*************************************************************************/

int mosheInTree(BinTree* root, int mosheDidNotFound)
{
    int equal=0;
    int mosheIsHere;
    mosheIsHere = 1;
    //if root is NULL, return that moshe did not fount(value 0)
    if (root==NULL)
    {
        return mosheDidNotFound;
    }

    /*search post order for moshe while making the counter for the value
     that got back from the left and then the right pointers */

    mosheDidNotFound= mosheInTree(root->left, mosheDidNotFound);
    mosheDidNotFound= mosheInTree(root->right,mosheDidNotFound);

    /*check the root itself if moshe is here
     (check for the name, and the male gender*/

    if (strcmp(root->name, "Moshe")==equal && root->gender== 'M')
    {
        //return that moshe is found(value 1).
        return (mosheDidNotFound+  mosheIsHere);
    }
    //if we did not found moshe we back that we did not found him(value 0).
    else return mosheDidNotFound;
}
//end of function

/************************************************************************
* function name: actionChildInOrder*
* The Input: the function gets the root of the tree*
* The output: the function scan the tree in order and activate each
  kid task with his name*
* The Function operation: the function works recursive in order which means
    activate the left side than activate  the root itself than
    activate the right side*
*************************************************************************/

void actionChildInOrder(BinTree* root)
{
    //if the node is NULL do nothing
    if (root==NULL)
    {
        return;
    }
    //action the left node of the current node
    actionChildInOrder(root->left);
    //activate the current node task
    root->task(root->action);
    //action the right node of the current node
    actionChildInOrder(root->right);
}
//end of function

/************************************************************************
* function name: actionChildPreOrder*
* The Input: the function gets the root of the tree*
* The output: the function scan the tree pre order and activate each
  kid task with his name*
* The Function operation: the function works recursive pre order which means
    activate the root itself than activate the left side than
    activate the right side*
*************************************************************************/

void actionChildPreOrder(BinTree *root) {
    //if the node is NULL do nothing
    if (root==NULL)
    {
        return;
    }
    //activate the current node task
    root->task(root->action);
    //action the left node of the current node
    actionChildPreOrder(root->left);
    //action the right node of the current node
    actionChildPreOrder(root->right);
}
//end of function

/************************************************************************
* function name: actionChildPostOrder*
* The Input: the function gets the root of the tree*
* The output: the function scan the tree post order and activate each
  kid task with his name*
* The Function operation: the function works recursive pre order which means
    activate the left side than activate the right side than
    activate the root's task itself*
*************************************************************************/

void actionChildPostOrder(BinTree* root)
{
    //if the node is NULL do nothing
    if (root==NULL)
    {
        return;
    }
    //action the left node of the current node
    actionChildPostOrder(root->left);
    //action the right node of the current node
    actionChildPostOrder(root->right);
    //activate the current node task
    root->task(root->action);
}
//end of function


//mission 4 functions(3)

/************************************************************************
* function name: printChildrenPreOrder*
* The Input: the function gets the root of the tree*
* The output: the function scan the tree post order and prints the
  node details*
* The Function operation: the function works recursive pre order which means
    print the node itself than print the left side than
    prints the right side than*
*************************************************************************/

void printChildrenPreOrder(BinTree* root)
{
    //if the node is NULL do nothing
    if (root==NULL)
    {
        return;
    }
    //printing according to the right format the node itself
    printf("id: %d, name: %s, gender: %c, age: %d\n",
           root->id, root->name, root->gender, root->age);
    //printing according to the right format the left side of the tree
    printChildrenPreOrder(root->left);
    //printing according to the right format the right side of the tree
    printChildrenPreOrder(root->right);
}
//end of function

/************************************************************************
* function name: printChildrenInOrder*
* The Input: the function gets the root of the tree*
* The output: the function scan the tree In order and prints the
  node details*
* The Function operation: the function works recursive in order which means
    print the left side than print the node itself than
    prints the right side*
*************************************************************************/

void printChildrenInOrder(BinTree* root)
{
    //if the node is NULL do nothing
    if (root==NULL)
    {
        return;
    }
    //printing according to the right format the left side of the tree
    printChildrenInOrder(root->left);
    //printing according to the right format the node itself
    printf("id: %d, name: %s, gender: %c, age: %d\n",
           root->id, root->name, root->gender, root->age);
    //printing according to the right format the right side of the tree
    printChildrenInOrder(root->right);

}
//end of function

/************************************************************************
* function name: printChildrenPostOrder*
* The Input: the function gets the root of the tree*
* The output: the function scan the tree post order and prints the
  node details*
* The Function operation: the function works recursive post order which means
    print the left side than prints the right side
    than print the node itself *
*************************************************************************/


void printChildrenPostOrder(BinTree* root)
{
    //if the node is NULL do nothing
    if (root==NULL)
    {
        return;
    }
    //printing according to the right format the left side of the tree
    printChildrenPostOrder(root->left);
    //printing according to the right format the right side of the tree
    printChildrenPostOrder(root->right);
    //printing according to the right format the node itself
    printf("id: %d, name: %s, gender: %c, age: %d\n",
           root->id, root->name, root->gender, root->age);
}
//end of function


//mission 5 functions(5)

/************************************************************************
* function name: printNumberOfAllJews*
* The Input: the function gets the root of the tree*
* The output: the function prints the number of all jews*
* The Function operation: the function call to the function that count the
 * tree and prints the number she gets *
*************************************************************************/

void printNumberOfAllJews(BinTree* root)
{
    int counterJews=0;
    //call the counterJews function and store the number
    counterJews= countingChildren(root, counterJews);
    //prints the number of all jews to the user
    printf("size of all jews is: %d\n", counterJews);
}
//end of function

/************************************************************************
* function name: countMales*
* The Input: the function gets the root of the tree*
* The output: the function prints the number of the males*
* The Function operation: the function call to the function that count the
 * tree by gender with the 'M' char and prints the number she gets*
*************************************************************************/

void countMales(BinTree* root)
{
    char gender;
    //declare the right letter for the male gender
    gender='M';
    int counterMaleJews=0;
    //call the function that count the jews by gender and store the number
    counterMaleJews= countingChildrenByGender(root, gender, counterMaleJews);
    //prints the number to the user
    printf("size of all male jews is: %d\n", counterMaleJews);

}
//end of function

/************************************************************************
* function name: countFemales*
* The Input: the function gets the root of the tree*
* The output: the function prints the number of the females*
* The Function operation: the function call to the function that count the
 * tree by gender with the 'F' char and prints the number she gets*
*************************************************************************/

void countFemales(BinTree* root)
{
    char gender;
    //declare the right letter for the female gender
    gender='F';
    int counterFemaleJews=0;
    //call the function that count the jews by gender and store the number
    counterFemaleJews=countingChildrenByGender(root,gender, counterFemaleJews);
    //prints the number to the user
    printf("size of all female jews is: %d\n", counterFemaleJews);
}
//end of function

/************************************************************************
* function name: countingChildren*
* The Input: the function gets the root of the tree and counter number(int)*
* The output: the function return int with the number of the children*
* The Function operation: the function works recursive to
  scan the tree post order and
  check if there is child,if yes she return the
  counter+anotherChild(value 1) that indicates that
  there is another child here*
*************************************************************************/


int countingChildren(BinTree *root, int counter)
{
    int anotherChild=1;
    //if the node is NULL do nothing
    if(root==NULL)
        return counter;
    //check the left side of the node
    counter=countingChildren(root->left, counter);
    //check the right side of the node
    counter=countingChildren(root->right, counter);
    //check the node itself(if there is male or female)
    if(root->gender=='M'|| root->gender=='F')
    {
        //if there is child add another child to the counter
        return (counter+anotherChild);
    }
    //else return the counter as it is
    else return counter;
}
//end of function

/************************************************************************
* function name: countingChildrenByGender.
* The Input: the function gets the root of the tree,counter number(int)
 * and char gender to compare if its male or female*
* The output: the function return int with the number of the children
  of the gender requsted*
* The Function operation: the function works recursive to
  scan the tree post order and
  check if there is child with the gender requsted,if yes she return the
  counter+anotherChild(value 1) that indicates that
  there is another child with the gender requsted here.
*************************************************************************/

int countingChildrenByGender(BinTree *root, char gender, int counter)
{
    int anotherChild=1;
    //if the node is NULL do nothing
    if(root==NULL)
        return counter;
    //check the left side of the node
    counter=countingChildrenByGender(root->left, gender, counter);
    //check the node itself(if there is male or female)
    counter=countingChildrenByGender(root->right, gender, counter);
    //check the node itself(if there is child according to char gender)
    if(root->gender==gender)
    {
        //if there is child according to the gender add to the counter
        return (counter+anotherChild);
    }
    //else return the counter as it is
    else return counter;
}
//end of function

//mission 6 function(1).

/************************************************************************
* function name: freeisrael*
* The Input: BinTree* pointer to the root
* The output: none.
* The Function operation: the function works recursivley  post order
 free the memory we allocated, first the memeory of the name
 then the root memory  *
*************************************************************************/

void freeisrael(BinTree* root)
{
    //if the node is NULL do nothing
    if (root==NULL)
        return;
    //free the left node
    freeisrael(root->left);
    //free the right node
    freeisrael(root->right);
    //free the name of the current node
    free(root->name);
    //free the current node
    free(root);
}
//end of function

/*The function to add twenty years to the tree including the functions to
  handle moshe while he is eighty years old(4)*/

/************************************************************************
* function name: twentyYearsLater*
* The Input: the root of the tree*
* The output: return int according to the thing that happen in
  after 20 years: 1. moshe is 80 years old. 2. the tree is empty.
  3. nothing happened. *
  * The Function operation: first the function operate the function that add
   20 years to the age on the tree, second she check if moshe is 80 years
   old if he is she return to the main if moshe is not 80 years old
   she continue with operate the function that delete someone if he is
   120 years old that she check if he root is NULL if he is she return it
   to the main if the root is not NULL and if not she return nothing
   happen value*
*************************************************************************/



int twentyYearsLater(BinTree *root)
{
    int mosheIs80YearsOld=1;
    int theTreeIsEmpty=2;
    int nothingHappen=0;
    BinTree* mosheNode;
    int moshe=0;
    //operate the function that add 20 years old on th root
    add20(root);
    //operate the function that check if moshe is 80 years old
    moshe= mosheIsEighty(root, moshe);
    //if moshe is 80 years old return the value of it
    if (moshe==mosheIs80YearsOld)
    {
        return mosheIs80YearsOld;
    }
    //operate the function that delete "child" when he is 120 years old
    root = deleteWhen120YearsOld(root, root);
    //if the root is NULL after the 120 years function return it to the main
    if(root==NULL)
    {
        return theTreeIsEmpty;
    }
    //if the root is not NULL return that nothing happen
    else return nothingHappen;
}
//end of function



/************************************************************************
* function name: mosheIsEighty*
* The Input: pointer to BinTree and int that indicate if moshe found*
* The output: int for the user value 1 if moshe found and 0 if not
* The Function operation: the function works post order and scan the left side
  of the tree the the right side and then the root itself. If
  moshe found and he is 80 years old return 1 and prints the message
  for the end of the program*
*************************************************************************/

int mosheIsEighty(BinTree* root, int moshe)
{
    char mosheName[10]= "Moshe";
    int isEighty=1;
    int equal=0;
    int maxMosheAge=80;
    //if the root is NULL return 0;
    if (root==NULL)
    {
        return moshe;
    }
    //scan the left side of the tree for moshe 80 years old
    moshe= mosheIsEighty(root->left, moshe);
    //scan the right side of the tree for moshe 80 years old
    moshe= mosheIsEighty(root->right,moshe);
    //check the root for the name "Moshe" while he is male and 80 years old.
    if (strcmp(root->name, mosheName)==equal &&
    root->gender== 'M' &&root->age==maxMosheAge)
    {
        //print the end program message
        printf("%s say: let my people go!\n", root->name);
        //return value that indicates that moshe alive and eighty years old
        return (moshe + isEighty);
    }
    //if moshe didnt found return 0.
    else return moshe;
}
//end of function


/************************************************************************
* function name: add20*
* The Input: the root of the tree*
* The output: none*
* The Function operation: the function works recursive post-order to add
  20 years to the age of the childs in the tree*
*************************************************************************/

void add20(BinTree* root)
{
    int addTwentyYearsToAge=20;
    //if the root is NULL return;
    if (root==NULL)
        return;
    //add 20 years to the left side of the node
    add20(root->left);
    //add 20 years to the right side of the node
    add20(root->right);
    //add 20 years to the current node
    root->age=root->age+addTwentyYearsToAge;
}
//end of function

/************************************************************************
* function name: deleteWhen120YearsOld*
* The Input: the function gets pointer to BinTree and pointer to his
  father node*
* The output: the runction return the node*
* The Function operation: the function works recursive to delete the
  some one who reach age 120 post order for the left side
  of the tree then the right side and the node itself.
  The deletion has 2 parts one to check if the father
  is equal to root meaning the root is the head of the tree and second
  if they are not equal meaning it is another node but the head.
  Then, after this checking we have 3 situation of delete: 1. node without
  leafs- we just delete and make the father node as NULL.
  2. node with one leaf- copy his son to the node and delete the son with
  linking again. 3. node with 2 leafs- copy the smallest node that is bigger
  than the one we want to delete and delete this smallest node with linking
  his right leaf to the father
*************************************************************************/

BinTree* deleteWhen120YearsOld(BinTree *root, BinTree *father)
{
    BinTree* saveNode;
    BinTree* fatherNode;
    int maxAge=120;
    //if the root is NULL return the root
    if(root==NULL)
        return root;
    //delete the left node of this node(and send this one as father).
    deleteWhen120YearsOld(root->left, root);
    //delete the right node of this node(and send this one as father).
    deleteWhen120YearsOld(root->right, root);

    /*start deletion if the age is 120 and in
    this case the father is the root meaning
     this is the head of the tree*/

    if (root->age==maxAge&& root==father)
    {
        //first case- both leafs are NULL
        if (root->right == NULL && root->left == NULL)
        {
            //free the name memory
            free(root->name);
            //free the node memory
            free(root);
            //make the root NULL(this is the head and no child nodes).
            root=NULL;
            //return the root
            return root;
        }
        //second case- left root is NULL and right root is not NULL
        if (root->right != NULL && root->left == NULL)
        {
            //make the saveNode as the right node
            saveNode = root->right;
            //copy the name in the saveNode to the current node
            strcpy(root->name, saveNode->name);
            //make the current node age as the saveNode age
            root->age = saveNode->age;
            //make the current node id as the saveNode id
            root->id = saveNode->id;
            //make the current node gender as the saveNode gender
            root->gender = saveNode->gender;

            /*make the current node task
            pointer as the saveNode task pointer*/

            root->task = saveNode->task;
            //make the current node left pointer as the saveNode left pointer
            root->left = saveNode->left;
            //make the current node right pointer as the saveNode right pointer
            root->right = saveNode->right;
            //free the saveNode name memory
            free(saveNode->name);
            //free the node memory
            free(saveNode);
            //return the root
            return root;
        }
        //end of if loop

        //third case- left root is not NULL and right root is NULL
        if (root->right == NULL && root->left != NULL)
        {
            //make the saveNode as the left node
            saveNode = root->left;
            //copy the name in the saveNode to the current node
            strcpy(root->name, saveNode->name);
            //make the current node age as the saveNode age
            root->age = saveNode->age;
            //make the current node id as the saveNode id
            root->id = saveNode->id;
            //make the current node gender as the saveNode gender
            root->gender = saveNode->gender;

            /*make the current node task
            pointer as the saveNode task pointer*/

            root->task = saveNode->task;
            //make the current node left pointer as the saveNode left pointer
            root->left = saveNode->left;
            //make the current node right pointer as the saveNode right pointer
            root->right = saveNode->right;
            //free the saveNode name memory
            free(saveNode->name);
            //free the node memory
            free(saveNode);
            //return the root
            return root;
        }
        //end of if loop

        /*fourth case- both nodes left and right are not NULL
         * (in this case we go to the smallest node of the
         * bigger nodes it mean we go one node right and the
         * left until left is NULL*/

        if (root->right != NULL && root->left != NULL)
        {
            //make the saveNode as the right node
            saveNode = root->right;
            if (saveNode->left == NULL)
            {
                //copy the name in the saveNode to the current node
                strcpy(root->name, saveNode->name);
                //make the current node age as the saveNode age
                root->age = saveNode->age;
                //make the current node gender as the saveNode gender
                root->gender=saveNode->gender;
                //make the current node id as the saveNode id
                root->id = saveNode->id;

                /*make the current node task
                 pointer as the saveNode task pointer*/

                root->task = saveNode->task;

                /*make the current node right
                pointer as the saveNode right pointer*/

                root->right =saveNode->right;
                //free the saveNode name memory
                free(saveNode->name);
                //free the node memory
                free(saveNode);
                //return the root
                return root;
            }
            //end of if loop

            /*other case in the delete of 2 leafs is the case
             when we have smaller nodes that the right nodes
             but they are bigger then the current node so we copy him*/

            else {

                /*make while loop to go to the left side and store the current
                 * node as the father node to link the node right node back*/

                while (saveNode->left != NULL)
                {
                    //make the father node as the current node
                    fatherNode = saveNode;
                    //go to the left with the save node
                    saveNode = saveNode->left;
                }
                //copy the name in the saveNode to the current node
                strcpy(root->name, saveNode->name);
                //make the current node age as the saveNode age
                root->age = saveNode->age;
                //make the current node id as the saveNode id
                root->id = saveNode->id;

                /*make the current node task
                pointer as the saveNode task pointer*/

                root->task = saveNode->task;
                //make the current node gender as the saveNode gender
                root->gender=saveNode->gender;
                //link back the deleted node right pointer to his father
                fatherNode->left = saveNode->right;
                //free the saveNode name memory
                free(saveNode->name);
                //free the node memory
                free(saveNode);
                //return the root
                return root;
            }
            //end of else loop
        }
        //end of if loop
    }
    //end of if loop

    /*start deletion if the age is 120 and in
    this case the father is not the root meaning
     this is not the head of the tree*/

    if(root->age==maxAge&&root != father)
    {
        //first case- both leafs are NULL
        if(root->right==NULL && root->left==NULL)
        {
            //if the root id is smaller than his father id
            if(root->id < father->id)
            {
                //free the saveNode name memory
                free(root->name);
                //free the node memory
                free(root);

                /*the fact that this root id is smaller,
                 mean we delete his father left node so we make him NULL*/

                father->left=NULL;
                //return the root
                return root;
            }
            //if the root id is bigger than his father id
            else
            {
                //free the saveNode name memory
                free(root->name);
                //free the node memory
                free(root);

                /*the fact that this root id is bigger,
                 mean we delete his father right node so we make him NULL*/

                father->right=NULL;
                //return the root
                return root;
            }
        }
        //end of if loop

        //second case- left root is NULL and right root is not NULL
        if(root->right!=NULL && root->left==NULL)
        {
            //make the saveNode as the right node
            saveNode = root->right;
            //copy the name in the saveNode to the current node
            strcpy(root->name, saveNode->name);
            //make the current node age as the saveNode age
            root->age = saveNode->age;
            //make the current node gender as the saveNode gender
            root->gender=saveNode->gender;
            //make the current node id as the saveNode id
            root->id = saveNode->id;

            /*make the current node task
            pointer as the saveNode task pointer*/

            root->task = saveNode->task;

            //make the current node right pointer as the saveNode right pointer

            root->right =saveNode->right;
            //make the current node left pointer as the saveNode left pointer
            root->left=saveNode->left;
            //free the saveNode name memory
            free(saveNode->name);
            //free the node memory
            free(saveNode);
            //return the root
            return root;
        }
        //end of if loop

        //third case- left root is not NULL and right root NULL
        if(root->right==NULL && root->left!=NULL)
        {
            //make the saveNode as the left node
            saveNode = root->left;
            //copy the name in the saveNode to the current node
            strcpy(root->name, saveNode->name);
            //make the current node age as the saveNode age
            root->age = saveNode->age;
            //make the current node gender as the saveNode gender
            root->gender=saveNode->gender;
            //make the current node id as the saveNode id
            root->id = saveNode->id;

            /*make the current node task
            pointer as the saveNode task pointer*/

            root->task = saveNode->task;
            //make the current node right pointer as the saveNode right pointer
            root->right =saveNode->right;
            //make the current node left pointer as the saveNode left pointer
            root->left=saveNode->left;
            //free the saveNode name memory
            free(saveNode->name);
            //free the node memory
            free(saveNode);
            //return the root
            return root;
        }
        //end of if loop

        /*fourth case- both nodes left and right are not NULL
         * (in this case we go to the smallest node of the
         * bigger nodes it mean we go one node right and the
         * left until left is NULL*/

        if(root->right!=NULL && root->left!=NULL)
        {
            //make the saveNode as the right node
            saveNode = root->right;
            if (saveNode->left == NULL)
            {
                //copy the name in the saveNode to the current node
                strcpy(root->name, saveNode->name);
                //make the current node age as the saveNode age
                root->age = saveNode->age;
                //make the current node gender as the saveNode gender
                root->gender=saveNode->gender;
                //make the current node id as the saveNode id
                root->id = saveNode->id;

                /*make the current node task
                 pointer as the saveNode task pointer*/

                root->task = saveNode->task;

                /*make the current node right
                pointer as the saveNode right pointer*/

                root->right=saveNode->right;
                //free the saveNode name memory
                free(saveNode->name);
                //free the node memory
                free(saveNode);
                //return the root
                return root;
            }
            //end of if loop

            /*other case in the delete of 2 leafs is the case
             when we have smaller nodes that the right nodes
             but they are bigger then the current node so we copy him*/

            else {

                /*make while loop to go to the left side and store the current
                 * node as the father node to link the node right node back*/

                while(saveNode->left != NULL)
                {
                    //make the father node as the current node
                    fatherNode=saveNode;
                    //go to the left with the save node
                    saveNode=saveNode->left;
                }
                //copy the name in the saveNode to the current node
                strcpy(root->name, saveNode->name);
                //make the current node age as the saveNode age
                root->age=saveNode->age;
                //make the current node id as the saveNode id
                root->id=saveNode->id;

                /*make the current node task
                 pointer as the saveNode task pointer*/

                root->task=saveNode->task;
                //make the current node gender as the saveNode gender
                root->gender=saveNode->gender;
                //link back the deleted node right pointer to his father
                fatherNode->left= saveNode->right;
                //free the saveNode name memory
                free(saveNode->name);
                //free the node memory
                free(saveNode);
                //return the root
                return root;
            }
            //end of else loop
        }
        //end of if loop
    }
    //end of if loop

    //return the root when nothing happened
    return root;
}
//end of function



