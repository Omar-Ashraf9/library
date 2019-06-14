/// Assignment #1
/// Omar Ashraf Labib Hassan , 20170363 , G_10.
/// Hussein Hossam Hussein Idris , 20170352 , G_9.
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <istream>
using namespace std;
struct book
{
    char ISBN[5];
    string title;
    string author_name;
    string price;
    string year;
    string num_of_pages;
};
void AddBook(fstream & out)
{
    book object;
    cout << "Enter the ISBN: " << endl;
    cin >> object.ISBN;
    cout << "Enter the author name: " << endl;
    cin.ignore();
    getline(cin,object.author_name);
    cout << "Enter the title: " << endl;
    getline(cin,object.title);
    cout << "Enter the price: " << endl;
    cin >> object.price;
    cout << "Enter the year: " << endl;
    cin >> object.year;
    cout << "Enter the number of pages: " << endl;
    cin >> object.num_of_pages;

    string buffer = "";
    buffer = buffer + object.ISBN;
    buffer = buffer + "|";
    buffer = buffer + object.author_name;
    buffer = buffer + "|";
    buffer = buffer + object.title;
    buffer = buffer + "|";
    buffer = buffer + object.price;
    buffer = buffer + "|";
    buffer = buffer + object.year;
    buffer = buffer + "|";
    buffer = buffer + object.num_of_pages;
    buffer = buffer + "|";
    buffer = buffer + "\n";

    size_t size = buffer.size();
    out.write((&buffer[0]),size);
}
void printall(fstream & in)
{
    while(!in.eof())
    {
    string buffer2;
    getline(in,buffer2);
    cout << buffer2 << endl;
    }
}
void printbook(fstream & out,string title)
{
    string temp;
    getline(out,temp);
    while(!out.eof()){
            if(temp.find(title) != string::npos){
                cout << temp << endl;
            }
            getline(out,temp);
    }
}
void deletebook(string ISBN)
{
    string temp;
    ifstream f1;
    f1.open("test1.txt",ios::in);
    ofstream f2;
    f2.open("modify.txt",ios::out);
    f1.seekg(0,ios::beg);
    while(!f1.eof()){
            getline(f1,temp);
            if(temp.find(ISBN) != string::npos){
                cout << "The record that will delete is: " << temp << endl;
                continue;
            }
            size_t Size = temp.size();
            f2.write((&temp[0]),Size);
            f2 << "\n";
    }
    f1.close();
    f2.close();
    remove("test1.txt");
    rename("modify.txt","test1.txt");
}
void updatebook(string ISBN)
{
    string temp;
   /// string updated;
    ifstream f1;
    f1.open("test1.txt",ios::in);
    fstream f2;
    f2.open("modify.txt",ios::out);
    f1.seekg(0,ios::beg);
    while(!f1.eof()){
            getline(f1,temp);
            if(temp.find(ISBN) != string::npos){
                cout << "The record that will update is: " << temp << endl;
                AddBook(f2);
                continue;
            }
            size_t Size = temp.size();
            f2.write((&temp[0]),Size);
            f2 << "\n";
    }
    f1.close();
    f2.close();
    remove("test1.txt");
    rename("modify.txt","test1.txt");
}

int main()
{


    char choice;
    int input;
    cout << "((((((((((((Ahln ya user ya habibi))))))))))))" << endl;
    cout << "what do want to do?" << endl;
    while (true){
    cout << "1- to Add books\n2- to print book by title\n3- to print all books\n4- to update book by ISBN number\n5- to delete book by ISBN number\n6- to terminate the program" << endl;
    cin >> choice;
    fstream f;
    switch(choice)
    {
    case '1':{
        cout << "How many books do you want to write?" << endl;
        cin >> input;
        f.open("test1.txt",ios::out);
        while(input!=0)
       {
            AddBook(f);
            cin.ignore();
            input--;
       }
       f.close();
       }break;
    case '2':{
        f.open("test1.txt",ios::in);
        string s;
        cout << "What is the title of the book you want to print?" << endl;
        cin >> s;
        printbook(f,s);
        f.close();
        }break;
    case '3':{
        f.open("test1.txt",ios::in);
        cout << "The books saved in the file are: " << endl;
        printall(f);
        f.close();
        }break;
    case '4':{
        string update_ISBN;
        cout << "Enter the ISBN number of the book that you would like to update: " << endl;
        cin >> update_ISBN;
        updatebook(update_ISBN);
        }break;
    case '5':{
        string delete_ISBN;
        cout << "Enter the ISBN number of the book that you would like to delete: " << endl;
        cin >> delete_ISBN;
        deletebook(delete_ISBN);
        }break;
    case '6':{
        cout << "Thanks for using the program :)" << endl;
        exit(0);
        }break;
    default:{
        cout << "Error! , invalid input :(" << endl;
        }break;
    }
    }

    return 0;
}
