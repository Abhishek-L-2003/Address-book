#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include "contact.h"
#define RED  "\033[1;31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"
#define BBLUE "\033[94m"
#define BCYAN "\033[96m"
#define BMAGENTA "\033[95m"

int edit_contact(AddressBook *addressbook)
{
   
    int ret = search_contacts(addressbook); // First search for the contact
    if(ret == -1)
    {
        return 0;
    }

    int i, input1;
    char str[10];
    char name1[50], phone1[20], mail1[50];
    printf("Enter the index of the contact you want to edit: ");
    scanf("%d", &i);

    // Check for valid index
    if(i < 0 || i >= addressbook->contact_count)
    {
        printf(RED "Invalid index\n" RESET);
        return 0;
    }

    printf("What do you want to edit:\n1.name\n2.phonenumber\n3.email\n");
    scanf("%d", &input1);
    getchar();

    // Edit Name
    if(input1 == 1)
    {
        printf("Enter the new name: ");
        scanf("%[^\n]", name1);

        // logic to check name is in exisistence or not
        for(int i=0; i<addressbook->contact_count; i++)
        {
            if(strcmp(addressbook->contact_details[i].Name,name1)==0)
            {
                printf("--------------------------------------\n");
                printf(RED "Name is already in exisistence\n" RESET);
                printf("--------------------------------------\n");
                return 0;
            }
        }

        if(validate_name(name1) == 0) // validation call
        {
            strcpy(addressbook->contact_details[i].Name, name1);
            printf(BBLUE "Do you want to save [Yes] or [No]: " RESET);
            scanf("%s",str);
            if(strcmp(str,"Yes")==0)
            {
                saveContactsToFile(addressbook);
            }
        }
        else
        {
            printf(RED "Edit failed, invalid name\n" RESET);
            return 0;
        }
    }
    // Edit Phone
    else if(input1 == 2)
    {
        printf("Enter the new phone number: ");
        scanf("%s", phone1);

        // logic to check phonenumber is in exisistence or not
        for(int i=0; i<addressbook->contact_count; i++)
        {
            if(strcmp(addressbook->contact_details[i].Mobile_number,phone1)==0)
            {
                printf("--------------------------------------\n");
                printf(RED "Phone number is already in exisistence\n" RESET);
                printf("--------------------------------------\n");
                return 0;
            }
        }

        if(validate_phone(phone1) == 0) // validation call
        {
            strcpy(addressbook->contact_details[i].Mobile_number, phone1);
            printf(BBLUE "Do you want to save [Yes] or [No]: " RESET);
            scanf("%s",str);
            if(strcmp(str,"Yes")==0)
            {
                saveContactsToFile(addressbook);
            }
        }
        else
        {
            printf(RED "Edit failed, invalid phone number\n" RESET);
            return 0;
        }
    }
    // Edit Email
    else if(input1 == 3)
    {

        printf("Enter the new email: ");
        scanf("%s", mail1);

        // logic to check mail is in exisistence or not
        for(int i=0; i<addressbook->contact_count; i++)
        {
            if(strcmp(addressbook->contact_details[i].Mail_ID,mail1)==0)
            {
                printf("--------------------------------------\n");
                printf(RED "Mail is already in exisistence\n" RESET);
                printf("--------------------------------------\n");
                return 0;
            }
        }

        if(validate_mail(mail1) == 0) // validation call
        {
            strcpy(addressbook->contact_details[i].Mail_ID, mail1);
            printf(BBLUE"Do you want to save [Yes] or [No]: " RESET);
            scanf("%s",str);
            if(strcmp(str,"Yes")==0)
            {
                saveContactsToFile(addressbook);
            }
        }
        else
        {
            printf(RED "Edit failed, invalid email\n" RESET);
            return 0;
        }
    }
    else
    {
        printf(RED "Invalid choice\n" RESET);
        return 0;
    }
    printf("--------------------------------------\n");
    printf(GREEN "Contact updated successfully\n" RESET);
   
    return 1;
}
