#include<iostream>
#include<string>
#include<queue>
using namespace std;
struct Book{
    string title;
    string author;
    int yearofpublication;
    string publication;
    int copies;
    Book(string t, string a, int y, string p){
    title = t;
    author = a;
    yearofpublication = y;
    publication = p;
    }
    void display() const{
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Year: " << yearofpublication << endl;
        cout << "Publisher: " << publication << endl;

    }
};
class Library{
    queue<Book> books;
    public:
    void insertBook(const Book&b){
        books.push(b);
        cout<<"Book added :"<<b.title<<endl;
    }
    void deleteBook(){
        if(!books.empty()){
            cout<<"Book deleted :"<<books.front().title<<endl;
        }
        else{
            cout<<"No book to delete"<<endl;
        }
    }
    void displayBooks(){
        if(books.empty()){
            cout<<"Library is empty"<<endl;
            return;
        }
        else{
            cout<<"Books"<<endl;
            queue<Book>temp = books;
            while(!temp.empty()){
                temp.front().display();
                temp.pop();
            }
        }
    }
};
int main(){
    Library lib;
    int choice;
    while(choice!=4){
        cout<<"choice 1:Insert Book"<<endl;
        cout<<"choice 2:Delete Book"<<endl;
        cout<<"choice 3:Display Book"<<endl;
        cout<<"choice 4:exit "<<endl;
        cout<<"Enter choice :";
        cin>>choice;
        if(choice==1){
            string title,author,publisher;
            int year;
            cout<<"Enter title :";
            cin>>title;
            cout<<"Enter author: ";
            cin>>author;
            cout<<"Enter year: ";
            cin>>year;
            cout<<"Enter publisher: ";
            cin>>publisher;
            lib.insertBook(Book(title,author,year,publisher));
        }
        else if(choice==2){
            lib.deleteBook();
        }
        else if(choice==3){
            lib.displayBooks();
        }
        else if(choice==4){
            cout<<"Program Exited"<<endl;
        }
    }
    return 0;
}