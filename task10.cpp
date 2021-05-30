#include <iostream>

using namespace std;

/* 
    * 10. Описанный в упражнении 9 подход нерационален, так как каждый из 10 массивов 
    * объявляется отдельно, с использованием отдельного имени, и каждый адрес получают отдельно. 
    * Вы можете упростить программу, используя операцию new, которая позволит вам выделить 
    * память для массивов в цикле и одновременно связать с ними указатели:
    * 
    * for ( j = 0: j < NUMARRAYS; j++ )	// создаем NUMARRAYS массивов
    * *( ар + j ) = new int [ MAXSIZE ]: //no MAXSIZE целых чисел в каждом
    * 
    * Перепишите программу упражнения 9, используя этот подход. Доступ к отдельному элементу 
    * массивов вы сможете получить, используя то же выражение, что и в упражнении 9, или 
    * аналогичное выражение с указателями: *(*(ap+j)+k).
*/

const int NUMARRAYS = 10;  // кол-во массивов
const int MAXSIZE = 10;  // максимальный размер массивов


int main() {
    int* ap[NUMARRAYS];  // создаем массив указателей
    for (int i = 0; i < NUMARRAYS; i++) {
        ap[i] = new int[MAXSIZE];  // создаем новый массив
    }

    // заполнение массивов значениями от 0 до 99
    int p = 0;
    for (int i = 0; i < NUMARRAYS; i++) {
        for (int j = 0; j < MAXSIZE; j++) {
            ap[i][j] = p + j;
        }
        p += 10;
    }

    // вывод данных на экран
    for (int i = 0; i < NUMARRAYS; i++) {
        for (int j = 0; j < MAXSIZE; j++)
            cout << ap[i][j] << " ";
        cout << "\n";
    }

    return 0;
}