#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void accountType (string *accType){
    cout << "Enter account type: ";
    cin >> *accType;
    while (*accType != "reader" && *accType != "librarian") {
        cout << "Enter correct account type: ";
        cin >> *accType;
    } 
}

void loginInfo (string *loginUser, string *passwordUser){
    cout << "Enter login: ";
    cin >> *loginUser;
    cout << "Enter password: ";
    cin >> *passwordUser;
    cout << endl;
}

bool readerLogin(string loginUser, string passwordUser){
    string loginPasswordTxt, loginTxt, passwordTxt;
    vector <string> allLoginTxt, allPasswordTxt;
    ifstream fin;
        fin.open("readers.txt");
        if(fin.is_open()){
            while(!fin.eof() ){
                loginPasswordTxt = "";
                getline(fin, loginPasswordTxt);
                int dividerPosition = loginPasswordTxt.find(" ");
                loginTxt = loginPasswordTxt.substr(0, dividerPosition);
                passwordTxt = loginPasswordTxt.substr(dividerPosition + 1);
                allPasswordTxt.push_back(passwordTxt);
                allLoginTxt.push_back(loginTxt);
            }
            for (int i = 0; i < allPasswordTxt.size(); i++){
                if (loginUser == allLoginTxt[i] && passwordUser == allPasswordTxt[i]){
                    return true;
                    break;
                }
            }
        }
        else
            cout << "readers.txt doesn't open" << endl;
            
        fin.close();
    cout << "Incorrect login or password." << endl;
    return false;
}

bool librarianLogin(string loginUser, string passwordUser){
    string loginPasswordTxt, loginTxt, passwordTxt;
    vector <string> allLoginTxt, allPasswordTxt;
    ifstream fin;
        fin.open("librarian.txt");
        if(fin.is_open()){
            while(!fin.eof()){
                loginPasswordTxt = "";
                getline(fin, loginPasswordTxt);
                int dividerPosition = loginPasswordTxt.find(" ");
                loginTxt = loginPasswordTxt.substr(0, dividerPosition);
                passwordTxt = loginPasswordTxt.substr(dividerPosition + 1);
                allPasswordTxt.push_back(passwordTxt);
                allLoginTxt.push_back(loginTxt);
            }
            for (int i = 0; i < allPasswordTxt.size(); i++){
                if (loginUser == allLoginTxt[i] && passwordUser == allPasswordTxt[i]){
                    return true;
                    break;
                }
            }
        }
        else
            cout << "librarian.txt doesn't open" << endl;
        
        fin.close();
    cout << "Incorrect login or password." << endl;
    return false;
}

void readerMenu(){
    cout << " --------MENU--------\n";
    cout << "|1.All books        |\n";
    cout << "|2.Search book      |\n";
    cout << "|3.Add to Favourites|\n";
    cout << "|4.My Favourites    |\n";
    cout << "|5.My Balance       |\n";
    cout << "|6.Buy a book       |\n";
    cout << "|7.Exit             |\n";
    cout << " --------------------\n";
}

void librarianMenu(){
    cout << " --------MENU--------\n";
    cout << "|1.All books         |\n";
    cout << "|2.Search book       |\n";
    cout << "|3.All Readers       |\n";
    cout << "|4.Search reader     |\n";
    cout << "|5.Exit              |\n";
    cout << " --------------------\n";
}

void allBooks(){
    string book;
    ifstream fin;
        fin.open("books.txt");
        if(fin.is_open()){
            cout << "   All Books\n";
            while(!fin.eof()){
                book = "";
                getline(fin,book);
                cout << book << endl;
            }
            cout << endl;
        }
        else
            cout << "books.txt doesn't open" << endl;

        fin.close();
}

void searchBook() {
    string book;
    ifstream fin;
        fin.open("books.txt");
        if(fin.is_open()){
            vector <string> allBooksTxt;
            vector <string> allBookNamesTxt;
            vector <string> allBookAuthorsTxt;
            vector <string> allBookYearsTxt;
            while(!fin.eof()){
                book = "";
                getline(fin,book);
                int dividerPosition1 = book.find("\"");
                
                int dividerPosition2;
                int findDividerPosition2 = -1;
                do {
                    findDividerPosition2 = book.find("\"", findDividerPosition2 + 1);
                    if (findDividerPosition2 != -1)
                        dividerPosition2 = findDividerPosition2 - dividerPosition1 - 1;
                } while (findDividerPosition2 != -1);
                
                int dividerPosition3 = book.find("-") + 1;
                
                int dividerPosition4;
                int findDividerPosition4 = -1;
                do {
                    findDividerPosition4 = book.find("-", findDividerPosition4 + 1);
                    if (findDividerPosition4 != -1)
                        dividerPosition4 = findDividerPosition4 - dividerPosition3 - 2;
                } while (findDividerPosition4 != -1);
                
                int dividerPosition5;
                int findDividerPosition5 = -1;
                do {
                    findDividerPosition5 = book.find("-", findDividerPosition5 + 1);
                    if (findDividerPosition5 != -1)
                        dividerPosition5 = findDividerPosition5 + 2;
                } while (findDividerPosition5 != -1);
                
                string booksTxt = book.substr(dividerPosition1);
                allBooksTxt.push_back(booksTxt);
                string bookNameTxt = book.substr(dividerPosition1 + 1, dividerPosition2);
                allBookNamesTxt.push_back(bookNameTxt);
                string bookAuthorTxt = book.substr(dividerPosition3 + 1, dividerPosition4);
                allBookAuthorsTxt.push_back(bookAuthorTxt);
                string bookYearTxt = book.substr(dividerPosition5);
                allBookYearsTxt.push_back(bookYearTxt);
            }
            
            int bookOption;
            cout << " --------------------------\n";
            cout << "|Search by:                |\n";
            cout << "|   1.Book's name          |\n";
            cout << "|   2.Book's author        |\n";
            cout << "|   3.Book's year of issue |\n";
            cout << " --------------------------\n";
            cout << "Choose an option: ";
            cin >> bookOption;
            cout << endl;
            
            string bookExist = "";
            switch (bookOption){
                case 1:{
                    string bookName;
                    cout << "Enter book name: ";
                    cin.ignore();
                    getline(cin, bookName);
                    
                    for (int i = 0; i < allBookNamesTxt.size(); i++){
                        if (bookName == allBookNamesTxt[i]){
                            bookExist =  allBooksTxt[i];
                        }
                    }
                    if (bookExist != "")
                        cout << bookExist << endl;
                    else 
                            cout << "This book has not yet been added to the library.\n";
                    break;
                }
                case 2:{
                    string bookAuthor;
                    cout << "Enter book's author: ";
                    cin.ignore();
                    getline(cin, bookAuthor);
                    for (int i = 0; i < allBookAuthorsTxt.size(); i++){
                        if (bookAuthor == allBookAuthorsTxt[i]){
                            bookExist =  allBooksTxt[i];
                        }
                    }
                    if (bookExist != "")
                        cout << bookExist << endl;
                    else 
                            cout << "This book has not yet been added to the library.\n";
                    break;
                }
                case 3:{
                    string bookYear;
                    cout << "Enter book's year: ";
                    cin.ignore();
                    getline(cin, bookYear);
                    for (int i = 0; i < allBookYearsTxt.size(); i++){
                        if (bookYear == allBookYearsTxt[i]){
                            bookExist =  allBooksTxt[i];
                        }
                    }
                    if (bookExist != "")
                        cout << bookExist << endl;
                    else 
                            cout << "This book has not yet been added to the library.\n";
                    break;                    
                }
            }
            cout << endl;
        }
        else
            cout << "books.txt doesn't open" << endl;
        fin.close();
}

int main()
{
    string accType, loginUser, passwordUser;
    
    accountType(&accType);
    loginInfo (&loginUser, &passwordUser);
    
    if(accType == "reader" && readerLogin(loginUser, passwordUser)){
        int option;
        readerMenu();
        
        while(option != 7) {
            cout << "Choose an option: " ;
            cin >> option;
            cout << endl;
                
            switch(option){
                case 1:
                    allBooks();
                    break;
                case 2:
                    searchBook();
                    break;
                // case 3:
                //     addFavourite();
                //     break;
                // case 4:
                //     myFavourite();
                //     break;
                // case 5:
                //     myBalance()
                //     break;
                // case 6:
                //     buyBook
                //     break;
            }
            string goBackMenu;
            if (option != 7){
                cout << "Want to go to menu? ";
                cin >> goBackMenu;
                cout << endl;
                if (goBackMenu == "yes")
                    readerMenu();
                else
                    exit(0);        
                } 
        }
    }
    
    else if(accType == "librarian" && librarianLogin(loginUser, passwordUser)){
        int option;
        librarianMenu();
        
        while(option != 5) {
            cout << "Choose an option: " ;
            cin >> option;
            cout << endl;
                
            switch(option){
                case 1:
                    allBooks();
                    break;
                case 2:
                    searchBook();
                    break;
                // case 3:
                //     allReaders();
                //     break;
                // case 4:
                //     searchReader();
                //     break;
            }
            string goBackMenu;
            if (option != 5){
                cout << "Want to go to menu? ";
                cin >> goBackMenu;
                cout << endl;
                if (goBackMenu == "yes")
                    librarianMenu();
                else
                    exit(0);        
            } 
        }
    }
    
    return 0;
}