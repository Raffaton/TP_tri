#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nom[50];
    char prenom[50];
    char matricule[20];
    float moyenne;
} Etudiant;

void swap(Etudiant *a, Etudiant *b) {
    Etudiant temp = *a;
    *a = *b;
    *b = temp;
}

void printEtudiants(Etudiant etudiants[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%s %s | Matricule: %s | Moyenne: %.2f\n",
               etudiants[i].prenom,
               etudiants[i].nom,
               etudiants[i].matricule,
               etudiants[i].moyenne);
    }
    printf("\n");
}

int partition(Etudiant etudiants[], int low, int high) {
    float pivot = etudiants[high].moyenne;

    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (etudiants[j].moyenne < pivot) {
            i++;
            swap(&etudiants[i], &etudiants[j]);
        }
    }

    swap(&etudiants[i + 1], &etudiants[high]);
    return i + 1;
}

void quickSort(Etudiant etudiants[], int low, int high) {
    if (low < high) {
        int pi = partition(etudiants, low, high);
        quickSort(etudiants, low, pi - 1);
        quickSort(etudiants, pi + 1, high);
    }
}

void tri_insertion(Etudiant etudiants[], int taille) {
    int i, j;
    Etudiant cle;

    for (i = 1; i < taille; i++) {
        cle = etudiants[i];
        j = i - 1;

        while (j >= 0 && strcmp(etudiants[j].nom, cle.nom) > 0) {
            etudiants[j + 1] = etudiants[j];
            j--;
        }

        etudiants[j + 1] = cle;
    }
}


int main() {
    Etudiant etudiants[20] = {
        {"Durand", "Alice", "MAT1001", 14.5},
        {"Martin", "Jean", "MAT1002", 12.8},
        {"Bernard", "Lucie", "MAT1003", 15.3},
        {"Dubois", "Marc", "MAT1004", 10.5},
        {"Thomas", "Sophie", "MAT1005", 16.2},
        {"Robert", "Paul", "MAT1006", 11.9},
        {"Richard", "Emma", "MAT1007", 13.4},
        {"Petit", "Lucas", "MAT1008", 9.8},
        {"Leroy", "Chloe", "MAT1009", 17.1},
        {"Moreau", "Hugo", "MAT1010", 14.2},
        {"Simon", "Lea", "MAT1011", 13.0},
        {"Laurent", "Nathan", "MAT1012", 15.7},
        {"Lemoine", "Camille", "MAT1013", 10.0},
        {"Roux", "Ines", "MAT1014", 16.8},
        {"Fontaine", "Noah", "MAT1015", 12.5},
        {"Blanc", "Zoe", "MAT1016", 11.1},
        {"Garnier", "Tom", "MAT1017", 13.9},
        {"Henry", "Julie", "MAT1018", 14.7},
        {"Perrin", "Antoine", "MAT1019", 10.3},
        {"Renard", "Manon", "MAT1020", 15.0}
    };

    int n = 20;

    printf("Etudiants avant tri :\n");
    printEtudiants(etudiants, n);

    quickSort(etudiants, 0, n - 1);

    printf("Etudiants apres tri par moyenne :\n");
    printEtudiants(etudiants, n);

    tri_insertion(etudiants, n);

    printf("Etudiants apres tri par ordre alphabetique :\n");
    printEtudiants(etudiants, n);

    return 0;
}
