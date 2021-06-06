#include "liste_temp.h"
#include<string>
#include<iostream>

using namespace std;

template <typename T>
class Element {
public:
   // constructeur
   Element(const T& s);

private:
   T valeur;

   // pointeurs vers les voisins
   Element<T>* precedent;
   Element<T>* suivant;

friend class Liste<T>;
friend class Iterateur<T>;
};

template <typename T>
Element<T>::Element(const T& s) {
   valeur = s;
   precedent = suivant = NULL;
}

template <typename T>
Iterateur<T>::Iterateur() {
   position = dernier = NULL;
}

template <typename T>
T& Iterateur<T>::get() const {
   return position->valeur;
}

//operateur get()
template<typename T>
T& Iterateur<T>::operator*() const
{
	return this->position->valeur;
}

template <typename T>
void Iterateur<T>::suivant() {
   position = position->suivant;
}
template <typename T>
Iterateur<T>& Iterateur<T>::operator++()
{
	this->suivant();
	return *this;
}
template <typename T>
Iterateur<T> Iterateur<T>::operator++(int)
{
	Iterateur<T> res(*this);
	++(*this);
	return *this;
}
template <typename T>
Iterateur<T>& Iterateur<T>::operator--()
{
	this->precedent();
	return *this;
}
template <typename T>
Iterateur<T> Iterateur<T>::operator--(int)
{
	Iterateur<T> res(*this);
	--(*this);
	return *this;
}
template <typename T>
bool Iterateur<T>::operator==(const Iterateur<T>& p)
{
   return (position==p.position);
}
template <typename T>
bool Iterateur<T>::operator!=(const Iterateur<T>& it)
{
  return (position != it.position);
}


template <typename T>
void Iterateur<T>::precedent() {
   if (position == NULL) // fin de la liste
      position = dernier;
   else
      position = position->precedent;
}

template <typename T>
bool Iterateur<T>::egal(const Iterateur<T>& b) const {
   return position == b.position;
}

template <typename T>
Liste<T>::Liste() {
   premier = dernier = NULL;
}

template <typename T>
Iterateur<T> Liste<T>::debut() const {
   Iterateur<T> it;
   it.position = premier;
   it.dernier = dernier;
   return it;
}

template <typename T>
Iterateur<T> Liste<T>::fin() const {
   Iterateur<T> it;
   it.position = NULL;
   it.dernier = dernier;
   return it;
}

// ajouter s a la fin de la liste
template <typename T>
void Liste<T>::ajouter(const T& s){
  	Element<T>* pe = new Element<T>(s);
  	if(premier == NULL){
  		premier = dernier =pe;
  	}
  	else{
  		pe->precedent = dernier;
  		dernier ->suivant = pe;
  		dernier = pe;
  	    }
}

// ajouter s avant la position pos
template <typename T>
void Liste<T>::inserer(Iterateur<T>& pos, const T& s){
    Element<T>* element=new Element<T>(s);
    if (pos.position == NULL) this->ajouter(s);
    else {
      if (pos.position == premier){
        element->suivant = pos.position;
        pos.position->precedent = element;
        premier = element;
      }else{
        element->suivant = pos.position;
        pos.position->precedent->suivant = element;
        element->precedent = pos.position->precedent;
        pos.position->precedent = element;
      }
    }//Jetbrains
  }

  // supprimer l'element a la position pos
  template <typename T>
  void Liste<T>::supprimer(Iterateur<T>& pos) {
        if (pos.position != NULL){//la liste n'est pas vide !!
          if (premier == dernier) {//notre liste contient qu'un seul element
            premier = dernier = NULL;
          }else{/*notre liste contient plusieurs elements*/
            if (pos.position->suivant == NULL) {//pos se trouve au dernier element dans la Liste
              dernier = pos.position->precedent;
              pos.position->precedent->suivant=NULL;


            }else{
              if (pos.position->precedent == NULL) {/*le cas ou pos se trouve dans le premier element */
                premier = pos.position->suivant;
                pos.position->suivant->precedent = NULL;
              }else{/* le cas ou element se trouve entre deux element de la liste */
                pos.position->precedent->suivant = pos.position->suivant;
                pos.position->suivant->precedent = pos.position->precedent;

              }
            }
          }
        }
        delete(pos.position);/*dans tout les cas on doit libérer la memoire*/

    }


  //constructeur par recopie
  template <typename T>
  Liste<T>::Liste(const Liste<T>& l){
    if (premier == NULL)
    {
        cout<<"la liste est vide ya rien a copier"<<endl;
    }else{
    Iterateur<T> it = l.debut();
    while (it.position != NULL)
    {
      ajouter(it.position->valeur);
      it.suivant();
    }
  }
  }

  //le destructeur
  template <typename T>
  Liste<T>::~Liste(){
    if (this->premier == this->dernier) {
      delete(this->premier);
    }else{
      while (this->premier != this->dernier)
      {
      this->premier =  this->premier->suivant;
        delete(this->premier->precedent);
      }
      delete(this->premier);
    }

  }

  //l'operateur (=)
  template <typename T>
  Liste<T>& Liste<T>::operator=(const Liste<T>& l)
  {
    Liste<T> resultat(l);
    return resultat;
  }

  template <typename T>
  void Liste<T>::afficher() {
  	Iterateur<T> it = this->debut();

  	while (it.position != NULL) {
  		cout  << it.get() << endl;
  		it.suivant();
  	}

  }
