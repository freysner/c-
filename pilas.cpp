// pilas.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <iostream>

using namespace std;
template <class tipoElemento>
//typedef int tipoElemento;
class Pila
{
	public:
		Pila(int max);
		~Pila();
		void meter(tipoElemento v);
		tipoElemento sacar();
		int vacia();
	private:
		struct nodo
		{	tipoElemento clave; struct nodo *siguiente;};
		struct nodo *cabeza, *z;
};
template <class tipoElemento>
Pila<tipoElemento>::Pila(int max)
{
	cabeza=new nodo; z=new nodo;
	cabeza->siguiente=z; z->siguiente=z;
}
template <class tipoElemento>
Pila<tipoElemento>::~Pila()
{
	struct nodo *t=cabeza;
	while(t!=z)
	{	cabeza=t;t=t->siguiente; delete cabeza;}
}
template <class tipoElemento>
void Pila<tipoElemento>::meter(tipoElemento v)
{
	struct nodo *t=new nodo;
	t->clave=v; t->siguiente=cabeza->siguiente;
	cabeza->siguiente=t;
}
template <class tipoElemento>
tipoElemento Pila<tipoElemento>::sacar()
{
	tipoElemento x;
	struct nodo *t=cabeza->siguiente;
	cabeza->siguiente=t->siguiente; x=t->clave;
	delete t; return x;
}
template <class tipoElemento>
//int Pila::vacia()
int Pila<tipoElemento>::vacia()
{
	//cabeza->siguiente=z;
	return cabeza->siguiente==z;
}

int _tmain(int argc, _TCHAR* argv[])
{
	char c; Pila<int> acc(50); int x;

	while(cin.get(c))
	{
		x=0;
		while(c==' ') cin.get(c);
		if(c=='+') 
			x=acc.sacar()+acc.sacar();
			//x=x+acc.sacar();
		if(c=='*') 
			x=acc.sacar()*acc.sacar();
			//x=x*acc.sacar();
		while(c>='0' && c<='9')
		{	x=10*x+(c-'0'); 
			cin.get(c);
			//cout<<"por numero-->> "<<x<<'\n';
		}
		if(x!=0)//aumentado para obtener el ultimo resultado
		acc.meter(x);
		//cout<<"salio-->> "<<x<<'\n';
	}
	cout<<acc.sacar()<<'\n';
	//cout<<"fin-->"<<x<<'\n';
	system("pause");
	return 0;
}

