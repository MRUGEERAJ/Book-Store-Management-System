#include<bits/stdc++.h>
using namespace std;

class BookStore
{
    int BookID;
    string BookName;
    string Author;
    int No_of_Copies=0;

    public:
        int getID()
        {
            return BookID;
        }
        string getName()
        {
            return BookName;
        }
        string getAuthor()
        {
            return Author;
        }
        int getNCpy()
        {
            return No_of_Copies;
        }

        void setName(string name)
        {
            BookName=name;
        }
        void setAuthor(string auth)
        {
            Author=auth;
        }
        void setNCpy(int ncpy)
        {
            No_of_Copies=ncpy;
        }
        void addBook(int bid,string name,string author,int ncpy);
        void deleteBook(int bid);
        void updateBook(int bid);
        friend void checkBook();
        friend void showBooks();
};

vector<BookStore> Books;

void BookStore::addBook(int bid,string name,string auth,int ncpy)
{
    BookID=bid;
    BookName=name;
    Author=auth;
    No_of_Copies+=ncpy;
}

void BookStore::deleteBook(int bid)
{
    int flag=0,i;
    for(i=0;i<Books.size();i++)
    {
        if(Books[i].getID()==bid)
        {
            flag=1;
            break;
        }
    }
    auto itr=Books.begin()+i;
    if(flag==1)
    {
        Books.erase(itr);
        cout<<"         BOOK DELETED!!"<<endl;
    }
    else
        cout<<"SORRY ..BOOK NOT FOUND"<<endl;
}

void BookStore::updateBook(int bid)
{
    int flag=0,i;
    for(i=0;i<Books.size();i++)
    {
        if(Books[i].getID()==bid)
        {
            flag=1;
            break;
        }
    }
    if(flag==1)
    {
        int x;
        cout<<"What do you want to update?"<<endl<<endl;
        cout<<"Enter your Choice"<<endl;
        cout<<" 1 to update Book Name"<<endl;
        cout<<" 2 to update Book Author"<<endl;
        cout<<" 3 to update No. of Copies"<<endl<<endl;
        cin>>x;
        string name,auth;
        int ncpy;
        switch(x)
        {
            case 1:
                cout<<"Enter Book Name: "<<endl;
                cin.ignore();
                getline(cin,name);
                Books[i].setName(name);
                cout<<"         BOOK UPDATED!!"<<endl;
                break;
            case 2:
                cout<<"Enter Book's Author Name: "<<endl;
                cin.ignore();
                getline(cin,auth);
                Books[i].setAuthor(auth);
                cout<<"         BOOK UPDATED!!"<<endl;
                break;
            case 3:
                cout<<"Enter No. of copy: "<<endl;
                cin>>ncpy;
                Books[i].setNCpy(ncpy);
                cout<<"         BOOK UPDATED!!"<<endl;
                break;

            default:
                cout<<endl<<"INVALID CHOICE"<<endl;
                break;

        }

    }
    else
        cout<<"SORRY ..BOOK NOT FOUND"<<endl;
}

void checkBook(int bid)
{
    int flag=0,i;
    for(i=0;i<Books.size();i++)
    {
        if(Books[i].getID()==bid)
        {
            flag=1;
            break;
        }
    }
    if(flag==1)
    {
        cout<<"         BOOK FOUND!!"<<endl;
        cout<<"Book ID: "<<Books[i].getID()<<endl;
        cout<<"Book Name: "<<Books[i].getName()<<endl;
        cout<<"Author: "<<Books[i].getAuthor()<<endl;
        cout<<"No. of Books: "<<Books[i].getNCpy()<<endl;
        cout<<endl<<endl;
    }
    else
        cout<<"SORRY ..BOOK NOT FOUND"<<endl<<endl;
    system("pause");

}

void showBooks()
{
    system("cls");
    cout<<"               BOOK SHELF"<<endl<<endl;
    if(Books.size()==0)
        cout<<"EMPTY!!"<<endl<<endl;
    else
    {
        for(int i=0;i<Books.size();i++)
        {
            cout<<"Book ID: "<<Books[i].getID()<<endl;
            cout<<"Book Name: "<<Books[i].getName()<<endl;
            cout<<"Author: "<<Books[i].getAuthor()<<endl;
            cout<<"No. of Books: "<<Books[i].getNCpy()<<endl;
            cout<<endl<<endl;
        }
    }
    system("pause");
}

void panel()
{
    system("cls");
    cout<<endl<<endl;
    cout<<"           HEY,BOOKAHOLIC!! "<<endl;
    cout<<"Enter your Choice"<<endl;
    cout<<" 1 to ADD a Book"<<endl;
    cout<<" 2 to DISPLAY all Books"<<endl;
    cout<<" 3 to DELETE a Book"<<endl;
    cout<<" 4 to CHECK a particular Book"<<endl;
    cout<<" 5 to UPDATE Book details"<<endl;
    cout<<" 6 to EXIT"<<endl<<endl;
}

int main()
{
    BookStore bk;
    int choice;
    char c;
    while(true)
    {
        panel();
        cin>>choice;
        switch (choice)
        {
            case 1:
                do{
                    BookStore bk;
                    system("cls");
                    int bid,nocpy;
                    string name,author;
                    cout<<"           ADD BOOKS"<<endl;
                    cout<<endl<<"Enter BookID: ";
                    cin>>bid;
                    cin.ignore();
                    cout<<endl<<"Enter Book Name: ";
                    getline(cin,name);
                    cout<<endl<<"Enter Book Author: ";
                    getline(cin,author);
                    cout<<endl<<"No. of Books: ";
                    cin>>nocpy;

                    bk.addBook(bid,name,author,nocpy);
                    Books.push_back(bk);
                    cout<<endl<<"           BOOK ADDED!!";
                    cout<<endl<<"Want to add another book? (y/n) : ";
                    cin>>c;
                }
                while(c=='y' || c=='Y');
                break;


            case 2:
                showBooks();
                break;

            case 3:
                do{
                    BookStore bk;
                    system("cls");
                    int bid;
                    cout<<"           DELETE BOOKS"<<endl;
                    cout<<endl<<"Enter BookID of Book which you want to delete: ";
                    cin>>bid;
                    bk.deleteBook(bid);
                    cout<<endl<<"Want to delete another book? (y/n) : ";
                    cin>>c;
                }
                while(c=='y' || c=='Y');
                break;

            case 4:
                int bid;
                system("cls");
                cout<<"            CHECK BOOK"<<endl;
                cout<<endl<<"Enter BookID of Book which you want to check: ";
                cin>>bid;
                checkBook(bid);
                break;

            case 5:
                do{
                    BookStore bk;
                    system("cls");
                    int bid;
                    cout<<"            UPDATE BOOK DETAILS"<<endl;
                    cout<<endl<<"Enter BookID of Book you want to update: ";
                    cin>>bid;
                    bk.updateBook(bid);
                    cout<<endl<<"Want to update another book? (y/n) : ";
                    cin>>c;
                }
                while(c=='y' || c=='Y');
                break;

            case 6:
                cout<<endl<<"SEE YOU SOON..BYEEEE"<<endl;
                exit(0);
                break;

            default:
                cout<<endl<<"INVALID CHOICE"<<endl;
                break;
        }
    }
}
