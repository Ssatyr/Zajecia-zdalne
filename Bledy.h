//
//  Bledy.h
//  bledy
//
//  Created by Witek Kardas on 25/02/2020.
//  Copyright © 2020 Witek Kardas. All rights reserved.
//
#include<iostream>

#ifndef Bledy_h
#define Bledy_h


class bad_dzielenie{
private:
    double d1, d2;
public:
    bad_dzielenie(double a = 0, double b = 0) : d1(a), d2(b) {}
    void msg();
};

inline void bad_dzielenie::msg()
{
    std::cout << "Podane wartosci to: " << d1 << " " << d2 << "(jeden z nich to 0)" << std::endl;
}


#endif /* Bledy_h */
