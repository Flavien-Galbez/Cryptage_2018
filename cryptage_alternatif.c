#include "cryptage_cesar.h"
#include "cryptage_alternatif.h"

void autre_methode()
{
	int choix;
	do
	{
		printf("\n");
		printf("Veuillez selectionner une fonctionnalite de la variante (1 to 5):\n");
		printf(" 1 - Chiffrer un mot\n");
		printf(" 2 - Dechiffrer un mot\n");
		printf(" 3 - Chiffrer un texte se trouvant dans un fichier\n");
		printf(" 4 - Dechiffrer un texte se trouvant dans un fichier\n");
		printf(" 5 - Revenir au cryptage de base\n");
		scanf("%d",&choix);	
		if (choix==1)
		{
			chiffrer_un_mot_alternatif();
		}
		if (choix==2)
		{
			dechiffrer_un_mot_alternatif();
		}
		if (choix==3)
		{
			chiffrer_un_texte_alternatif();
		}
		if (choix==4)
		{
			dechiffrer_un_texte_alternatif();
		}
		printf("\n");
	}
	while(choix!=5); //On revient au menu principal seulement si on saisit le choix 5
}

char coder_lettre_alternatif (char c, int n)
{
	char resultat=c;
	if (c%2==0) //Si le code ASCII de la lettre est pair alors elle est codé par la lettre de 2*n position dans l'alphabet après elle (de façon circulaire)
	{
		if (est_lettre_minuscule(c)==true)
		{
			resultat=((c-'a'+2*n)%26+'a');
		}
		else
		{
			if (est_lettre_majuscule(c)==true)
			{
				resultat=((c-'A'+2*n)%26+'A');
			}
		}
	}
	else //Si le code ASCII de la lettre est pair alors elle est codé par la lettre de 2*n position dans l'alphabet avant elle (de façon circulaire)
	{
		if (est_lettre_minuscule(c)==true)
		{
			resultat=((c-'a'-2*n)%26+'a');
			if(resultat<'a')
			{
				resultat+=26; //permet de replacer le caractere s'il est sorti des lettres minuscules
			}
		}
		else
		{
			if (est_lettre_majuscule(c)==true)
			{
				resultat=((c-'A'-2*n)%26+'A');
				if(resultat<'A')
				{
					resultat+=26; //permet de replacer le caractere s'il est sorti des lettres majuscules
				}
			}
		}
	}
	return resultat;
}

char decoder_lettre_alternatif (char c, int n)
{
	char resultat=c; 
	if (c%2==0) //Si le code ASCII de la lettre est pair alors elle est décodé par la lettre de 2*n position dans l'alphabet avant elle (de façon circulaire)
	{
		if (est_lettre_minuscule(c)==true)
		{
			resultat=((c-'a'-2*n)%26+'a');
			if(resultat<'a')
			{
				resultat+=26; //permet de replacer le caractere s'il est sorti des lettres minuscules
			}
		}
		else
		{
			if (est_lettre_majuscule(c)==true)
			{
				resultat=((c-'A'-2*n)%26+'A');
				if(resultat<'A')
				{
					resultat+=26; //permet de replacer le caractere s'il est sorti des lettres majuscules
				}
			}
		}
	}
	else //Si le code ASCII de la lettre est pair alors elle est décodé par la lettre de 2*n position dans l'alphabet après elle (de façon circulaire)
	{
		if (est_lettre_minuscule(c)==true)
		{
			resultat=((c-'a'+2*n)%26+'a');
		}
		else
		{
			if (est_lettre_majuscule(c)==true)
			{
				resultat=((c-'A'+2*n)%26+'A');
			}
		}
	}
	return resultat;
}

char * chiffrement_alternatif (char* mot, int n)
{
	int longueur_mot=longueur(mot);
	char* mot_chiffre = (char*)malloc((longueur_mot+1)*sizeof(char)); //On n'oublie pas de garder une case pour le '\0' donc longueur_mot+1
	for (int i=0;i<longueur_mot;i++)
	{
		mot_chiffre[i]=coder_lettre_alternatif(mot[i],n);
	}
	mot_chiffre[longueur_mot]='\0'; //Et on le place bien évidemmment à la fin
	return mot_chiffre;
}

char * dechiffrement_alternatif (char* mot, int n)
{
	int longueur_mot=longueur(mot);
	char* mot_dechiffre = (char*)malloc((longueur_mot+1)*sizeof(char)); //On n'oublie pas de garder une case pour le '\0' donc longueur_mot+1
	for (int i=0;i<longueur_mot;i++)
	{
		mot_dechiffre[i]=decoder_lettre_alternatif(mot[i],n);
	}
	mot_dechiffre[longueur_mot]='\0'; //Et on le place bien évidemmment à la fin
	return mot_dechiffre;
}

void chiffrer_un_mot_alternatif()
{
	char* mot_saisi = saisir_mot();
	int n = saisir_cle();
	char* mot_chiffre = chiffrement_alternatif(mot_saisi,n);
	printf("Le mot crypte est : %s\n",mot_chiffre);
}

void dechiffrer_un_mot_alternatif()
{
	char* mot_saisi = saisir_mot();
	int n = saisir_cle();
	char* mot_dechiffre = dechiffrement_alternatif(mot_saisi,n);
	printf("Le mot decrypte est : %s\n",mot_dechiffre);
}

void chiffrer_un_texte_alternatif()
{
	char* nom_fichier = choix_texte();
	char* nom_fichier_crypte = saisir_fichier_nouveau();
	int n = saisir_cle();
	FILE * fichier = fopen (nom_fichier,"r"); //ouvre le premier fichier en mode lecture
	FILE * new_fichier=fopen(nom_fichier_crypte,"w"); //creer le second fichier en mode écriture
	if( fichier != NULL )
	{
		char* s =(char*)malloc(10*sizeof(char));//on crée un pointeur pour contenir le nombre n sous forme de caractère
		sprintf(s, "%d", n); // permet de convertir un entier en chaîne de caractère
		fputs(s,new_fichier); // place n sur la première ligne
		fputs("\n",new_fichier);
		char c = fgetc (fichier);
		while ( c != EOF ) //tant qu'on n'a pas atteind la fin du fichier
		{
			fputc(coder_lettre_alternatif(c,n),new_fichier); //les caracteres du 1er fichier sont cryptés un par un et saisis en même temps sur le nouveau fichier
			c = fgetc ( fichier );
		}
		fclose ( fichier );
		fclose ( new_fichier );
		printf (" Le nouveau fichier %s a bien ete creer\n", nom_fichier_crypte );
	}
	else
	{
		//Le fichier n'a pas été trouver
		printf (" Probleme lors de l'ouverture du fichier %s\n", nom_fichier );
	}
}

void dechiffrer_un_texte_alternatif()
{
	char* nom_fichier =choix_texte();
	char* nom_fichier_decrypte = saisir_fichier_nouveau();
	int n;
	FILE * fichier = fopen ( nom_fichier ,"r"); //ouvre le premier fichier en mode lecture
	FILE * new_fichier=fopen(nom_fichier_decrypte,"w"); //creer le second fichier en mode écriture
	if( fichier != NULL )
	{
		char* s =(char*)malloc(10*sizeof(char)); //On crée un pointeur pour récupérer n sous forme de caractère
		char c;
		int i=0;
		do
		{
			c = fgetc ( fichier );
			s[i]=c;
			i++;
		}
		while(c!='\n'); //permet de récupérer n qui est en tête de fichier
		sscanf(s, "%d", &n); //permet de transformer la chaine de caractère en un entier n utilisable
		c = fgetc ( fichier );
		while ( c != EOF ) 
		{
			fputc(decoder_lettre_alternatif(c,n),new_fichier); //les caracteres du 1er fichier sont décryptés un par un et saisis en même temps sur le nouveau fichier
			c = fgetc ( fichier );
		}
		fclose ( fichier );
		fclose ( new_fichier );
		printf (" Le nouveau fichier %s a bien ete cree\n", nom_fichier_decrypte );
	}
	else
	{
		//Le fichier n'a pas été trouver
		printf (" Probleme lors de l'ouverture du fichier %s\n", nom_fichier );
	}
}