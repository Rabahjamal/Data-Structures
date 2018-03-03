#include "HashTable.h"
using namespace std;

int main()
{
    HashTable<int, int>*h = new HashTable<int, int>;
    h->insert(3, 7);
    h->insert(4, 8);
    h->insert(103, 2);
    h->insert(5, 10);
    cout << h->search(3) << endl;
    cout << h->get(4) << endl;
    h->remove(103);
    h->insert(105, 10);
    cout << h->search(103) << endl;
    cout << h->search(105) << endl;
    cout << h->search(5) << endl;
    cout << h->size << endl;
    cout << h->empty() << endl;

}
