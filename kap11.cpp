#include "Vanlig.h"

using namespace std;

void bytVarden(int* pA, int* pB) {
    swap(*pA, *pB);
}
void bytVarden(double* pA, double* pB) {
    swap(*pA, *pB);

}


void automattestaBytVarden() {
    int a = 1;
    int b = 2;
    bytVarden(&a, &b);
    double x = 1.5;
    double y = 2.5;
    bytVarden(&x, &y);
    assert(x == 2.5 && y == 1.5);
}

int length(const char* string) {
    const char* p = string;
    while (*p != 0)
        p++;
    return p - string;
}
void automattestaLength() {
    assert(length("hej") == 3);
}

bool arLika(const char* str1, const char* str2) {
    if (length(str1) != length(str2))
        return false;
    int i = 0;
    while (*(str1 + i) != 0) {
        if (*(str1 + i) != *(str2 + i))
            return false;
        i++;
    }
    return true;
}



void automattestaArLika() {
    assert(arLika("abcd", "abcd"));
    assert(!arLika("abcd e", "abcd"));
    assert(!arLika("abcd", "abcd e"));
    assert(!arLika("abcd", "abcX"));
    assert(!arLika("abcd", "Xbcd"));

}

void konverteraTillVersaler(char* str) {
    int i = 0;
    while (*(str + i) != 0) {
        *(str + i) = toupper(*(str + i));
        i++;
    }

}

void konverteraTillVersaler() {
    char str1[] = "abc ABC 123 .,- xyz";
    char str2[] = "ABC ABC 123 .,- XYZ";
    konverteraTillVersaler(str1);
    konverteraTillVersaler(str2);
    assert(arLika(str1, str2));
    cout << str1 << str2 << endl;
}

void konverteraTilLlRubrik(char* str) {
    int i = 0;
    while (*(str + i) != 0) {
        if (*(str + i - 1) == 32)
            *(str + i) = toupper(*(str + i));
        else*(str + i) = tolower(*(str + i));
        i += 1;


    }
    *str = toupper(*str);
}

void konverteraTillRubrik() {
    char str1[] = "this is a test";
    char str2[] = "THIS IS A TEST";
    char rubrik[] = "This Is A Test";
    konverteraTilLlRubrik(str1);
    konverteraTilLlRubrik(str2);
    assert(arLika(str1, rubrik));
    assert(arLika(str1, rubrik));
    cout << str1 << " " << rubrik << endl;

}

void skrivStringar(const char** strings, int antal) {
    int i = 0;
    while (antal != 0) {
        cout << *(strings + i) << endl;
        i++;
    }
    cout << *strings << endl;
}
void provaSkrivStringar() {
    const int antal = 7;
    const char* dagnamn[antal] = { "mondag", "tisdag", "onstag", "torsdag", "fredag", "lordag", "sondag" };
    skrivStringar(dagnamn, antal);
}

void fyllMedKonstant(int* pBegin, int* pEnd, int konstant) {
    for (int* p = pBegin; *p < *pEnd; p += 1)
        *p = konstant;
}

void testaFyllMedKonstant() {
    int arr[10];
    fyllMedKonstant(&arr[0], &arr[10], 42);
}





void skrivUtArr(const int* pBegin, int* pEnd) {
    for (int const* p = pBegin; p < pEnd; p += 1)
        cout << *p;
    cout << endl;
}
void fyllMeedKonstant(int* pBegin, int* pEnd, int konstant) {
    for (int* p = pBegin; p < pEnd; p += 1)
        *p = konstant;
}
void fyllMedSlumptal(int* pBegin, int* pEnd, int minst, int storst) {
    for (int* p = pBegin; p < pEnd; p += 1)
        *p = (rand() % storst + 1 - minst) + minst;
}

int minst(const int* pBegin, const int* pEnd) {
    assert(pEnd - pBegin > 0);
    int minst = *pBegin;
    for (int const* p = pBegin; p < pEnd; p++) {
        if (minst > *p)
            minst = *p;
    }
    return minst;
}
int storst(const int* pBegin, const int* pEnd) {
    assert(pEnd - pBegin > 0);
    int storst = *pBegin;
    for (int const* p = pBegin; p < pEnd; p++) {
        if (storst < *p)
            storst = *p;
    }
    return storst;
}

bool isSorterad(const int* pBegin, const int* pEnd) {
    for (const int*p = pBegin; p<pEnd;p+=1){
        while(*p>*(p+1))
            return false;

    }
    return true;
}

bool innehaller(const int* pBegin, const int* pEnd, int x) {
    for (const int* p = pBegin; p < pEnd; p += 1) {
        if (*p == x)
            return true;
    }
    return false;
}
void testaArrayFunktionerna() {
    const int storlek = 10;
    int arr[storlek]{};
    fyllMeedKonstant(&arr[0], &arr[storlek],5);
    skrivUtArr(&arr[0], &arr[storlek]);
    arr[0]-= 1;
    arr[storlek - 1]+= 1;
    assert(isSorterad(&arr[0],&arr[storlek]));
    arr[0] = 6;
    assert(!isSorterad(&arr[0], &arr[storlek]));
    fyllMedSlumptal(&arr[0], &arr[storlek],-2,2);
    skrivUtArr(&arr[0], &arr[storlek]);
    arr[1]=-3;
    arr[storlek - 1]=3;
    int m = minst(&arr[0], &arr[storlek]);
    int s = storst(&arr[0], &arr[storlek]);
    assert(m == -3 && s == 3);
    assert(innehaller(&arr[0],&arr[storlek],3));
}


void forsokAndraVArden(int a, int& b) {
    a = 42;
    b = 42;
}
void anropaAndraVArden() {
    int j = 1;
    int k = 1;
    forsokAndraVArden(j, k);
    cout << "j = " << j << endl;
    cout << "k = " << k << endl;
}

char* cStringCopy(const char* cstring) {
    char* copy = new char[100];
    int i = 0;
    while (*(cstring + i) != 0) {
        *(copy + i) = *(cstring + i);
        i++;

    }
    return copy;
}
char* cstringFranUppmaning(const char* uppmaning) {
    cout << uppmaning;
    char str[100];
    cin >> setw(100) >> str;
    return cStringCopy(str);
}

void provaCstringFranUppmanuing() {
    const char* fornamn = cstringFranUppmaning("Ditt Fornamn: ");
    const char* efternamn = cstringFranUppmaning("Ditt efternamn: ");
    cout << "Hej " << fornamn << " " << efternamn << "!" << endl;

    delete[] fornamn;
    delete[] efternamn;
}

void bytVarden(int& a, int& b) {
    int c = a;
    a = b;
    b = c;
}
void bytVarden(double& a, double& b) {
    double d = a;
    a = b;
    b = d;


}

void automattesstaBytVarden() {
    int a = 1;
    int b = 2;
    bytVarden(a, b);
    assert(a == 2 && b == 1);
    double x = 1.5;
    double y = 2.5;
    bytVarden(x, y);
    assert(x == 2.5 && y == 1.5);
}
void fusk(int* pBegin, int* pEnd, int k) {
    for (int* pX = pBegin; pX < pEnd; pX++)
        *pX = k;
}
void fusktest() {
    const int n = 10;
    int tal[n]{ 1,1,1,1,1,1,1,1,1,1 };
    fusk(&tal[0], &tal[n], 2);
    fusk(&tal[n / 2], &tal[n], 3);
    int produkt = tal[0] * tal[n - 1];
    cout << produkt << endl;
}





void kap11() {
    automattesstaBytVarden();
}