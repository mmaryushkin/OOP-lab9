#include <iostream>
#include <string>

using namespace std;

/* 
    * 7. Модифицируйте класс person из программы, представленной ниже, чтобы он включал в себя не 
    * только имя человека, но и сведения о его зарплате в виде поля salary типа float. 
    * 
    * Вам будет необходимо изменить методы setName() и printName() на setData() и printData(), 
    * включив в них возможность ввода и вывода значения salary, как это можно сделать с именем. 
    * Вам также понадобится метод getSalary(). Используя указатели, напишите функцию salsortQ, 
    * которая сортирует указатели массива persPtr по значениям зарплаты. Попробуйте вместить всю 
    * сортировку в функцию salsort(), не вызывая других функций, как это сделано в программе PERS0RT
    * 
    * Исходные комментарии на английском
    * Мои комментарии на русском
    * 
    * P.S. ПОТОМУ ЧТО Я РУССКИЙ!!!
*/


class Person {  // class of persons

protected:
    string name;  // person's name
    float salary;  // зарплата

public:
    void setData() {  // получение данных
        cout << "\nEnter name: "; cin >> name;
        cout << "Enter salary: "; cin >> salary;
    }

    void printData() {  // отобразить данные на экране
        cout << name << "\n" << salary << endl;
    }

    string getName() {  // return the name
        return name;
    }

    float getSalary() {  // возвращает зарплату
        return salary;
    }
};


void order(Person** pp1, Person** pp2) {
    /* Функция меняет местами значения зарплат по двум указателям */

    // Если первая зарплата больше второй зарплаты
    if ((*pp1)->getSalary() > (*pp2)->getSalary()) {  // разименовывем указатели, чтобы получить указатель на объекты класса Person
        // поменять местами указатели на объекты класса Person
        Person* tempptr = *pp1;
        *pp1 = *pp2;
        *pp2 = tempptr;
    }
} 


void bsort(Person** pp, int n) {
    /* Функция сортирует указатели на объекты класса Person */

    for(int j = 0; j < n; j++) {  // outer loop
        for(int k = j+1; k < n; k++) {
            order(pp+j, pp+k);  // поменять местами содержимое указателей
        }
    }
}


int main() {
    Person* persPtr[100];  // массив указателей на объекты класса Person
    int n = 0;  // кол-во объектов Person в массиве
    char choice;
    do {  // положить объект Person в массив
        persPtr[n] = new Person;  // создать новый объект
        persPtr[n]->setData();  // обращаемся к объекту по указателю и получаем данные
        n++;
        cout << "\nEnter another (y/n)?: "; cin >> choice;
    } while (choice == 'y');

    // напечатать исходный массив
    for (int j = 0; j < n; j++)
        persPtr[j]->printData();  // обращаемся к объекту по указателю и печатаем данные
    
    bsort(persPtr, n);  // отсортировать указатели
    cout << "\nSorted list: " << endl;
    for (int j = 0; j < n; j++)
        persPtr[j]->printData();
    
    cout << endl;
    return 0;
}
