#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include "contact.h"
#define RED  "\033[1;31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

int search_contacts(AddressBook *addressbook)
{
    int option,flag=0,found=0;
    char inputname[20];
    char inputphone[20];
    char inputmail[20];

     printf("Enter the option: ");
    scanf("%d",&option);
    getchar();
    if(option==1)
    {
        flag=1;
        printf("Enter the name to be searched: ");
        scanf("%[^\n]",inputname);

        // To check name in the addressbook contact details
        for(int i=0; i<addressbook->contact_count; i++)
        {
            if(strncmp(addressbook->contact_details[i].Name,inputname,strlen(inputname))==0)
            {
                 printf("------------------------------------------------------------\n");   
                printf("%d. %s \t%s \t%s\n", i,addressbook->contact_details[i].Name,addressbook->contact_details[i].Mobile_number,addressbook->contact_details[i].Mail_ID);
                found = 1;
            }  
        }      
         printf("------------------------------------------------------------\n");     
    }

    else if(option==2)
    {
        flag=1;
        printf("Enter the phone number to be searched: ");
        scanf("%s", inputphone);

        // To check number in the addressbook contact details
         for(int i=0; i<addressbook->contact_count; i++)
        {
            if(strncmp(addressbook->contact_details[i].Mobile_number,inputphone,strlen(inputphone))==0)
            {
                 printf("------------------------------------------------------------\n");   
                printf("%d. %s \t%s \t%s\n", i,addressbook->contact_details[i].Name,addressbook->contact_details[i].Mobile_number,addressbook->contact_details[i].Mail_ID);
                found = 1;
            }
        }
         printf("------------------------------------------------------------\n");   
    }

    else if(option==3)
    {
        flag=1;
        printf("Enter the mail to be searched: ");
        scanf("%s", inputmail);

        // To check mail in the addressbook contact details
        for(int i=0; i<addressbook->contact_count; i++)
        {
            if(strncmp(addressbook->contact_details[i].Mail_ID,inputmail,strlen(inputmail)) == 0)
            {
                 printf("------------------------------------------------------------\n");   
                printf("%d. %s \t%s \t%s\n", i,addressbook->contact_details[i].Name,addressbook->contact_details[i].Mobile_number,addressbook->contact_details[i].Mail_ID);
                found = 1;
            }   
        }
         printf("------------------------------------------------------------\n");   
    }

    else if(option==4)
    {
        return 0;
    }

    if(flag == 0 || addressbook->contact_count == 0)
    {
        printf(RED "Data not found\n" RESET);
        return -1;
    }

    if(found == 0)
    {
        printf(RED "Contact not found\n" RESET);
        return -1;
    }

    return 1; 
}
