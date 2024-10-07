/*
 * Nom du projet: 04_nbre_premiers
 * Nom du fichier: main.cpp
 * Auteur: Maikol Correia Da Silva
 * Date: 04-10-2024
 * Description: Ce programme permet d'afficher les nombres premiers à partir de 2
 *              jusqu'au nombre choisi par l'utilisateur (par exemple, 20).
 *              L'utilisateur peut également recommencer s'il le souhaite.
 */

#include <iostream>
#include <cmath>

using namespace std;

int main() {

    // Description du programme
    cout << "Ce programme a pour but d'afficher les nombres premiers a partir de 2, "
         << "jusqu'au nombre que vous aurez choisi." << endl;

    char restart; // variable qui permettra à l'utilisateur de recommencer ou non

    do {
        int  nb_user; // variable qui stockera le nombre de l'utilisateur

        // Demande une valeur à l'utilisateur
        do {
            cout << "Entrer une valeur [2-1000] :";
            cin  >> nb_user;
        } while(nb_user < 2 || nb_user > 1000);

        int nb_prime = 1;

        // Dans tout les cas le 2 est affiché
        cout << "Voici la liste des nombres premiers " << endl
             << '\t' << 2 << '\t';

        // Calcule des nombres premiers
        for (int i = 3; i <= nb_user; i++) {
            if (i % 2) { // Check si impair
                bool divisible = false;
                for (int j = 3; j <= sqrt(i) + 1; j += 2) {
                    if (i % j == 0) {
                        divisible = true;
                        break;
                    }
                }
                if (!divisible) {
                    cout << i << '\t';
                    nb_prime++;
                    if (nb_prime % 5 == 0) {
                        cout << endl << '\t';
                    }
                }
            }
        }

        // Demande si l'utilisateur veut recommencer
        do {
            cout << endl << "Voulez-vous recommencer [O/N] :";
            cin >> restart;
        } while (restart != 'N' && restart != 'O');

    } while (restart != 'N');

    cout << endl << "Fin du programme" << endl;
}