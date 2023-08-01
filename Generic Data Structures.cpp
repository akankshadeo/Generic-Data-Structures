#include<iostream>
using namespace std;

//Structure for Singly Linear and Singly Circular
template<class T>
struct NodeS
{
    T data;
    struct NodeS *next;
};

//Structure for Doubly Linear and Doubly Circular
template<class T>
struct NodeD
{
    T data;
    struct NodeD *next;
    struct NodeD *prev;
};

//Structure for Binary tree
template<class T>
struct NodeB
{
    T data;
    struct NodeB *lchild;
    struct NodeB *rchild;
};


///////////////////////////////////////////////////////////////////
//                  SINGLY LINEAR LINKED LIST CODE               //
///////////////////////////////////////////////////////////////////

template<class T>
class SinglyLL
{
public:
    struct NodeS<T> * First;
    int iCount;

    SinglyLL();
    ~SinglyLL();

    void Display();
    int Count();

    void InsertFirst(T no);
    void InsertLast(T no);
    void InsertAtPos(T no, int);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);
};

template<class T>
SinglyLL<T> :: SinglyLL()
{
    First = NULL;
    iCount = 0;
}

template<class T>
SinglyLL<T> :: ~SinglyLL()
{
    NodeS<T> * temp = First;

    for (int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        temp = First;
        First = First -> next;
        delete temp;
    }
}

template<class T>
void SinglyLL<T> :: Display()
{
        NodeS<T> * temp = First;

        cout<<"Elements of Singly Linear Linked Linked List are : \n";
        while(temp != NULL)
        {
            cout<< " |"<<temp->data<<"| -> ";
            temp = temp -> next;
        }
        cout<<"NULL\n";
}

template<class T>
int SinglyLL<T> :: Count()
{
        return iCount;
}

template<class T>
void SinglyLL<T>:: InsertFirst(T no)
{
    NodeS<T> * newn = new NodeS<T>;         //**

    newn-> data = no;
    newn-> next = NULL;

    if (First == NULL)   //LL is empty
    {
        First = newn;
    }
    else               //LL contains at least one node
    {
        newn -> next = First;
        First = newn;
    }

    iCount++;
}

template<class T>
void SinglyLL<T> :: InsertLast(T no)
{
    NodeS<T> * newn = new NodeS<T>;

    newn-> data = no;
    newn->next = NULL;

    if (First == NULL)   //LL is empty
    {
        First = newn;
    }
    else               //LL contains at least one node
    {
        NodeS<T> * temp = First;

        while (temp -> next != NULL)
        {
            temp = temp->next;
        }
        temp -> next = newn;
    }

    iCount++;

}

template<class T>
void SinglyLL<T> :: InsertAtPos(T no, int ipos)
{
    if ((ipos < 1) || (ipos > iCount + 1))
    {
        cout<<"Invalid Position \n";
        return;
    }

    if (ipos == 1)
    {
        InsertFirst(no);
    }
    else if (ipos == iCount + 1)
    {
        InsertLast(no);
    }
    else
    {
        NodeS<T> * temp = First;
        int iCnt = 0;

        for (iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp = temp -> next;
        }

        NodeS<T> * newn = new NodeS<T>;

        newn-> data = no;
        newn->next = NULL;

        newn->next = temp->next;
        temp -> next = newn;

        iCount++;
    }

}

template<class T>
void SinglyLL<T> :: DeleteFirst()
{
    if (First == NULL)     //Empty LL
    {
        return;
    }
    else if (First -> next == NULL)         //1 node in LL
    {
        delete First;
        First = NULL;
    }
    else       //More than one node in LL
    {
        NodeS<T> * temp = First;
        First = First-> next;
        delete temp;
    }

    iCount--;
}

template<class T>
void SinglyLL<T> :: DeleteLast()
{
    if (First == NULL)     //Empty LL
    {
        return;
    }
    else if (First -> next == NULL)         //1 node in LL
    {
        delete First;
        First = NULL;
    }
    else       //More than one node in LL
    {
        NodeS<T> * temp = First;

        while(temp -> next -> next != NULL)
        {
            temp = temp -> next;
        }
        delete temp->next;
        temp->next = NULL;
    }

    iCount--;     //not applicable for if part
}


template<class T>
void SinglyLL<T> :: DeleteAtPos(int ipos)
{
    if ((ipos < 1) || (ipos > iCount))
    {
        cout<<"Invalid Position \n";
        return;
    }

    if (ipos == 1)
    {
        DeleteFirst( );
    }
    else if (ipos == iCount)
    {
        DeleteLast();
    }
    else
    {
        NodeS<T> * temp = First;
        NodeS<T> * tempX = NULL;
        int iCnt = 0;

        for (iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp = temp -> next;
        }

        tempX = temp -> next;
        temp->next = temp->next->next;
        delete tempX;

        iCount--;
    }
}

///////////////////////////////////////////////////////////////////
//                SINGLY CIRCULAR LINKED LIST CODE               //
///////////////////////////////////////////////////////////////////

template<class T>
class SinglyCL
{
public:
    struct NodeS<T> * First;
    struct NodeS<T> *Last;
    int iCount;

    SinglyCL();
    ~SinglyCL();

    void Display();
    int Count();

    void InsertFirst(T no);
    void InsertLast(T no);
    void InsertAtPos(T no, int);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);

};

template<class T>
SinglyCL<T> :: SinglyCL()
{
    First = NULL;
    iCount = 0;
    Last = NULL;
}

template<class T>
SinglyCL<T> :: ~SinglyCL()
{
    NodeS<T> * temp = First;

    for (int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        temp = First;
        First = First -> next;
        delete temp;
    }
}

template<class T>
void SinglyCL<T> :: Display()
{
        NodeS<T> * temp = First;

        cout<<"Elements of Singly Linear Linked Linked List are : \n";
        while(temp != NULL)
        {
            cout<< " |"<<temp->data<<"| -> ";
            temp = temp -> next;
        }
        cout<<"NULL\n";
}

template<class T>
int SinglyCL<T> :: Count()
{
        return iCount;
}


template<class T>
void SinglyCL<T> :: InsertFirst(T no)
{
    NodeS<T> * newn = new NodeS<T>;

    newn-> data = no;
    newn->next = NULL;

    if (First == NULL && Last == NULL)
    {
        First = newn;
        Last = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }
    Last -> next = First;
    iCount++;
}

template<class T>
void SinglyCL<T> :: InsertLast(T no)
{
    NodeS<T> * newn = new NodeS<T>;

    newn-> data = no;
    newn->next = NULL;

    if (First == NULL && Last == NULL)
    {
        First = newn;
        Last = newn;
    }
    else
    {
        Last->next = newn;
        Last = newn;
    }
    Last -> next = newn;
    iCount++;

}

template<class T>
void SinglyCL<T> :: InsertAtPos(T no,int ipos)
{
    if ((ipos < 0) || (ipos > iCount + 1))
    {
        cout<<"Invalid position\n";
    }

    if (ipos == 1)
    {
        InsertFirst(no);
    }
    else if (ipos == iCount +1)
    {
        InsertLast(no);
    }
    else
    {
        NodeS<T> * temp = First;
        NodeS<T> * newn = new NodeS<T>;

        newn-> data = no;
        newn->next = NULL;

        for (int icnt = 1; icnt < ipos - 1; icnt++)
        {
            temp = temp->next;
        }

        newn -> next = temp -> next;
        temp -> next = newn;
    }
    iCount++;
}

template<class T>
void SinglyCL<T> :: DeleteFirst()
{
    if (iCount == 0)
    {
        cout<<"Nothing in Linked List\n";
        return;
    }
    else if (iCount == 1)
    {
        delete(First);
        First = NULL;
        Last = NULL;
    }
    else
    {
        NodeS<T> * temp = First;
        First = First -> next;
        delete(temp);
    }
    Last -> next = First;
    iCount--;
}

template<class T>
void SinglyCL<T> :: DeleteLast()
{
    if (iCount == 0)
    {
        cout<<"Nothing in Linked List\n";
        return;
    }
    else if (iCount == 1)
    {
        delete(First);
        First = NULL;
        Last = NULL;
    }
    else
    {
        NodeS<T> * temp = First;

        while (temp -> next != Last)
        {
            temp =  temp -> next;
        }

        delete(Last);
        Last = temp;
        Last -> next = First;

    }
    Last -> next = First;
    iCount--;

}

template<class T>
void SinglyCL<T> :: DeleteAtPos(int ipos)
{
    if ((ipos < 0) || (ipos > iCount))
    {
        cout<<"Invalid position\n";
    }

    if (ipos == 1)
    {
        DeleteFirst();
    }
    else if (ipos == iCount +1)
    {
        DeleteLast();
    }
    else
    {
        NodeS<T> * temp = First;
        NodeS<T> * tempX = NULL;

        for (int icnt = 1; icnt < ipos - 1; icnt++)
        {
            temp = temp->next;
        }

        tempX = temp -> next;

        temp -> next = temp -> next -> next;
        delete(tempX);
    }
    iCount--;

}

///////////////////////////////////////////////////////////////////
//                DOUBLY LINEAR LINKED LIST CODE                //
///////////////////////////////////////////////////////////////////

template<class T>
class DoublyLL
{
public:
    struct NodeD<T> * First;
    int iCount;

    DoublyLL();
    ~DoublyLL();

    void Display();
    int Count();

    void InsertFirst(T no);
    void InsertLast(T no);
    void InsertAtPos(T no, int);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);

};

template<class T>
DoublyLL<T> :: DoublyLL()
{
    First = NULL;
    iCount = 0;
}

template<class T>
DoublyLL<T> :: ~DoublyLL()
{
    NodeD<T> * temp = First;

    for (int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        temp = First;
        First = First -> next;
        delete temp;
    }

}

template<class T>
void DoublyLL<T> :: Display()
{
        NodeD<T> * temp = First;

        cout<<"Elements of Singly Linear Linked Linked List are : \n";
        while(temp != NULL)
        {
            cout<< " |"<<temp->data<<"| -> ";
            temp = temp -> next;
        }
        cout<<"NULL\n";
}

template<class T>
int DoublyLL<T> :: Count()
{
        return iCount;
}

template<class T>
void DoublyLL<T> :: InsertFirst(T no)
{
    NodeD<T> * newn = new NodeD<T>;

    newn-> data = no;
    newn->next = NULL;

    if (First == NULL)
    {
        First = newn;
    }
    else
    {
        First -> prev = newn;
        newn -> next = First;
        First = newn;
    }
    iCount++;
}

template<class T>
void DoublyLL<T> :: InsertLast(T no)
{
    NodeD<T> * newn = new NodeD<T>;

    newn-> data = no;
    newn->next = NULL;


    if (First == NULL)
    {
        First = newn;
    }
    else
    {
        NodeD<T> * temp = First;
        while(temp -> next != NULL)
        {
            temp = temp -> next;
        }
        temp -> next = newn;
        newn -> prev = temp;
    }
    iCount++;

}

template<class T>
void DoublyLL<T> :: InsertAtPos(T no, int ipos)
{
    if ((ipos < 1) || (ipos > iCount + 1))
    {
        cout<<"Invalid Position\n";
        return;
    }

    if (ipos == 1)
    {
        InsertFirst(no);
    }
    else if (ipos == iCount + 1)
    {
        InsertLast(no);
    }
    else
    {
        NodeD<T> * newn = new NodeD<T>;

        newn-> data = no;
        newn->next = NULL;

        NodeD<T> * temp = First;

        for (int icnt = 1; icnt < ipos - 1 ; icnt++)
        {
              temp = temp -> next;
        }

        newn -> next = temp -> next;
        temp -> next -> prev = newn;
        newn -> prev = temp;
        temp -> next = newn;
    }
    iCount++;
}

template<class T>
void DoublyLL<T> :: DeleteFirst()
{
    if (iCount == 0)
    {
        cout<<"Nothing in Linked List\n";
        return;
    }
    else if (iCount == 1)
    {
        delete(First);
        First = NULL;
    }
    else
    {
        NodeD<T> * temp = First;
        First = First -> next;
        delete temp;
    }
    iCount--;
}

template<class T>
void DoublyLL<T> :: DeleteLast()
{
    if (iCount == 0)
    {
        cout<<"Nothing in Linked List\n";
        return;
    }
    else if (iCount == 1)
    {
        delete(First);
        First = NULL;
    }
    else
    {
        NodeD<T> * temp = First;

        while (temp -> next -> next != NULL)
        {
            temp = temp -> next;
        }
        delete(temp-> next);
        temp -> next = NULL;
    }
    iCount--;
}

template<class T>
void DoublyLL<T> :: DeleteAtPos(int ipos)
{
    if ((ipos < 1) || (ipos > iCount))
    {
        cout<<"Invalid Position\n";
        return;
    }

    if (ipos == 1)
    {
        DeleteFirst();
    }
    else if (ipos == iCount)
    {
        DeleteLast();
    }
    else
    {
        NodeD<T> * temp = First;

        for (int icnt = 1; icnt < ipos - 1 ; icnt++)
        {
              temp = temp -> next;
        }

        temp -> next = temp -> next -> next;
        delete(temp->next-> prev);
        temp -> next -> prev = temp;

    }
    iCount--;

}

///////////////////////////////////////////////////////////////////
//                DOUBLY CIRCULAR LINKED LIST CODE                //
///////////////////////////////////////////////////////////////////

template<class T>
class DoublyCL
{
public:
    struct NodeD<T> * First;
    struct NodeD<T> *Last;
    int iCount;

    DoublyCL();
    ~DoublyCL();

    void Display();
    int Count();

    void InsertFirst(T no);
    void InsertLast(T no);
    void InsertAtPos(T no, int);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);

};

template<class T>
DoublyCL<T> :: DoublyCL()
{
    First = NULL;
    iCount = 0;
    Last = NULL;
}

template<class T>
DoublyCL<T> :: ~DoublyCL()
{
    NodeD<T> * temp = First;

    for (int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        temp = First;
        First = First -> next;
        delete temp;
    }

}


template<class T>
void DoublyCL<T> :: Display()
{
        NodeD<T> * temp = First;

        cout<<"Elements of Singly Linear Linked Linked List are : \n";
        while(temp != NULL)
        {
            cout<< " |"<<temp->data<<"| -> ";
            temp = temp -> next;
        }
        cout<<"NULL\n";
}

template<class T>
int DoublyCL<T> :: Count()
{
        return iCount;
}

template<class T>
void DoublyCL<T> :: InsertFirst(T no)
{
    NodeD<T> * newn = new NodeD<T>;

    newn-> data = no;
    newn->next = NULL;

    if (First == NULL && Last == NULL)
    {
        First = newn;
        Last = newn;
    }
    else
    {
        newn -> next = First;
        First -> prev = newn;
        First = newn;
    }
    Last -> next = First;
    First -> prev = Last;
    iCount++;
}

template<class T>
void DoublyCL<T> :: InsertLast(T no)
{
    NodeD<T> * newn = new NodeD<T>;

    newn-> data = no;
    newn->next = NULL;

    if (First == NULL && Last == NULL)
    {
        First = newn;
        Last = newn;
    }
    else
    {
        Last -> next = newn;
        newn -> prev = Last;
        Last = Last -> next;
    }
    Last -> next = First;
    First -> prev = Last;
    iCount++;

}

template<class T>
void DoublyCL<T> ::InsertAtPos(T no, int ipos)
{
    if ((ipos < 0) || (ipos > iCount + 1))
    {
        cout<<"INvalid position\n";
    }

    if (ipos == 1)
    {
        InsertFirst(no);
    }
    else if (ipos == iCount +1)
    {
        InsertLast(no);
    }
    else
    {
        NodeD<T> * temp = First;

        for (int icnt = 1; icnt < ipos - 1; icnt++)
        {
            temp = temp->next;
        }

    NodeD<T> * newn = new NodeD<T>;

    newn-> data = no;
    newn->next = NULL;

        newn -> next = temp -> next;
        temp -> next -> prev = newn;

        temp -> next = newn;
        newn -> prev = temp;
    }
    iCount++;
}

template<class T>
void DoublyCL<T> :: DeleteFirst()
{
    if (iCount == 0)
    {
        return;
    }
    else if (iCount == 1)
    {
        delete(First);
        First = NULL;
        Last = NULL;
    }
    else
    {
        First = First-> next;
        delete First -> prev;

        First -> prev = Last;
        Last -> next = First;

    }
    iCount--;
}

template<class T>
void DoublyCL<T> :: DeleteLast()
{
    if (iCount == 0)
    {
        return;
    }
    else if (iCount == 1)
    {
        delete(First);
        First = NULL;
        Last = NULL;
    }
    else
    {
        Last = Last-> prev;
        delete Last -> next;

        First -> prev = Last;
        Last -> next = First;

    }
    iCount--;

}

template<class T>
void DoublyCL<T> :: DeleteAtPos(int ipos)
{
    if ((ipos < 0) || (ipos > iCount))
    {
        cout<<"Invalid position\n";
    }

    if (ipos == 1)
    {
        DeleteFirst();
    }
    else if (ipos == iCount)
    {
        DeleteLast();
    }
    else
    {
        NodeD<T> * temp = First;

        for (int icnt = 1; icnt <= ipos - 1; icnt++)
        {
            temp = temp->next;
        }
        temp -> next = temp->next -> next;
        delete temp -> next -> prev;
        temp -> next -> prev = temp;
    }
    iCount--;
}

///////////////////////////////////////////
//             Binary Tree              //
//////////////////////////////////////////


template<class T>
class BinaryTree
{
public:
    struct NodeB<T> * First;
    int iCount;

    BinaryTree();
    ~BinaryTree();

    void Display();
    int CountNodes();
    int CountLeafNodes();
    int CountParentNodes();

    void Insert(T no);

    void Preorder();
    void Inorder();
    void Postorder();

    bool Search(T no);
};

template<class T>
void BinaryTree<T> :: Insert(T no)
{
    NodeB<T> * newn = new NodeB<T>;
    NodeB<T> * temp = First;

    newn-> data = no;
    newn->lchild = NULL;
    newn->rchild = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        while(1)
        {
            if(no == temp->data)
            {
                cout<<"Duplicate element : uanble to insert\n";
                delete newn;
                break;
            }
            else if(no > temp->data)
            {
                if(temp->rchild == NULL)
                {
                    temp->rchild = newn;
                    break;
                }
                temp = temp -> rchild;
            }
            else if(no < temp -> data)
            {
                if(temp->lchild == NULL)
                {
                    temp->lchild = newn;
                    break;
                }
                temp = temp->lchild;
            }
        }
    }
}

template<class T>
void BinaryTree<T> :: Preorder()
{
    NodeB<T> * temp = First;
    if(First != NULL)
    {
        cout<<"%d\t",temp->data;
        Preorder(temp->lchild);
        PreOrder(temp->rchild);
    }
}

///////////////////////////////////////////
//               Stack                   //
//////////////////////////////////////////

template<class T>
class Stack
{
public:
    struct NodeS<T> * First;
    int iCount;

    Stack();
    ~Stack();

    void Display();
    int Count();

    void push(T no);
    T pop();

};

template<class T>
Stack<T> :: Stack()
{
    First = NULL;
    iCount = 0;
}

template<class T>
Stack<T> :: ~Stack()
{
    NodeS<T> * temp = First;

    for (int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        temp = First;
        First = First -> next;
        delete temp;
    }
}

template<class T>
void Stack<T> :: Display()
{
    if(First == NULL)
    {
        cout<<"Nothing to display here. Stack is empty.\n";
    }
    else
    {
        cout<<"Elements of Stack are : \n";

     NodeS<T> * temp = First;

    for (int icnt = 1; icnt <= iCount; icnt++)
    {
        cout<<temp->data<<"\n";
        temp = temp -> next;
    }
    }
}

template<class T>
int Stack<T> :: Count()
{
    return iCount;
}

template<class T>
void Stack<T> :: push(T no)
{
    NodeS<T> * newn = new NodeS<T>;

    newn-> data = no;
    newn-> next = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        NodeS<T> * temp = First;

        while (temp -> next != NULL)
        {
            temp = temp -> next;
        }
        temp -> next = newn;
    }
    iCount++;
}

template<class T>
T Stack<T> :: pop()
{
    T Value;

    if (iCount == 0)
    {
        cout<<"Stack is empty\n";
        return;
    }
    else if(iCount == 1)
    {
        Value = First -> data;
        delete First;
        First = NULL;
    }
    else
    {
        NodeS<T> *  temp = First;

        while (temp -> next -> next != NULL)
        {
            temp = temp -> next;
        }

        Value = temp -> next -> data;
        delete temp -> next;
        temp -> next = NULL;
    }
    iCount--;
    return Value;

}

///////////////////////////////////////////
//                Queue                  //
//////////////////////////////////////////

template<class T>
class Queue
{
public:
    struct NodeS<T> * First;
    int iCount;

    Queue();
    ~Queue();

    void Display();
    int Count();

    void enqueue(T no);
    T dequeue();

};

template<class T>
Queue<T> :: Queue()
{
    First = NULL;
    iCount = 0;
}

template<class T>
Queue<T> :: ~Queue()
{
    NodeS<T> * temp = First;

    for (int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        temp = First;
        First = First -> next;
        delete temp;
    }
}

template<class T>
void Queue<T> :: Display()
{
    if(First == NULL)
    {
        cout<<"Nothing to display here. Queue is empty.\n";
    }
    else
    {
        cout<<"Elements of Queue are : \n";

     NodeS<T> * temp = First;

    for (int icnt = 1; icnt <= iCount; icnt++)
    {
        cout<<temp->data<<"\n";
        temp = temp -> next;
    }
    }
}

template<class T>
int Queue<T> :: Queue()
{
    return iCount;
}

template<class T>
void Stack<T> :: enqueue(T no)
{
    NodeS<T> * newn = new NodeS<T>;

    newn-> data = no;
    newn-> next = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        NodeS<T> * temp = First;

        while (temp -> next != NULL)
        {
            temp = temp -> next;
        }
        temp -> next = newn;
    }
    iCount++;
}

template<class T>
T Queue<T> :: dequeue()
{
    T Value;

    if (iCount == 0)
    {
        cout<<"Stack is empty\n";
        return;
    }
    else(iCount == 1)
    {
        Value = First -> data;
        delete First;
        First = NULL;
    }
    iCount--;
    return Value;
}

int main()
{
    BinaryTree<int> obj1;

    obj1.Insert(21);
    obj1.Insert(23);
    obj1.Insert(15);
    obj1.Insert(78);
    obj1.Insert(45);
    obj1.Insert(10);
    obj1.Insert(90);
    obj1.Insert(18);
    obj1.Insert(7);

    cout<<"\nElements in Preorder format : \n";
    obj1.Preorder();
    return 0;
}
