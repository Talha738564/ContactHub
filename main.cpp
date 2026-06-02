#include<iostream>
#include"contacts.h"
using namespace std;
void showmenu();

int choice;
int main()
{   do
    {
        showmenu();

    }
    while(choice!=6);
    
    
    
}
void showmenu()
{
    // Showing the Menu to the user that what he/she can do
    cout<<"<<<<<<<<<<   CONTACT HUB  >>>>>>>>>>>>> "<<endl;
    cout<<"1. Add Contact"<<endl;
    cout<<"2. View Contacts"<<endl;
    cout<<"3. Search Contact"<<endl;
    cout<<"4. Update Contact"<<endl;
    cout<<"5. Delete Contact"<<endl;
    cout<<"6. Exit"<<endl;

    // User will select from the options that what he want to  do 
    
    cout<<"Please Enter Your Choice:";
    cin>>choice;
    // Loop for asking another option
    if(choice==1)
    {
        addContact();
    }

    if(choice==2)
    {
        viewContacts();
    }
    if(choice==3)
    {
        searchContact();
    }
    if(choice==4)
    {
        modifyContact();
    }
    if(choice==5)
    {
        deleteContact();
    }
    if(choice==6)
    {
        cout << "Exiting Contact Hub... Goodbye!" << endl;
    }
    

}

    
    


    
            


    
    
    
    