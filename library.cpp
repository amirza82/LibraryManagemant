#include<iostream>
#include<vector>
#include<stdlib.h>
#include<algorithm>
#include<string>
#include<iomanip>
using namespace std;
//structs are: admin, usre, book
struct admin
{
    string UserName;
    string password;
};

struct user
{
    string UserName;
    string password;
    string FullName[2];
    long long int PhoneNumber;
    int date[3]; //[00(day)/00(monthe)/0000(year)]
    int RentedBooksNumber;
    string RentedBooksID[3] = {"none", "none", "none"};
};

struct book
{
    string ID;
    string title;
    string writer;
    string genre;
    bool availability = true;
};

//declartions
vector<admin> admins;

vector<user> users;

vector<book> books;

bool IsAdmin = false;

bool panle = true;

int index = -1;

//predefined info

void predefined()
{
    //predefind admins
    admins.resize(1);
    admins[0].UserName = "admin";
    admins[0].password = "admin";

    //predefined users
    users.resize(2);
    users[0].UserName = "user1";
    users[0].FullName[0] = "example";
    users[0].FullName[1] = "user1";
    users[0].password = "1234";
    users[0].PhoneNumber = 1234;
    users[0].date[0] = 11; users[0].date[1] = 11; users[0].date[2] = 1111;

    users[1].UserName = "user2";
    users[1].FullName[0] = "example";
    users[1].FullName[1] = "user2";
    users[1].password = "1234";
    users[1].PhoneNumber = 1234;
    users[1].date[0] = 11; users[0].date[1] = 11; users[0].date[2] = 1111;

    //predefined books
    books.resize(4);
    books[0].ID = "book1";
    books[0].title = "book1";
    books[0].genre = "history";
    books[0].writer = "writer1";

        
    books[1].ID = "book2";
    books[1].title = "book2";
    books[1].genre = "history";
    books[1].writer = "writer2";

    books[2].ID = "book3";
    books[2].title = "book3";
    books[2].genre = "other";
    books[2].writer = "writer3";

    books[3].ID = "book4";
    books[3].title = "book4";
    books[3].genre = "other";
    books[3].writer = "writer4";


}

        //login functions

//User signup
int User_signup(int index)
{
    system("cls");
    cout << "are you sure you didn't signin befor ?" << endl << "1. YES" << endl << "2. NO , I want to login";
    int u;
    cin >> u;
    if (u == 2)
    {
        return index;
    }

    system("cls");
    index = users.size();
    users.resize(users.size()+1);
    while(true){
        cout << "Enter your username: ";

        cin >> users[users.size()-1].UserName;
        bool b = true;
        
        for (size_t i = 0; i < users.size()-1; i++)
        {
            
            if (users[users.size()-1].UserName == users[i].UserName)
            {
                b = false;
                break;
            }
            
        }
        
        if(b == false)
        cout << "This username is not avalable. Chose another one." << endl;
        else break;
    }
    

    cout << "Enter your full name: ";

    for (size_t i = 0; i < 2; i++)
    {
        cin >> users[users.size()-1].FullName[i];
    }
    cout << "Enter your phone number: ";

    cin >> users[users.size()-1].PhoneNumber;

    cout << "Enter today's date (dd mm yyyy)";

    for (size_t i = 0; i < 3; i++)
    {
        cin >> users[users.size()-1].date[i];
    }
    cout << "Enter your pasaword: ";
    cin >> users[users.size()-1].password;

    cout << "SAVED" << endl;

    

    return index;
}

//User login

int User_login(int index)
{
    system("cls");
    index = 0;
    string u;
    cout << "Enter your username: ";
    cin >> u;
    for (size_t i = 0; i < users.size(); i++)
    {
        if (u == users[i].UserName)
        {
            index = i;
            u = "done";
            break;
        }
        
    }
    if (u != "done"){
        cout << "this username dose not exists.";
        return -1;
    }
    cout << "Enter your password: ";
    cin >> u;

    if (u != users[index].password)
    {
        cout << "Username is not correct.";
        return -1;
    }
    return index;

}

//Admin login

int Admin_login(int index)
{
    system("cls");
    index = 0;
    string u;
    cout << "Enter your username: ";
    cin >> u;
    for (size_t i = 0; i < admins.size(); i++)
    {
        if (u == admins[i].UserName)
        {
            index = i;
            u = "done";
            break;
        }
        
    }
    if (u != "done"){
        cout << "this username dose not exists.";
        return -1;
    }
    cout << "Enter your password: ";
    cin >> u;

    if (u != admins[index].password)
    {
        cout << "Password is not correct.";
        return -1;
    }
    IsAdmin = true;
    return index;
}

//A function for login options

int start(int index)
{
    IsAdmin = false;
    
    
    while(index == -1)
    {
        system("cls");
        int options;
        cout << "Wlcome to the library" << endl << "for loging in enter 1" << endl << "for signing up enter 2" << endl << "for loging in as admin enter 3" << endl;
        cin >> options;
        switch (options)
        {
        case 1:
            index = User_login(index);
            break;
        case 2:
            index = User_signup(index);
            break;
        case 3:
            index = Admin_login(index);
            break;
        default:
            break;
        }
    }

    return index;
}

        //Userpanle subfunctions

//show books

void show_books()
{
    cout << boolalpha;
    cout << "show the books based on genre: " << endl << "1. show all    2. history    3. other genres" << endl;
    int option = 1;
    cin >> option;
    int i = 0, j = 1;
    switch (option)
    {
    case 2:
        
        while(option == 2)
        {
            system("cls");
            if(books.size() - i <= 5)
            {
                for (i; i < books.size(); i++)
                {
                    if(books[i].genre == "history"){
                    cout << j << ". " << "name: " << books[i].title << " writer: " << books[i].writer << " genre: " << books[i].genre << " ID: " << books[i].ID << " availability: " << books[i].availability << endl;
                    j++;
                    }
                }
                cout << "Enter 0 to back" << endl;
                cin >> option;
            }
            else
            {
                for (i; i < 5; i++)
                {
                    if(books[i].genre == "history"){
                    cout << j << ". " << "name: " << books[i].title << " writer: " << books[i].writer << " genre: " << books[i].genre << " ID: " << books[i].ID << " availability: " << books[i].availability << endl;
                    j++;
                    }
                }
                option = 0;
                cout << "For next page enter 2 \n Or enter 0 to back" << endl;
                cin >> option;

            }
            
        }
        break;
    case 3:
        
        while(option == 3)
        {
            system("cls");
            if(books.size() - i <= 5)
            {
                for (i; i < books.size(); i++)
                {
                    if(books[i].genre == "other"){
                    cout << j << ". " << "name: " << books[i].title << " writer: " << books[i].writer << " genre: " << books[i].genre << " ID: " << books[i].ID << " availability: " << books[i].availability << endl;
                    j++;
                    }
                }
                cout << "Enter 0 to back" << endl;
                cin >> option;
            }
            else
            {
                for (i; i < 5; i++)
                {
                    if(books[i].genre == "other"){
                    cout << j << ". " << "name: " << books[i].title << " writer: " << books[i].writer << " genre: " << books[i].genre << " ID: " << books[i].ID << " availability: " << books[i].availability << endl;
                    j++;
                    }
                }
                option = 0;
                cout << "For next page enter 3 \n Or enter 0 to back" << endl;
                cin >> option;
            }
        }
        break;
    
    default:
        
        while(option == 1)
        {
            system("cls");
            if(books.size() - i <= 5)
            {
                for (i; i < books.size(); i++)
                {
                    cout << j << ". " << "name: " << books[i].title << " writer: " << books[i].writer << " genre: " << books[i].genre << " ID: " << books[i].ID << " availability: " << books[i].availability << endl;
                    j++;
                }
                cout << "Enter 0 to back";
                cin >> option;
            }
            else
            {
                for (i; i < 5; i++)
                {
                    cout << j << ". " << "name: " << books[i].title << " writer: " << books[i].writer << " genre: " << books[i].genre << " ID: " << books[i].ID << " availability: " << books[i].availability << endl;
                    j++;
                }
                option = 0;
                cout << "For next page enter 1 \n Or enter 0 to back" << endl;
                cin >> option;
            }
        }
        break;
    }
}



//rent a book

void rent_book(int index)
{
    int option = 1;
    while(option == 1)
    {
        system("cls");
        cout << "Enter the book ID: ";
        string bookID;
        cin >> bookID;
        for (size_t i = 0; i < books.size(); i++)
        {
            if (bookID == books[i].ID && books[i].availability && users[index].RentedBooksNumber < 3)
            {
                users[index].RentedBooksID[users[index].RentedBooksNumber] = books[i].ID;
                users[index].RentedBooksNumber++;
                option = 0;
                break;
            }
            
        }
        if (option != 0)
        {
            cout << "ID is wrong." << endl;
            option = 1;
        }
    }
    
    
}

//search for a book

void search_book()
{
    system("cls");
    cout << "search based on \n1. book's title\n2. book's writer\n0. back";
    int option = 0;
    cin >> option;
    bool BookFound = false;
    string u;
    switch (option)
    {
    case 1:
        cout << "enter the book's title: " << endl;
        
        cin >> u;
        
        for (size_t i = 0; i < books.size(); i++)
        {
            if (u == books[i].title)
            {
                cout << "ID: " << books[i].ID << endl;
                BookFound = true;
                break;
            }
        }
        if (BookFound == false)
        {
            cout << "book with this title did not found" << endl;
        }
       
        break;
    case 2:
        cout << "enter the book's writer: " << endl;
        cin >> u;
        
        for (size_t i = 0; i < books.size(); i++)
        {
            if (u == books[i].writer)
            {
                cout << "ID: " << books[i].ID << endl;
                BookFound = true;
                break;
            }
        }
        if (BookFound == false)
        {
            cout << "book with this writer did not found" << endl;
        }
        
        break;
    default:
        break;
    }
}

//Delivering a book back

void deliver_back(int index)
{
    system("cls");
    cout << "you have rented " << users[index].RentedBooksNumber << " books" << endl;
    for (size_t i = 0; i < 3; i++)
    {
        cout << "book ID: " << users[index].RentedBooksID[i] << endl;
    }
    
    cout << "enter the book ID: ";
    string u;
    bool delivered = false;
    cin >> u;
    for (size_t i = 0; i < 3; i++)
    {
        if (u == users[index].RentedBooksID[i])
        {

            users[index].RentedBooksID[i] = "none";
            users[index].RentedBooksNumber --;
            for (size_t j = 0; j < books.size(); j++)
            {
                if (u == books[j].ID)
                {
                    books[j].availability = true;
                    break;
                }
                
            }
            delivered = true;
            break;
        }
        
    }
    
    if (delivered)
    {
        cout << "book successfully delivered!" << endl;
    }
    else
    {
        cout << "Book ID is wrong." << endl;
    }
    
}


        //User panle main functions

//chooseing a book

void rent_books(int index)
{
    system("cls");
    int option = 0;
    while(option == 0)
    {
        cout << "1. see the books" << endl << "2. rent a book" << endl << "3. search a book" << endl << "4. Deliver a book back"<< endl << "0. back" << endl;
        cin >> option;
        switch (option)
        {
        case 1:
            show_books();
            option = 0;
            system("pause");
            system("cls");
            break;
        case 2:
            rent_book(index);
            option = 0;
            system("pause");
            system("cls");
            break;
        case 3:
            search_book();
            option = 0;
            system("pause");
            system("cls");
            break;
        case 4: 
            deliver_back(index);
            option = 0;
            system("pause");
            system("cls");
            break;
        default:
            option = 1;
            break;
        }
    }
}
//changing account informations

void change_acc_info(int index)
{
    system("cls");
    cout << "1. Username: " << users[index].UserName << endl;
    cout << "2. Password: " << users[index].password << endl;
    cout << "3. Full Name: " << users[index].FullName[0] << " " << users[index].FullName[1] << endl;
    cout << "4. Phone number: " << users[index].PhoneNumber << endl;
    cout << "rented books: 1. " << users[index].RentedBooksID[0] << " 2. " << users[index].RentedBooksID[1] << " 3. " << users[index].RentedBooksID[2] << endl;
    cout << "to change each of the ebove information enter its number or enter 0 to bake to the previous page" << endl;
    int options = 0;
    cin >> options;
    switch (options)
    {
    case 1:
        while(true)
        {
            cout << "Enter your new username: ";
            string u;
            cin >> u;
            bool b = true;
            
            for (size_t i = 0; i < index; i++)
            {
                
                if (u == users[i].UserName)
                {
                    b = false;
                    break;
                }
                
            }
            
            if(b == false)
            cout << "This username is not avalable. Chose another one." << endl;
            else {
                users[index].UserName = u;
                cout << "SAVED" << endl;
                break;
            }
        }
        system("pause");
        break;
    case 2:
        cout << "enter your new password: ";
        cin >> users[index].password;
        cout << "SAVED" << endl;
        system("pause");
        break;
    case 3:
        cout << "Enter your new name: ";
        for (size_t i = 0; i < 2; i++)
        {
            cin >> users[index].FullName[i];
        }
        cout << "SAVED" << endl;
        system("pause");
        break;
    case 4:
        cout << "enter your new phone number";
        cin >> users[index].PhoneNumber;
        cout << "SAVED" << endl;
        system("pause");
        break;
    default:
        
        break;
    }
}

                //the user panle function

int user_panle(int index)
{
    while(true)
    {
        system("cls");
        cout << "USER PANLE: \n\n\n";
        cout << "For book options ENTER 1 " << "\nTo view/change account info ENTER 2 " << "\nEnter 0 to back";
        int options = 0;
        cin >> options;
        switch (options)
        {
        case 1:
            rent_books(index);
            break;
        case 2:
            change_acc_info(index);
            break;
        default:
            return -1;
            break;
        }
    }
}

        //admin panle subfunctions

//changing account info

void cahnge_admin_info(int index)
{
    system("cls");
    cout << "Your Username is: " << admins[index].UserName << endl;
    cout << "Your password is: " << admins[index].password << endl;
    cout << "\n1. change the password\n2. change the Username\n0. back\n";
    int options = 0;
    cin >> options;
    switch (options)
    {
    case 1:
        while(true)
        {
            system("cls");
            cout << "Enter your new username: ";
            string u;
            cin >> u;
            bool b = true;
            
            for (size_t i = 0; i < index; i++)
            {
                
                if (u == admins[i].UserName)
                {
                    b = false;
                    break;
                }
                
            }
            
            if(b == false)
            cout << "This username is not avalable. Chose another one." << endl;
            else {
                admins[index].UserName = u;
                cout << "SAVED" << endl;
                break;
            }
        }
        system("pause");
        break;
    case 2:
        cout << "enter your new password: ";
        cin >> admins[index].password;
        cout << "SAVED" << endl;
        system("pause");
        break;
    default:
        break;
    }
}

//function to show rented books

void show_rented_books()
{
    system("cls");
    cout << "following book/books are in rent: \n\n";
    for (size_t i = 0; i < books.size(); i++)
    {
        if (books[i].availability == false)
        {
            cout << "title: " << books[i].title << " ID: " << books[i].ID << endl;
        }
        
    }
    system("pause");
}

//show who is rented a book

void who_rented_book()
{
    system("cls");
    cout << "these are who currently rented a book: \n\n";
    for (size_t i = 0; i < users.size(); i++)
    {
        if (users[i].RentedBooksNumber > 0)
        {
            cout << "name: " << users[i].FullName[0] << " " << users[i].FullName[1] << " ID: " << users[i].UserName << endl;
        }
        
    }
    system("pause");
}

//add a book

void add_book()
{
    system("cls");
    books.resize(books.size() + 1);
    while(true){
        cout << "Enter the book's ID: ";

        cin >> books[books.size()-1].ID;
        bool b = true;
        
        for (size_t i = 0; i < books.size()-1; i++)
        {
            
            if (books[books.size()-1].ID == books[i].ID)
            {
                b = false;
                break;
            }
            
        }
        
        if(b == false)
        cout << "This ID already exists. Enter another one." << endl;
        else break;
    }
    
    cout << "Enter the book's title: ";
    cin >> books[books.size()-1].title;

    cout << "Enter the book's genre (history / other): ";
    cin >> books[books.size()-1].genre;

    cout << "Enter the book's writer: ";
    cin >> books[books.size()-1].writer;
    
    cout << "SAVED!" << endl;
    system("pause");
}

//delete a book

void delete_book()
{
    system("cls");
    cout << "Enter the ID of book you want to delete: ";
    string u;
    cin >> u;
    bool deleted = false;
    for (size_t i = 0; i < books.size(); i++)
    {
        if (u == books[i].ID)
        {
            books.erase(books.begin() + i);
            deleted = true;
        }
    }
    if (deleted)
    {
        cout << "book has been removed\n";
    }
    else
    {
        cout << "ID dose not exists\n";
    }
    system("pause");
}

//delete a user

void delete_user()
{
    system("cls");
    cout << "Enter the username of user you want to delete: ";
    string u;
    cin >> u;
    bool deleted = false;
    for (size_t i = 0; i < users.size(); i++)
    {
        if (u == users[i].UserName)
        {
            users.erase(users.begin() + i);
            deleted = true;
        }
    }
    if (deleted)
    {
        cout << "user has been removed\n";
    }
    else
    {
        cout << "username dose not exists\n";
    }
    system("pause");
}

//changing books info

void edit_books_info()
{
    system("cls");
    cout << "Enter the book's ID: ";
    string u;
    cin >> u;
    int bookindex = 0;
    bool BookFound = false;
    for (size_t i = 0; books.size(); i++)
    {
        if(books[i].ID == u)
        {
            BookFound = true;
            bookindex = i;
            break;
        }
    }
    if (BookFound)
    {
        system("cls");
        cout << "1. ID: " << books[bookindex].ID << "\n2. title: " << books[bookindex].title <<"\n3. genre: " << books[bookindex].genre << "\n4. writer: " << books[bookindex].writer << "\n0. back";
        cout << "\n\nEnter the number of information you want to chang: ";
        int option = 0;
        cin >> option;
        system("cls");
        switch (option)
        {
        case 1:
            while(true)
            {
                cout << "Enter the nwe ID: ";
                string newID;
                bool IDexists = false;
                cin >> newID;
                for (size_t i = 0; i < books.size(); i++)
                {
                    if (books[i].ID == newID)
                    {
                        IDexists = true;
                        break;
                    }
                    
                }
                if (IDexists)
                {
                    cout << "ID is in use. Enter another one.";
                }
                else
                {
                    books[bookindex].ID = newID;
                    break;
                }
                    
            }
            cout << "SAVED";
            system("pause");
            break;
        case 2:
            cout << "Enter new title: ";
            cin >> books[bookindex].title;
            cout << "SAVED" << endl;
            system("pause");
            break;
        case 3:
            cout << "Enter new genre: ";
            cin >> books[bookindex].genre;
            cout << "SAVED" << endl;
            system("pause");
            break;
        case 4:
            cout << "Enter new writer";
            cin >> books[bookindex].writer;
            cout << "SAVED" << endl;
            system("pause");
        default:
            break;
        }


    }
    
}


            //the admin panle function


int admin_panle(int index)
{
    while(true)
    {
        system("cls");
        cout << "ADMIN PANLE\n\n\n";
        cout << "1. change your account info\n" << "2. show the rented books\n" << "3. show who rented a book\n" << "4. add a book\n" << "5. delete a book\n" << "6. delete a user\n" << "7. change a book's info\n" << "0. back\n";
        int options = 0;
        cin >> options;
        switch (options)
        {
        case 1:
            cahnge_admin_info(index);
            break;
        case 2:
            show_rented_books();
            break;
        case 3:
            who_rented_book();
            break;
        case 4:
            add_book();
            break;
        case 5:
            delete_book();
            break;
        case 6:
            delete_user();
            break;
        case 7:
            edit_books_info();
            break;
        default:
            return -1;
            break;
        }
    }
}



int main(){

    predefined();
    while(index == -1)
    {
        
        index = start(index);
        if (IsAdmin)
        {
           index = admin_panle(index);
        }
        else
        {
            index = user_panle(index);
        }
        
    }
    
    return 0;
}