#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

// declaration des structures

typedef struct {
    char nom[50];
    char marque[50];
    int stock;
} Ordinateur;

typedef struct {
    char nom[50];
    char marque[50];
    int stock;
} CarteGraphique;

// déclaration des variables globales
char nom_boutique[] = "Boutique Informatique";
char admin_mot_de_passe[] = "admin123";
char employe_mot_de_passe[] = "employe123";

int nombre_ordinateurs = 0;
int nombre_cartes_graphiques = 0;

Ordinateur ordinateurs[100];
CarteGraphique cartes_graphiques[100];

// les différentes fonction de l'application de gestion de la boutique

void ajouter_ordinateur(char nom[], char marque[], int stock) {
    Ordinateur ordinateur;
    strcpy(ordinateur.nom, nom);
    strcpy(ordinateur.marque, marque);
    ordinateur.stock = stock;
    ordinateurs[nombre_ordinateurs++] = ordinateur;
    printf("L'ordinateur %s a été bien ajouté à la boutique.\n", nom);
}

void afficher_ordinateurs() {
    printf("Liste des ordinateurs disponibles :\n");
    for (int i = 0; i < nombre_ordinateurs; i++) {
        printf("Nom : %s\n", ordinateurs[i].nom);
        printf("Marque : %s\n", ordinateurs[i].marque);
        printf("Stock : %d\n", ordinateurs[i].stock);
        printf("-----------------------------\n");
    }
}

void afficher_stock_ordinateurs() {
    printf("Stock des ordinateurs :\n");
    for (int i = 0; i < nombre_ordinateurs; i++) {
        printf("Ordinateur : %s\n", ordinateurs[i].nom);
        printf("Stock : %d\n", ordinateurs[i].stock);
        printf("-----------------------------\n");
    }
}

void consulter_ordinateur(char nom[]) {
    for (int i = 0; i < nombre_ordinateurs; i++) {
        if (strcmp(ordinateurs[i].nom, nom) == 0) {
            printf("Détails de l'ordinateur %s\n", nom);
            printf("Marque : %s\n", ordinateurs[i].marque);
            printf("Stock : %d\n", ordinateurs[i].stock);
            return;
        }
    }
    printf("L'ordinateur %s n'existe pas dans la boutique.\n", nom);
}

void mettre_a_jour_stock_ordinateur(char nom[], int stock) {
    for (int i = 0; i < nombre_ordinateurs; i++) {
        if (strcmp(ordinateurs[i].nom, nom) == 0) {
            ordinateurs[i].stock = stock;
            printf("Stock de l'ordinateur %s mis à jour : %d\n", nom, stock);
            return;
        }
    }
    printf("L'ordinateur %s n'existe pas dans la boutique.\n", nom);
}

void ajouter_carte_graphique(char nom[], char marque[], int stock) {
    CarteGraphique carte_graphique;
    strcpy(carte_graphique.nom, nom);
    strcpy(carte_graphique.marque, marque);
    carte_graphique.stock = stock;
    cartes_graphiques[nombre_cartes_graphiques++] = carte_graphique;
    printf("La carte graphique %s a été bien ajoutée à la boutique.\n", nom);
}

void afficher_stock_cartes_graphiques() {
    printf("Stock des cartes graphiques :\n");
    for (int i = 0; i < nombre_cartes_graphiques; i++) {
        printf("Carte graphique : %s\n", cartes_graphiques[i].nom);
        printf("Stock : %d\n", cartes_graphiques[i].stock);
        printf("-----------------------------\n");
    }
}

// fonction utilisé par les administrateurs

void administrateur() {
    while (1) {
        printf("-----------------------------\n");
        printf("1. Ajouter un nouvel Ordinateur\n");
        printf("2. Mettre à jour le stock d'un Ordinateur\n");
        printf("3. Ajouter une nouvelle carte graphique\n");
        printf("4. Afficher le stock des ordinateurs\n");
        printf("5. Afficher le stock des cartes graphiques\n");
        printf("6. Déconnexion\n");
        int choix;
        printf("Choisissez une option : ");
        scanf("%d", &choix);

        if (choix == 1) {
            char nom[50], marque[50];
            int stock;

            printf("Nom de l'ordinateur : ");
            scanf("%s", nom);
            printf("Marque de l'ordinateur : ");
            scanf("%s", marque);
            printf("Stock initial de l'ordinateur : ");
            scanf("%d", &stock);

            ajouter_ordinateur(nom, marque, stock);
        }
        else if (choix == 2) {
            char nom[50];
            int stock;

            printf("Nom de l'ordinateur : ");
            scanf("%s", nom);
            printf("Nouveau stock de l'ordinateur : ");
            scanf("%d", &stock);

            mettre_a_jour_stock_ordinateur(nom, stock);
        }
        else if (choix == 3) {
            char nom[50], marque[50];
            int stock;

            printf("Nom de la carte graphique : ");
            scanf("%s", nom);
            printf("Marque de la carte graphique : ");
            scanf("%s", marque);
            printf("Stock initial de la carte graphique : ");
            scanf("%d", &stock);

            ajouter_carte_graphique(nom, marque, stock);
        }
        else if (choix == 4) {
            afficher_stock_ordinateurs();
        }
        else if (choix == 5) {
            afficher_stock_cartes_graphiques();
        }
        else if (choix == 6) {
            printf("Déconnexion de l'administrateur.\n");
            break;
        }
        else {
            printf("Choix invalide.\n");
        }
    }
}

// fonction utilisé par les employés
void employe() {

    while (1) {
        printf("-----------------------------\n");
        printf("1. Afficher le stock des ordinateurs\n");
        printf("2. Afficher le stock des cartes graphiques\n");
        printf("3. Consulter les détails d'un ordinateur\n");
        printf("4. Déconnexion\n");
        int choix;
        printf("Choisissez une option : ");
        scanf("%d", &choix);

        if (choix == 1) {
            afficher_stock_ordinateurs();
        }
        else if (choix == 2) {
            afficher_stock_cartes_graphiques();
        }
        else if (choix == 3) {
            char nom[50];
            printf("Nom de l'ordinateur : ");
            scanf("%s", nom);
            consulter_ordinateur(nom);
        }
        else if (choix == 4) {
            printf("Déconnexion de l'employé.\n");
            break;
        }
        else {
            printf("Choix invalide.\n");
        }
    }
}



// Fonction principale
void main() {
    printf("Bienvenue dans %s\n", nom_boutique);
    while (1) {
        printf("-----------------------------\n");
        printf("1. Se connecter en tant qu'administrateur\n");
        printf("2. Se connecter en tant qu'employe\n");
        printf("3. Quitter l'application\n");
        int choix;
        printf("Choisissez une option : ");
        scanf("%d", &choix);

        if (choix == 1) {
            char mot_de_passe[50];
            printf("Mot de passe administrateur : ");
            scanf("%s", mot_de_passe);
            if (strcmp(mot_de_passe, admin_mot_de_passe) == 0) {
                administrateur();
            }
            else {
                printf("Mot de passe incorrect.\n");
            }
        }
        else if (choix == 2) {
            char mot_de_passe[50];
            printf("Mot de passe employe : ");
            scanf("%s", mot_de_passe);
            if (strcmp(mot_de_passe, employe_mot_de_passe) == 0) {
                employe();
            }
            else {
                printf("Mot de passe incorrect.\n");
            }
        }
        else if (choix == 3) {
            printf("Merci d'avoir utilisé %s\n", nom_boutique);
            break;
        }
        else {
            printf("Choix invalide.\n");
        }
    }
}






