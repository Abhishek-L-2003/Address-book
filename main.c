#include <stdio.h>
#include "contact.h"
#define RED  "\033[1;31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"
/* Structure declaration */

int main()
{
    /* Variable and structre defintion */
    int option;
    AddressBook addressbook;
    addressbook.contact_count = 0;
    loadContactsFromFile(&addressbook);

    while (1)
    {
        printf("\nAddress book menu\n"); /* Give a prompt message for a user */
        printf("1.Add contact\n2.search contact\n3.Edit contact\n4.Delete contact\n5.Display contact\n6.Save contact\n7.Exit\n");
        printf("Enter the option : ");
        scanf("%d", &option);

        switch (option) /* Based on choosed option */
        {
        case 1:
        {
            create_contact(&addressbook);
            break;
        }

        case 2:
        {
            printf("Search Contact menu :\n1.Search by Name:\n2.Search by Phone:\n3.Search by Mail:\n4.Exit\n"); /* Providing menu */
            search_contacts(&addressbook);
            break;
        }
        case 3:
            printf("Edit Contact menu : \n1.Name \n2.Mobile number\n3.Mail ID\n4.Exit\n"); /* Providing menu */
            getchar();
            edit_contact(&addressbook);
            break;

        case 4:
        {
            printf("Delete Contact menu : \n1.Search by Name \n2.Search by Mobile number\n3.Search by Mail ID\n4.Exit\n"); /* Providing menu */

            delete_contact(&addressbook);
            break;
        }
        case 5:
        {
            printf("List Contacts:\n");
            list_contacts(&addressbook,1);
            break;
        }

        case 6:
            printf(GREEN "Saving contacts\n" RESET);
            save_contacts(&addressbook);
            break;

        case 7:
            printf(GREEN "INFO : Save and Exit...\n" RESET);
            return 0;

        default:
            printf(RED "Invalid option \n" RESET);
            break;
        }
    }
    return 0;
}
