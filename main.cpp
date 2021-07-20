#include <iostream>
#include <stdlib.h>
 
using namespace std;
 
struct nodo{
 
       int nro;
       
       struct nodo *sgte;
 
};
 
 
 
typedef struct nodo *Tlista;
 
 
/*-------------------- Insertar siguiente Elemento-------------------------*/
void insertarSgte(Tlista &lista, int valor)
 
{
 
    Tlista t, q = new(struct nodo);
 
    q->nro  = valor;
 
    q->sgte = NULL;
 
    if(lista==NULL)
 
    {
        lista = q;
    }
 
    else
 
    {
        t = lista;
        while(t->sgte!=NULL)
        {
            t = t->sgte;
        }
 
        t->sgte = q;
    }
 
}
 
/*----------------------Mostrar Lista--------------------------------------*/
void reportarLista(Tlista lista)
 
{
 
     int i = 0;
 
     while(lista != NULL)
 
     {
 
          cout <<' '<< i+1 <<") " << lista->nro << endl;
 
          lista = lista->sgte;
 
          i++;
 
     }
 
}
 
 
void calcularMayMenProm(Tlista lista, int mayor, int menor, int promedio, int n){
 
    while(lista!=NULL){
 
     if(mayor<(lista->nro))
 
        mayor=lista->nro;
 
     if(menor>(lista->nro))
 
        menor=lista->nro;
 
     promedio+=lista->nro;
 
     lista=lista->sgte;
     }
 
     promedio=promedio/n;
 
     cout<<endl<<"mayor:"<<mayor<<endl;
 
     cout<<endl<<"menor:"<<menor<<endl;
 
     cout<<endl<<"promedio:"<<promedio<<endl<<endl;
 
}
 
/*------------------------- Funcion Principal ---------------------------*/
 
int main(void)
 
{
       int mayor;
       int menor; 
       int promedio;
       int n;
    Tlista lista = NULL;
 
    system("color 0a");
 
    cout<<"\n\n\t\t[  EJERCICIOS LISTAS SIMPLES ]\n";
 
    cout<<"\t\t-----------------------------\n\n";
 
    cout<<" EJERCICIO 1: Calcular mayor,menor y promedio de una lista"<<endl<<endl;
 
    cout<<"\n Ingrese tamanio de lista: ";
 
    cin>>n;
 
    for(int i=1;i<=n;i++){
 
        insertarSgte(lista,i);
    }
    cout<<endl<<"Elementos de lista"<<endl;
    reportarLista(lista);
 
    mayor=lista->nro;
 
    menor=lista->nro;
 
    promedio=lista->nro;
 
    lista=lista->sgte;
 
    calcularMayMenProm(lista, mayor, menor, promedio, n);
 
 
    system("pause");
 
   return 0;
 
}