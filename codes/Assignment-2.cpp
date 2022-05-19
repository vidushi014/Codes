/* 
    Ques:-  Implement all the functions of a dictionary (ADT) using hashing and handle collision 
            using chaining with/without replacement.Data : set of(key, value) , keys are mapped 
            to values, keys must be comparable, keys must be unique. 
            Standard operations: Insert(key, value), Find(key), Delete(key)
*/

#include <bits/stdc++.h>
using namespace std;

const int MAX = 10;
class dictionary;
class node
{
    string key, value;
    node *next;

public:
    friend class dictionary;
    node()
    {
        next = NULL;
    }
    node(string key, string value)
    {
        this->key = key;
        this->value = value;
        next = NULL;
    }
};

class dictionary
{
    node *head[MAX];

public:
    dictionary()
    {
        for (int i = 0; i < MAX; i++)
            head[i] = NULL;
    }
    int hashf(string word);
    bool insert(string, string);
    string find(string word);
    bool deleteWord(string word);
    void display();
};

bool dictionary::deleteWord(string word)    //TO DELETE A WORD
{
    int index = hashf(word);
    node *tmp = head[index];
    node *par = head[index];
    if (tmp == NULL) //if no word is present at that index
    {
        return false;
    }
    
    if (tmp->key == word && tmp->next == NULL) //only one word is present
    {
        tmp->next = NULL;
        delete tmp;
        return true;
    }

    while (tmp->key != word && tmp->next != NULL)
    {
        par = tmp;
        tmp = tmp->next;
    }
    if (tmp->key == word && tmp->next != NULL)
    {
        par->next = tmp->next;
        tmp->next = NULL;
        delete tmp;
        return true;
    }
    if (tmp->key == word && tmp->next == NULL) //delete at end
    {
        par->next = NULL;
        tmp->next = NULL;
        delete tmp;
        return true;
    }
    return false;
}

string dictionary::find(string word)    //TO FIND A WORD
{
    int index = hashf(word);
    node *start = head[index];
    if (start == NULL)
        return "-1";
    while (start != NULL)
    {
        if (start->key == word)
            return start->value;
        start = start->next;
    }
    return "-1";
}

bool dictionary::insert(string word, string meaning)    //TO ADD A WORD
{
    int index = hashf(word);
    node *p = new node(word, meaning);

    if (head[index] == NULL)
    {
        head[index] = p;
        //cout << "\n" << word << " Inserted. ";
        return true;
    }
    else
    {                                               //COLLISION HANDLING
        node *start = head[index];
        while (start->next != NULL)
        {
            start = start->next;
        }
        start->next = p;
        //cout << "\n" << word << " Inserted. ";
        return true;
    }
    return false;
}

int dictionary::hashf(string word)  //HASH FUNCTION
{
    int asciiSum = 0;
    for (int i = 0; i < word.length(); i++)
    {
        asciiSum = asciiSum + word[i];
    }
    return (asciiSum % 10);
}

void dictionary :: display()
    {
        for (long i = 0; i < MAX; i++)
        {
            node *temp = new node;
            temp = head[i];
            cout << i << " : ";
            while (temp != NULL)
            {
                cout << " ->" << temp->key;
                temp = temp->next;
            }
            cout << "\n";
        }
    }

int main()
{
    dictionary oxford;
    int choice;
    string word, meaning;

    do
    {
        cout << "\n\n**** DICTIONARY ****\n";
        cout << "1.Insert Word\n2.Find Word\n3.Delete Word\n4.Display\n5.Exit\n";
        
        cout << "\nEnter Your Choice :";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter Word: ";
                cin >> word;
                cout << "Enter Meaning: ";
                cin >> meaning;
                if (oxford.insert(word, meaning))
                    cout << "\n -- "<< word << " Inserted into dictionary.";
                else
                    cout << "\nFailed to insert.";
                break;

            case 2:
                cout << "\nEnter Word to Search: ";
                cin >> word;
                meaning = oxford.find(word);
                if (meaning != "-1")
                    cout << "\n Word Is present.\n " << word << " = " << meaning;
                else
                {
                    cout << "\n Word Not Present";
                }
                break;

            case 3:
                cout << "Enter Word to Delete: ";
                cin >> word;
                if (oxford.deleteWord(word))
                    cout << " Word is deleted.";
                else
                {
                    cout << "\nFailed to delete " << word;
                }
                break;

            case 4:
                oxford.display();
                break;

            case 5:
                cout<<"\n--- Thank You ---\n";
                break;

            default:
                cout << "\nWrong Choice.";
        }
    } while (choice != 5);

    return 0;
}