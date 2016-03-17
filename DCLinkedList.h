#ifndef DOUBLECIRCULARLINKEDLIST_H_INCLUDED
#define DOUBLECIRCULARLINKEDLIST_H_INCLUDED

/*Double Circular Linked List implementation*/

template <class Type>
struct Node{

    Node* next;
    Type* key;
    Node* prev;

};

template <class Type>
class DoubleCircularLinkedList {

private:
    Node<Type>* m_node;
public:
    DoubleCircularLinkedList();
    bool isEmpty();
    Type* popKey();
    void pushKey(Type* key);
    void next();
    void previous();
    Type* getCurrentKey();
   // print();
};

template <class Type>
DoubleCircularLinkedList<Type>::DoubleCircularLinkedList()
{
    m_node = NULL;
}

template <class Type>
bool DoubleCircularLinkedList<Type>::isEmpty()
{
    if(m_node)
        return false;
    else
        return true;
}

template <class Type>
Type* DoubleCircularLinkedList<Type>::popKey()
{
    Type* key = NULL;

    if(m_node != NULL)
    {
        if(m_node->next != m_node)
        {
            m_node->prev->next = m_node->next;
            m_node->next->prev = m_node->prev;

        }

        key = m_node->key;
        delete m_node;
    }
        return key;
}

template <class Type>
void DoubleCircularLinkedList<Type>::pushKey(Type* key)
{
    Node<Type>* newNode = new Node<Type>();
    newNode->key = key;

    if(m_node == NULL)
    {
            m_node = newNode;
            m_node->next = m_node;
            m_node->prev = m_node;
    }
    else
    {
        newNode->prev = m_node;
        newNode->next = m_node->next;
        newNode->next->prev = newNode;
        m_node->next = newNode;
    }
}

template <class Type>
void DoubleCircularLinkedList<Type>::next(){
    if(!isEmpty())
        m_node = m_node->next;
}

template <class Type>
void DoubleCircularLinkedList<Type>::previous()
{
    if(!isEmpty())
        m_node = m_node->prev;
}

template <class Type>
Type* DoubleCircularLinkedList<Type>::getCurrentKey()
{
    if(isEmpty())
        return NULL;
    else
        return m_node->key;
}





#endif
