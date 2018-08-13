#include<iostream>
using namespace std;

class Llist
{

    struct node
    {
        int value;
        int counts;
        struct node *next;
    };
    struct node *save;
    struct node *start;
    struct node *ptr;
    struct node *copy_;


public:

    Llist()
    {
        start = NULL;


    }
    void create_beg()
    {
        int num;
        struct node *new_node;
        cout << "Please enter the elements (-1 to EXIT): " << endl;
        cin >> num;



        while(num != -1)
        {

            new_node = new node;
            new_node ->value = num;
            new_node ->next = start;

            start = new_node;
            cin >> num;

        }
    }


   void create_end()
    {
        int num;
        struct node *new_node;
        cout << "Please enter the elements (-1 to EXIT): " << endl;
        cin >> num;


        while(num != -1)
        {
            new_node = new node;
            if(start == NULL)
            {

                new_node->next = start;
                start = new_node;
                save = new_node;
            }
            else
            {
                new_node ->value = num;
                new_node ->next = NULL;
                save ->next = new_node;
                save = new_node;
            }
            cin >> num;
        }

    }




    void show_ll()
    {
        ptr = start;
        while(ptr != NULL)
        {
            cout << ptr ->value << " ";
            ptr = ptr ->next;
        }
        cout << " " <<endl;
    }


        void insert_beg(int num)
    {
        struct node *new_node;
       new_node= new node;
       new_node->value=num;
       new_node->next=start;
       start=new_node;
    }


    void insert_end(int num)
    {
        struct node *new_node;
        new_node=new node;
        new_node->value=num;
        new_node->next=save->next;
        save->next=new_node;
        save=new_node;
    }



    void insert_after(int given,int num)
    {
        struct node *new_node;
        ptr=start;
        while(ptr!=NULL)
        {
            if(ptr->value==given)
                break;
            ptr=ptr->next;
        }
        new_node=new node;
        new_node->value=num;
        new_node->next=ptr->next;
        ptr->next=new_node;
    }
    void insert_before(int given,int num)
    {
        struct node *new_node;
        ptr=start;
        while(ptr!=NULL)
        {
            if(ptr->value==given)
                break;
                copy_=ptr;
            ptr=ptr->next;
        }
        new_node=new node;
        new_node->value=num;
        new_node->next=copy_->next;
        copy_->next=new_node;
    }
    void insert_sort(int num)
    {
        int flag;
        struct node *new_node;
        copy_ = NULL;
        ptr=start;
        while(ptr!=NULL)
        {
            if(ptr->value>num)
            {
                break;
            }
                copy_= ptr;
                ptr=ptr->next;
            }


            if(ptr==NULL)
            {
                insert_end(num);
            }
            else if(copy_== NULL)
            {

                insert_beg(num);
            }
            else{
                new_node= new node;
                new_node->value=num;
                new_node->next=copy_->next;
                copy_->next = new_node;


            }

        }

};



int main()
{   char ch;
    Llist ops;
    int flag = 0;
    do
    {
        int op;
        cout << "  " << endl;
        cout << "Enter 1 to create the Linked List (By Insertion at the end)." << endl;
        cout << "Enter 2 to create the Linked List (By Insertion at the beginning)" << endl;
        cout << "Enter 3 to display the elements." << endl;
        cout << "Enter 4 to insert new element into the list." << endl;
        cout << "Enter 0 to exit." << endl;
        cout << " " << endl;
        cout << " " << endl;
        cout << "Please enter the option: ";
        cin >> op;
        cout << " " << endl;
        cout << " " << endl;


        switch(op)
        {
            case(1): ops.create_end();
                break;
            case(2): ops.create_beg();
                break;
            case(3):ops.show_ll();
                break;
            case(4):

            {       cout << " " << endl;
                    cout << "\tTo Insert at the beginning of the list, Enter 10." << endl;
                    cout << "\tTo Insert at the end of the list, Enter 20." << endl;
                    cout << "\tTo Insert after a specific element in the list, Enter 30." << endl;
                    cout << "\tTo Insert before a specific element in the list, Enter 40." << endl;
                    cout << "\tTo Insert an element inside a sorted list, Enter 50." << endl;
                    cout << " " << endl;
                    cout << "\t\tChoice('a'/ 'b'/ 'c'/ 'd' / 'e'): ";
                    cin >> ch;
                    switch(ch)
                    {
                        case(10): ops.create_beg();
                            break;
                        case(20): ops.create_end();
                            break;
                    }


            }

                break;

            case(0): flag = 1;
                break;

        }
    }while(flag == 0);
}


