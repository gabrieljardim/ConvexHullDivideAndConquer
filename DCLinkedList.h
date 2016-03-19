#ifndef DOUBLECIRCULARLINKEDLIST_H
#define DOUBLECIRCULARLINKEDLIST_H

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
    int count();

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
        key = m_node->key;

        if(m_node->prev != m_node) //caso onde a lista tem mais que 1 elemento
        {
            Node<Type>* temp;

            temp = m_node->prev;
            m_node->prev->next = m_node->next;
            m_node->next->prev = m_node->prev;
            delete m_node;
            m_node = temp;
        }
        else
        {
                delete m_node;
                m_node = NULL;
        }
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
        newNode->prev = m_node->prev;
        newNode->next = m_node;
        newNode->prev->next = newNode;
        m_node->prev = newNode;
        m_node = newNode;
    }
}

template <class Type>
void DoubleCircularLinkedList<Type>::next()
{
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

template <class Type>
int DoubleCircularLinkedList<Type>::count()
{
    int count = 0;
    if(m_node)
    {
        Node<Type>* aux;
        aux = m_node;

        do
        {
            m_node = m_node->next;
            count++;

        } while(m_node != aux);
    }
    return count;
}


#endif
