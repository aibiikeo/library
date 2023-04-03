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
    cout << "You're not registered yet." << endl;
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
    cout << "You're not registered yet." << endl;
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

string searchBook() {
    string book;
    ifstream fin;
        fin.open("books.txt");
        if(fin.is_open()){
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
            switch (bookOption){
                case 1:{
                    string bookName;
                    cout << "Enter book name: ";
                    cin.ignore();
                    getline(cin, bookName);
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
                        string bookNameTxt = book.substr(dividerPosition1 + 1, dividerPosition2);
                        if (bookNameTxt == bookName)
                            cout << book.substr(dividerPosition1) << endl;
                    }
                    break;
                }
                case 2:{
                    string bookAuthor;
                    cout << "Enter book's author: ";
                    cin.ignore();
                    getline(cin, bookAuthor);
                    while(!fin.eof()){
                        book = "";
                        getline(fin,book);
                        int dividerPosition1 = book.find("-") + 1;
                        int dividerPosition2;
                        int findDividerPosition2 = -1;
                        do {
                            findDividerPosition2 = book.find("-", findDividerPosition2 + 1);
                            if (findDividerPosition2 != -1)
                                dividerPosition2 = findDividerPosition2 - dividerPosition1 - 2;
                        } while (findDividerPosition2 != -1);
                        string bookAuthorTxt = book.substr(dividerPosition1 + 1, dividerPosition2);
                        int dividerPositionStart = book.find("\"");
                        if (bookAuthorTxt == bookAuthor)
                            cout << book.substr(dividerPositionStart) << endl;
                    }
                    break;
                }
                case 3:{
                    string bookYear;
                    cout << "Enter book's year: ";
                    cin.ignore();
                    getline(cin, bookYear);
                    while(!fin.eof()){
                        book = "";
                        getline(fin,book);
                        // int dividerPosition1 = book.find("-") + 1;
                        int dividerPosition2;
                        int findDividerPosition2 = -1;
                        do {
                            findDividerPosition2 = book.find("-", findDividerPosition2 + 1);
                            if (findDividerPosition2 != -1)
                                dividerPosition2 = findDividerPosition2 + 2;
                        } while (findDividerPosition2 != -1);
                        string bookYearTxt = book.substr(dividerPosition2);
                        int dividerPositionStart = book.find("\"");
                        if (bookYearTxt == bookYear)
                            cout << book.substr(dividerPositionStart) << endl;
                    }
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