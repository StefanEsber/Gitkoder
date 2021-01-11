#ifndef KORT_H
#define KORT_H
#include <string>
#include <ostream>

enum class Kortfarg {
    hjarter,
    spader,
    ruter,
    klover,
};

struct Spelkort {
    int valor;//1..13
    Kortfarg farg;
};

Spelkort spelkort(Kortfarg farg, int valor);

std::string stringFranKortFarg(Kortfarg farg);
std::string stringFranKortvalor(int kortvalor);
std::string stringFranSpelKort(Spelkort kort);




struct Kortlek {
    Spelkort korten[52];
    int antalKortKvar;
};


Kortlek kortlekNy();
void blandaKortlek(Kortlek& kortlek);
Spelkort kortFranKorlek(Kortlek& kortlek);
int antalKortKvar(const Kortlek& kortlek);
void aterstallKorlek(Kortlek& kortlek);



#endif // KORT_H
