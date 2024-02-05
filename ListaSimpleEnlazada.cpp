#include <iostream>
#include <conio.h>
#include <stdlib.h>

struct Nodo
{
	int dato;
   	Nodo *sig;
};

void insertar_i(Nodo *&frente, int a)
{
	Nodo *q;
	Nodo *nuevo=new Nodo();
   q = nuevo;
   q -> dato = a;
   q -> sig = frente;
   frente = q;
}

void eliminar_i(Nodo *&frente)
{
	Nodo *q;
   if(frente != NULL)
   {
   	q = frente;
   	frente = q ->sig;
   	delete (q);
   }
   else
   {
   	cout<<"\n\tNo hay elemento.";
   }
}

void insertar_f(Nodo *&frente,Nodo *&q, Nodo *&r, int a)
{
	Nodo *nuevo=new Nodo();
   q=nuevo;
   q -> dato = a;
   q -> sig= frente;
   r=q;
   if(frente ==  NULL )
   {
   	q->sig= frente;
      frente=q;
   }
   else{
   	while(r->sig != NULL)
      {
   		r=r->sig;
      }
   	r -> sig = q;
   	q -> sig = NULL;
   }
}
void eliminar_f(Nodo *&frente)
{
	Nodo *q;
   Nodo *r;
   if(frente != NULL)
   {
   	q = frente;
      while(q->sig!=NULL)
      {
      	r=q;
         q=q->sig;
      }
      if(frente==q)
      {
      	frente=NULL;
      }
      else
      {
      	r->sig = NULL;
      }
   	delete (q);
   }
   else
   {
   	cout<<"\n\tNo hay elementos.";
   }
}

void insertar_a_r(Nodo *&frente,Nodo *&q, Nodo *&r, int a, int ref)
{
   int b=1;
   q=frente;
   b=1;
   r=q;

   if(frente ==  NULL )
   {
   	cout<<"\n\tNo hay elementos";
   }
   else
   {
   while(q->dato !=ref && b==1)
   {
   	if(q->sig!=NULL)
   	{
   		r=q;
   		q=q->sig;
   	}
   	else
   	{
      	b=0;
   	}
   }


   if(b!=0)
   {
	Nodo *x=new Nodo();
   	x -> dato = a;
        x ->sig = q;
   		if(frente ==q)
   			{
            	frente = x;
   			}
   		else
         	{
   				r->sig=x;
   			}
   }
   else
   {
   cout<<"\tNo se encontro referente. ";
   }
   }

}


void insertar_d_r(Nodo *&frente,Nodo *&q, int a, int ref)
{
   int b;
   q=frente;

   if(frente ==  NULL )
   {
   	cout<<"\n\tNo hay elementos.";
   }
   else
   {
   q=frente;
   b=1;
   	while(q->dato !=ref && b==1)
   	{
   		if(q->sig!=NULL)
   		{
   			q=q->sig;
   		}
   		else
   		{
      		b=0;
   		}

   	}

   	if(b!=0)
   	{
			Nodo *x=new Nodo();
   		x -> dato = a;
      	x -> sig  = q -> sig;
         q -> sig = x;


   	}
   	else
   	{
   		cout<<"\tNo se encontro referente. ";
   	}
   }

}

void eliminar_ref(Nodo *&frente, int ref)
{
	Nodo *q;
   Nodo *r;
   int b=1;
   if(frente != NULL)
   {
   	q = frente;
      r = frente;
      while(q->dato!=ref && b==1)
      {
      	if(q->sig!=NULL)
   		{
   			r=q;
        		q=q->sig;
   		}
   		else
   		{
      		b=0;
   		}

      }
      if(b!=0)
   	{
      	if(frente==q)
      	{
      		frente=NULL;
      	}
      	else
      	{
      		r->sig = q -> sig;
      	}
   		delete (q);
		}
      else
   	{
   		cout<<"\tNo se encontro referente. ";
   	}
   }
   else
   {
   	 cout<<"\n\tNo hay elemento.";
   }
}



void eliminar_a_r(Nodo *&frente, int ref)
{
	Nodo *q;
   Nodo *r;
   Nodo *t;
   int b;
   if(frente != NULL)
   {
   	q = frente;
      r = frente;
      t = frente;
      b = 1;
      while(q->dato!=ref && b==1)
      {
      	if(q->sig!=NULL)
   		{
         	t=r;
   			r=q;
        		q=q->sig;
   		}
   		else
   		{
      		b=0;
   		}

      }
      if(b!=0)
   	{
      	if(frente==q)
      	{
      		cout<<"\tEs nodo cabecera.";
      	}
      	else
      	{
				if(frente==r)
            {
      			frente=q;
            }
            else
            {
               t -> sig = q;
            }
         	delete (r);
      	}

		}
      else
   	{
   		cout<<"\tNo se encontro referente. ";
   	}
   }
   else
   {
   	 cout<<"\n\tNo hay elemento.";
   }
}


void eliminar_d_r(Nodo *&frente, int ref)
{
	Nodo *q;
   Nodo *r;
   int b;
   if(frente != NULL)
   {
   	q = frente;
      r = frente;
      b = 1;
      while(q->dato!=ref && b==1)
      {
      	if(q->sig!=NULL)
   		{
        		q=q->sig;
   		}
   		else
   		{
      		b=0;
   		}

      }
      if(b!=0)
   	{
      	if(q -> sig == NULL)
      	{
      		cout<<"\tEs nodo ultimo.";
      	}
      	else
      	{
				r = q -> sig;
            q -> sig = r -> sig;
         	delete (r);
      	}
		}
      else
   	{
   		cout<<"\tNo se encontro referente. ";
   	}
   }
   else
   {
   	 cout<<"\n\tNo hay elemento.";
   }
}




void mostrar(Nodo *&frente)
{
	cout << "\n"<<endl;
	Nodo *aux=frente;
   if(frente!=NULL)
   {
   	cout<<"   Frente ->  ";
   	while(aux!=NULL)
      {
      	cout<<" "<<aux->dato<<" . ";
         aux=aux->sig;
      }
      cout<<" <- Final ";
   }else
   {
   	cout<<"\tNo hay elementos.";
   }
}
int main()
{
	Nodo *frente;
	Nodo *q;
	Nodo *r;
	int dato,ref;
	frente=NULL;
	int op;

	cout<<"\n\tLISTAS ENLAZADAS            Nota: Por defecto ya se muestra la lista\n";cout<<"\t---------------- ";

do{
    cout<<endl<<endl;
    cout<<"    INSERTAR : "<<endl;
    cout<<" \t1. Por el inicio   "<<endl;
    cout<<" \t2. Por el final   "<<endl;
    cout<<" \t3. Antes de la referencia "<<endl;
    cout<<" \t4. Despues de la referencia "<<endl;
    cout<<"    ELIMINAR : "<<endl;
    cout<<" \t5. Por el inicio   "<<endl;
    cout<<" \t6. Por el final   "<<endl;
    cout<<" \t7. Por referencia "<<endl;
    cout<<" \t8. Antes de la referencia "<<endl;
    cout<<" \t9. Despues de la referencia "<<endl;

cout<<"\n  INGRESE OPCION: ";
cin>>op;
cout<<endl;

switch(op)
{
	case 1:
   cout<<"\tIngrese dato : ";
  	cin>>dato;cout<<endl;    clrscr();
   insertar_i( frente, dato );		mostrar(frente);
   break;
   case 2:
   cout<<"\tIngrese dato : ";
   cin>>dato;cout<<endl;        clrscr();
   insertar_f(frente,q,r,dato);		mostrar(frente);
   break;
   case 3:
   cout<<"\tIngrese dato : ";
   cin>>dato;cout<<endl;
   cout<<"\tIngrese referente : ";
   cin>>ref;cout<<endl;clrscr();
   insertar_a_r(frente,q,r,dato,ref);		mostrar(frente);
   break;
   case 4:
   cout<<"\tIngrese dato : ";
   cin>>dato;cout<<endl;
   cout<<"\tIngrese referente : ";
   cin>>ref;cout<<endl;clrscr();
   insertar_d_r(frente,q,dato,ref);		mostrar(frente);
   break;
   case 5:
   eliminar_i(frente);     clrscr();			mostrar(frente);
   break;
   case 6:
   eliminar_f(frente);     clrscr();			mostrar(frente);
   break;
   case 7:
   cout<<"\tIngrese referente : ";
   cin>>ref;cout<<endl;   clrscr();
   eliminar_ref(frente,ref);   mostrar(frente);
   break;
   case 8:
   cout<<"\tIngrese referente : ";
   cin>>ref;cout<<endl; clrscr();
   eliminar_a_r(frente,ref);     mostrar(frente);
   break;
   case 9:
   cout<<"\tIngrese referente : ";
   cin>>ref;cout<<endl; clrscr();
   eliminar_d_r(frente,ref);     mostrar(frente);
   break;

}
}while(op!=10);

   cout<<endl;
system("pause");
}