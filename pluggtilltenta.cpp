#include "Vanlig.h"
#include "myMathfunctions.h"

using namespace std;




void konveteraTillRubrik(char* str) {
	char* pStr = str;
	for (int i = 0; (pStr + i) != 0; i += 1) {
		if (*(pStr + i - 1) == 32 || i == 0)
			*(pStr + i) = toupper(*(pStr + i));

	}

}




void skrivVaxel(int antalkronor) {

	const int antalValorer = 8;
	int valorer[antalValorer]{ 500,200,100,20,10,5,2,1 };
	int antal = 0;
	for (int i = 0; i < antalValorer; i += 1) {
		antal = antalkronor / valorer[i];
		antalkronor -= valorer[i] * antal;
		if (antal > 0)
			cout << antal << " X " << valorer[i] << endl;

	}
}

void skrivUtArr(int arr[], int antal) {
	cout << "(";
	for (int i = 0; i < antal; i += 1)
		cout << arr[i] << " ";
		cout << ")" << endl;
}

void fyllMedKonstant(int arr[], int antal, int konstant) {
	for (int i = 0; i < antal; i += 1) 
		arr[i] = konstant;
	}

void fyllMedSlumptal(int arr[], int antal, int minst, int störst) {
	for (int i = 0; i < antal; i += 1) {
		arr[i] = (rand() % störst + 1 - minst) + minst;
		}
}
int minst(int arr[], int antal) {
	int minst = arr[0];
	for (int i = 0; i < antal; i += 1) {
		if(minst > arr[i])
			minst=arr[i];
	}
	return minst;
}
int störst(int arr[], int antal) {
	int störst = arr[0];
	for (int i = 0; i < antal; i += 1) {
		if (störst < arr[i])
			störst = arr[i];
	}
	return störst;
}
bool arSorterad(int arr[], int antal) {
	for (int i = 0; i < antal; i += 1) {
		if (arr[i] < arr[i-1] )
			return false;
	}
	return true;
}
bool innehaller(int arr[], int antal, int x) {
	for (int i = 0; i < antal; i += 1) {
		if (arr[i] == x)
			return true;
	}
	return false;
}
void provaArrayFunktionerna() {
	const int storlek = 10;
	int arr[storlek];
	fyllMedKonstant(arr, storlek, 5);
	skrivUtArr(arr, storlek);
	arr[0] -= 1;
	arr[storlek - 1] += 1;
	if (arSorterad(arr, storlek))
		cout << "Arrayen är sorterad" << endl;
	else cout << "BUG BUG ärSorterad tycks inte fungera" << endl;
	arr[0] = 6;
	if (arSorterad(arr, storlek))
		cout << "BUG ärSorterad tror att arrayen är sorterad" << endl;
	fyllMedSlumptal(arr, storlek, -2, 2);
	skrivUtArr(arr, storlek);
	arr[1] = -3; // Detta blir det minsta värdet
	arr[storlek - 1] = 3; // Detta blir det största värdet
	int m = minst(arr, storlek);
	int s = störst(arr, storlek);
	cout << "minst=" << m << " storst=" << s << endl;
	if (m != -3 || s != 3)
		cout << "BUG!!!!!!!!!!!" << endl;
	if (!innehaller(arr, storlek, 3))
		cout << "BUG!!!!!!!!!!!" << endl;
}



void sorteraMedSelection(int arr[], int antal) {
	for (int i = 0; i < antal; i += 1) {
		int kMin = i;
		for (int k = i; k < antal; k += 1) {
			if (arr[k] < arr[kMin])
				kMin =k;
		}
		int gamlaI = arr[i];
		arr[i] = arr[kMin];
		arr[kMin] = gamlaI;
	}
	
}
void provaSorteraMedSelection() {
	const int storlek = 20;
	int arr[storlek];
	fyllMedSlumptal(arr, storlek, 0, 100);
	if (arSorterad(arr, storlek))
		cout << "BUG Det verkar som om fyllMedSlumptal inte fungerar" << endl;
	sorteraMedSelection(arr, storlek);
	if (arSorterad(arr, storlek))
		cout << "Det verkar som om select-sorteringen fungerade" << endl;
	else cout << "BUG i select sorteringsalgoritmen" << endl;
}

bool arLika(const char str1[], const char str2[]) {
	for (int i = 0; str1[i] != 0 || str2[i] != 0;i+=1) {
			if (str1[i] != str2[i])
				return false;
		}
		return true;
	
}


void automattestaarLika() {
	assert(arLika("abcd", "abcd"));
	assert(!arLika("abcd e", "abcd"));
	assert(!arLika("abcd", "abcd e"));
	assert(!arLika("abcd", "abcX"));
	assert(!arLika("abcd", "Xbcd"));

}

void provararLika(const char str1[], const char str2[]) {
	bool lika = arLika(str1, str2);
	if (lika)
		cout << str1 << " och " << str2 << " är lika" << endl;
	else cout << str1 << " och " << str2 << " är OLIKA" << endl;
}


	void konverteraTillVersaler(char str[]) {
		for (int i = 0; str[i] != 0; i += 1) {
			str[i] = toupper(str[i]);
		}
		
	}

	void automattestaKonverteraTillVersaler() {
		char str1[] = "abc ABC 123 .,- xyz";
		char str2[] = "ABC ABC 123 .,- XYZ";
		konverteraTillVersaler(str1);
		assert(arLika(str1, str2));
	}

	void konverteraTillRubrik(char str[]) {
		for (int i = 0; str[i] != 0; i += 1) {
			if (str[i - 1] == 32 || i == 0)
				str[i] = toupper(str[i]);
			else str[i] = tolower(str[i]);
		}
		
		
	}
	void automattestaKonverteraTillRubrik() {
		char str1[] = "this is a test";
		char str2[] = "THIS IS A TEST";
		char rubrik[] = "This Is A Test";
		konverteraTillRubrik(str1);
		konverteraTillRubrik(str2);
		assert(arLika(str1, rubrik));
		assert(arLika(str2, rubrik));
	}


	bool arVokal(char ch) {
		char vokal[] = "aeiouyAEIOUY";
		for (int i = 0; i < vokal[i]!=0; i += 1) {
			if (vokal[i]==ch)
				return true;;
		}
		return false;
		
	}
	bool arKonsonant(char ch) {
		 char konst[] = "bcdfghjklmnpqrstvxzBCDFGHJKLMNPQRSTVXZ";
		for (int i = 0; konst[i] != 0; i += 1) {
			if (konst[i] == ch)
				return true;
		}
		return false;
	
	}
	
	void automattestaArVokalOchKonsonant() {
		char vokaler[] = "aeiouyAEIOUY";
		char konsonanter[] = "bcdfghjklmnpqrstvxzBCDFGHJKLMNPQRSTVXZ";
		char andraTecken[] = ".,?!; ";

		for (int i = 0; vokaler[i] != 0; i += 1)
			assert(arVokal(vokaler[i]));
		for (int i = 0; konsonanter[i] != 0; i += 1)
			assert(arKonsonant(konsonanter[i]));
		for (int i = 0; andraTecken[i] != 0; i += 1)
			assert(!arVokal(andraTecken[i]) && !arKonsonant(andraTecken[i]));
	}
	
	string versalsträng(const string str) {
		string ch = str;
		for (int i = 0; i < str.size(); i += 1) {
			ch[i] = toupper(str[i]);
		}
		return ch;
	}
	
	void automattestaVersalsträng() {
		assert(versalsträng("abc ABC 123 .,- xyz") == "ABC ABC 123 .,- XYZ");
		cout << versalsträng("abc ABC 123") << endl;
	}
	
	string iSprik(string str) {
		string vokal= "aeiouyAEIOUY";
		for (unsigned int i = 0; i < str.size(); i += 1) { 
			for (unsigned int k = 0; k < vokal.size(); k += 1) {
				if (str[i] == vokal[k] && islower(str[i]))
					str[i] = 'i';
				if (str[i] == vokal[k] && isupper(str[i]))
					str[i] = 'I';
			}
			
		}
		cout << str<< endl;
		return str;
	}
	void automattestaISprik() {
		assert(iSprik("abcdefghijklmnopqrstuvxyz,.!? ") == "ibcdifghijklmnipqrstivxiz,.!? ");
		assert(iSprik("ABCDEFGHIJKLMNOPQRSTUVXYZ") == "IBCDIFGHIJKLMNIPQRSTIVXIZ");
	}
	
	string rövarSpråk(string str) {
		const string ch = "bcdfghjklmnpqrstvxzBCDFGHJKLMNPQRSTVXZ";
		string re;
		for (unsigned int i = 0; i < str.size(); i += 1) {
			for (unsigned int n = 0; n < ch.size(); n += 1) {
				if (str[i] == ch[n]) {
					re += str[i];
					re += 'o';

				}
				
				
			}
			re += str[i];
			
		}
		return re;
	}
	void automattestaRövarspråk() {
		assert(rövarSpråk("abcdefghijklmnopqrstuvxyz,.!?")
			== "abobcocdodefofgoghohijojkoklolmomnonopopqoqrorsostotuvovxoxyzoz,.!?");
	}


	void testaCin() {
		while (true) {
			int x = 0;
			cout << "Skriv ett heltal: ";
			cin >> x;
			cout << "Läste in " << x << endl;
		}
	}


	double flyttalFrånUppmaning(const char uppmaning[]) {
		while (true) {
			int x = 0;
			cout << uppmaning;
			cin >> x;
			if (!cin.fail())
				return x;
			else {
				cout << "Ogiltig inmatning, skriv heltal! " << endl;
				cin.clear();
				cin.ignore(1000, '\n');
			}
		}
	
	}




	void provaFlyttalFrånUppmaning() {
		const double bokPris = flyttalFrånUppmaning("Hur många kronor kostar boken?");
		const double antalSidor = flyttalFrånUppmaning("Hur många sidor har boken?");
		
			const double procentAttLäsa = flyttalFrånUppmaning("Hur många procent av sidorna kommer du att läsa? ");
		    cout << "Du har angett att boken kostar " << bokPris << " kronor"
			<< ", och att den har " << antalSidor << " sidor"
			<< ", och att du tänker läsa " << procentAttLäsa << "%" << endl;
	}

	void testaCinString() {
		cout << "TestaCsting" << endl;
		while (true) {
			string string = "";
			cout << "skriv en sträng:";
			cin >> string;
			if (!cin.fail())
				cout << "Lyckades läsa" << string << endl;
			else {
				cout << "misslyckad inläsning" << endl;
				cin.clear();
				cin.ignore(1000, '\n');
			}

		}
	}

	bool utförBeräkningar(string uttryck) {
		cout << "Beräknar" << uttryck << endl;
		return true;
	}

	
	bool utforCalc(string kommando) {
		int a, b;
		char op;
		istringstream stream(kommando);
		stream >> a >> op >> b;
		bool ok = !stream.fail();
		if (ok) {
			char dum;
			stream >> dum;
			ok = stream.fail();
		}
	
		if (ok) {
			if (op == '+') cout << a + b << endl;
			else if (op == '*') cout << a * b << endl;
			else if (op == '-') cout << a - b << endl;
			else if (op == '%') cout << a % b << endl;
			else if (op == '/') cout << a/b << endl;
		}
		return ok;
	
	
	}


	void huvudloop() {
		while (true) {
			string txtRad;
			cout << ":";
			getline(cin, txtRad);
			if (txtRad == "")
				continue;
			if (txtRad == "exit")
				break;
			bool ok = utforCalc(txtRad);
			if (!ok)
				cout << "Förstår ej." << endl;
		}
	}

	vector<string>ordlistan() {
		string path = "C:/Users/Stefan Esber/Desktop/hej.txt";
		ifstream filen(path);
		vector<string> listan;
		string ettOrd;
		while (filen >> ettOrd) {
			listan.push_back(ettOrd);
		}
		return listan;
	}
	void provaOrdlistan() {
		vector<string> skrivaUt = ordlistan();
		for (int i = 0; i < skrivaUt.size(); i += 1) {
			cout << skrivaUt[i] << endl;
		}
	}

	bool matchaFrageNyckel(string ord, string nyckel) {
		if (nyckel.size() != ord.size())
			return false;
		for (unsigned int i = 0; i < ord.size(); i += 1) {
			if (nyckel[i] == '?')
				continue;
			if (nyckel[i] == ord[i])
				continue;
			else return false;
		}
		return true;
	}
	void automattestaMatcharFragenyckel() {
		assert(matchaFrageNyckel("xaby", "?ab?"));
		assert(!matchaFrageNyckel("xaby", "?abz"));
		assert(!matchaFrageNyckel("xaby", "?abyx"));
		assert(!matchaFrageNyckel("xabyx", "?aby"));
	}



	void skrivMatchningar(const vector<string>& allaOrd, string nyckel) {
		for (unsigned int i = 0; i < allaOrd.size(); i += 1) {
			if (matchaFrageNyckel(allaOrd[i], nyckel))
				cout << allaOrd[i] << endl;
		}
	}
	void ordMatch() {
		vector<string> allaOrd = ordlistan();
		cout << "Välkommen till ordmatch!" << endl;
		while (true) {
			cout << "NYCKEL:";
			string nyckel;
			getline(cin, nyckel);
			if (nyckel == "")
				continue;
			if (nyckel == "avbryt")
				break;
			skrivMatchningar(allaOrd, nyckel);
		}
		cout << "(ordmatchningen avbröts)" << endl;
	}


	void skrivHejFilsystem() {
		string filnamn = "C:/Users/Stefan Esber/Desktop/Visualkoder/Skolproject/hej.txt";
		ofstream ut;
		ut.open(filnamn);
		for (int i = 0; i < 10; i += 1)
			ut << "Hej filsystem!" << endl;
		ut.close();
		
	}

	void störst(int x) {
		cout << "Resultatet blev " << x << endl;
	}
	double störst(double x, double y) {
		return max(x, y);
	}
	
	void provaAllaStörst() {
		cout << störst(3, 7) << endl; // 7
		cout << störst(störst(3, 8), störst(7, 5)) << endl; // 8
		cout << störst(störst(-5.2, -14.3), -10.5) << endl; // -5.2
		assert(störst(störst(2.0, 2.5), 1.0) > 2.4);
		assert(störst(störst(2, 3),störst( 1, 8)) == 8);

	}

	int tarningsvärde() {
		int varde = 1 + rand() % 6;
		return varde;
	}
	int bruttovinst(int t1, int t2, int t3) {
		if (t1 == 6 && t2 == 6 && t3 == 6)
			return 100;
		if (t1!=6&&t1 == t2 && t2 == t3)
			return 50;
		if (t1 == t2 || t1 == t3 || t2 == t3)
			return 20;
		else return 0;
	}

	int bruttovinstFrånUtfördSpelomgång() {
		int t1 = tarningsvärde();
		int t2 = tarningsvärde();
		int t3 = tarningsvärde();
		int vinst = bruttovinst(t1,t2,t3);
		//cout << "Tärningarna blev " << t1 << " " << t2 << " " << t3 << " " <<
		// "Och vinsten blev " << vinst << "kr" << endl;
		return vinst;
	}
	
	//void spelaTärningsspelet() {
		//int kapital = 100;
	//	while (kapital >= 10) {
	//			cout << "Du har " << kapital << " kronor" << endl;
	//		bool spelaMera = boolFrånUppmaning("Vill du spela mera? (j/n): ");
	//		if (spelaMera) {
	//			kapital = kapital - 10 + bruttovinstFrånUtfördSpelomgång();
		//	}
		//	else {
			//	cout << "Fegis!!" << endl;
				//break;
//			}
//		}
//	}



	void spelAnalys() {
		double analys = 0;
		for (int i = 0; i < 999999; i += 1) {
			analys += bruttovinstFrånUtfördSpelomgång();
			analys -= 10;
		}
		cout << "Din vinst eller förlust blev " << analys << "och din vinst per spelomgång blev " <<
			analys / 1000000 << "."<< endl;
	}

	void testastorlek() {
		cout << "min " << numeric_limits<int>::min() << endl;
		cout << "max " << numeric_limits<int>::max() << endl;
		cout << "digits " << numeric_limits<double>::max() << endl;
		cout << "dbl min " << numeric_limits<double>::min() << endl;
		cout << "dlb max" << numeric_limits<double>::max() << endl;
	}
	void demonstrearOverflow() {
		cout << "Demo av overflow " << endl;
		int tal = 5;
		for (int i = 0; i < 25; i += 1) {
			cout	<<	 tal << endl;
			tal = tal * 10 + 5;
		}
	}

	void demoAvflowflyttal() {
		float tal = 5;
		for (int n = 0; n < 50; n += 1) {
			cout << tal << endl;
			tal = tal * 10 + 5;
		}
	}

	typedef double (*FUnkAvEnVariabel)(double);
	void tabuleraVärden(double xMin, double xMax, double steg, FUnkAvEnVariabel f) {
		for (double x = xMin; x <= xMax; x += steg)
			cout << "x =" << x << "\t f = " << f(x) << endl;
	}

	double fallhöjdtid(double t) {
		const double a = 9.81;
		double s = a * t * t / 2;
		return s;
	}
	void testaTabuleraVärden() {
		cout << "fallhöjdtid " << endl;
		tabuleraVärden(1, 5, 1, fallhöjdtid);
		cout << endl;
		cout << "sin" << endl;
		//tabuleraVärden(0,M_PI,M_PI/4,sin);
	}



	bool boolFrånUppmaning(const char uppmaning[]) {
			string x;
			while (true) {
				cout << uppmaning;
				cin >> x;
				if (x == "j" || x == "J")
					return true;
				if (x == "n" || x == "N")
					return false;
				else {
					cout << "Ogiltig inmatning" << endl;
					cin.clear();
					cin.ignore(1000, '\n');
				}

			}

		}
	

	string spelbord(int antalStickor) {
		string stickor = "";

		for (int i = 0; i < antalStickor; i += 1) {

			if (i % 5 != 0 || i == 0)
				stickor += "|";
			if (i % 5 == 0 && i > 0)
				stickor += " |";



		}

		return stickor;

	}

	int spelarensDrag(int antalStickor) {
		assert(antalStickor >= 1);
		cout << "Hur många vill du plocka?";
		int iX = 0;
		while (true) {
			cin >> iX;
			if (iX==2)
				return iX;
			if (iX == 1)
				return iX;
			
			else {
				cout << "Ogilting inmatning. Välj 1 eller 2 stickor att plocka "  << endl;
				cin.clear();
				cin.ignore(1000, '\n');
			}

		}
	}

	int datornsDrag(int antalStickor) {
		assert(antalStickor >= 1);
		return rand() % 2 + 1;

		
	}
	void spelaStickspelet() {
		while (true) {
			bool spela = boolFrånUppmaning("Vill du spela sticka?");
			if (!spela) {
				cout << "Fegis!" << endl;
				break;
			}
			int antalStickor = 20 + rand() % 8;
			cout << spelbord(antalStickor) << endl;
			while (antalStickor > 0) {
				antalStickor -= spelarensDrag(antalStickor);
				cout << spelbord(antalStickor) << endl;
				if (antalStickor == 0) {
					cout << "Du vann på tur!" << endl;
					break;
				}
				int drag = datornsDrag(antalStickor);
				cout << "Datorn tar " << drag << endl;
				antalStickor -= drag;
				cout << spelbord(antalStickor) << endl;
				if (antalStickor == 0) {
					cout << "Datorn vann, looser!" << endl;
					break;
				}
			}
		}
	}


	void bytVärdeen(int* pA, int* pB) {
		swap(*pA, *pB);
	}
	void bytVärdeen(double* pA, double* pB) {
		swap(*pA, *pB);
	}
	void automattestaBytVärdeen() {
		int a = 1;
		int b = 2;
		bytVärdeen(&a, &b);
		assert(a == 2 && b == 1);
		double x = 1.5;
		double y = 2.5;
		bytVärdeen(&x, &y);
		assert(x == 2.5 && y == 1.5);
	}


	bool ärLikaPekare(const char* str1, const char* str2) {
		for (int i = 0; *(str1 + i) != 0 || *(str2 + i) != 0; i += 1) {
			if (*(str1 + i) != *(str2 + i))
				return false;
		}
		return true;
	}
	void konverteraTillVersalerMedPekare(char* str) {
		for (int i = 0; *(str + i) != 0; i+=1) {
				*(str + i) = toupper(*(str + i));
		}
		cout << (str) << endl;
	}

	void automattestaarLikaa() {
		assert(ärLikaPekare("abcd", "abcd"));
		assert(!ärLikaPekare("abcd e", "abcd"));
		assert(!ärLikaPekare("abcd", "abcd e"));
		assert(!ärLikaPekare("abcd", "abcX"));
		assert(!ärLikaPekare("abcd", "Xbcd"));
		
	}

	void automattestaKonverteraTillVersalerr() {
		char str1[] = "abc ABC 123 .,- xyz";
		char str2[] = "ABC ABC 123 .,- XYZ";
		konverteraTillVersalerMedPekare(str1);
		
	}

	void konverteraTillRubrikk(char* str) {
		
		for (int i = 0; *(str + i) != 0; i+= 1){
			if (*(str + i - 1) == 32 || i==0)
				*(str + i) = toupper(*(str + i));
			else *(str + i) = tolower(*(str + i));
			
		}
	}
	
	void automattestaKonverteraTillRubrikk() {
		char str1[] = "this is a test";
		char str2[] = "THIS IS A TEST";
		char rubrik[] = "This Is A Test";
		konverteraTillRubrikk(str1);
		konverteraTillRubrikk(str2);
		assert(ärLikaPekare(str1, rubrik));
		assert(ärLikaPekare(str2, rubrik));
	}
	void skrivStrangar(const char** strangar, int antal) {
		for (int i = 0; i < antal; i += 1) {
			cout << *(strangar+i) << endl;
		}
	
	}

	void provaSkrivStrangar() {
		const int antal = 7;
		const char* dagnamn[antal] = { "måndag", "tisdag", "onsdag", "torsdag",
		"fredag", "lördag", "söndag" };
		skrivStrangar(dagnamn, antal);
	}

	void skrivUtArrMedPekare(const int* pBegin, const int* pEnd) {
		for (const int *i = pBegin; i < pEnd; i += 1) 
			cout << *i;
		cout << endl;
		
	}
	void fyllMedKonstantPekare(int* pBegin,int* pEnd, int konstant) {
		for ( int  *p = pBegin; p < pEnd; p += 1)
			*p =konstant;
	}
	void fyllMedSlumptalPekare(int* pBegin, int* pEnd, int minst, int störst) {
			for (int *p = pBegin; p < pEnd; p += 1) 
			*p = (rand() % störst + 1 - minst) + minst;
		
		
	}
	int minsst(const int* pBegin, const int* pEnd) {
		assert(pEnd - pBegin > 0);
		int minst = *pBegin;
		for (const int *p = pBegin; p < pEnd; p++) {
			if (minst > *p)
				minst = *p;
		}
		return minst;
	}
	int störsst(const int* pBegin, const int* pEnd) {
		assert(pEnd - pBegin > 0);
		int störst = *pBegin;
		for (const int *p= pBegin; p < pEnd; p+= 1) {
			if (störst < *p)
				störst = *p;	
		}
		return störst;
	}
	bool ärrSorterad(const int* pBegin, const int* pEnd) {
		for (const int* p = pBegin; p < pEnd-1; p += 1) {
			while (*p > *(p + 1))
				return false;
		}
		return true;
	}
	bool innehållerr(const int* pBegin, const int* pEnd, int x) {
		for (const int* p = pBegin; p < pEnd; p += 1) {
			if (*p == x)
				return true;
		}	
		return false;
	}

	void testaArrayFunktionernaa() {
		const int storlek = 10;
		int arr[storlek];
		fyllMedKonstantPekare(&arr[0], &arr[storlek], 5);
		skrivUtArrMedPekare(&arr[0], &arr[storlek]);
		arr[0] -= 1;
		arr[storlek - 1] += 1;
		assert(ärrSorterad(&arr[0], &arr[storlek]));
		arr[0] = 6;
		assert(!ärrSorterad(&arr[0], &arr[storlek]));
		fyllMedSlumptalPekare(&arr[0], &arr[storlek], -2, 2);
		skrivUtArrMedPekare(&arr[0], &arr[storlek]);
		arr[1] = -3; // Detta blir det minsta värdet
		arr[storlek - 1] = 3; // Detta blir det största värdet
		int m = minsst(&arr[0], &arr[storlek]);
		int s = störsst(&arr[0], &arr[storlek]);
		assert(m == -3 && s == 3);
		assert(innehållerr(&arr[0], &arr[storlek], 3));
	}

	void tvaDimArr() {
		int arr[3][3] = { { 1,2,3 }, { 1, 2, 3 }, {1,2,3}
		};
		for (int i = 0; i < 3; i += 1)
			for (int k = 0; k < 3; k += 1) {
				cout << arr[i][k] << " ";
				if (k == 2)
					cout << '\n';

			}
		cout << endl;
	}

	void testaTvåDimArrayer() {
		int x[3][3] = { {1,2,3}, {1,2,3} ,{1,2,3} };
		for (int i = 0; i < 3; i += 1) {
			for (int j = 0; j < 3; j += 1) {
				cout << "Elementet pa x ar [ " << i
					<< "][" << j << "]";
				cout << x[i][j] << endl;
			}
		}
		
	}
	struct Player {
		string player_name;
		int player_level;
	};
	
	Player platyerNameandClass(string x, int y) {
		Player player2;
		player2.player_name = x;
		player2.player_level = y;
		cout << player2.player_name << player2.player_level << endl;
		return player2;
		}



	void sorteramedSelection2(int arr[],int antal) {

		for (int i = 0; i < antal; i += 1) {
			int ix = i;
			for (int k = i; k < antal; k += 1) {
				if (arr[k] < arr[ix])
					ix = k;
			}
			int gamlaI = arr[i];
			arr[i] = arr[ix];
			arr[ix] = gamlaI;

		}
	}
	void provaSorteraMedSelection2() {
		const int storlek = 20;
		int arr[storlek];
		fyllMedSlumptal(arr, storlek, 0, 100);
		if (arSorterad(arr, storlek))
			cout << "BUG Det verkar som om fyllMedSlumptal inte fungerar" << endl;
		sorteramedSelection2(arr, storlek);
		if (arSorterad(arr, storlek))
			cout << "Det verkar som om select-sorteringen fungerade" << endl;
		else cout << "BUG i select sorteringsalgoritmen" << endl;
		for (int k = 0; k < storlek; k++)
			cout << arr[k] << ", ";
		cout << endl;
	}



	bool ärLLika(const char str1[], const char str2[]) {
		for (int i = 0; str1[i] != 0 && str2[i] != 0;i+=1){
			if (str1[i] != str2[i]) 
				return false;	
			}
		return true;
	}

	void automattestaÄrLLika() {
		assert(ärLLika("abcd", "abcd"));
		assert(!ärLLika("abcd e", "abcd"));
		assert(!ärLLika("abcd", "abcd e"));
		assert(!ärLLika("abcd", "abcX"));
		assert(!ärLLika("abcd", "Xbcd"));

	}

	void konverteraTillVersalerr(char str[]) {
		for (int i = 0; str[i] != 0; i += 1) {
			str[i] = toupper(str[i]);
		}
	}


	void automattestaKonverteraTillVersaleerr() {
		char str1[] = "abc ABC 123 .,- xyz";
		char str2[] = "ABC ABC 123 .,- XYZ";
		konverteraTillVersalerr(str1);
		assert(ärLLika(str1, str2));
	}



	void testaVecto() {
		vector<int>vec1{ 1,2,3,4,5 };
		for (int i = 0; i < 10; i += 1) {
			vec1.push_back(rand());
			cout << vec1[i] << " ";
		}
		cout << endl;
		cout << vec1.size() << endl;
	}

	
	void testaminAssert() {
		int a = 1;
		int b = 2;
		int gamlaA = a;
		a = b;
		b = gamlaA;
		assert(b == 1 && a == 2);
	}
	//0000   0011
	//0001   1111
	bool ärrLika(const char str1[], const char str2[]) {
		for (int i = 0; str1[i] != 0 || str2[i] != 0; i += 1) {
			if (str1[i] != str2[i])
				return false;
			cout << i << endl;
		}
		
		return true;
			
		
	}
	void aautomattestaÄrLika() {
		assert(ärrLika("abcd", "abcd"));
		assert(!ärrLika("abcd e", "abcd"));
		assert(!ärrLika("abcd", "abcd e"));
		assert(!ärrLika("abcd", "abcX"));
		assert(!ärrLika("abcd", "Xbcd"));
	}

	void testaNN() {
		const char str1[4] = "hej";
		const char str2[7] = "hejhej";
		for (int i = 0; str1[i] != 0 || str2[i] != 0; i += 1) {
			cout << i << endl;
		
		}
		
	}

	void testaSk() {
		const int n = 10;
		int tal[n]{ 2,3,5,7,11,13,17,19,23,27 };
		int index = 0;
		int* p = tal;
		while (*p < 7) {

			p += 1;
			index += 1;
			
		}
	
		cout << index << endl;
	}
	
	void callkapPlugg(){
		testaSk();

		//testaNN();
		//aautomattestaÄrLika();
		//testaminAssert();
		//testaVecto();
		
	//automattestaKonverteraTillVersalerr();
	//automattestaÄrLLika();
	//provaSorteraMedSelection2();
	//platyerNameandClass("kukragnar", 99);
	
	//tvaDimArr();
	//testaTvåDimArrayer();
	//testaArrayFunktionernaa();
    //provaSkrivStrangar();
	//automattestaKonverteraTillRubrikk();
	//automattestaKonverteraTillVersalerr();
	//automattestaarLikaa();
	//automattestaBytVärdeen();
	//spelaStickspelet();
	//demoAvflowflyttal();
	//demonstrearOverflow();
	//testastorlek();
	//spelAnalys();
	//spelaTärningsspelet();
	//provaAllaStörst();
	//skrivHejFilsystem();
	//automattestaMatcharFragenyckel();
	//provaOrdlistan();
	//huvudloop();
	//testaCinString();
	//provaFlyttalFrånUppmaning();
	//testaCin();
	//automattestaRövarspråk();
	//automattestaISprik();
	//automattestaVersalsträng();
	//automattestaArVokalOchKonsonant();
	//automattestaKonverteraTillRubrik();
	//automattestaKonverteraTillVersaler();
	//skrivVaxel(947);
	//provaArrayFunktionerna();
	//provaSorteraMedSelection();
	//automattestaarLika();
		

}
