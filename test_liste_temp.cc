#include <iostream>
#include"liste_temp.h"
#include"liste_temp.cc"
int main()
{

	Liste<string> l;
	l.ajouter("Baleze Bruno");
  l.ajouter("Costaud Claude");
  l.ajouter("Doue Damien");
  l.ajouter("Vaillant Veronique");

	Iterateur<string> it = l.debut();
  Iterateur<string> p = l.debut();
	it++; it++; it++;
  p++;
	l.inserer(it, "Sage Stephane");
	l.afficher();
	it = l.debut();
	it++;
  if (it == p) {cout<<"daghyooooool"<<endl;}
  else{cout<<"machi daghyulll"<<endl;}
	l.supprimer(it);
	l.afficher();



     return 0;
}
