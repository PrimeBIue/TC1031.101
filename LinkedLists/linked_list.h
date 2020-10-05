#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

#include <stddef.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <class T>
class Node
{
private:
    T val;
    Node<T> *next;

public:
    ~Node<T>() {};
    Node<T>(T pVal, Node<T> *pNext)
    {
        val = pVal;
        next = pNext;
    };

    T get_val() {return val;};
    void set_val(T pVal) {val = pVal;};
    Node<T> *get_next() {return next;};
    void set_next(Node<T> *pNext) {next = pNext;};
};

template <class T>
class LinkedList
{
protected:
    Node<T> *head;

public:
    ~LinkedList()
    {
        // to be implemented
    };
    LinkedList()
    {
        head = NULL;
    };

    int length()
    {
        int length = 0;
        Node<T> *ptr = head;
        while (ptr != NULL)
        {
            length++;
            ptr = ptr->get_next();
        }
        return length;
    };

    void print()
    {
        Node<T> *ptr = head;
        while (ptr != NULL)
        {
            std::cout << ptr->get_val() << ", ";
            ptr = ptr->get_next();
        }
        std::cout << std::endl;        
    }

    void push(T pVal)
    {
        Node<T> *node = new Node<T>(pVal, head);
        head = node;
    };

    void append(T pVal)
    {   
        Node<T> *node = new Node<T>(pVal, NULL);
        if(is_empty())
        {
            head = node;
            return;
        }
            

        Node<T> *ptr = head;


        while (ptr->get_next() != NULL)
        {
            ptr = ptr->get_next();
        }
        
        ptr->set_next(node);
    };

    int insert_item(T pVal, int index)
    {
        if (index > length())
            return -1;
        if (index < 0)
            return -2;
        if (index == 0)
        {
            push(pVal);
            return 1;
        }

        int i = 0;
        Node<T> *ptr = head;
        Node<T> *pre = NULL;
        while (ptr != NULL && index > i)
        {
            pre = ptr;
            ptr = ptr->get_next();
            i++;
        }
        Node<T> *node = new Node<T>(pVal, ptr);
        pre->set_next(node);
        return 1;
    };

    bool is_empty()
    {        
        return head == NULL;
    };

    int delete_item(int index)
    {
        if (is_empty())
            return -1;
        if (index >= length())
            return -1;
        if (index < 0)
            return -2;
        if (index == 0)
        {
            Node<T> *temp = head;
            head = head->get_next();
            delete temp;
            return 1;
        }

        int i = 0;
        Node<T> *ptr = head;
        Node<T> *pre = NULL;
        while (ptr->get_next() != NULL && index > i)
        {
            pre = ptr;
            ptr = ptr->get_next();
            i++;
        }
        pre->set_next(ptr->get_next());
        delete ptr;
        return 1;
    };

    int get_nth(int index, T &item)
    {
        if (index < 0)
            return -1;
        if (index >= length())
            return -2;
            
        int i = 0;
        Node<T> *ptr = head;
        while (ptr->get_next() != NULL && index > i)
        {
            ptr = ptr->get_next();
            i++;
        }
        item = ptr->get_val();
        return 1;
    };

    /*
        Dado un elemento devuelve el número de veces que el mismo aparece en la lista.
        Complejidad computacional: O(n)
    */

    int count(T searchFor)
    {
        int c = 0; //contador
        Node<T> *ptr = head; //puntero a la cabeza de la LinkedList

        /*El puntero avanza a traves de la lista y checa que 
        no sea igual a NULL y si su valor es igual a searchfor 
        aniade 1 al contador*/

        while (ptr != NULL)
        {
            if(ptr->get_val() == searchFor)
                c++;
            //Mueve al puntero una posición más adelante
            ptr = ptr->get_next();
        }
        return c;
    };

    /*
        Eliminar la lista enlazada y liberar memoria de todos sus nodos.
        Complejidad computacional: O(n)
    */
    void DeleteList()
    {
        Node<T> *ptr = head;
        Node<T> *next; //This saves the next position to later move the ptr variable
        while(ptr != NULL)
        {
            next = ptr->get_next();
            free(ptr); //This delocates a memory block
            ptr = next;
        }
        head = NULL; //Returns the value of head to NULL
    };

    /*
        Insertar un nodo en una lista enlazada ordenada.
        Complejidad computacional: O(n)
    */
    void SortedInsert (Node<T> *newNode)
    {
        T val = newNode->get_val();
        Node<T> *ptr = head;
        Node<T> *next = ptr->get_next();

        //En caso de que el valor del nuevo nodo sea menor al valor del head
        if(val < ptr->get_val())
        {
            head = newNode;
            newNode->set_next(ptr);
            return;
        }

        while(next != NULL)
        {
            if(ptr->get_val() <= val && val <= next->get_val())
            {
                ptr->set_next(newNode);
                newNode->set_next(next);
                return;
            }
            ptr = next;
            next = next->get_next();
        }
        ptr->set_next(newNode);

    };
    /*
        Eliminar duplicados de una lista ordenada.
        Complejidad computacional: O(n)
    */


    void RemoveDuplicates()
    {
        if(is_empty())
            return;

        Node<T> *ptr = head;
        Node<T> *next = ptr->get_next();
        while(next != NULL)
        {
            if(ptr->get_val() == next->get_val())
            {
                ptr->set_next(next->get_next());

                if(next->get_next() != NULL)
                    next = next->get_next();
                else
                {
                    delete next;
                    return;
                }
                    
            }
            else
            {
                ptr = next;
                next = next->get_next();
            }
        }
    };

    /*
        Invertir orden de una lista enlazada.
        Complejidad computacional: O(n)
    */
    void Reverse()
    {
        if(is_empty())
            return;

        Node<T> *a = head;
        Node<T> *b = NULL;
        Node<T> *c = NULL;

        while(a != NULL)
        {
            c = a->get_next();
            a->set_next(b);
            b = a;
            a = c;
        }
        head = b;

    };
};

#endif