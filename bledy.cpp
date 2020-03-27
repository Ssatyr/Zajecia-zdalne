//
//  main.cpp
//  bledy
//
//  Created by Witek Kardas on 25/02/2020.
//  Copyright © 2020 Witek Kardas. All rights reserved.
//

#include <iostream>
#include "Bledy.h"

using namespace std;

double dodawanie(double a, double b);
double odejmowanie(double a, double b);
double mnozenie(double a, double b);
double dzielenie(double a, double b);

int main(int argc, const char * argv[]) {
    
    double a, b;
    
    while(1){
        cout << "Podaj dwie liczby" << endl;
        cin >> a >> b;
        
        try{
            cout << dodawanie(a, b) << endl;
            cout << odejmowanie(a, b) << endl;
            cout << mnozenie(a, b) << endl;
            cout << dzielenie(a, b) << endl;
        }
        catch (bad_dzielenie & bd){
            bd.msg();
            cout<< "Podaj kolejne dwie" << endl;
            continue;
        }
    }
    
    return 0;
}


double dodawanie(double a, double b){
    return a+b;
}

double odejmowanie(double a, double b){
    return a-b;
}

double mnozenie(double a, double b){
    return a*b;
}

double dzielenie(double a, double b){
    if (a == 0 || b == 0)
        throw bad_dzielenie(a,b);
    return a/b;
}
