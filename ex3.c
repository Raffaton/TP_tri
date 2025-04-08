#include <stdio.h>
#include <stdlib.h>

int *fusion_2_listes_triees(int tab1[], int taille1, int tab2[], int taille2)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int total = taille1 + taille2;
    
    int *fusion = malloc(total * sizeof(int));
    if (fusion == NULL) {
        printf("Memory allocation failed\n");
        return 0;
    }

    while (i < taille1 && j < taille2)
    {
        if (tab1[i] < tab2[j])
        {
            fusion[k] = tab1[i];
            i++;
        }
        else
        {
            fusion[k] = tab2[j];
            j++;
        }
        k++;
    }

    while (i < taille1)
    {
        fusion[k] = tab1[i];
        k++;
        i++;
    }

    while (j < taille2)
    {
        fusion[k] = tab2[j];
        k++;
        j++;
    }

    return fusion;
}

void afficher_tableau(const int *tab, int taille)
{
    for (int i = 0; i < taille; i++)
    {
        printf("%d ", tab[i]);
    }
    printf("\n");
}

int main()
{
    int liste1[] = {1, 3, 5, 7};
    int taille1 = sizeof(liste1) / sizeof(liste1[0]);
    
    int liste2[] = {2, 4, 6, 8, 10};
    int taille2 = sizeof(liste2) / sizeof(liste2[0]);
    
    int *fusionnee = fusion_2_listes_triees(liste1, taille1, liste2, taille2);

    printf("Tableau fusionne :\n");
    afficher_tableau(fusionnee, taille1 + taille2);
    
    free(fusionnee);
    fusionnee = NULL;

    return 0;
}