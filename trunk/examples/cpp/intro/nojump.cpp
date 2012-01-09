class X
{
public:
    X();
};

X::X()
{
}

void f(int i)
{
    if(i < 10)
    {
        goto jump; // Error: goto bypasses init 
    }

    X x1;
jump:
    switch(i)
    {
        case 1: // Error: case bypasses init
            X x2;
            break;
        case 2: // Error: case bypasses init
            X x3;
            break;
    }
}

int main()
{
    f(9);
    f(10);
}

