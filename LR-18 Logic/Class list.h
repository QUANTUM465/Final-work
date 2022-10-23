#pragma once
#include "Class element.h"

using namespace std;

template<typename T>
class List 
{
public:
    List(); // �������� ������������ �����
    ~List(); // �������� ����������� �����
    
    void swap(int index1, int index2);
    void clear(); // �������� ������� ��������� ������ ������
    void pop_front(); // �������� ������� ��������� ������� ��������
    void push_back(T data); // �������� ������� ��������� �������� � ����� �����
    int GetSize() { return Size; } // �������� ������� �����
    T& operator[](const int index); // �������� ������� �������������� ���������
    void push_front(T data); // �������� ������� ��������� �������� � ������� �����
    void pop_back(); // �������� ������� ��������� ��������� ��������
    void insert(T value, int index); // ��������� �������� � ����-��� ������� ������
    void removeAt(int index); // ��������� �������� �� �������� ��������
private:
    template<typename T> // �������� ������� 
    class element
    {
    public:
        element* pNext; //� ��'��� ����� ���������� ������ ��������� �� ���������� �������
        T data = data;  // ���� �� ������ ��'��� 
        element(T data = T(), element* pNext = nullptr) // ����������� ������ element
        {
            this->pNext = pNext;
            this->data = data;
        }
    };
    int Size; // ��������� ����� 
    element<T>* head; //�������� �� ������� ������

};

template<typename T>
List<T>::List() // ��������� ������������
{
    Size = 0; // ����� ������
    head = nullptr; // �������� �� �������� ��������
}
template<typename T>
List<T>::~List() // ��������� �����������
{
    clear();
}

template<typename T>
inline void List<T>::swap(int index1, int index2)
{
    element<T>* previous1 = this->head;     // �������� �� ������ ������������ ��������
    element<T>* previous2 = this->head;
    element<T>* temp;
    if (index1 == 0)
    {
        for (int i = 0; i < index2 - 1; i++)
        {
            previous2 = previous2->pNext;
        }
        element<T>* current1 = this->head;  
        element<T>* current2 = previous2->pNext;
        
        previous2->pNext = current1;
        
        temp = current1->pNext;             //
        current1->pNext = current2->pNext;  // ���� pNext ���� �������� ����� �������� ����� temp
        current2->pNext = temp;             //

        this->head = current2;

        return;
    }
    for (int i = 0; i < index1-1; i++)
    {
        previous1 = previous1->pNext;

    }
    for (int i = 0; i < index2-1; i++)
    {
        previous2 = previous2->pNext;
    }
    element<T>* current1 = previous1->pNext;  // ��������� ����� current
    element<T>* current2 = previous2->pNext;  

    temp = previous1->pNext;
    previous1->pNext = previous2->pNext;
    previous2->pNext = temp;

    temp = current1->pNext;
    current1->pNext = current2->pNext;
    current2->pNext = temp;
}

template<typename T>
void List<T>::clear() // ��������� ������ ������
{
    while (Size)
    {
        pop_front();
    }
}

template<typename T>
void List<T>::pop_front()
{
    element<T>* temp = head; // �������� �� ���� ������� ��������
    // ������� �� ���������� 1 � 2 
    // �� ��������� ������� element<T> temp = head �� ������� �� ���� �� ��������� ��������
    // head = head->pNext ������ 2 ������� �������� ������ 
    // �� ������� ��� ���� ��� �� ���������� ��������� ������
    head = head->pNext; // ��������� ������� ������ ���������� ��������
    delete temp; // ��������� ������ �� �� ����� temp

    Size--; // ������ �������� ������� �������� ������� ���� ���� ��������
}

template<typename T>
void List<T>::push_back(T data) // ������� ��������� � �������� � ����� ������ 
{
    if (head == nullptr) // �������� �� �������� �������� ���� true �� ��������� ������ ������
    {
        head = new element<T>(data);
    }
    else
    {
        element<T>* current = this->head; // ��������� ����� current
        // pNext ����� �� ������ ���������� �������� ���� ����� ����
        // ���� ���� �������� pNext �� ������� nullptr �� ���� ��������� �������
        // ����� ������� ������ ������ � ��� ���� � ����� ������ ���� � ������ ���������� ��������
        // ������� �� ��������� ����� 1 � 2
        // ��������� �������� ����� 1 � ���� pNext ������ ���������� �������� � ��� ��� �� ������ ������ 1 �������� ���� nullptr
        // ���� ���� pNext �� ������� nullptr ���� ���� ��������� ������� ������      
        // ���� ��������� �������� ����� 2 ���� pNext �������� ����� 1
        // ���� ��������� � pNext 1 �������� ������ ������ 2 
        while (current->pNext != nullptr) // �������� �� �� ����� ���� ������ ������
        {
            current = current->pNext;    // ���� current ������������ ������ ���������� �������� ���� �� ���� �� ���� ������ 
                                         // ������� ������� �� ������ nullptr ��� ���� �� � ������
        }
        current->pNext = new element<T>(data); // ������� ������ �������� � ������
    }
    Size++;
}

template<typename T>
T& List<T>::operator[](const int index) // ����� ���������� ������ �� �������� �������������� �������������� ��������� [] 
{
    int counter = 0;
    element<T>* current = this->head;
    while (current != nullptr) // ������ ���� �������� current �� ������� nullptr 
    {
        if (counter == index) // ���� ������ �������� ������� �������� �� ��������� ���� data � ����� ����������� ����������
        {
            return current->data;
        }
        current = current->pNext; // � ������ ������� ������� ������ ���������� �������� 
        counter++; // ˳������� �������� �� 1
    }
}

template<typename T>
void List<T>::push_front(T data) // ��������� �������� �� ������� ������
{
    head = new element<T>(data, head);
    Size++;
}

template<typename T>
void List<T>::pop_back() //��������� ��������� ��������
{
    removeAt(Size - 1);
}

template<typename T>
void List<T>::insert(T value, int index) // ��������� �������� � ����-��� ������� ������
{ // � ������ ����������� ��� ��������� �������� ���� �� ����� �������� � ���� ������ �� ���� ����� ������� ������� ����
    if (index == 0)
    {
        push_front(value);
    }
    else
    {
        element<T>* previous = this->head; // ��������� �������� ������� head
        for (int i = 0; i < index - 1; i++)
        {                                 // ����������� ������� � �������� ����� �������
            previous = previous->pNext;   // ����� ���� ������� ������� �� ������ 3 �� ��� ���� ���� ������� � �������� 2
        }                            // ���� ���� ���������� �� previous ���� ������ ������ � ���� ������� � �������� 2     
        element<T>* newelement = new element<T>(value, previous->pNext); // ��������� ������ �������� 
        // ���� ������ ���� � ������ �������� 4 � ��� ��� �� ������� 2 �������� ������ ���� ���������� �������� 3
        // p.s. � ����� ���� 3 ������� ���� 4 � ����� 3
        previous->pNext = newelement; // ���������� � ��� pNext �������� 2 ������������ ����� �������� 3
        Size++;
    }
}

template<typename T>
void List<T>::removeAt(int index) // ��������� �������� �� �������� ��������
{
    if (index == 0)
    {
        pop_front();
    }
    else
    {
        element<T>* previous = this->head; // ������ ��������� ������� ������� ���� ���� �� ������ ��������
        for (int i = 0; i < index - 1; i++)
        {
            previous = previous->pNext;
        }
        element<T>* toDelete = previous->pNext; // ������ �������� 2 ��� ���� ��� ����� ���� ��������
        previous->pNext = toDelete->pNext; //��������� 1 �������� ������ 3 ���� ���� ��������� ����� 2
        delete toDelete; // �������� ��������� �����
        Size--;
    }

}






