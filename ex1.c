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
        printf("Nom : %s", medicament[i]->nom);
        printf("Code : %d\n", medicament[i]->code_medicament);
        printf("Date de fabrication : %d\n", medicament[i]->date_fabrication);
        printf("Prix : %d\n", medicament[i]->prix);
        printf("Nombre vendu : %d\n", medicament[i]->nbr_vendu);
        printf("Stock : %d\n", medicament[i]->stock);
    }
}

int main() {
    int taille = 3;
    Medicament** medicament = malloc(taille * sizeof(Medicament*));
    if (medicament == NULL) {
        printf("Erreur d'allocation de memoire pour le tableau\n");
        return 0;
    }

    for (int i = 0; i < taille; i++)
    {
        medicament[i] = malloc(sizeof(Medicament));
        if (medicament[i] == NULL) {
            printf("Erreur d'allocation de memoire pour un medicament\n");
            return 0;
        }
        initialiser_medicament(medicament[i], i);
    }

    tri_bulle(medicament, taille);
    afficher_medicament(medicament, taille);

    return 0;
}