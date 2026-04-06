#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Auteur{
private:
string nom;
bool prime;
public:
Auteur( string n, bool p=false): nom(n),prime(p){}
 string getnom()const{ return nom;}
 bool getprix()const{return prime; }
Auteur(Auteur const&)=delete;
Auteur&operator=(const Auteur&)=delete;
};
class oeuvre{
private:
    string titre;
    const Auteurs&auteur;
    string langue;
public:
    oeuvre(string t,const Auteur&a,string l):
    titre(t),auteur(a),langue(l),{}
    string gettitre()const{ return titre;}
    const auteur&getAuteur()const{return auteur;}
    void affiche(){
    cout<<titre<<","<<auteur.getnom()<<"en"<<langue;}
    ~oeuvre(){ cout<<"l'oeuvre";affiche();
    cout<<"\"x' est plus disponible "<<endl;}
    oeuvre(oeuvreconst&)=delete;
    oeuvre&operator=(const oeuvre&)=delete;
};

class










int main()
{
  Auteur a1("Victor Hugo"),
         a2("Alexandre Dumas"),
         a3("Raymond Queneau", true);

  Oeuvre o1("Les Misérables"           , a1, "français" ),
         o2("L'Homme qui rit"          , a1, "français" ),
         o3("Le Comte de Monte-Cristo" , a2, "français" ),
         o4("Zazie dans le métro"      , a3, "français" ),
         o5("The Count of Monte-Cristo", a2, "anglais" );

  Bibliotheque biblio("municipale");
  biblio.stocker(o1, 2);
  biblio.stocker(o2);
  biblio.stocker(o3, 3);
  biblio.stocker(o4);
  biblio.stocker(o5);

  cout << "La bibliothèque " << biblio.getNom()
       << " offre les exemplaires suivants :" << endl;
  biblio.lister_exemplaires();

  const string langue("anglais");
  cout << " Les exemplaires en "<< langue << " sont :" << endl;
  biblio.lister_exemplaires(langue);

  cout << " Les auteurs à succès sont :" << endl;
  biblio.afficher_auteurs(true);

  cout << " Il y a " << biblio.compter_exemplaires(o3) << " exemplaires de "
       << o3.getTitre() << endl;

  return 0;
}
