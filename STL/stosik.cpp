#include <iostream>
#include <stack>
using namespace std;

void menu(){
cout << "Dodaj na stos monety o DOWOLNYM* nominale!" << endl;
cout << "1. Pokaz jaka moneta jest na gorze stosu" <<endl;
cout << "2. Czy sa jakies monety na stosie?" <<endl;
cout << "3. Dodaj monete na stos" <<endl;
cout << "4. Usun ze stosu ostatnia monete (ta widoczna)" <<endl;
cout << "5. Ile jest elementow na stosie?" <<endl;
cout << "6. Wyswietl caly stos" << endl;
cout << "0. KONIEC" << endl;

cout << "* - musi sie miescic w zakresie int'a" << endl;
cout <<"Co chcesz zrobic? : " << endl;
}

/*
stack::top() in C++ STL
stack::empty() and stack::size() in C++ STL
stack::push() and stack::pop() in C++ STL
stack::swap() in C++ STL
stack::emplace() in C++ STL
Recent Articles on C++ Stack
*/

int main()
{
    menu();
    stack <int> stosik;
    stack <int> zapasowy;
    int wybor;
    int nominal;
    while(wybor!=0){

        cin >> wybor;

        switch(wybor)
        {
        case 1:
            if (stosik.empty())
                cout << "Stosik jest pusty" << endl;
            else
                {
                    cout<<stosik.top()<<endl;
                }
            break;
        case 2:
            if(stosik.empty())
                cout << "Stosik monet jest pusty!" << endl;
            else
                cout << "Masz cos na swoim stosiku" << endl;
            break;
        case 3:
                cout << "Monete o jakim nominale chcesz dodac na stos?: ";
                cin >> nominal;
                stosik.push(nominal);
            break;
        case 4:
            if (stosik.empty()){
                cout << "Stosik jest pusty" << endl;
                }
            else{
                cout << "Usunieto monete o nominale " << stosik.top() << endl;
                stosik.pop();
                }
            break;
        case 5:
            cout << "Masz " << stosik.size() << " monet" <<endl;
            break;
        case 6:
            while(!stosik.empty()){
                cout<< stosik.top() << " ";
                zapasowy.push(stosik.top());
                stosik.pop();
            }
            while(!zapasowy.empty()){
                stosik.push(zapasowy.top());
                zapasowy.pop();
            }
            cout << endl;
            break;
        default:
            cout << "Podano zly numer" <<endl;
            break;
        }
        cout <<"Co chcesz zrobic? : " << endl;
    }

    cout << "KONIEC" << endl;

    return 0;
}
