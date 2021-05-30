#include <iostream>

using namespace std;

/* 
    * 8. Исправьте функцию additem() из программы связного списка так, чтобы она добавляла 
    * новый элемент в конец списка, а не в начало. Это будет означать, что первый вставленный 
    * элемент будет выведен первым и результат работы программы будет следующим: 
    * 
    * 25 
    * 36 
    * 49 
    * 64 
    * 
    * Для того чтобы добавить элемент, вам необходимо будет пройти по цепи до конца списка, 
    * а затем изменить указатель последнего элемента так, чтобы он указывал на новый элемент.
    * 
    * Исходные комментарии на английском
    * Мои комментарии на русском
*/


struct Link {  // one element of list
    int data;  // data item
    Link* next;  // указатель на следующий объект типа Link
};


class LinkList {  // список объектов типа Link

private:
    Link* first;  // указатель на первый элемент

public:
    LinkList() {  // no-argument constructor
        first = NULL;  // no first Link
    }

    void additem(int d) {
    /* Метод добавления элементов в конец списка */
    
        Link* newlink = new Link;  // создаем новый элемент списка
        newlink->data = d;  // кладем в него значение
        if (first != NULL) {  // если первый элемент ссылается на другие элементы списка
            Link* p = first;  // создаем указатель на первый элемент
            while(p->next != NULL) {  // пока первый элемент ссылается на другие элементы списка
                p = p->next;  // двигаемся по списку
            }
            p->next = newlink;  // создаем ссылку из первого элемента на новый элемент
        }
        else
           first = newlink;  // первый элемент равен новому объекту со значением d
        newlink->next = NULL;  // последний элемент
}

    void display() {
        // display all links

        Link* current = first;  // установить указатель на первый элемент
        while (current != NULL) {  // quit on last Link
            cout << current->data << endl;  // print data
            current = current->next;  // установить указатель на следующий элемент
        }
    }
};


int main() {
    LinkList li;  // make linked list
    // добавить 4 элемента в список
    li.additem(25);
    li.additem(36);
    li.additem(49);
    li.additem(64);

    li.display();  // display entire list
    return 0;
}
