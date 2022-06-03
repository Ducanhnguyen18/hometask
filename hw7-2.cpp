#include <iostream>
using namespace std;

struct fraction
{
    int a;
    int b;
};

bool valid(fraction &f)
{
    return f.b != 0;
}

void optimize(fraction &f)
{

    int _a = (f.a > 0) ? (f.a) : (-f.a);
    int _b = (f.b > 0) ? (f.b) : (-f.b);

  
    while (_a != 0 && _b != 0)
    {
        if (_a < _b)
            _b %= _a;
        else
            _a %= _b;
    }

    int c = _a + _b; 
    f.a /= c;
    f.b /= c;
}

void disp(const fraction &f)
{
    if (f.a == 0)
        cout << f.a << endl;
    else
    {
        if ((f.a < 0 && f.b > 0) || (f.a > 0 && f.b < 0))
        {
            cout << "-";
        }
        cout << ((f.a > 0) ? (f.a) : (-f.a)) << "/";
        cout << ((f.b > 0) ? (f.b) : (-f.b)) << endl;
    }
}

int main()
{
    cout << "Input fraction: ";
    int a, b;
    cin >> a >> b;

    fraction x = {a, b};
    if (valid(x))
    {
        optimize(x);
        disp(x);
    }
    else
    {
        cout << "Error: Invalid fraction." << endl;
    }
    return 0;
}