#pragma once
#include<iostream>
using namespace std;
//1)Se citește un vector cu n elemente, numere naturale. Să se înlocuiască ultimul element prim din vector cu 0, apoi să se afișeze vectorul.
bool estePrim(int n) {
	if (n == 1 || n == 0) {
		return false;
	}
	for (int i = 2; i < n / 2; i++) {
		if (n % i == 0) {
			return false;
		}
	}

	return true;


}
void inlocuireCu0(int* v, int d) {
	int* p = &v[d];
	while (p > v) {
		if (estePrim(*p)) {
		
			*p = 0;
		}
		p--;
	}



}
void afisareVectoriPointeri(int* v, int d) {
	int* pimulElem = &v[0];
	int* ultimElmement = &v[d];
	while (pimulElem != ultimElmement) {
		cout << *pimulElem << " ";
		pimulElem++;


	}


}
void sol1() {
	int v[100] = { 3,9,12,7 };
	int d = 4;
	inlocuireCu0( v,  d);
	cout << "vectorul dupa inlocuire este " << endl;
	afisareVectoriPointeri(v, d);


}
//2)Se citește un vector cu n elemente, numere naturale. Să se afișeze elementele din vector care sunt multipli ai ultimului element.
void afisareElemMultipleCuUltimul(int *v, int d ) {
	int* p = &v[d];
	int* pElemnt = v;
	for (int i = 0; i < d; i++) {
		if (*pElemnt % *p == 0) {
			cout << *pElemnt << " ";
		}
	
	}


}
void sol2() {
	int v[100] = { 12,18,33,71,6 };
	int d=5;

	afisareElemMultipleCuUltimul(v, d);
	cout << "vectoru este ";
	afisareVectoriPointeri(v, d);



}
//3)Să se determine maximul şi minimul valorilor elementelor unui vector.
void minimVector(int* v, int d) {
	int *minimP = &v[0];
	for (int* p = v; p < v+d; p++) {
	
		if (*p < *minimP) {
			minimP = p;

		}
	
	
	
	}
	cout << "min este " << *minimP << endl;

}
void maximVector(int* v, int d) {
	int* maximP = &v[0];
	for (int* p = v; p < v+d; p++) {
		if (*p > *maximP) {
			maximP = p;
		}
	
	
	}


	cout << "maxim este " << *maximP << endl;

}
void sol3() {
	int v[100] = { 12,72,13,87,41,7 };
	int d = 6;

	minimVector(v, d);
	maximVector(v, d);


}
//ex4)Să se determine indicele maximului şi cel al minimului valorilor elementelor unui vector.
void indiceMinim(int* v, int d, int* indMinim) {
	*indMinim = 0;
	for (int i = 0; i < d; i++) {
		if (v[i] < v[*indMinim]) {
		
			*indMinim= i;
		
		}
	
	
	}



}
void indiceMaxim(int* v, int d, int* indiceMaxim) {
	*indiceMaxim = 0;
	for (int i = 0; i < d; i++) {
		if (v[i] > v[*indiceMaxim]) {
			*indiceMaxim = i;
		}
	
	}

}
void sol4() {
	int v[100] = { 12,7,45,99,42 };
	int d = 5;
	int indMinim = 0;
	int indMaxim = 0;
	indiceMinim(v, d, &indMinim);
	indiceMaxim(v, d, &indMaxim);
;
	cout << "indicele minim este " << indMinim << endl;
	cout << "indicele maxim este " << indMaxim << endl;
	


}
//5)Se citește un vector cu n elemente, numere naturale. Să se determine suma valorilor elementelor cuprinse între primul și ultimul element par al vectorului, inclusiv acestea.
int primulElemntPar(int* v, int d) {
	int* elemPar1 = 0;
	for (int i = 0; i < d; i++) {
		if (*(v+i) % 2 == 0) {
			return i;
		}
	
	
	}

}
int  ultimulElemntPar(int* v, int d) {
	int* elemPar2 = 0;
	for (int i = d-1; i >0; i--) {
		if (*(v + i) % 2 == 0) {
			return i;
		
		}
	
	
	}



}
int sumaelemPare(int* v, int primElmPar, int ultimulElemPar) {
	int suma = 0;
	for (int i = primElmPar; i < ultimulElemPar; i++) {
		suma = suma + *(v + i);
	
	}

	return suma;

}
void sol5() {
	int v[100] = { 12,7,9,13,17,22 };
	int d = 6;

	int elemPar1 = primulElemntPar(v, d);
	int elemPar2 = ultimulElemntPar(v, d);
	int suma = sumaelemPare(v, elemPar1, elemPar2);
	cout << "suma dintre primul si ultimul element par este " << suma << endl;



}
//6)Se dă un vector cu n numere naturale. Să se determine câte dintre elemente au valoarea strict mai mare decât media aritmetică a elementelor vectorului.
int mediaElemVector(int* v, int d) {
	int suma = 0;
	for (int i = 0; i < d; i++) {
		suma = suma + *(v + i);
	
	
	}
	return suma / d;


}
int contorElemMaiMari(int* v, int d) {
	int contor = 0;;
	for (int i = 0; i < d; i++) {
		if (*(v + i) > mediaElemVector(v, d)) {
			contor++;
		
		}
	
	
	}

	return contor;


}
void sol6() {
	int v[100] = { 1,2,3,4,5,6,0 };
	int d = 7;
	int elemMaiMari = contorElemMaiMari(v, d);
	cout << "nr de elemente mai mari decat media este " << elemMaiMari << endl;



}
//7)Se dă un vector cu n numere naturale. Să se determine câte dintre perechile de elemente egal depărtate de capetele vectorului sunt prime între ele.
int cmmdc(int a, int b) {
	while (b > 0) {
		int aux = b;
		b = a % b;
		a = aux;
	
	
	}

	return a;

}
int contorPrime(int* v, int d) {
	int contor = 0;
	for (int i = 0; i < d; i++) {
		int elemPrim1 = *(v + i);
		int elemPrim2 = *(v + d - 1 - i);
		if (cmmdc(elemPrim1, elemPrim2)==1) {
			contor++;
		}
	}

	return contor;


}
void sol7() {
	int v[100] = { 2,4,9,5,25,7 };
	int d = 6;
	int contor = contorPrime(v, d);
	cout << "nr de elemente egal departate si prime intre ele este " << contor << endl;



}
//8)Se dă un vector cu n elemente, numere naturale. Afișați în ordine crescătoare valorile prime din vector.
void bubbleSortPointeri(int* v, int d) {
	bool sortat = false;											
	do {
		sortat = true;

		for (int* p = v; (v + d-1) != p; p++) {

			if (*(p + 1) < *p) {
				int aux = *p;
				*p = *(p + 1);
				*(p + 1) = aux;

				sortat = false;
			}
		}


	} while (sortat == false);

}
void sortareVectorElemPrim(int* v, int d) {
	int vectPrime[100] = {};
	int conotrElemPrime = 0;
	for (int* p = v; p < v + d; p++) {
		if (estePrim(*p)) {
			vectPrime[conotrElemPrime++] = *p;
		
		
		}
	
	
	}
	bubbleSortPointeri(vectPrime, conotrElemPrime);
	cout << "vect dupa sortare este " << endl;
	afisareVectoriPointeri(vectPrime, conotrElemPrime);



}
void sol8() {
	int v[100] = { 13,7,12,71,3 };
	int d = 5;
	sortareVectorElemPrim(v, d);


}
//9)Să se scrie un program care ordonează elementele unui vector crescător după suma cifrelor.
int sumaCif(int n) {
	int suma = 0;
	while (n > 0) {
		int cif = n % 10;
		suma = suma + cif;
		n = n / 10;
	}
	return suma;



}
void sortareSuma(int* v, int d) {
	bool sortat = false;
	do {
		sortat = true;

		for (int* p = v; (v + d-1) != p; p++) {

			if (sumaCif(*(p + 1)) < sumaCif(*p)) {
				int aux = *p;
				*p = *(p + 1);
				*(p + 1) = aux;

				sortat = false;
			}
		}


	} while (sortat == false);




}
void sol9() {
	int v[100] = { 12,11,77,98 };
	int d = 4;
	sortareSuma(v, d);
	cout << "vectorul dupa sortare este ";
	afisareVectoriPointeri(v, d);



}
//10)Să se scrie un program care ordonează elementele unui vector crescător după prima cifră
int primaCif(int n) {
	while (n >= 10) {
	
		n = n / 10;
	
	}
	return n;

}
void sortarePrimaCif(int* v, int d) {

	bool sortat = false;
	do {
		sortat = true;

		for (int* p = v; (v + d - 1) != p; p++) {

			if (primaCif(*(p + 1)) < primaCif(*p)) {
				int aux = *p;
				*p = *(p + 1);
				*(p + 1) = aux;

				sortat = false;
			}
		}


	} while (sortat == false);




}
void sol10() {
	int v[100] = { 13,45,22,75,65,89,98 };
	int d = 7;
	sortarePrimaCif(v, d);
	cout << "vectorul dupa sortare este ";
	afisareVectoriPointeri(v, d);


}
//11)Se dă un şir cu n elemente, numere naturale. Să se verifice dacă în şir există elemente impare.
bool esteImpar(int* v, int d) {
	for (int i = 0; i < d; i++) {
		if (*(v + i) % 2 != 0) {
			return true;


		}

	}
	return false;
}
void sol11() {
	int v[100] = { 12,7,32,31,99 };
	int d = 5;
	if (esteImpar(v, d)==true) {
		cout << "in sir exista elemente impare " << endl;
	
	}
	else {
		cout << "in sir nu exista elemente impare " << endl;

	}

}
//12)Se dă un şir cu n elemente, numere naturale. Să se verifice dacă toate elementele şirului au număr par de cifre.
int contorCif(int n) {
	int contor = 0;
	while (n > 0) {
		int cif = n % 10;
		contor++;
		n = n / 10;
	
	
	}
	return contor;

}
bool auNrImparDeCif(int* v, int d) {
	for (int i = 0; i < d; i++) {
		if (contorCif  ((*(v + i)) % 2 != 0)) {
			return false;
		}
	
	
	}
	return true;


}
void sol12() {
	int v[100] = { 13,65,43,78,90,17,41 };
	int d = 7;
	if (auNrImparDeCif(v, d) == true) {
		cout << "elem sirului au nr impar de cifre " << endl;
	}
	else {
		cout << "elementele sirului nu au nr impar de cifre " << endl;
	}


}
//13)Se dă un şir cu n elemente, numere naturale. Să se verifice dacă toate elementele şirului sunt multipli ai ultimului element din şir.
bool esteMultiplu(int* v, int d) {
	int ultimELement = *(v + d - 1);
	for (int i = 0; i < d - 1; i++) {
		if (*(v + i) % ultimELement != 0) {
			return false;
		}
	
	
	
	}
	return true;



}
void sol13() {
	int v[100] = { 13,26,39,13 };
	int d = 4;
	if (esteMultiplu(v, d) == true) {
		cout << "toate elem sirului sumt multiple ultimului eleemnt " << endl;

	}
	else {
		cout << "nu toate elementele sirului sunt multiple ultimului element " << endl;
	}



}
//14)Se dau doi vectori cu câte n elemente, numere naturale. Verificați dacă cei doi vectori conțin exact aceleași elemente.
bool auAceleasiElem(int* v1,int *v2, int d) {
	for (int i = 0; i < d; i++) {
		if (*(v1 + i) != *(v2 + i)) {
			return false;
		}
	}
	return true;




}
void sol14() {
	int v1[100] = { 5,6,7,8,9,10 };
	int v2[100] = { 5,6,7,18,9,10 };
	int d = 6;
	if (auAceleasiElem(v1, v2, d)) {
		cout << "vectorii au aceleasi elemente " << endl;
	
	
	}
	else {
		cout << "vectorii au elemente diferite " << endl;
	}

}
//15)Se dă un şir cu n elemente, numere naturale. Să se verifice dacă există în şir elemente care să aibă ambii vecini de aceeaşi paritate cu el.
bool areVeciniDeAceeasiParitate(int* v, int d) {
	for (int* p = v + 1; p < v + d - 1; p++) {
		if ((*(p - 1) % 2 == *p % 2) && (*(p + 1) % 2 == *p % 2)) {
		return true;
		}
	
	}
	return false;




}
void sol15() {
	int v[100] = { 2,4,6,9,10,13 };
	int d = 6;
	if (areVeciniDeAceeasiParitate(v, d)==true) {
	
		cout << "vectorul are elem cu vecini de aceeasi paritate " << endl;
	}
	else {
		cout << "vectorul NU are elem cu vecini de aceeasi paritate " << endl;
	}



}
//16)Să se șteargă dintr-un vector toate elementele care sunt numere prime.
void stergereElem(int* v, int& d) {
	int* p = v;
	int* pFinal = v;
	for (int i = 0; i < d; i++) {
		if (estePrim(*p)) {
			*pFinal = *p;
			*pFinal++;
		}
		p++;
	}
	d = pFinal - v;


}
void sol16() {
	int v[100] = { 7,12,8,43,13 };
	int d = 5;
	stergereElem(v, d);
	cout << "vectorul dupa stergere este " << endl;
	afisareVectoriPointeri(v, d);




}
//17)Să se șteargă dintr - un vector toate elementele pare.
bool estePar(int n) {
	if (n % 2 != 0) {
		return false;

	}
	return true;

}
void stergereElemPar(int* v, int& d) {
	int* p = v;
	int* pFinal = v;
	for (int i = 0; i < d; i++) {
		if (!estePar(*p)) {
			*pFinal = *p;
			*pFinal++;
		}
		p++;
	}
	d = pFinal - v;


}
void sol17() {
	int v[100] = { 17,45,22,28,16,19 };
	int d = 6;
	stergereElemPar(v, d);
	cout << "vectorul dupa stergere este " << endl;
	afisareVectoriPointeri(v, d);


}
//18)Să se insereze într-un șir după fiecare element par dublul său.
void inserareElem(int* v, int& d, int key, int pozitie) {
	for (int i = d - 1; i >= pozitie; i--) {
		*(v + i) = *(v + i - 1);

	}
	*(v + pozitie) = key;
	d++;


}
void inserarePar(int* v, int& d) {
	for (int i = 0; i < d; i++) {
		if (*(v + i) % 2 == 0) {
			int key = *(v + i) * 2;
			inserareElem(v, d, key, i + 1);
		
		}
		else {
			i++;
		}
	
	}





}
void sol18() {
	int v[100] = { 2,3,4,5,6};
	int d = 5;

	inserarePar(v, d);
	cout << "vectorul dupa inserare este " << endl;
	afisareVectoriPointeri(v, d);

}
//19)Se dă un șir de n numere naturale nenule. Pentru fiecare element din șir se va afișa valoarea 1 dacă acesta este perfect sau 0 în caz contrar.
bool estePP(int n) {
	int radical = sqrt(n);
	if (radical * radical == n) {
		return true;
	}
	return false;

}
void inlocuirePP(int* v, int d) {
	for (int* p = v; p < v + d; p++) {
		if (estePP(*p)) {
			cout << 1 << " ";
		
		}
		else {
			cout << 0 << " ";
		}
	
	
	
	}




}
void sol19() {
	int v[100] = { 49,7,16,25,9,5,21 };
	int d = 7;
	cout << "vectorul cu 0 si 1 este " << endl;
	inlocuirePP(v, d);



}
//20)Se dă un şir cu n elemente, numere naturale. Să se verifice dacă toate elementele şirului au număr par de cifre.
int contorCifre(int n) {
	int contor = 0;
	while (n > 0) {
		int cif = n % 10;
		contor++;
		n = n / 10;


	}
	return contor;

}
bool nAreNrImaparCif(int* v, int d) {
	for (int i = 0; i < d; i++) {
		if (contorCif((*(v + i)) % 2 != 0)) {
			return false;
		}


	}
	return true;


}
void sol20() {
	int v[100] = { 13,65,43,78,90,17,41 };
	int d = 7;
	if (auNrImparDeCif(v, d) == true) {
		cout << "vectorul are nr impar de cif " << endl;
	}
	else {
		cout << "vectorul nu are nr impar de cifre " << endl;
	}


}
