#include<stdio.h>

int decomposer (int a, int tab[], int nbEff)
{
	int i=0;
	printf("%d/2\t", a);
	while (a!=0)
	{
		if (a%2==1)
			tab[i]=1;
		else 
			tab[i]=0;
		printf ("%d\t", a);
		a=a/2;
		i++;
		nbEff++;
	}
	printf("\n");
	return nbEff;
}
void afficherResteK (int tab[], int nbEff)
{
	int i;
	printf("Restes\t");
	for (i=0; i<nbEff; i++)
		printf ("%d \t", tab[i]);
	printf("\nk\t");
	int a;
	for (a=0; a<nbEff; a++)
		printf ("%d\t", a);
	printf ("\n");
}
void afficheligne4 (int valeurDef, int base, int nbEff, int tab2[])
{
	printf ("%dk\t", valeurDef);
	tab2[0]=valeurDef;
	int i;
	printf ("%d\t", valeurDef);
	for (i=1; i<nbEff; i++){
		valeurDef=(valeurDef*valeurDef)%base;
		printf("%d\t", valeurDef);
		tab2[i]=valeurDef;
	}
	printf("\n");
}

void afficheligne5 (int valeurDef, int base, int tab[], int nbEff, int tab2[])
{
	int i=1;
	printf ("\t%d\t", valeurDef);
	for (i=1; i<nbEff; i++){
		if (tab[i]==1){
			valeurDef=(valeurDef*tab2[i])%base;
			printf("%d\t", valeurDef);
		}
		else
			printf("-\t");
	}
	printf("\n");
}

int main()
{
	int valeurDec, nbEff=0, base, valeurDef;
	int tab[20]={};
	int tab2[20]={};
	printf("Quelle est la valeur à décomposer en base 2?\n");
	scanf("%d", &valeurDec);
	while (valeurDec<0){
		printf("Quelle est la valeur à décomposer en base 2?\n");
		scanf("%d", &valeurDec);
	}
	printf ("Dans quelle base sommes nous?\n");
	scanf ("%d", &base);
	printf ("Quelle est la valeur défini?\n");
	scanf ("%d", &valeurDef);
	nbEff=decomposer (valeurDec, tab, nbEff);
	afficherResteK (tab, nbEff);
	afficheligne4(valeurDef, base, nbEff, tab2);
	afficheligne5(valeurDef, base, tab, nbEff, tab2);
	return 0;
}