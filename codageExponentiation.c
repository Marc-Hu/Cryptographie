#include<stdio.h>

/*
* Author : Marc HU
* Title : codage par exponentiation
* Programme qui va coder ou décoder des lettres ou groupement de lettre en format ASCII
* 
*/


/*
* Fonction qui va décomposer et afficher la ligne 
* On va décomposer un nombre en base 2
* Et on va l'afficher
* On va retourner le nombre effectif du tableau que l'on a crée
*/
int decomposer (int a, int tab[], int nbEff)
{
	printf("%d/2\t", a);
	for (int i=0; a!=0; i++){
		if (a%2==1)
			tab[i]=1;
		else 
			tab[i]=0;
		printf ("%d\t", a);
		a=a/2;
		nbEff++;
	}
	printf("\n");
	return nbEff;
}

/*
* Fonction qui va afficher la ligne des restes de la décomposition (1 ou 0) 
* On va aussi afficher k qui est l'indice des cases du tableau 
*/

void afficherResteK (int tab[], int nbEff)
{
	printf("Restes\t");
	for (int i=0; i<nbEff; i++)
		printf ("%d \t", tab[i]);
	printf("\nk\t");
	for (int i=0; i<nbEff; i++)
		printf ("%d\t", i);
	printf ("\n");
}

/*
* Fonction qui va afficher la 4ème lignes du codage/décodage
*/
void afficheligne4 (int valeurDef, int base, int nbEff, int tab2[])
{
	printf ("%dk\t", valeurDef);
	tab2[0]=valeurDef;
	printf ("%d\t", valeurDef);
	for (int i=1; i<nbEff; i++){
		valeurDef=(valeurDef*valeurDef)%base;
		printf("%d\t", valeurDef);
		tab2[i]=valeurDef;
	}
	printf("\n");
}

/*
* Fonction qui va afficher la 5ème lignes du codage/décodage
* On affiche aussi le résultat attendu
*/

void afficheligne5 (int valeurDef, int base, int tab[], int nbEff, int tab2[])
{
	int valDepart = valeurDef;
	printf ("\t%d\t", valeurDef);
	for (int i=1; i<nbEff; i++){
		if (tab[i]==1){
			valeurDef=(valeurDef*tab2[i])%base;
			printf("%d\t", valeurDef);
		}
		else
			printf("-\t");
	}
	printf("\nLe codage/décodage par exponentiation de %d est : %d\n", valDepart, valeurDef);
}

/*
* On demande à l'utilisateur la valeur à décomposer en base 2
* Puis on lui demande dans quelle base on se trouve
* Et pour finir on lui demande la valeur à coder/décoder
*/

int main()
{
	int valeurDec, nbEff=0, base, valeurDef;
	int tab[20]={};
	int tab2[20]={};
	do{
		printf("Quelle est la valeur à décomposer en base 2?\n");
		scanf("%d", &valeurDec);
	}while(valeurDec<0);
	do{
		printf ("Dans quelle base sommes nous?\n");
		scanf ("%d", &base);
	}while(base<0);
	do{
		printf ("Quelle est la valeur à coder/décoder?\n");
		scanf ("%d", &valeurDef);
	}while(valeurDef<0);
	nbEff=decomposer (valeurDec, tab, nbEff);
	afficherResteK (tab, nbEff);
	afficheligne4(valeurDef, base, nbEff, tab2);
	afficheligne5(valeurDef, base, tab, nbEff, tab2);
	return 0;
}