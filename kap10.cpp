#include "Vanlig.h"
#include "myMathFunctions.h"
using namespace std;


//sats för störst värde med samma funktionsnamn
void alraStorsta(int x) {
    cout << "Resultated blev: " << x << endl;
}

void theBiggest() {
    cout << biggest(3, 7) << endl; // 7
    cout << biggest(biggest(3, 8), biggest(7, 5)) << endl; // 8
    cout << biggest(biggest(-5.2, -14.3), -10.5) << endl; // -5.2
    assert(biggest(biggest(2.0, 2.5), 1.0) > 2.4);
    assert(biggest(biggest(2, 3), biggest(1, 8)) == 8);
}

void skrivSlumptal(int antal) {
    for (int i = 0; i < antal; i++)
        cout << rand() << endl;
    cout << endl;
}
void provaSlumptal() {
    skrivSlumptal(5);
    skrivSlumptal(5);
}
void provaCyklicitet() {
    int x = 42;
    long int anropTillRand = 0;
    int antalSeddaX = 0;
    long int senasteAnropsnummret = 0;
    while (antalSeddaX < 3) {
        int slumptal = rand();
        anropTillRand++;
        if (slumptal == x) {
            cout << "Sag " << x << "efter " << anropTillRand << "anrop'\n";
            if (antalSeddaX > 0)
                cout << anropTillRand - senasteAnropsnummret
                << "anrop senast forra " << endl;
            antalSeddaX++;
            senasteAnropsnummret = anropTillRand;
            cout << "Efter " << x << "kommer nu"
                << rand() << "," << rand() << "," << rand() << endl << endl;
            anropTillRand += 3;
        }
    }

}
//returnerar slumptal
int seedaSlumptal() {
    srand(unsigned(time(nullptr)));
    return rand();
}
void testaSeedaSlumptal() {
    for (int i = 0; i < 5; i++)
        cout << seedaSlumptal() << " "
        << endl;
}//returnerar slumptal
int tarningVarde() {
    int n = rand() % 6 + 1;
    return n;
}
int bruttoVinst(int t1, int t2, int t3) {
    if (t1 == 6 && t2 == 6 && t3 == 6)
        return 100;
    if (t1 == t2 && t2 == t3)
        return 50;
    if (t1 == t2 || t1 == t3 || t2 == t3)
        return 20;
    return 0;

}
bool boolFranUppmaning(const char uppmaning[]) {
    while (true) {
        char x;
        cout << uppmaning;
        cin >> x;
        if (x=='j')
            return true;
        if (x == 'n')
            return false;
        if (x!='j'&&x!='n')
            continue;

    }
    return false;


}
int bruttoVinstFranSpelOmgang() {
    int t1 = tarningVarde();
    int t2 = tarningVarde();
    int t3 = tarningVarde();
    int vinst = bruttoVinst(t1, t2, t3);
    cout << "Tarningarna blev: " << t1 << "," << t2 << "," << t3 << "," <<
        "Du vann: " << vinst << endl;
    return vinst;
}

void spelaTarningar() {
    int kapital = 100;
    while (kapital >= 10) {
        cout << "Du har " << kapital << " kronor" << endl;
        bool spelaMera = boolFranUppmaning("Vill du spela mer? (j/n):");
        if (spelaMera) {
            kapital = kapital - 10 + bruttoVinstFranSpelOmgang();
        }
        else {
            cout << "Du ar en ansvarsfull vuxen man med rakningar!" << endl;
            break;
        }
    }
}

int nettoVinst() {
    int t1 = tarningVarde();
    int t2 = tarningVarde();
    int t3 = tarningVarde();
    int vinst = bruttoVinst(t1, t2, t3) - 10;
    return vinst;
}
void skrivAnalysAvSpel() {
    double analys = 0;
    for (unsigned int i = 0; i < 99999; i++) {
        analys += nettoVinst();

    }
    cout << "Totala vinsten blev " << analys << '\n'
        << "Den genomslitliga vinsten blir " << analys / 1000000 << '\n';

}

string versalString(const string str) {
    string ch = str;
    for (unsigned int i = 0; i < str.size(); i++)
        ch[i] = toupper(str[i]);

    return ch;
}

void testaVstring() {
    assert(versalString("abc ABC 123") == "ABC ABC 123");
}


double flyttalFrannUppmaning(const char uppmaning[]) {


    while (true) {
        int x;
        cout << uppmaning;
        cin >> x;
        if (!cin.fail()) {
            return x;
        }
        else {
            cout << "gick inte o lasa forsok igen" << endl;
            cin.clear();
            cin.ignore(100, '\n');
        }

    }
}




void provaFlyttalFranUppmaning() {
    const double bokPris = flyttalFrannUppmaning("Hur många kronor kostar boken?");
    const double antalSidor = flyttalFrannUppmaning("Hur många sidor har boken?");

    const double procentAttLasa = flyttalFrannUppmaning("Hur många procent av sidorna kommer du att läsa? ");
    cout << "Du har angett att boken kostar " << bokPris << " kronor"
        << ", och att den har " << antalSidor << " sidor"
        << ", och att du tänker läsa " << procentAttLasa << "%" << endl;
}






void kap10() {
    
    skrivAnalysAvSpel();
}
