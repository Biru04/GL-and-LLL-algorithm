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




typ norma(vector<typ> a) {
    typ result = 0;
    for (int i = 0; i < a.size(); i++) {
        result += (a[i] * a[i]);
    }
    return result;
}

typ iloczyn_skalarny(vector<typ> a, vector<typ> b) {
    typ result = 0;
    for (int i = 0; i < a.size(); i++) {
        result += (a[i] * b[i]);
    }
    return result;
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

vector<typ> dodawanie_wektorow(vector<typ> a, vector<typ> b) {
    vector<typ> result;
    for (int i = 0; i < a.size(); i++) {
        result.push_back(a[i] + b[i]);
    }
    return result;
}



void showMatrix(vector<typ> a) {
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }
}

typ round(typ counter, typ denominator){
    int q=floor(((double)counter/(double)denominator)+0.5);
    return q;
}

vector<typ> mnozenie_wektora_przez_liczbe(vector<typ> v, int factor){
    vector<typ> result(v.size(),0);
    for(int i=0;i<v.size();i++){
        result[i]=v[i]*factor;
    }
    return result;
}

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

typ bigNumberGenerator(typ n){
    typ  w1=0;
    w1=rand()%2;
    if(n==1){
    }else{
        for(int i=1;i<n;i++){
            w1=w1+szybkie_potegowanie(2,n-i)*(rand()%2);
        }
    }
    return w1;
}
int main(){
    vector< vector<typ> > base;
    long double condition;
    int i, j , k=1, n,c;
    vector<typ> tmp;
    srand( time( NULL ) );
    cout<<"Wybierz jedna z opcji uruchomiena programu: "<<endl;
    cout<<"1. Podaj wymiar kraty oraz wygeneruj wektory."<<endl;
    cout<<"2. Dzialanie Algorytmu LLL dla przykladu z zajec."<<endl;
    cin>>c;
    if(c==1){
        cout<<"Podaj wymiar kraty: "<<endl;
        cin>>n;
        for(i=0;i<n;i++){
            int bits=17;
            for(j=0;j<n;j++){
                tmp.push_back(bigNumberGenerator(bits));
            }
            base.push_back(tmp);
            tmp.clear();
            bits=0;
        }
    }else if(c==2){
        n=2;
        tmp.push_back(66586820);
        tmp.push_back(65354729);
        base.push_back(tmp);
        tmp.clear();
        tmp.push_back(6513996);
        tmp.push_back(6393464);
        base.push_back(tmp);
        tmp.clear();

    }

    vector< long double> vektor(n, 0.0);
    vector<vector<long double> > factor(n,vektor);
    vector<typ> q(n,0);

    cout<<"Wektory wejsciowe:"<<endl;
    for(int i=0; i<base.size();i++)  {
        cout<<"v"<<i+1<<": ";
        showMatrix(base[i]);
        cout<<endl;
    }
    int min=0;
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(norma(base[i]) < norma(base[j])){
                min=j;
            }
        }
        if(min!=0)swap(base[i],base[min]);
        min=0;
    }

    while(k<n){
        for(j=k-1;j>=0;j--){
            q[j]=round(iloczyn_skalarny(base[j], base[k]),norma(base[j]));
            base[k]=odejmowanie_wektorow(base[k],mnozenie_wektora_przez_liczbe(base[j],q[j]));
            for(i=0;i<k;i++){
                factor[k][i]=(long double) iloczyn_skalarny(base[k],base[i])/norma(base[i]);
            }
        }
        condition = 0.75 - pow(factor[k][k-1],2);
        if((norma(base[k]))>=(condition*norma(base[k-1]))){
            k=k+1;
        }
        else{
            swap(base[k],base[k-1]);
            k = max(1, k-1);
        }
    }
    cout<<endl<<"Lepsza baza: "<<endl;
    for(i=0;i<n;i++){
        cout<<"v"<<i+1<<": ";
        showMatrix(base[i]);
        cout<<endl;
    }

    return 0;
}
