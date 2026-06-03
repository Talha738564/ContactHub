#include <iostream>
#include <fstream>
#include<cstdio>// INcluding it to use remove and rename file feature
#include "contacts.h"

using namespace std;

void addContact()
{
    string name,phoneNumber,Email,Address;  

    ofstream fout;
    fout.open("contacts.txt",ios::app);
    // Checking the error in opening a file 
    if(!(fout.fail())) 
    {
        // Using getline instead of the insertion ">>" operator to read the full input including the spaces
        cout << "Please Enter your Name: ";
        cin.ignore();
        getline(cin, name);
        
        cout << "Please Enter your Phone Number: ";
        getline(cin, phoneNumber);
        
        cout << "Please Enter your Email Address: ";
        getline(cin, Email);

        cout << "Please Enter your Home Address: ";
        getline(cin, Address);

        fout << "Name    : " << name << endl;
        fout << "Phone   : " << phoneNumber << endl;
        fout << "Email   : " << Email << endl;
        fout << "Address : " << Address << endl;
        fout << "--------------------------------" << endl;


        cout << "Contact added successfully!"<<endl;
        


    }
    else{
        cout<<" There is some error in writing to the file ";
    }
    fout.close();
}
void viewContacts()
{
    string data;
    

    ifstream fin;
    fin.open("contacts.txt");
    if(!(fin.fail()))
    {
        // Check if file is empty
        // here the fin.peek() will finds no character to look at and returns EOF
        if(fin.peek() == EOF)
        {
            cout << "No contacts found." << endl;
            fin.close();
            return;
        }


        while(getline(fin,data))
        {
        
            cout<<data<<endl;
    
            
    
        }
        
        fin.close();
    }
    else
    {

        cout<<" There is some error in reading  from  the file ";
    }
    
    

 
    
}

void searchContact()
{
    ifstream fin;
    int count =0;
    string searchName,target,line;
    bool found;
    cin.ignore();
    cout<<"Please Enter the name to search the Contact: ";
    getline(cin,searchName);
    target="Name    : "+ searchName;

    fin.open("contacts.txt");
    if(!(fin.fail()))
    {
        while(getline(fin, line))
        {
            if(line == target)
            {
                found = true;
                cout <<endl<< "Contact Found!"<<endl<<endl;

                // Name
                cout << line << endl;          
                // Phone
                getline(fin, line); 
                cout << line << endl; 
                // Email
                getline(fin, line); 
                cout << line << endl; 
                // Address
                getline(fin, line); 
                cout << line << endl; 
                // ------------------------
                getline(fin, line); 
                cout << line << endl; 

                break; 
            }
        }

        if(!found)
        {
            cout << "Contact not Found!" << endl;
            cout<<"Your required Contact is not available in the Contact Book"<<endl;
        }


        
    }
    else
    {

        cout<<" There is some error in reading  from  the file ";

    }
    fin.close();





}

void modifyContact()
{
    string modifyName,nameLine,phoneLine,emailLine,addressLine,separatorLine;
    string modifyTarget,newName,newPhone,newEmail,newAddress;
    bool found=false;
    cin.ignore();
    cout<<"Please Enter the Contact Name from the Contact Book to Modify: ";

    getline(cin,modifyName);
    modifyTarget="Name    : "+ modifyName;
    ifstream fin;
    ofstream fout;
    fin.open("contacts.txt");
    // opening the temporary file which will help to modify the required contact
    fout.open("temp.txt");
    if(!(fin.fail())&&!(fout.fail()))
    {
        if(fin.peek() == EOF)
        {
            cout<<"No contacts available."<<endl;
            fin.close();
            fout.close();
            return;
        }
        while(getline(fin, nameLine))
        {
            
            if(!getline(fin, phoneLine)) break;
            if(!getline(fin, emailLine)) break;
            if(!getline(fin, addressLine)) break;
            if(!getline(fin, separatorLine)) break;
            if(nameLine==modifyTarget)
            {
                found=true;
                cout << "...........Contact Found to Modify..........." << endl;

                cout << "Enter New Name: ";
                getline(cin, newName);
                cout << "Enter New Phone Number: ";
                getline(cin, newPhone);
                cout << "Enter New Email Address: ";
                getline(cin, newEmail);
                cout << "Enter New Home Address: ";
                getline(cin, newAddress);
                fout << "Name    : " << newName << endl;
                fout << "Phone   : " << newPhone << endl;
                fout << "Email   : " << newEmail << endl;
                fout << "Address : " << newAddress << endl;
                fout << "--------------------------------" << endl;
                
            }
            else
            {
                fout << nameLine << endl;
                fout << phoneLine << endl;
                fout << emailLine << endl;
                fout << addressLine << endl;
                fout << separatorLine << endl;
                
            }
        }
    }    
    else
    {
        cout<<"There is some error in writing or reading to the file.";

    }
    fin.close();
    fout.close();


    // Now deleting the Contact file and renamed the temporary file to Contacts.txt
    if(found)
    {
        cout<<endl<<"-------->>>>>> Contact Modified successfully <<<<<<<<<----------"<<endl;

        remove("contacts.txt");
        rename("temp.txt","contacts.txt");
    }
    else
    {
        cout<<"Required Contact name not found in the Contact Book"<<endl;
        remove("temp.txt");
        
    }
}
    
void deleteContact()
{
    string deleteName,nameLine,phoneLine,emailLine,addressLine,separatorLine;
    string deleteTarget;
    bool found=false;
    bool deleted=false;
    cin.ignore();
    cout<<"Please Enter the Contact Name from the Contact Book to Delete: ";

    getline(cin,deleteName);
    deleteTarget="Name    : "+ deleteName;
    ifstream fin;
    ofstream fout;
    fin.open("contacts.txt");
    // opening the temporary file which will help to delete the required contact
    fout.open("temp.txt");
    if(!(fin.fail())&&!(fout.fail()))
    {
        if(fin.peek() == EOF)
        {
            cout<<"No contacts available."<<endl;
            fin.close();
            fout.close();
            return;
        }
        while(getline(fin, nameLine))
        {
            if(!getline(fin, phoneLine)) break;
            if(!getline(fin, emailLine)) break;
            if(!getline(fin, addressLine)) break;
            if(!getline(fin, separatorLine)) break;
            if(nameLine==deleteTarget)
            {
                found=true;
                cout << "...........Contact Found to Delete............." << endl;
                char choice;
                cout << "Are you sure you want to delete this contact? (Y/N): ";
                cin >> choice;

                if(choice=='Y' || choice=='y')
                {
                    deleted=true;

                }
                else
                {
                    fout << nameLine << endl;
                    fout << phoneLine << endl;
                    fout << emailLine << endl;
                    fout << addressLine << endl;
                    fout << separatorLine << endl;
                }

                
                
            }
            else
            {
                fout << nameLine << endl;
                fout << phoneLine << endl;
                fout << emailLine << endl;
                fout << addressLine << endl;
                fout << separatorLine << endl;
                
            }
        }
    }    
    else
    {
        cout<<"There is some error in writing or reading to the file.";

    }
    fin.close();
    fout.close();


    // Now deleting the Contact file and renamed the temporary file to Contacts.txt
    if(deleted)
    {
        cout<<endl<<"-------->>>>>Contact Deleted successfully<<<<<<<-----------"<<endl;

        remove("contacts.txt");
        rename("temp.txt","contacts.txt");
    }
    else if(found)
    {
        cout<<"Deletion Cancelled!"<<endl;
        remove("temp.txt");
        
    }
    else
    {
        cout << "Required Contact name not found in the Contact Book." << endl;
        remove("temp.txt");
    }

}