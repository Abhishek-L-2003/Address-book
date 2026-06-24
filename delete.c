#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include "contact.h"
#define RED  "\033[1;31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

int delete_contact(AddressBook *addressbook)
{
   
    int ret = search_contacts(addressbook); // First search for the contact
    if(ret == -1)
    {
        return 0;
    }

    int i;
    printf("Enter the index of the contact you want to delete: ");
    scanf("%d", &i);
    getchar();

    // Check for valid index
    if(i < 0 || i >= addressbook->contact_count)
    {
        printf(RED "Invalid index\n" RESET);
        return 0;
    }

    for(int j=i; j<addressbook->contact_count-1; j++)
    {
        addressbook->contact_details[j] = addressbook->contact_details[j+1];
    }
    addressbook->contact_count--; 
    
    saveContactsToFile(addressbook);   
    printf("------------------------------------------------------------\n");   
    printf(GREEN "Contact deleted successfully\n" RESET);
}
