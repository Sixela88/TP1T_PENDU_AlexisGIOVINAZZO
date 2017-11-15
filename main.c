#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAILLE 255
#define MOT "TROUVER"
//Prototypes :
void Initialisation(int *vie,char mot[TAILLE],int *taillemot, char carfind[TAILLE]);
void CarTrouve(int *taillemot,char carsaisi, char mot[TAILLE], char carfind[TAILLE], int *vie);

 //BUT : Jeu du pendu
    //ENTREES : caractere pour trouver le mot,choix pour recommencer
    //SORTIES : affichage du mot et des lettres trouvées ainsi que le nombre de "vies" restantes

    /*

    //BUT : Procédure d'initialisation du mot de mon pendu et des vies
    //Sorties : Nombre de vies et mot à trouver
    PROCEDURE Initialisation(var vie:Entier; var mot:Chaine; var taillemot:Entier; var carfind:Chaine) // Si le mot change VAR pour le mot et la taille du mot

    VAR
        i: Entier

    DEBUT

        vie <- 6
        mot <- "TROUVER"
        taillemot <- longueur(mot)

        POUR i DE 1 A taillemot FAIRE
            carfind[i]<- "_"
        FINPOUR

    FINPROCEDURE

    //BUT : Procédure de vérification de l'existence du caractère saisi dans le mot à trouver.
    //Sorties : Caracteres trouvé ou vie perdue
    PROCEDURE CarTrouve(taillemot : Entier; car:Caractere; mot:Chaine; var carfind:Chaine; var vie:Entier)

    var
        i:Entier
        carexiste:booleen

    DEBUT
        carexiste <- FAUX
        POUR i DE 1 A taillemot FAIRE
            SI (car=mot[i]) ALORS
                carfind[i]<-car
                carexiste <- VRAI
            FINSI
        SI (carexiste=FAUX)
            ECRIRE "Vous perdez une vie"
            vie <- vie-1
        FINSI
    FINPROCEDURE


    //PROGRAMME PRINCIPAL

    VAR
        car : caractere
        choix : caractere
        vie : entier
        mot : chaine
        taillemot: entier
        carfind : chaine
        vict : booleen

    DEBUT
        ECRIRE "JEU DU PENDU"

        REPETER

            Initialisation(vies,mot,taillemot,carfind)

            REPETER
                Fonction(cls)
                ECRIRE (carfind)
                ECRIRE "Entrez un caractère"
                LIRE Fonction(ToUpper(car))
                CarTrouve(taillemot,car,mot,carfind,vie) //Utilisation de la procédure CarTrouve pour vérifier que le caractère saisi existe dans le mot à trouver

                SI (carfind=mot) ALORS
                    vict <- VRAI
                    ECRIRE "Vous avez trouvé le mot! BRAVO !"
                    ECRIRE ("Le mot était bien ",mot)
                FINSI

                SI (vies<=0) ALORS
                    vict <- FAUX
                    ECRIRE "Désolé ! Vous avez perdu !"
                    ECRIRE ("Le mot était ",mot)
                FINSI

            JUSQU'A (vict=VRAI OU vict=FAUX)

            ECRIRE "Voulez-vous recommencer une partie ? O/N"
            LIRE (choix)

        JUSQU'A (choix=N)

    FIN
    */

int main()
{

    //Variables:
    char carsaisi=' ';
    char choix=' ';
    int vie=0;
    char mot[TAILLE];
    int taillemot=0;
    char carfind[TAILLE];
    int vict=0;

    printf("JEU DU PENDU\n");

        do{
            Initialisation(&vie,mot,&taillemot,carfind);
            vict=2;

            do{
                system("cls");
                fflush(stdin);
                printf("Ce que vous avez deja trouve : \n");
                puts(carfind);
                printf("Entrez un caractere\n");
                carsaisi=toupper(getchar());
                CarTrouve(&taillemot,carsaisi,mot,carfind,&vie);//Utilisation de la procédure CarTrouve pour vérifier que le caractère saisi existe dans le mot à trouver
                //fflush(stdin);

                if (carfind==mot){ //Victoire
                    vict=1;
                    printf("Vous avez trouvé le mot ! BRAVO !\n");
                    printf("Le mot était bien \n",mot);
                }

                if (&vie<=0){ //Défaite
                    vict=0;
                    printf("Désolé, vous avez perdu.\n");
                    printf("Le mot était \n",mot);
                }

            }while (vict==2);

            printf("Voulez-vous recommencer une partie ? O/N\n");
            choix=getchar();

        }while(choix=='O');

    system("pause");
    return 0;
}

void Initialisation(int *vie,char mot[TAILLE],int *taillemot, char carfind[TAILLE]){

    int i=0;

    *vie=6;
    strcpy(mot,"TROUVER");    //scanf("%s",mot);

    *taillemot = strlen(mot);

    for(i=0;i<=*taillemot-1;i++){
        carfind[i]= '_';
        if (i==*taillemot-1)
            carfind[i+1]='\0';
        }
}

void CarTrouve(int *taillemot,char carsaisi, char mot[TAILLE], char carfind[TAILLE], int *vie){

    int i=0;
    int carexiste=0;

    for(i=0;i<=*taillemot-1;i++){
        if (carsaisi==mot[i]){
            carfind[i]=carsaisi;
            carexiste=1;
        }
    }
    if (carexiste==0){
        printf("Vous perdez une vie\n");
        *vie=*vie-1;
    }
}






