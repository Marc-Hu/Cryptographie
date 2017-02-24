#include<stdio.h>

void affichage (int tab1[], int tab2[], int nbEff)
{
	printf("Rn\tUn\tVn\tQn\n");
	int a=0, i=0, i2=0;
	while (i<nbEff){
		printf("%d\t", tab1[i]);
		i++;
		if (i==nbEff)
			printf("\n");
	}
	while (i2<nbEff){
		printf("%d\t", tab2[i2]);
		i2++;
		if (i2==nbEff)
			printf("\n");
	}
	while (tab1[0]==0 || tab2[0]==0){
		if (a==0){
			tab1[0]=tab1[0]%tab2[0];
			tab1[1]=tab1[1]-(tab2[1]*tab2[3]);
			tab1[2]=tab1[2]-(tab2[2]*tab2[3]);
			tab1[3]=tab2[0]/tab1[0];
			a=1;
		}
	}
}

int main(){
	int tab1[4]={};
	int tab2[4]={};
	int nbEff=4;
	int i=0;
	printf("Dividende?\n");
	scanf("%d", &tab1[i]);
	printf("Diviseur?\n");
	scanf("%d", &tab2[i]);
	tab1[1]=1;
	tab1[2]=0;
	tab2[1]=0;
	tab2[2]=1;
	tab2[3]=tab1[i]/tab2[i];
	affichage (tab1, tab2, nbEff);	
	return 0;
}