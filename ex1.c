#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nom[50];
    int code_medicament;
    int date_fabrication;
    int prix;
    int nbr_vendu;
    int stock;
} Medicament;

void initialiser_medicament(Medicament* medicament, int i) {
    printf("Entrez le nom du medicament %d : ", i + 1);
    fgets(medicament->nom, sizeof(medicament->nom), stdin);
    printf("Entrez le code du medicament %d : ", i + 1);
    scanf("%d", &medicament->code_medicament);
    getchar();
    printf("Entrez la date de fabrication du medicament %d : ", i + 1);
    scanf("%d", &medicament->date_fabrication);
    getchar();
    printf("Entrez le prix du medicament %d : ", i + 1);
    scanf("%d", &medicament->prix);
    getchar();
    printf("Entrez le nombre de medicament vendu %d : ", i + 1);
    scanf("%d", &medicament->nbr_vendu);
    getchar();
    printf("Entrez le stock du medicament %d : ", i + 1);
    scanf("%d", &medicament->stock);
    getchar();
}

int compare_date(int date1, int date2) {
    int annee1 = date1 % 10000;
    int annee2 = date2 % 10000;
    
    if (annee1 > annee2) {
        return 1;
    } else if (annee1 < annee2) {
        return 0;
    }
    
    int mois1 = (date1 / 10000) % 100;
    int mois2 = (date2 / 10000) % 100;
    
    if (mois1 > mois2) {
        return 1;
    } else if (mois1 < mois2) {
        return 0;
    }
    
    int jour1 = (date1 / 1000000);
    int jour2 = (date2 / 1000000);
    
    if (jour1 > jour2) {
        return 1;
    }
    
    return 0;
}

void tri_bulle(Medicament* medicament[], int taille) {
    int i, j;
    int tableau_trie;
    Medicament* temp;
    
    for (i = 0; i < taille - 1; i++) {
        tableau_trie = 1; 
        
        for (j = 0; j < taille - i - 1; j++) {
            if (compare_date(medicament[j]->date_fabrication, medicament[j + 1]->date_fabrication)) {
                temp = medicament[j];
                medicament[j] = medicament[j + 1];
                medicament[j + 1] = temp;
                tableau_trie = 0;  
            }
        }
        
        if (tableau_trie) {
            break;
        }
    }
}

void afficher_medicament(Medicament* medicament[], int taille) {
    for (int i = 0; i < taille; i++) {
        printf("Medicament %d :\n", i + 1);
        printf("Nom : %s\n", medicament[i]->nom);
        printf("Code : %d\n", medicament[i]->code_medicament);
        printf("Date de fabrication : %d\n", medicament[i]->date_fabrication);
        printf("Prix : %d\n", medicament[i]->prix);
        printf("Nombre vendu : %d\n", medicament[i]->nbr_vendu);
        printf("Stock : %d\n\n", medicament[i]->stock);
    }
}

void recherche_dichotomique(Medicament** medicaments, int taille) {
    int debut = 0;
    int fin = taille - 1;
    int trouve = 0;
    int mil;
    
    while (!trouve && debut <= fin) {
        mil = (debut + fin) / 2;

        int resultat_comparaison = strcmp(medicaments[mil]->nom, "paracetamol");
        
        if (resultat_comparaison == 0) {
            trouve = 1;
        } else {
            if (resultat_comparaison < 0) {
                debut = mil + 1;
            } else {
                fin = mil - 1;
            }
        }
    }
    
    if (trouve) {
        printf("Le paracetamol est le %deme medicament de la liste\n", mil + 1);
    } else {
        printf("Le paracetamol n'est pas dans le tableau\n");
    }
}

int main() {
    int taille = 5;
    Medicament** medicament = malloc(taille * sizeof(Medicament*));
    if (medicament == NULL) {
        printf("Erreur d'allocation de memoire pour le tableau\n");
        return 0;
    }

    // for (int i = 0; i < taille; i++)
    // {
    //     medicament[i] = malloc(sizeof(Medicament));
    //     if (medicament[i] == NULL) {
    //         printf("Erreur d'allocation de memoire pour un medicament\n");
    //         return 0;
    //     }
    //     initialiser_medicament(medicament[i], i);
    // }

    Medicament medicaments_init[] = {
        {"ibuprofene", 1, 20012025, 700, 90, 60},
        {"amoxicilline", 2, 10032018, 1200, 45, 100},
        {"aspirine", 3, 15043000, 450, 200, 150},
        {"paracetamol", 4, 30122026, 500, 120, 80},
        {"omeprazole", 5, 20122225, 850, 75, 120}
    };

    for (int i = 0; i < taille; i++) {
        medicament[i] = malloc(sizeof(Medicament));
        *medicament[i] = medicaments_init[i];
    }

    tri_bulle(medicament, taille);
    afficher_medicament(medicament, taille);
    recherche_dichotomique(medicament, taille);

    return 0;
}