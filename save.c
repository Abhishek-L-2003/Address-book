#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include "contact.h"

int save_contacts(AddressBook *addressbook)
{
   saveContactsToFile(addressbook);   // Save contacts to file
   exit(EXIT_SUCCESS);
}