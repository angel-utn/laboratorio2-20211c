#include <iostream>
using namespace std;

int main()
{
    int vec[4] = {111, 222, 333, 444};
    int *p, i;

    p = vec;
    for(i=0; i<4; i++){
        cout << *p << endl;
        p++;
    }

    return 0;
}
