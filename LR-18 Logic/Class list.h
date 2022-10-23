#pragma once
#include "Class element.h"

using namespace std;

template<typename T>
class List 
{
public:
    List(); // Прототип конструктора класу
    ~List(); // Прототип деструктора класу
    
    void swap(int index1, int index2);
    void clear(); // Прототип функції видалення цілого списку
    void pop_front(); // Прототип функції видалення першого елементу
    void push_back(T data); // Прототип функції додавання елементу в кінець спику
    int GetSize() { return Size; } // Прототип функції розміу
    T& operator[](const int index); // Прототип функції перевантаження оператора
    void push_front(T data); // Прототип функції додавання елементу в початок спику
    void pop_back(); // Прототип функції видалення останього елементу
    void insert(T value, int index); // Додавання елемента в будь-яку частину списка
    void removeAt(int index); // Видалення елементу за вказаним індексом
private:
    template<typename T> // Шаблонна функція 
    class element
    {
    public:
        element* pNext; //В об'єкті класу зберігається адреса вказівника на настпупний елемент
        T data = data;  // Данні які містить об'єкт 
        element(T data = T(), element* pNext = nullptr) // Конструктор классу element
        {
            this->pNext = pNext;
            this->data = data;
        }
    };
    int Size; // Тимчасова змінна 
    element<T>* head; //Вказівник на початок списку

};

template<typename T>
List<T>::List() // Реалізація конструктора
{
    Size = 0; // Розмір списку
    head = nullptr; // Вказівник на нульовий вказівник
}
template<typename T>
List<T>::~List() // Реалізація деструктора
{
    clear();
}

template<typename T>
inline void List<T>::swap(int index1, int index2)
{
    element<T>* previous1 = this->head;     // Вказівник на адресу попереднього елементу
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
        current1->pNext = current2->pNext;  // Обмін pNext двох елементів через тимасову змінну temp
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
    element<T>* current1 = previous1->pNext;  // Тимчасова змінна current
    element<T>* current2 = previous2->pNext;  

    temp = previous1->pNext;
    previous1->pNext = previous2->pNext;
    previous2->pNext = temp;

    temp = current1->pNext;
    current1->pNext = current2->pNext;
    current2->pNext = temp;
}

template<typename T>
void List<T>::clear() // Видалення цілого списку
{
    while (Size)
    {
        pop_front();
    }
}

template<typename T>
void List<T>::pop_front()
{
    element<T>* temp = head; // Вказівник на данні першого елементу
    // Приклад на елемментах 1 і 2 
    // За допомогою функції element<T> temp = head ми вказуємо на данні які необхідно видалити
    // head = head->pNext робить 2 елемент початком списку 
    // Це потрібно для того щоб не порушувати структуру списку
    head = head->pNext; // Присвоєння початку списку наступному елементу
    delete temp; // Видалення данних на які вказує temp

    Size--; // Потріно зменшити кількість елементів оскільки один було видалено
}

template<typename T>
void List<T>::push_back(T data) // Функція додавання в елемента в кінець списку 
{
    if (head == nullptr) // Вказівник на нульовий вказівник якщо true то створення нового списку
    {
        head = new element<T>(data);
    }
    else
    {
        element<T>* current = this->head; // Тимчасова змінна current
        // pNext вказує на адресу наступного елементу якщо такий існує
        // Якщо поле елементу pNext НЕ дорівнює nullptr то існує наступний елемент
        // Кожен елемент списку містить в собі данні а також адресу свою і адресу наступного елемента
        // Приклад на елементах номер 1 і 2
        // Присвоєння елементу номер 1 в поле pNext адреси наступного елементи в той час як адреса самого 1 елемента буде nullptr
        // Якщо поле pNext НЕ дорівнює nullptr отже існує наступний елемент списку      
        // Потім присвоєння елементу номер 2 поля pNext елемента номер 1
        // Отже інфорація з pNext 1 елемента містить адресу 2 
        while (current->pNext != nullptr) // Перевірка на що вказує поле адреси данних
        {
            current = current->pNext;    // Полю current присвоюється адреса наступного елементу поки не дійде до кінця списку 
                                         // Останній елемент має адресу nullptr так само як і перший
        }
        current->pNext = new element<T>(data); // Додання нового елементу в список
    }
    Size++;
}

template<typename T>
T& List<T>::operator[](const int index) // Пошук необхідних данних за індексом використовуючи перевантаження оператора [] 
{
    int counter = 0;
    element<T>* current = this->head;
    while (current != nullptr) // Працює якщо вказівник current не дорівнює nullptr 
    {
        if (counter == index) // Якщо індекс елемента дорівнює шуканому то повертаємо поле data в якому знаходитьяс інформація
        {
            return current->data;
        }
        current = current->pNext; // В іншому випадку просимо адресу наступного елемента 
        counter++; // Лічильник збільшуємо на 1
    }
}

template<typename T>
void List<T>::push_front(T data) // Додавання елементу на початок списку
{
    head = new element<T>(data, head);
    Size++;
}

template<typename T>
void List<T>::pop_back() //видалення останього елемента
{
    removeAt(Size - 1);
}

template<typename T>
void List<T>::insert(T value, int index) // Додавання елемента в будь-яку частину списка
{ // В дужках записуються два параметри спочатку данні які треба записати а потім індекс під яким даний елемент повинен бути
    if (index == 0)
    {
        push_front(value);
    }
    else
    {
        element<T>* previous = this->head; // Тимчасова вказівник дорівнює head
        for (int i = 0; i < index - 1; i++)
        {                                 // Знаходження елемент з індексом перед заданим
            previous = previous->pNext;   // Тобто якщо заданий елемент має індекс 3 то цей цикл шукає елемент з індексом 2
        }                            // Коли цикл виконується то previous буде містити адресу і данні елемент з індексом 2     
        element<T>* newelement = new element<T>(value, previous->pNext); // Створення нового елемента 
        // який містить данні і адресу елемента 4 в той час як елемент 2 міститиме адресу ново створеного елемента 3
        // p.s. у цьому циклі 3 елемент став 4 а новий 3
        previous->pNext = newelement; // Інформація в полі pNext елемента 2 присвоюється адресі елемента 3
        Size++;
    }
}

template<typename T>
void List<T>::removeAt(int index) // Видалення елементу за вказаним індексом
{
    if (index == 0)
    {
        pop_front();
    }
    else
    {
        element<T>* previous = this->head; // знайти попередній елемент відносно того який ми хочемо видалити
        for (int i = 0; i < index - 1; i++)
        {
            previous = previous->pNext;
        }
        element<T>* toDelete = previous->pNext; // адреса елемента 2 для того щоб пізніше його видалити
        previous->pNext = toDelete->pNext; //присвоєння 1 елементу адреси 3 який після видалення стане 2
        delete toDelete; // очищення тимчасової змінної
        Size--;
    }

}






