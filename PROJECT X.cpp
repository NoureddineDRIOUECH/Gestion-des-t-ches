#include <iostream>

#include<string>
using namespace std;


class task {
private :
    int num ;
string taski ;
string statut ;

public :


    void settaski (string ta );
    void setstatut (string st);
    string gettaski ();
    string getstatut ();
void addtask ();
task*  removtask (task t[] ,int n,int ind);
void addstatut ();
void gettask () ;
};
// implementation

void task::settaski (string ta ){
    this->taski = ta ;
}
    void task::setstatut (string st){
    this->statut= st ;

    }
    string task::gettaski (){
    return this->taski ;
    }
     string task::getstatut(){
    return this->statut;
    }
// les methodes :
void task::addtask( ) {
    string nom;
    cout << "entrez une tache a faire : ";
       cin.ignore();
    getline(cin ,nom);
    taski = nom;
    statut = "incomplete";
    cout << endl;
}

void task::addstatut() {

    string st ;
    cout << "entrez l'etat de la tache :" ;
    cin >> st ;

    if (st == "complete") {
        statut=st ;
    } else {
        cout << "retapez la commande " << endl ;
    }
}
void task::gettask(){


    cout << this->taski << "-"<<this->statut ;
    cout << endl ;

}
task * task::removtask (task t[] ,int n,int ind){
    int j ;
 for (j=n;j<=ind;j++){
    t[j]=t[j+1];
 }

return t ;
}
int main() {
   const int taille =100 ;
   task t[taille];

   cout << "GESTION DES TACHES :::: ->>> " << endl ;
    int i=0 ;
    string choix ;

   int n ;
int j ,m;
do {

 cout <<"entrez un de ces comandes (ajouter, supprimer, completer, quitter) " ;

   cin >> choix ;
cout << endl ;

   if (choix == "ajouter" ){
       t[i].addtask() ;
          for (j = 0; j < i; j++) {
           cout << j+1 << ". ";
           t[j].gettask();
       }
   }
    if (choix =="completer" ){

    cout << "entrez le numero de la tache : " ;
    cin >> n;
    n--;
        t[n].addstatut() ;
           for (j = 0; j < i; j++) {
           cout << j+1 << ". ";
           t[j].gettask();
       }

    }


       if (choix=="supprimer"){

      int m;
            cout << "entrez le numero de la tache : ";
            cin >> m;
            m--;
            t[i].removtask(t, m, i);
            i--;
   for (j = 0; j < i; j++) {
           cout << j+1 << ". ";
           t[j].gettask();
       }
       }


i++ ;
   } while (choix != "quitter")  ;


    return 0;
}
