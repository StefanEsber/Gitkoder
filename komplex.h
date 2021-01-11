#ifndef KOMPLEX_H
#define KOMPLEX_H
#include <ostream>
#include <string>
#include <iostream>


struct Komplex {
    double re;
    double im;
};

Komplex komplexFromReIm(double re, double im);
Komplex komplexFromAbsArg(double absolutbelopp, double vinkelIGrader);

double real(Komplex c);
double img(Komplex c);
double abs(Komplex c);
double argGrader(Komplex c);

Komplex konjugat(Komplex c);
Komplex summa(Komplex a, Komplex b);
Komplex differens(Komplex a, Komplex b);
Komplex produkt(Komplex a, Komplex b);
Komplex kvot(Komplex a, Komplex b);


std::string stringFromKomplex(Komplex c);


Komplex konjugat(Komplex c);
Komplex summa(Komplex a, Komplex b);
Komplex differens(Komplex a, Komplex b);
Komplex produkt(Komplex a, Komplex b);
Komplex kvot(Komplex a, Komplex b);


Komplex operator+(Komplex a, Komplex b);
Komplex operator+(Komplex a, double b);
Komplex operator+(double a, Komplex b);
Komplex operator-(Komplex a, Komplex b);
Komplex operator-(Komplex a, double b);
Komplex operator-(double a, Komplex b);
Komplex operator*(Komplex a, Komplex b);
Komplex operator*(Komplex a, double b);
Komplex operator*(double a, Komplex b);
Komplex operator/(Komplex a, Komplex b);
Komplex operator/(Komplex a, double b);
Komplex operator/(double a, Komplex b);


std::ostream& operator<<(std::ostream& o, Komplex c);
std::string stringFromKomplex(Komplex c);

#endif // KOMPLEX_H
