#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    srand( time (NULL));
    for(int i=0; i < 40; i++){
        cout << rand()%1000000000 <<endl;
    }

    return 0;
}
