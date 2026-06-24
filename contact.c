/*
Project     : Addressbook 
Name        : Abhishek L
Date        : 25/01/2026
Description : Addressbook contains all the contact details like Name Phone Email
Sample i/p  : 1.Add contact
              2.search contact
              3.Edit contact
              4.Delete contact
              5.Display contact
              6.Save contact
              7.Exit
              Enter the option : 1
              Enter the Details:
              Enter the Name:Arki
              Enter the Phone Number:8618388639
              Enter the mail.id:arkeshumesh07@gmail.com
              --------------------------------------
              Do you want to save [Yes] or [No]: Yes
              --------------------------------------
              Contact saved successfully

Sample o\p  : Arki,8618388639,arkiumesh07@gmail.com

*/

#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include "contact.h"
#define RED  "\033[1;31m"
#define GREEN "\033[32m"
#define BBLUE "\033[94m"
#define BCYAN "\033[96m"
#define BMAGENTA "\033[95m"
#define RESET "\033[0m"

int create_contact(AddressBook *addressbook)
{
    char name[20];
    char phone[20];
    char mail[20];
    char str[10];

    printf("Enter the Details:\n");
    nam :
    printf("Enter the Name:");
    getchar();
    scanf("%[^\n]",name);

    // check entered name is in exisitence or not
    for(int i=0; i<addressbook->contact_count; i++)
        {
            if(strcmp(addressbook->contact_details[i].Name,name)==0)
            {
                printf("--------------------------------------\n");   
                printf(RED "Name is already in existence\n" RESET);
                printf("--------------------------------------\n");
                goto nam;
            }
        }

    if(validate_name(name)) // validation call
    {
        printf(RED "Invalid Name\n" RESET);
        goto nam;
    }
    num :
    printf("Enter the Phone Number:");
    getchar();
    scanf("%s",phone);

    //check entered phone number in exisistence or not
    for(int i=0; i<addressbook->contact_count; i++)
        {
            if(strcmp(addressbook->contact_details[i].Mobile_number,phone)==0)
            {
                printf("--------------------------------------\n");
                printf(RED "Phone number is already in exisistance\n" RESET);
                printf("--------------------------------------\n");
                goto num;
            }
        }

    if(validate_phone(phone)) // validation call
    {
        printf(RED "phone number is invalid\n" RESET);
        goto num;
    }

    mai :
    printf("Enter the mail.id:");
    getchar();
    scanf("%[^\n]",mail);
    getchar();

    // logic to check mail is in exisistence or not
    for(int i=0; i<addressbook->contact_count; i++)
        {
            if(strcmp(addressbook->contact_details[i].Mail_ID,mail)==0) 
            {
                printf("--------------------------------------\n");
                printf(RED "Mail is already in exisistance\n" RESET);
                printf("--------------------------------------\n");
                goto mai;
            }
        }

    if(validate_mail(mail)) // validation call
    {
        printf(RED "Invalid mail\n" RESET);
        goto mai;
    }

    // copying Data to the addressbook contact details
    strcpy(addressbook->contact_details[addressbook->contact_count].Name,name);
    strcpy(addressbook->contact_details[addressbook->contact_count].Mobile_number,phone);
    strcpy(addressbook->contact_details[addressbook->contact_count].Mail_ID,mail);
    printf("--------------------------------------\n");

    addressbook->contact_count++;
    printf(BBLUE"Do you want to save [Yes] or [No]: " RESET);
    scanf("%s",str);
    if(strcmp(str, "Yes")==0)
    {
         saveContactsToFile(addressbook); // save to the contact.txt file
    }
    printf("--------------------------------------\n");
    printf(GREEN "Contact saved successfully\n" RESET);
}