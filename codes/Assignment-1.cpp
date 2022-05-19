#include<bits/stdc++.h>
using namespace std;

class data{
    public:
    string name;
    long long telephone_number;
};

class Telephone_book:public data{
    private:
    int size;
    list<data> *lst;
    public:
    Telephone_book(){
        this->size = 10;
        lst = new list<data>[10];
    }
    Telephone_book(int size){
        this->size = size;
        lst = new list<data>[size];
        
    }
    int getSum(long long n)
    {
        int sum = 0;
        while (n != 0) {
            sum = sum + n % 10;
            n = n / 10;
        }
        return sum;
    }
    void insert_data();
    void delet_data();
    void search_data();
    void display_data();
};

void Telephone_book::insert_data(){
    bool choice = true;
    data d;
    while(choice){
        cout<<"Enter the telephone number to enter\n";
        cin>>d.telephone_number;
        cout<<"Enter the Name\n";
        cin>>d.name;
        int index = getSum(d.telephone_number)%size;
        lst[index].push_back(d);
        cout<<"Would you like to enter more data? enter 1 for entering the data else 0\n";
        int ch;
        cin>>ch;
        if(ch!=1){
            choice= false;
        }
    }
}
void Telephone_book::display_data(){
    cout<<"\n--------Phoneboook----------\n";
    for(int i=0;i<size;i++){
        cout<<i<<". ";
        for(auto it = lst[i].begin();it!=lst[i].end();it++){
            cout<<it->name<<" "<<it->telephone_number<<" "<<": ";
        }
        cout<<"\n";
    }
}
void Telephone_book::search_data(){
    data d;
    long long search_number;
    cout<<"Enter the Number to search : ";
    cin>>search_number;
    int hash_value = getSum(search_number)%size;
    bool flag = true;
    for(auto it = lst[hash_value].begin();it!=lst[hash_value].end();it++){
        if (search_number == it->telephone_number){
            cout<<"Contact found at "<<hash_value<<": "<<it->name<<" "<<it->telephone_number<<"\n";
            flag = false;
            break;
        }
    }
        if(flag){
            cout<<"No contact found in the phonebook\n";
        }
}
void Telephone_book::delet_data(){
    long long delete_num;
    cout<<"Enter the Number to delete\n";
    cin>>delete_num;
    int hash_value = getSum(delete_num)%size;
    bool flag = true;
    for(auto it = lst[hash_value].begin();it!=lst[hash_value].end();it++){
        if (delete_num == it->telephone_number){
            flag = false;
            lst[hash_value].erase(it);
            cout<<"The data is delete\n";
            break;
        }
    }
        if(flag){
            cout<<"Value not find\n";
    }
}

int main(){
    int phone_book_size;
    cout<<"Enter the phone Entries Number to create a phone book\n";
    cin>>phone_book_size;
    Telephone_book t(phone_book_size);
    bool flag = true;
    while(flag){
        int ch;
        cout<<"--------------MENU---------------\n";
        cout<<"1.Insert data in phonebook\n";
        cout<<"2.Display contacts of phonebook\n";
        cout<<"3.Delete contacts in phonebook\n";
        cout<<"4.Search in phonebook\n";
        cout<<"5.Exit\n";
        cout<<"Enter the correct choice number\n";
        cin>>ch;
        switch(ch){
            case 1:{
                t.insert_data();
                break;
            }
            case 2:{
                t.display_data();
                break;
            }
            case 3:{
                t.delet_data();
                break;
            }
            case 4:{
                t.search_data();
                break;
            }
            case 5:{
                flag = false;
                break;
            }
            default :{
                cout<<"Enter the correct choice number\n";
            }
        }
    }
    return 0;
}