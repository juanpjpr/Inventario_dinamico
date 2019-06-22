#include <iostream>
using namespace std;

template <typename T>

struct nodo{
		T data;
		nodo<T>* sig;
		
		nodo<T>(){
			sig=NULL;
		}
		nodo<T>(T d){
			data=d;
			sig=NULL;
		}
	
	};

template <typename T>
struct Inventario{
	nodo<T>* lista;
	
	Inventario(){
		lista=NULL;
	}
	
	void agregar(T dato){
		if(lista==NULL){
			lista=new nodo<T>(dato);
		
		}else{
			nodo<T>* aux=lista;
			while(aux->sig!=NULL)
			{
				aux=aux->sig;
			}
			aux->sig=new nodo<T>(dato);
		}
	}
	
	void mostrar(){
		nodo<T>* aux=lista;
		if(lista==NULL){
			cout<<"No hay elementos";
		}else{
			while(aux!=NULL){
				cout<<aux->data<<endl;
				aux=aux->sig;
			}
		}
	}
	
	int cantElementos(){
		int c=0;
		nodo<T>* aux=lista;
		if(lista==NULL){
			return c;
		}else{
			while(aux!=NULL){
				c++;
				aux=aux->sig;
			}
			return c;
		}
	}
	
	T buscarPos(int pos){
		int c=1;
		nodo<T>* aux=lista;
		if(pos>cantElementos()){
			cout<<"No existe esa posicion"<<endl;
		}else{
			while(pos!=c){
				c++;
				aux=aux->sig;
			}
			return aux->data;
		}
	}

};

int main() {
	Inventario<string> i;
	i.agregar("juan");
	i.agregar("pedro");
	i.agregar("carlos");
	i.agregar("luis");
	i.agregar("jorge");
	i.agregar("raul");
	i.mostrar();
	cout<<"La cantidad de elementos son: "<<i.cantElementos()<<endl;
	cout<<"La posicion 2 le correposde a : "<<i.buscarPos(2)<<endl;
	i.borrar(2);
	i.mostrar();
	
}
