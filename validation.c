#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include"contact.h"
#define RED  "\033[1;31m"
#define RESET "\033[0m"


int validate_name(char *name)
{
    for(int i=0;name[i]!='\0';i++)
    {
        if(!(isalpha(name[i]) || name[i]==' ')) // if it is not alpha or space
        {
            return 1;
        }
    }
    return 0;
}

int validate_phone(char *phone)
{
   int len=strlen(phone);
   
   if(len!=10)
   {
    return 1;
   }

   for(int i=0;i<len;i++)
   {
    if(phone[0]<'6')
        {
        printf(RED "First number should be in the range of '6' to '9'\n" RESET);
        return 1;
        }
    else if(!isdigit(phone[i]) || phone[0]<'6' || phone[0]>'9') //if number is less than 6 or greater than 9
    {
        return 1;
    }
   }
   return 0;

}


int validate_mail(char *mail)
{
    for(int i=0;mail[i]!='\0';i++)
    {
        if(isupper(mail[i]) || mail[i]==' ') // if alpha is uppercase or space
        {            
            return 1;
        }
    }

    int i=0,a;
    while(mail[i]!='@') // To find the "@"" position
    {
        i++;
    }
    a=i;

    int j=0,b;
    while(mail[j]!='.') //To find the "." position
    {
        j++;
    }
    b=j;

    for(int i=a+1;i<b;i++)
    {
        if(isdigit(mail[i])) // if any digits between "@" and "." 
        {
            return 1;
        }
    }

    for(int i=b+1;mail[i]!='\0';i++)
    {
        if(!isalpha(mail[i])) // if it is not alpha after "."
        return 1;
    }

    int x=b;
    if(mail[x+1]!='c' || mail[x+2]!='o' || mail[x+3]!='m') // after "." com shiuld present 
    {
    return 1;
    }
    
    return 0;

}