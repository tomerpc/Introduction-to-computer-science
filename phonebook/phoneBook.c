/******************************************
 *Name: Tomer Cohen
 *Student ID: 209200658
 *Sumbit ID: cohentol
 *Excercise name: ex_5
 ******************************************/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//declare the Contact struct
typedef struct Contact
{
    char *firstName;
    char *lastName;
    char *phoneNum;
    struct Contact *next;
} Contact;
// declare the mission functions/
void printMenu();
void addNewContact(Contact *phoneBook[], int size);
void deleteContact(Contact *phoneBook[], int size);
void findContactByNumber(Contact *phoneBook[], int size);
void findContactByName(Contact *phoneBook[], int size);
void updatePhoneNumber(Contact *phoneBook[], int size);
void printPhoneBook(Contact *phoneBook[], int size);
void bye(Contact *phoneBook[], int size);

int main()
{
    // declare the function variables.
    int lettersNumber = 26;
    Contact *phoneBook[lettersNumber];
    int arraySize = lettersNumber;
    int i;
    int flag = 0;
    int on = 1;
    // fill the pointers array(phonebook) with NULL.
    for (i = 0; i < arraySize; i++)
    {
        phoneBook[i] = NULL;
    }
    int pick;
    // print the menu
    printMenu();
    // while loop for the menu until the user decide to exit.
    while (flag != on)
    {
        scanf("%d", &pick);
        // switch case to handle the user desicion.
        switch (pick)
        {
        // case 1-add new phone number.
        case 1:
        {
            // sending the user to the adding function.
            addNewContact(phoneBook, arraySize);
            // print the menu for the next desicion.
            printMenu();
            break;
        }
        // case 2-delete contact from the phonebook.
        case 2:
        {
            // sending the user to the delete function.
            deleteContact(phoneBook, arraySize);
            // print the menu for the next desicion.
            printMenu();
            break;
        }
        // case 3- find contact by number.
        case 3:
        {
            // sending the user to the searching function.
            findContactByNumber(phoneBook, arraySize);
            // print the menu for the next desicion.
            printMenu();
            break;
        }
        // case 4- find contact by name.
        case 4:
        {
            // sending the user to the searching function.
            findContactByName(phoneBook, arraySize);
            // print the menu for the next desicion.
            printMenu();
            break;
        }
        // case 5- update phone number.
        case 5:
        {
            // sending the user to the update function.
            updatePhoneNumber(phoneBook, arraySize);
            // print the menu for the next desicion.
            printMenu();
            break;
        }
        // case 6- print the phonebook.
        case 6:
        {
            // sending the user to the printing function.
            printPhoneBook(phoneBook, arraySize);
            // print the menu for the next desicion.
            printMenu();
            break;
        }
        // case 7-Exit the program.
        case 7:
        {
            // sending the user to the exit function.
            bye(phoneBook, arraySize);
            // method to break the while loop
            flag = on;
            break;
        }
        // default case- pick that isn't in the legal range.
        default:
        {
            // printing error message and asking to pick again.
            printf("Wrong option, try again: \n");
        }
        }
    }
}


/************************************************************************
 * function name: printMenu  *
 * The Input:none
 * The output: none
 * The Function operation: the function prints the menu of the 
 program *
 *************************************************************************/

void printMenu()
{
printf("Welcome to the phone book manager!\n"
                   "Choose an option:\n"
                   "1. Add a new contact to the phone book.\n"
                   "2. Delete a contact from the phone book.\n"
                   "3. Find a contact in the phone book by phone number.\n"
                   "4. Find a contact in the phone book by name.\n"
                   "5. Update phone number for a contact.\n"
                   "6. Print phone book.\n"
                   "7. Exit.\n");
}
//end of function

/************************************************************************
 * function name: addNewContact  *
 * The Input:the function get an contact pointers array and the size of it*
 * The output: the function has no output *
 * The Function operation: the function takes an
 contact pointers array and adding a
 new contact to the array with 3 steps: 1. check the input.
 2. allocate memory for the new contact. 3. add the contact to the
 right place. *
 *************************************************************************/

void addNewContact(Contact *phonebook[], int size)
{
    // declare the function variables.
    Contact *currentPerson = NULL;
    Contact *lastNode;
    Contact *saveNode;
    Contact *saveNode1;
    int equal = 0;
    int i = 0;
    int firstChar = 0;
    int firstLetter = 0;
    int checkInput = 1;
    //10 is the max lengath of the contact details+ '\0'
    int maxInputLength = 11;
    int asciiGapBetweenLetterAndNumber = 65;
    char name[maxInputLength];
    char familyName[maxInputLength];
    char phoneNumber[maxInputLength];
    // asking the user to write contact details
    printf("Enter a contact details "
     "(<first name> <last name> <phone number>): ");
    // scan the details to the right array according to the user writing
    scanf("%s", name);
    scanf("%s", familyName);
    scanf("%s", phoneNumber);

    /*step 1-check if the contact
     details alredy has beed added to the phonebook*/

    for (i = 0; i < size; i++)
    {
        // start search if the place in the phonebook is not empty
        if (phonebook[i] != NULL)
        {
            // take a pointer that will point to the phonebook pointer
            lastNode = phonebook[i];

            /*if the place in the phonebook
             has only one contact(the next node is empty).*/

            if (lastNode->next == NULL)
            {
                // compare the name and the last name to the user input.
                if (strcmp(lastNode->firstName, name) == equal &&
                    strcmp(lastNode->lastName, familyName) == equal)
                {
                    // printing a error message, and return to the main
                    printf("The addition of the contact has failed, "
                     "since the contact %s %s already exists!\n",
                      name, familyName);
                    return;
                }
                // compare the phone number to the user input.
                if (strcmp(lastNode->phoneNum, phoneNumber) == equal)
                {
                    // printing a error message, and return to the main
                    printf("The addition of the contact has failed, "
                     "since the phone number %s "
                      "already exists!\n", phoneNumber);
                    return;
                }
            }
            else
            {

            /*if the place in the phonebook has
            more than one contact(the next node is not empty).*/

            while (lastNode->next != NULL)
            {
                // compare the name and the last name to the user input.
                if (strcmp(lastNode->firstName, name) == equal &&
                    strcmp(lastNode->lastName, familyName) == equal)
                {
                    // printing a error message, and return to the main
                    printf("The addition of the contact has failed, "
                    "since the contact %s %s "
                     "already exists!\n", name, familyName);
                    return;
                }
                // compare the phone number to the user input.
                if (strcmp(lastNode->phoneNum, phoneNumber) == equal)
                {
                    // compare the phone number to the user input.
                    printf("The addition of the contact has failed,"
                    " since the phone number %s already exists!\n",phoneNumber);
                    return;
                }
                // change the node to his next part to check the next node.
                lastNode = lastNode->next;
            }
            // end of while loop

            /*last check for the last place(since the
             while loop works till next is not NULL we do another
              last check for the last place that his next is NULL)*/

                if (strcmp(lastNode->lastName, familyName) == equal
                &&strcmp(lastNode->firstName, name) == equal)
            {
                // printing a error message, and return to the main
                printf("The addition of the contact has failed,"
                " since the contact %s %s already exists!\n", name, familyName);
                return;
            }
            // compare the phone number to the user input.
            if (strcmp(lastNode->phoneNum, phoneNumber) == equal)
                {
                    // compare the phone number to the user input.
                    printf("The addition of the contact has failed,"
                    " since the phone number %s already exists!\n",phoneNumber);
                    return;
                }

          }
        // end of if loop
    }
    }
    // end of for loop

    // step 2- after we checked the input- we can create the new node.

    // getting memory for new contact
    currentPerson = (Contact *)malloc(sizeof(Contact));
    if (currentPerson != NULL)
    {
        // getting memory for the new contact first name
        currentPerson->firstName =(char *)malloc(sizeof(char)*maxInputLength);
        // if the memory allocated put name in it.
        if (currentPerson->firstName != NULL)
        {
            strcpy(currentPerson->firstName, name);
        }
        // if we can allocate the memory print fail message and free the node
        else
        {
            printf("The addition of the contact has failed!\n");
            free(currentPerson);
        }
        // getting memory for the new contact last name
        currentPerson->lastName=(char *)malloc(sizeof(char) *maxInputLength);
        // if the memory allocated put last name in it.
        if (currentPerson->lastName != NULL)
        {
            strcpy(currentPerson->lastName, familyName);
        }
        else
        {

            /*if we can't allocate the memory print
             fail message and free memory we allocated*/

            printf("The addition of the contact has failed!\n");
            free(currentPerson->firstName);
            free(currentPerson);
        }
        // getting memory for the new contact phone number
        currentPerson->phoneNum = (char *)malloc(sizeof(char)*maxInputLength);
        // if the memory allocated put the new phone number in it.
        if (currentPerson->phoneNum != NULL)
        {
            strcpy(currentPerson->phoneNum, phoneNumber);
        }

        /*if we can't allocate the memory print
         fail message and free memory we allocated*/

        else
        {
            printf("The addition of the contact has failed!\n");
            free(currentPerson->firstName);
            free(currentPerson->lastName);
            free(currentPerson);
        }

        // make the next pointer of the new node NULL
        currentPerson->next = NULL;
    }
    // end of if loop
    else
    {
        // print fail message if we dont have memory for new node.
        printf("The addition of the contact has failed!\n");
    }

    // step 3- put the node in the list.

    /* realize the first letter of the new family
     name so we can put the new node in the right
      place according to the family name of the new contact*/

    firstLetter = (int)familyName[firstChar]-asciiGapBetweenLetterAndNumber;
    // if the right place in the array is empty
    if (phonebook[firstLetter] == NULL)
    {

        /*put the node in the start of the
         list and print the successful message*/

        phonebook[firstLetter] = currentPerson;
        printf("The contact has been added successfully!\n");
    }
    // if the place in the array is not empty
    else
    {

        /*step 1-save the list with pointer that points
         to the start of the right place in the phonebook array*/

        saveNode = phonebook[firstLetter];
        // step 2- put the new node in the head of the array
        phonebook[firstLetter] = currentPerson;
        // step 3- link the array again to the phonebook's next pointer
        phonebook[firstLetter]->next = saveNode;
        // step 4- print the successful meassage.
        printf("The contact has been added successfully!\n");
    }
    return;
}
//end of function

/************************************************************************
 * function name: deleteContact  *
 * The Input: the function get an contact pointers array and the size of it *
 * The output: the function has no output *
 * The Function operation:the function takes input from the user
  and scan the phone book and if it appear in the phonebook
 it ask the user if he want to delete and delete the
 user contact.*
 *************************************************************************/

void deleteContact(Contact *phoneBook[], int size)
{
    Contact *saveNode;
    Contact *deleteNode;
    Contact *checkNode;
    Contact *lastNode = NULL;
    Contact *checkNode1;
    int asciiGapBetweenLetterAndNumber = 65;
    //10 is the max lengath of the contact details+ '\0'
    int maxInputLength = 11;
    int firstContactDeleted=2;
    int otherContactDeleted=1;
    int equal = 0;
    int delete = 0;
    int contactNumber = 0;
    int firstContact=0;
    int firstChar=0;
    char sureAnswer;
    int firstLetter;
    char Name[maxInputLength];
    char familyName[maxInputLength];
    printf("Enter a contact name (<first name> <last name>): ");
    scanf("%s", Name);
    scanf("%s", familyName);
    firstLetter= (int)familyName[firstChar] -asciiGapBetweenLetterAndNumber;
    checkNode = phoneBook[firstLetter];
    // check if deleted contact is the first one
    if (checkNode != NULL)
    {
        if (checkNode->next == NULL)
        {
            //check for the user contact in the list
            if (strcmp(checkNode->firstName, Name) == equal &&
                strcmp(checkNode->lastName, familyName) == equal)
            {
                delete = firstContactDeleted;
            }
        }
        // if it is not the first one check the other list
        else
        {
            //while loop when the next pointer is not empty
            while (checkNode->next != NULL)
            {
                 //check for the user contact in the list
                if (strcmp(checkNode->firstName, Name) == equal &&
                    strcmp(checkNode->lastName, familyName) == equal)
                {
                    //if the equality is in the first node
                    if (contactNumber ==firstContact)
                    {
                        //make the delete on
                        delete = firstContactDeleted;
                    }
                    //if the equality is not in the first ocntact
                    else
                        delete = otherContactDeleted;
                }
                //method to break the loop if we found the contact details.
                if (delete==otherContactDeleted||delete==firstContactDeleted)
                {
                    break;
                }
                //save the node we checked for deleteing after
                saveNode = checkNode;
                //make the node we check the node after
                checkNode = checkNode->next;
                //make the contact node number plus one
                contactNumber++;
            }
            //end of while loop

            //if loop for the last node if the first contact delete is not on
            if (delete != firstContactDeleted&&delete !=otherContactDeleted)
            {
                //check for the user contact in the list
                if (strcmp(checkNode->firstName, Name) == equal &&
                    strcmp(checkNode->lastName, familyName) == equal)
                {
                    //if it is make the delete as the other contact delete
                    delete = otherContactDeleted;
                }
            }
        }
        //end of else option
    }
    //end of if loop

    //if the first contact is list is deleted
    if (delete == firstContactDeleted)
    {
        //print sure message to the user and scan it
        printf("Are you sure? (y/n) ");
        getchar();
        scanf("%c", &sureAnswer);
        //check the user answer
        if (sureAnswer == 'y' || sureAnswer == 'Y')
        {
            //step 1-make the first node as the second node
            phoneBook[firstLetter] = checkNode->next;

            /*free the first node memory
            (struct memory, first name,last name, phonenumber)*/

            free(checkNode->firstName);
            free(checkNode->lastName);
            free(checkNode->phoneNum);
            free(checkNode);
            //print successful message
            printf("The contact has been deleted successfully!\n");
            //return to the main
            return;
        }
        //if the answer for the sure message is no, cancel the deletion
        else
        {
            printf("The deletion of the contact has been canceled.\n");
            return;
        }
    }
    //if other part in the list is deleted
    else if (delete ==otherContactDeleted)
    {
        //print sure message to the user and scan it
        printf("Are you sure? (y/n) ");
        getchar();
        scanf("%c", &sureAnswer);
        //check the user answer
        if (sureAnswer == 'y' || sureAnswer == 'Y')
        {
            //store the remain list in node
            checkNode1 = checkNode->next;
            /*free the deleted node memory
            (struct memory, first name,last name, phonenumber)*/
            free(checkNode->firstName);
            free(checkNode->lastName);
            free(checkNode->phoneNum);
            free(checkNode);
            //link the list again with the save node we saved before
            saveNode->next = checkNode1;
            //print successful message
            printf("The contact has been deleted successfully!\n");
            //return to the main
            return;
        }
        //if the answer for the sure message is no, cancel the deletion
        else
        {
            printf("The deletion of the contact has been canceled.\n");
            return;
        }
    }
    //end of if for the delete other parts

    /*if the user input didnt found in the
     search proccess print fail message to
     the user cause there is no contact
     with this name*/
     
    else
    {
        printf("The deletion of the contact has failed!\n");
        return;
    }
}

/************************************************************************
 * function name: findContactByName  *
 * The Input: the function get an contact pointers array and the size of it *
 * The output: none*
 * The Function operation: the function ask's the user for numer
 he want to find in the array and the function search for it
 and print the name of the contact and his number to the
 user *
 *************************************************************************/

void findContactByNumber(Contact *phoneBook[], int size)
{
    //10 is the max lengath of the contact details+ '\0'
    int maxInputLength = 11;
    int equal=0;
    int firstChar=0;
    char phoneNumber[maxInputLength];
    Contact *checkNode;
    Contact *checkNode1;
    int firstLetter;
    int i = 0;
    //ask the user for the phone number he want to find and scan it
    printf("Enter a phone number: ");
    scanf("%s", phoneNumber);
    checkNode = phoneBook[firstChar];
    //for loop to scan the whole array
    for (i = 0; i < size; i++)
    {
        //make the check node as the first node according the first letter
        checkNode = phoneBook[i];
        //start search if the node is not empty
        if (checkNode != NULL)
        {
           //check while the list has only one part(the next pointer is empty)
            if (checkNode->next == NULL)
            {

                /*compare the phone number in the
                 node and the phone number from the user*/

                if (strcmp(checkNode->phoneNum, phoneNumber) == equal)
                {

                    /*print the right contact the user
                     asked the function to search*/

                    printf("The following contact was found: %s %s %s\n",
                     checkNode->firstName, checkNode->lastName,
                      checkNode->phoneNum);
                    return;
                }
            }
            /*check while the list has more
            than one part(the next pointer is not empty)*/
            else
            {
               //while loop when the next pointer is not empty
                while (checkNode->next != NULL)
                {
                    /*compare the phone number in the
                     node and the phone number from the user*/
                    if (strcmp(checkNode->phoneNum, phoneNumber) == equal)
                    {
                    
                        /*print the right contact the user
                         asked the function to search*/
                         
                        printf("The following contact was found: %s %s %s\n",
                         checkNode->firstName, checkNode->lastName,
                          checkNode->phoneNum);
                        return;
                    }
                    
                    /*if we didnt found the number go to the next
                     node with compare the check node to his next pointer*/
                     
                    checkNode = checkNode->next;
                }

                /*check the last node while the next pointer
                 is empty(the while loop when it is not empty
                  and this when it is the last part)*/

                if (strcmp(checkNode->phoneNum, phoneNumber) == equal)
                {
                    printf("The following contact was found: %s %s %s\n",
                     checkNode->firstName, checkNode->lastName,
                      checkNode->phoneNum);
                    return;
                }
            }
            //end of else option
        }
        //end of if for when the part in the list is not empty
    }
    //end of for loop

    /*if we finished the search and didnt found-
     print that there is no such number in the phone book*/

    printf("No contact with a phone number %s was found in the phone book\n",
     phoneNumber);
}
//end of the function

/************************************************************************
 * function name: findContactByName  *
 * The Input: the function get an contact pointers array and the size of it *
 * The output: none *
 * The Function operation: get name from the user to search in the
 phonebook then realize the first last name char and search in
 the right place in the array according to the first letter
 then print the contact to the user if it is in the
 phonebook  *
 *************************************************************************/

void findContactByName(Contact *phoneBook[], int size)
{
    //10 is the max lengath of the contact details+ '\0'
    int maxInputLength = 11;
    int equal=0;
    int firstChar=0;
    char name[maxInputLength];
    char familyName[maxInputLength];
    Contact *checkNode;
    Contact *checkNode1;
    int firstLetter;
    int i = 0;
    int asciiGapBetweenLetterAndNumber = 65;
    printf("Enter a contact name (<first name> <last name>): ");
    scanf("%s", name);
    scanf("%s", familyName);
    firstLetter = (int)familyName[firstChar]-asciiGapBetweenLetterAndNumber;
    checkNode = phoneBook[firstLetter];
    //start search if the node is not empty
    if (checkNode != NULL)
    {
        //check while the list has only one part(the next pointer is empty)
        if (checkNode->next == NULL)
        {

            /*compare the contact name and last name
             in the node and the names from the user*/

            if (strcmp(checkNode->firstName, name) == equal &&
             strcmp(checkNode->lastName, familyName) == equal)
            {
            
              /*print the right contact
               the user asked the function to search*/
               
                printf("The following contact was found: %s %s %s\n",
                 checkNode->firstName, checkNode->lastName,
                  checkNode->phoneNum);
                return;
            }
        }
        //end of if loop

        /*check while the list has more than
         one part(the next pointer is not empty)*/

        else
        {
            //while loop when the next pointer is not empty
            while (checkNode->next != NULL)
            {

                /*compare the contact name and last name
                 in the node and the names from the user*/

                if (strcmp(checkNode->firstName, name) == equal
                 && strcmp(checkNode->lastName, familyName) == equal)
                {
                
                    /*print the right contact the
                     user asked the function to search*/
                     
                    printf("The following contact was found: %s %s %s\n",
                     checkNode->firstName, checkNode->lastName,
                      checkNode->phoneNum);
                    return;
                }

                /*if we didnt found the number go to the next
                 node with compare the check node to his next pointer*/

                checkNode = checkNode->next;
            }
            //end of while loop

            /*check the last node while the next pointer
            is empty(the while loop when it is not empty
            and this when it is the last part)*/

            if (strcmp(checkNode->firstName, name) == equal&&
             strcmp(checkNode->lastName, familyName) == equal)
            {
            
              /*print the right contact the user
               asked the function to search*/
               
                printf("The following contact was found: %s %s %s\n",
                 checkNode->firstName, checkNode->lastName,
                  checkNode->phoneNum);
                return;
            }
        }
        //end of else
    }
    //end of if loop

    /*if we finished the search and didnt found-
     print that we dont have this names in the phone book*/

    printf("No contact with a name %s %s was found in the phone book\n",
     name, familyName);
}
//end of function

/************************************************************************
 * function name: updatePhoneNumber  *
 * The Input: the function get an contact pointers array and the size of it *
 * The output: none *
 * The Function operation: the function gets contact that the
 user want to update than he print it to the user
 and gets from him new number from this contact and
 if it doesnt appear in the phonebook for
 other contact update the number for the contact the user
 asked for *
 *************************************************************************/

void updatePhoneNumber(Contact *phoneBook[], int size)
{
    //10 is the max lengath of the contact details+ '\0'
    int maxInputLength = 11;
    int equal=0;
    int firstChar=0;
    char name[maxInputLength];
    char familyName[maxInputLength];
    char phoneNumber[maxInputLength];
    Contact *checkNode;
    Contact *checkNode2;
    int firstLetter;
    int on=1;
    int i = 0;
    int update = 0;
    int asciiGapBetweenLetterAndNumber = 65;
    printf("Enter a contact name (<first name> <last name>): ");
    scanf("%s", name);
    scanf("%s", familyName);

    //step 1- search the contact in the list

    //realize the first family name letter for the user input
    firstLetter = (int)familyName[firstChar]- asciiGapBetweenLetterAndNumber;
    //make the check node as the right place accrding to the use input
    checkNode = phoneBook[firstLetter];
    //search for the user contact if the node is not empty
    if (checkNode != NULL)
    {
        //check while the list has only one part(the next pointer is empty)
        if (checkNode->next == NULL)
        {

            /*compare the contact name and last name
             in the node and the names from the user*/

            if (strcmp(checkNode->firstName, name) == equal&&
             strcmp(checkNode->lastName, familyName) == equal)
            {
                //print the contact the user asked for
                printf("The following contact was found: %s %s %s\n",
                 checkNode->firstName, checkNode->lastName,
                  checkNode->phoneNum);
                //make the update on
                update = on;
            }
        }

        /*check while the list has more than
         one part(the next pointer is not empty)*/

        else
        {
            //while loop when the next pointer is not empty
            while (checkNode->next != NULL)
            {

                /*compare the contact name and last name
                in the node and the names from the user*/

                if (strcmp(checkNode->firstName, name) == equal&&
                strcmp(checkNode->lastName, familyName)==equal)
                {
                    //print the contact the user asked for
                    printf("The following contact was found: %s %s %s\n",
                     checkNode->firstName, checkNode->lastName,
                     checkNode->phoneNum);
                    //make the update on
                    update = on;
                    break;
                }
                /*if we didnt found the contact go to the
                 next node with compare the check node to his next pointer*/
                checkNode = checkNode->next;
            }
            //end of while loop

            /*check the last node while the next pointer
            is empty(the while loop when it is not empty
            and this when it is the last part)*/

            if (strcmp(checkNode->firstName, name) == equal&&
            strcmp(checkNode->lastName, familyName)==equal)
            {
                //print the contact the user asked for
                printf("The following contact was found: %s %s %s\n",
                 checkNode->firstName, checkNode->lastName,
                  checkNode->phoneNum);
                //make the update on
                update = on;
            }
        }
        //end of else option
    }
    //end of if option


    /*step 2- if we found the contact
     check if the number appear in the list
     and update the contact*/

    if (update == on)
    {
        //ask the user for the new phone number
        printf("Enter the new phone number: ");
        scanf("%s", phoneNumber);
        //check if the number is in the list alredy
        for (i = 0; i < size; i++)
        {
            //make the check node as the first node for the letter
            checkNode2 = phoneBook[i];
            //search for the user contact if the node is not empty
            if (checkNode2 != NULL)
            {

                /*check while the list has only one part
                (the next pointer is empty)*/

                if (checkNode2->next == NULL)
                {

                    /*compare the phone number in the node
                     and the phone number from the user*/

                    if (strcmp(checkNode2->phoneNum, phoneNumber) == equal)
                    {
                        //if we have the number- print fail message
                        printf("The update of the contact has failed,"
                         " since the phone number %s already exists!\n",
                          checkNode2->phoneNum);
                        return;
                    }
                }

                /*check while the list has only one part
                (the next pointer is empty)*/

                else
                {
                    //while loop when the next pointer is not empty
                    while (checkNode2->next != NULL)
                    {

                        /*compare the phone number in the node
                         and the phone number from the user*/

                        if (strcmp(checkNode2->phoneNum, phoneNumber) ==equal)
                        {
                            //if we have the number- print fail message
                            printf("The update of the contact has failed,"
                            " since the phone number %s already exists!\n",
                            checkNode2->phoneNum);
                            return;
                        }

                        /*if we didnt found the number go to the next node
                        -compare the check node to his next pointer*/

                        checkNode2 = checkNode2->next;
                    }

                    /*check the last node while the next pointer
                     is empty(the while loop when it is not empty
                    and this when it is the last part)*/

                    if (strcmp(checkNode2->phoneNum, phoneNumber) ==equal)
                    {
                        //if we have the number- print fail message
                        printf("The update of the contact has failed, "
                        "since the phone number %s already exists!\n",
                        checkNode2->phoneNum);
                        return;
                    }
                }
                //end of else option
            }
            //end of if loop
        }
        //end of for loop

        /*if we didnt found the number in the list-
        update the number and print successful message*/

        strcpy(checkNode->phoneNum, phoneNumber);
        printf("The contact has been updated successfully!\n");
    }
    //end of if loop
    
    //if the update was not turn on print that we didnt found the contact
    else printf("No contact with a name %s %s was found in the phone book\n",
     name, familyName);
}
//end of function

/************************************************************************
 * function name: printPhoneBook  *
 * The Input: the function get an contact pointers array and the size of it *
 * The output: none *
 * The Function operation: the function print all the phone
 * book according to the family name letter
 *************************************************************************/

void printPhoneBook(Contact *phoneBook[], int size)
{
    int i = 0;
    Contact *checkNode;
    //for loop to print all the parts of the array
    for (i = 0; i < size; i++)
    {
        //make the check node as the first node according the first letter
        checkNode = phoneBook[i];
        //print if the letter in the list is not empty
        if (checkNode != NULL)
        {
            //print when it has only one node(next pointer is empty)
            if (checkNode->next == NULL)
            {
                //print the contact according to the right format
                printf("%-10s %-10s %-10s\n", checkNode->firstName,
                 checkNode->lastName, checkNode->phoneNum);
            }

            /*print if the letter has more than one node
            (next pointer is not empty)*/

            else
            {
                //while loop when the next pointer is not empty
                while (checkNode->next != NULL)
                {
                    //print the contact according to the right format
                    printf("%-10s %-10s %-10s\n", checkNode->firstName,
                    checkNode->lastName, checkNode->phoneNum);
                    checkNode = checkNode->next;
                }

                /*print the last node while the next pointer
                is empty(the while loop when it is not empty
                and this when it is the last part)*/

                printf("%-10s %-10s %-10s\n", checkNode->firstName,
                checkNode->lastName, checkNode->phoneNum);
            }
        }
        //end of if option
    }
    //end of for loop
}
//end of function

/************************************************************************
 * function name: bye *
 * The Input: the function get an contact pointers array and the size of it*
 * The output: the function has no output *
 * The Function operation: the function takes the array
 and free all the memory we
 allocated before then it prints bye! *
 *************************************************************************/

void bye(Contact *phoneBook[], int size)
{
    Contact *checkNode;
    Contact *checkNode2;
    int i = 0;
    for (i = 0; i < size; i++)
    {
        // make the check node as the place in the array contact pointer
        checkNode = phoneBook[i];
        // if check node is not NULL start the free proccess
        if (checkNode != NULL)
        {
            // if the next is empty we have one contact in the array place
            if (checkNode->next == NULL)
            {
                //free the name memory
                free(checkNode->firstName);
                //free the last name memory
                free(checkNode->lastName);
                //free the phone number memory
                free(checkNode->phoneNum);
                //free the node memory
                free(checkNode);
            }
            // if the next is not empty we have one contact in the array place
            else
            {
                //while loop when the next pointer is not empty
                while (checkNode->next != NULL)
                {
                    //store the current node in another node
                    checkNode2 = checkNode;
                    //make the current node as the next node
                    checkNode = checkNode->next;
                    //free the current first name node memory
                    free(checkNode2->firstName);
                    //free the current last name node memory
                    free(checkNode2->lastName);
                    //free the current phone number node memory
                    free(checkNode2->phoneNum);
                    //free the node memory
                    free(checkNode2);
                }
                //end of while loop

                /*free the last node when his next pointer is empty
                (while loop when the next is not empty and this
                 commands when it is the last node
                  and the next pointer is empty)*/

                //store the current node in another node
                checkNode2 = checkNode;
                //free the current first name node memory
                free(checkNode2->firstName);
                //free the current last name node memory
                free(checkNode2->lastName);
                 //free the current phone number node memory
                free(checkNode2->phoneNum);
                //free the node memory
                free(checkNode2);
            }
            //end of while loop
        }
        //end of else option
    }
    //end of if option to free the memory

    //print the Bye! message
    printf("Bye!");
}
//end of function