#include <iostream>
template <typename T>
void Swap(T& a, T& b);

struct point
{
char name[40];
double x;
double y;
};
// jawna specjalizacja
template <> void Swap<point>(point& j1, point& j2);
void Show(point& p);

int main()
{
using namespace std;
cout.precision(2);
cout.setf(ios::fixed, ios::floatfield);
int i = 10, j = 20;
cout << "i, j = " << i << ", " << j << ".\n";
cout << "Użycie generowanej przez kompilator funkcji "
"zamieniającej wartości int:\n";
Swap(i, j); // generuje void Swap(int &, int &)
cout << "Teraz i, j = " << i << ", " << j << ".\n";
point p1 = { "Początek wektora", 0.0, 0.0 };
point p2 = { "Koniec wektora", 10.5, 25.7 };
cout << "Przed zamianą struktur point:\n";
Show(p1);
Show(p2);
Swap(p1, p2); // używa void Swap(point &, point &)
cout << "Po zamianie struktur point:\n";
Show(p1);
Show(p2);
// cin.get();
return 0;
}

template <typename T>
void Swap(T& a, T& b) // wersja ogólna
{
T temp;
temp = a;
a = b;
b = temp;
}

// zamienia tylko pola salary i floor struktury job
template <> void Swap<point>(point& p1, point& p2) // specjalizacja
{
double t;
t = p1.x;
p1.x = p2.x;
p2.x = t;
t = p1.y;
p1.y = p2.y;
p2.y = t;
}

void Show(point& p)
{
using namespace std;
cout << p.name << ", x: " << p.x
<< ", y: " << p.y << endl;
}
