// lista.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
struct nodo
{	int clave;	struct nodo *siguiente;	};


int _tmain(int argc, _TCHAR* argv[])
{
	int i,N,M;
	struct nodo *t,*x;			//definir nodos
	cin>>N>>M;					//introducir N,M
	t=new nodo;	t->clave=1;x=t; //valor inicial 1
	for(i=2;i<=N;i++)
	{	
		t->siguiente=new nodo;
		t=t->siguiente;	t->clave=i;
		/*cout<<t->clave<<"llenando"<<'\n';*/

	}
	t->siguiente=x;
	//cout<<x->clave<<"a la cabeza"<<'\n';//t y x distintos
	while(t!=t->siguiente)
	//while(t!=x)
	{	
		for(i=1; i<M;i++) 
		{	
			t=t->siguiente;
			//cout<<t<<"ir al ultimo"<<'\n';
		}
		x=t->siguiente;
		cout<<x->clave<<" muere "<<'\n';
		t->siguiente=x->siguiente;
		delete x;
	}
	cout<<t->clave<<'\n';
	system("pause");
	return 0;
}

