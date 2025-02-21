#pragma once
#include<iostream>
using namespace std;

void teorieSize() {


	cout << "char " << sizeof(char) << endl;
	cout <<"double " <<sizeof(double) << endl;
	cout <<"int " << sizeof(int) << endl;
		
	

}

void teorieAdresaSiDereferentiere() {

	int x = 7;
	cout << &x;
	cout << *(&x);
	
}
void exercitiu() {
	int x = 7;
	int y = 2;
	int* p = &x;
	int* t = &y;
	*p = *p + 2;
	*t = *p - 1;
	y = 2;
	p = &y;
	*p = *p - 5;


	cout << &x << endl;
	cout << &y << endl;
	cout << p << endl;
	cout << t << endl;
	cout << x << endl;
	cout << y << endl;
	cout << *p << endl;
	cout << *t << endl;



}
void ex2() {
	int a = 3;
	int b = 6;
	int c = 9;
	int d = 12;
	int e = 15;
	int* p1 = &a;
	int* p2 = &b;
	int* p3 = &c;
	int* p4 = &d;
	int* p5 = &e;
	*p2 = *p1 + *p3;
	p3 = p5;
	*p4 = *p2 - *p3;
	p5 = &a;
	*p1 = *p4 * 2;
	p2 = p1;
	*p3 = *p2 + *p5;
	p4 = &c;
	*p5 = *p4 - *p1;
	cout << a <<" "<<b <<" "<<" "<<c <<" "<< d <<" "<< e << endl;
	
	
	cout << &a <<" "<< & b <<" "<< & c <<" "<< & d <<" "<< & e << endl;


	cout << *p1 <<" "<< * p2 <<" "<< * p3 <<" "<< * p4 <<" "<< * p5 << endl;




}