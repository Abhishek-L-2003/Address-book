#include <stdio.h>
#include<string.h>
#include "file.h"
#include "contact.h"


void saveContactsToFile(AddressBook *addressbook)
{
    FILE *ptr;
    if((ptr = fopen("contact.txt", "w")) == NULL)   // Open file for writing                       
    {
        printf("Error opening file\n");
        return;
    }

    fprintf(ptr, "%d\n", addressbook->contact_count); 

    
    Contacts temp[100];
    for (int i = 0; i < addressbook->contact_count; i++) 
    {
        temp[i] = addressbook->contact_details[i];
    }

    // Sort contacts by Name before saving
    for (int i = 0; i < addressbook->contact_count - 1; i++) 
    {
        for (int j = 0; j < addressbook->contact_count - i - 1; j++)
         {
            if (strcmp(temp[j].Name, temp[j+1].Name) > 0) 
            {
                Contacts t = temp[j];
                temp[j] = temp[j+1];    
                temp[j+1] = t;
            }
        }
    }

    // Save sorted contacts into context.txt file 
    for (int i = 0; i < addressbook->contact_count; i++) 
    {
        fprintf(ptr, "%s,%s,%s\n",temp[i].Name,temp[i].Mobile_number,temp[i].Mail_ID);
    }

    fclose(ptr); // Close file after writing
}



void loadContactsFromFile(AddressBook *addressbook) 
{
    FILE *fptr;
    if((fptr = fopen("contact.txt", "r")) == NULL)  // Open file for reading               
    {
        addressbook->contact_count = 0;       // Start with 0 contacts
        return;
    }

    int count;
    // Read contact count from first line
    if (fscanf(fptr, "%d\n", &count) != 1)
    {
        printf("Error: invalid file format\n");
        fclose(fptr);
        addressbook->contact_count = 0;
        return;
    }

    addressbook->contact_count = count;  // Save number of contacts

    for (int i = 0; i < count; i++)
    {
        fscanf(fptr, "%[^,],%[^,],%s\n",addressbook->contact_details[i].Name,addressbook->contact_details[i].Mobile_number,addressbook->contact_details[i].Mail_ID);
    }

    fclose(fptr); // Close file after reading
}
