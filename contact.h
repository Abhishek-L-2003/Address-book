#ifndef CONTACT_H
#define CONTACT_H

#define MAX_CONTACTS 100

typedef struct Contact_data
{
    char Name[32];
    char Mobile_number[11];
    char Mail_ID[35];
} Contacts;

typedef struct AddressBook_Data
{
    Contacts contact_details[100];
    int contact_count;
} AddressBook;

int validate_name(char name[]);
int validate_phone(char phone[]);
int validate_mail(char mail[]);

/* Function declarations */
// void init_intitalization(AddressBook *);
int create_contact(AddressBook *addressbook);
int list_contacts(AddressBook *addressbook,int sortCriteria);
int search_contacts(AddressBook *addressbook);
int edit_contact(AddressBook *addressbook);
int delete_contact(AddressBook *addressbook);
int save_contacts(AddressBook *addressbook);
void saveContactsToFile(AddressBook *addressbook);
void loadContactsFromFile(AddressBook *addressbook);

#endif // CONTACT_H
       // CONTACT_H