#include <iostream>

using namespace std;

struct Vector 
{
    double* elem;
    int sz;
};

void initialise_vector(Vector& v, int s);



int main()
{

    Vector v;
    initialise_vector(v, 5);
    cout << v.sz << endl;

    
    return 0;
}

void initialise_vector(Vector& v, int s)
{
    v.elem = new double[s];
    v.sz = s;
}

// ways to access a struct via different ways
void f(Vector v, Vector& r, Vector* p)
{
    int i1 = v.sz;
    int i2 = r.sz;
    int i3 = p->sz;
}