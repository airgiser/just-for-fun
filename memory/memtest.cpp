#include <iostream>
#include <vector>
#include <cstring>
#include "MemCheck.h"
using namespace std;

class FooObject {
public:
    FooObject(const char *str) {
        this->str = new char[strlen(str) + 1];
        strcpy(this->str, str);
    }

    ~FooObject() {
        delete [] str;
    }

private:
    char *str;
};

int main() {
    MEMCHECK_ON();
    cout << ">>starting..." << endl;
    int *p = new int;
    int *q = new int[3];
    int *r;
    FooObject strObj("foo string");
    delete p;
    delete [] q;
    delete r;
    cout << ">>end." << endl;
    MEMCHECK_OFF();
}
