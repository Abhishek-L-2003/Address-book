#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include "contact.h"
#define RED  "\033[1;31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"
#define BCYAN "\033[96m"

int list_contacts(AddressBook *addressbook,int sortCriteria)
{
    int sort;
    if (addressbook->contact_count == 0) 
    {
        printf(RED "No contacts available.\n" RESET); // No contacts in address book
        return 0;
    }

    printf("List contacts by:\n");
    printf("1. Name\n2. Phone\n3. Email\n");
    printf("enter option:");
    scanf("%d", &sort);

    // Copy contacts to a temporary array 
    Contacts temp[100];
    for (int i = 0; i < addressbook->contact_count; i++) 
    {
        temp[i] = addressbook->contact_details[i];
    }

    // Bubble sort
    for (int i = 0; i < addressbook->contact_count - 1; i++) 
    {
        for (int j = 0; j < addressbook->contact_count - i - 1; j++) 
        {
            int cmp = 0;

            // Compare by name
            if (sort == 1) 
            {
                cmp = strcmp(temp[j].Name, temp[j + 1].Name);
            } 
            // Compare by phone
            else if (sort == 2) 
            {
                cmp = strcmp(temp[j].Mobile_number, temp[j + 1].Mobile_number);
            } 
            // Compare by email
            else if (sort == 3) 
            {
                cmp = strcmp(temp[j].Mail_ID, temp[j + 1].Mail_ID);
            }

            // Swap contacts if out of order
            if (cmp > 0) 
            {
                Contacts t = temp[j];
                temp[j] = temp[j + 1];
                temp[j + 1] = t;
            }
        }
    }

    // Display sorted contacts
    printf("\nContacts:\n");
    for (int i = 0; i < addressbook->contact_count; i++) 
    {
        printf(BCYAN "%d. %s \t%s \t%s\n" RESET, i + 1,temp[i].Name,temp[i].Mobile_number,temp[i].Mail_ID);
    }
}
