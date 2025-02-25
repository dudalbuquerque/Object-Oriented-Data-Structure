#include <bits/stdc++.h>
#include <iostream>
#include "List.cpp"

using Key_t = unsigned int;
using namespace std;
// namespace std;


class Hashtable {
private:
    LinkedList<Key_t> *table;
    size_t sz;
    size_t cap;
    double maxLoad = 0.7;
    size_t hash(Key_t key);
    void rehash();
    public:
    size_t Size() const {return sz;}
    size_t Cap () const {return cap;}
    double loadFactor () const {return (double) sz/cap;}
    Hashtable(size_t cap): sz{0}, cap{cap}, table {new LinkedList<Key_t>[cap]} {};
    ~Hashtable();
    bool contains(Key_t k);
    bool insert (Key_t k);
    bool remove (Key_t k);

public:
    ~Hashtable() {
        delete[] table;
    }
    size_t hash(Key_t k) {
        return k % cap;
    }
    bool contains(Key_t k) {
        size_t pos = hash(k);
        LinkedList<Key_t> l = table[pos];
        int i = l.search(k);
        return i >= 0;
    }

    void rehash() {
        if (loadFactor() < maxLoad) return;
        Hashtable newT(2*cap);
        for (size_t i = 0; i < cap; i++) {
            LinkedList<Key_t> &l = table[i];
            for (size_t j = 0; j < l.size(); j++) {
                int key = l[j];
                newT.insert(key);
            }
        }
        cap = newT.cap;
        delete[] table;
        table = newT.table;
        newT.table = nullptr;
    }

    bool insert(Key_t k) {
        if (contains(k)) return false;
        rehash();
        size_t pos = hash(k);
        LinkedList<Key_t>& l = table[pos];
        l.prepend(k);
        sz++;
        return true;
    }

    bool remove(Key_t k) {
        size_t pos = hash(k);
        LinkedList<Key_t> l = table[pos];
        int i = l.search(k);
        if (i < 0) return false;
        l.remove(i);
        sz--;
        return true;
    }

    void printTable(Hashtable &t){
        cout << "" << endl;
        //for (size_)
        cout << "" << endl;
    }

};


int main() {
    size_t cap = 7;
    //double loadF = 4000.0;
    size_t n = 10000; //loadF * cap

    Hashtable t(cap);
    for (int i = 0; i < n; i++) {
    Key_t k = rand(); //% (100*n);
    //cout << "inserting " << k << endl;
    t.insert(k);
    }
    //printtable
    cout << "size: " << t.Size() << " cap: " << t.Cap() << " load: " << t.loadFactor() << endl;

    return 0;
}
