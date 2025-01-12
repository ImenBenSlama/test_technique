#include <iostream>
#include <fstream>  // Pour la lecture de fichiers
#include <string>

using namespace std;

// Fonction pour calculer la valeur d'étalonnage d'une ligne donnée
int calculerEtalonnage(const string& ligne) {
    int premierChiffre = -1, dernierChiffre = -1;

    // Trouver le premier chiffre
    for (char c : ligne) {
        if (isdigit(c)) {
            premierChiffre = c - '0'; // Convertir le caractère en entier
            break;
        }
    }

    // Trouver le dernier chiffre 
    for (int i = ligne.size() - 1; i >= 0; --i) {
        if (isdigit(ligne[i])) {
            dernierChiffre = ligne[i] - '0'; // Convertir le caractère en entier
            break;
        }
    }

    // Si on a trouvé un premier et un dernier chiffre, les combiner
    if (premierChiffre != -1 && dernierChiffre != -1) {
        return premierChiffre * 10 + dernierChiffre; // Former le nombre à deux chiffres
    }

    return 0; // Retourner 0 si aucun chiffre trouvé
}

int main() {
    ifstream fichier("C:/Users/imenb/OneDrive/Bureau/test_technique/document.txt");
 // Ouvrir le fichier
    if (!fichier) {
        cerr << "Erreur : impossible d'ouvrir le fichier.\n";
        return 1;
    }

    string ligne;
    int sommeTotale = 0;

    // Lire le fichier ligne par ligne
    while (getline(fichier, ligne)) {
        int etalonnage = calculerEtalonnage(ligne);
        cout << "Valeur d'étalonnage : " << etalonnage << endl;
        sommeTotale += etalonnage;
    }

    fichier.close(); // Fermer le fichier

    cout << "Somme totale des valeurs d'étalonnage : " << sommeTotale << endl;

    return 0;
}
