#include <iostream>
#include <vector>
#include <string>

// couleurs pour les mesages de succes
#define COLOR_GREEN "\033[1;32m"
#define COLOR_RESET "\033[0m"

using namespace std;

class Tache {
private:
    string nom;
    bool complete;

public:
    Tache(string nom) {
        this->nom = nom;
        complete = false;
    }

    void afficher(int indice) const {
        cout << "   " << indice << ". " << nom;
        if (complete) {
            cout << " - Complete" << endl;
        }
        else {
            cout << " - Incomplete" << endl;
        }
    }

    void marquerComplete() {
        complete = true;
    }
};

// fonction pour ajouter une nuvelle tache
void ajouterTache(vector<Tache>& listeTaches) {
    string nom;

    cout << "Nom de la tache: ";
    getline(cin, nom);
    cout << endl;

    Tache tache(nom);
    listeTaches.push_back(tache);

    cout << COLOR_GREEN << "La tache a ete ajoutee avec succes !" << COLOR_RESET << endl;
}

// fonction pour afficher toutes les taches
void afficherTaches(const vector<Tache>& listeTaches) {
    cout << endl << "Liste des taches : " << endl;
    if (listeTaches.empty()) {
        cout << "Aucune tache n'est disponible." << endl;
    }
    else {
        for (int i = 0; i < listeTaches.size(); i++) {
            listeTaches[i].afficher(i + 1);
        }
    }
    cout << endl;
}

// fonction pour marquer une tache comme terminee
void marquerComplete(vector<Tache>& listeTaches) {
    afficherTaches(listeTaches);

    int indice;
    cout << "Indice de la tache a marquer comme complete: ";
    cin >> indice;
    cout << endl;

    if (indice >= 1 && indice <= listeTaches.size()) {
        listeTaches[indice - 1].marquerComplete();
        cout << COLOR_GREEN << "La tache a ete marquee comme complete avec succes !" << COLOR_RESET << endl;
    }
    else {
        cout << "Indice de tache invalide !" << endl;
    }
}

// Fonction pour supprimer une tache
void supprimerTache(vector<Tache>& listeTaches) {
    afficherTaches(listeTaches);

    int indice;
    cout << "Indice de la tache a supprimer: ";
    cin >> indice;
    cout << endl;

    if (indice >= 1 && indice <= listeTaches.size()) {
        listeTaches.erase(listeTaches.begin() + indice - 1);
        cout << COLOR_GREEN << "La tache a ete supprimee avec succes !" << COLOR_RESET << endl;
    }
    else {
        cout << "Indice de tache invalide !" << endl;
    }
}

int main() {
    cout << "******************************************" << endl;
    cout << "           GESTION DES TACHES              " << endl;
    cout << "******************************************" << endl << endl;

    vector<Tache> listeTaches;
    int choix;

    do {
        cout << "Entrez l'une des commandes suivantes : " << endl;
        cout << "1. Afficher les taches" << endl;
        cout << "2. Ajouter une tache" << endl;
        cout << "3. Supprimer une tache" << endl;
        cout << "4. Marquer une tache comme complete" << endl;  \\ affichage du menu de commande 
        cout << "5. Quitter" << endl;
        cout << "Choix: ";

        cin >> choix;
        cin.ignore();
        cout << endl;

        switch (choix) {
            case 1:
                afficherTaches(listeTaches);
                break;
            case 2:
                ajouterTache(listeTaches);
                break;
            case 3:
                supprimerTache(listeTaches);
                break;
            case 4:
                marquerComplete(listeTaches);
                break;
            case 5:
                cout << "Au revoir !" << endl;
                break;
            default:
                cout << "Choix invalide." << endl;
                break;
        }
        cout << endl;

    } while (choix != 5);

    return 0;
}
