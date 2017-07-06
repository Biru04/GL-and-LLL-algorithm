#include <iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
#include<vector>
#include <time.h>
#include <cstdio>
#include <cmath>
#include<conio.h>


using namespace std;

typedef long long int typ;


typ szybkie_potegowanie(typ a, typ b)
{
  typ w = 1;
  while(b>0)
  {
	if (b%2 == 1) //jesli bit jest = 1
  	w *= a;
	a*= a;
	b/=2;
  }
  return w;
}

typ norma(vector <typ >v)
{
	typ i, suma=0, norma;
	for(i=0; i<v.size(); i++)
	{
		suma+=(v[i]*v[i]);
	}
	norma = sqrt(suma);
	return norma;
}

typ iloczyn_skalarny(vector <typ> v1, vector <typ> v2)
{
	typ iloczyn=0, i;
	for(i=0;i<v1.size();i++)
	{
		iloczyn+=v1[i]*v2[i];
	}
	return iloczyn;
}

vector<typ> mnozenie_wektora_przez_liczbe(vector <typ> v, typ liczba)
{
	typ i;
	for(i=0;i<v.size();i++)
	{
		v[i]*=liczba;
	}
	return v;
}

vector<typ> odejmowanie_wektorow(vector <typ> v1, vector <typ> v2)
{
	vector <typ> v3;
	typ i;
	for(i=0;i<v1.size();i++)
	{
		v3.push_back(v1[i]-v2[i]);
	}
	return v3;
}



void wypisz_wektor(vector<typ> wektor)
{
	int i;
	for(i=0;i<wektor.size();i++)
	{
		cout<<wektor[i]<<" ";

	}

}


void Gauss_Lagrange(vector<typ> v1, vector<typ> v2)
{

    typ B1, B2;
    double q;
    B1 = norma(v1);
    B1 *= B1;
    v2 = odejmowanie_wektorow(v2, mnozenie_wektora_przez_liczbe(v1, round(q)));
    B2 = norma(v2);
    B2 *= B2;

   do{
       swap(v1,v2);
	 	B1=B2;
	 	q = (double)iloczyn_skalarny(v1, v2) / (double)B1;
	 	v2 = odejmowanie_wektorow(v2, mnozenie_wektora_przez_liczbe(v1, round(q)));
        q = round ( q ) ;
	 	cout << "q " << q << endl;
	 	B2 = norma(v2);
	 	B2 *= B2;
	 }while ( q != 0 ) ;

	 cout<<endl;

	 cout<<"Wektor V1 zredukowany: ";
	 wypisz_wektor(v1);
	 cout<<endl;

	 cout<<"Wektor V2 zredukowany: ";
	 wypisz_wektor(v2);
	 cout<<endl;
}


int main()
{
    typ a, b, tmp;
    vector<typ> v1;
    vector<typ> v2;

    srand(time(NULL));

    cout<<"Algorytm Gaussa Lagrange: "<< endl;
    cout<<endl;
    cout<<"Podaj wartosci wektorow : ";

	for(int i = 0 ;i<2;i++){
		cin>>tmp;
		v1.push_back(tmp);
	}
	for(int i = 0 ;i<2;i++){
		cin>>tmp;
		v2.push_back(tmp);
	}

	cout<<"V1: "<<v1.at(0)<<" "<<v1.at(1)<<" \n";
	cout<<"V2: "<<v2.at(0)<<" "<<v2.at(1)<<" \n";
    cout<<endl;

    Gauss_Lagrange(v1, v2);
    getch();

    return 0;
}
