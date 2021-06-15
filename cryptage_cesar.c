#include "cryptage_cesar.h"

char * saisir_mot ()
{
	char * mot=(char*)malloc(sizeof(char));
	printf ("Saisir le mot : ");
	scanf("%s",mot);
	return mot;
}

int saisir_cle ()
{
	int n;
	do 
	{
		printf ("Saisir le nombre n pour la cle de cryptage (>0) : ");
		scanf("%d",&n);
	}
	while(n<=0);
	return n;
}

char * saisir_fichier()
{
	char* nom_fichier=(char*)malloc(sizeof(char));
	do
	{
		printf ("Saisir le fichier a utiliser (avec son extension .txt) : ");
		scanf("%s",nom_fichier);
	}
	while (est_fichier_txt(nom_fichier)==false); //On sécurise la saisie afin d'être sûr que l'utilisateur à saisie le nom d'un fichier correcte
	return nom_fichier;
}

char * saisir_fichier_nouveau()
{
	char* nom_fichier=(char*)malloc(sizeof(char));
	do
	{
		printf ("Saisir le nom du fichier sur lequel vous voullez enregistrer le texte chiffre (avec son extension .txt) : "); // Cette fonction est presque identique à la précédente, l'utilisateur rentre le nom d'un nouveau fichier et non d'un existant
		scanf("%s",nom_fichier);
	}
	while (est_fichier_txt(nom_fichier)==false);
	return nom_fichier;
}

unsigned int longueur(const char * chaine)
{
	int indice=0;
	while (chaine[indice]!='\0') // le '\0' marque la fin d'un mot
	{
		indice++;
	}
	return (indice);
}

bool est_lettre_minuscule (char caractere)
{
	bool resultat = true;
	if ('a'>caractere||'z'<caractere)
	{
		resultat= false;
	}
	return resultat;
}

bool est_lettre_majuscule (char caractere)
{
	bool resultat = true;
	if ('A'>caractere||'Z'<caractere)
	{
		resultat= false;
	}
	return resultat;
}

char * chiffrement (char* mot, int n)
{
	int cle = (3*n)%26;
	int longueur_mot=longueur(mot);
	char* mot_chiffre = (char*)malloc((longueur_mot+1)*sizeof(char)); //On n'oublie pas de garder une case pour le '\0' donc longueur_mot+1
	for (int i=0;i<longueur_mot;i++)
	{
		mot_chiffre[i]=coder_lettre(mot[i],cle);
	}
	mot_chiffre[longueur_mot]='\0'; //Et on le place bien évidemment à la fin
	return mot_chiffre;
}

char * dechiffrement (char* mot, int n)
{
	int cle = (3*n)%26;
	int longueur_mot=longueur(mot);
	char* mot_dechiffre = (char*)malloc((longueur_mot+1)*sizeof(char)); //On n'oublie pas de garder une case pour le '\0' donc longueur_mot+1
	for (int i=0;i<longueur_mot;i++)
	{
		mot_dechiffre[i]=decoder_lettre(mot[i],cle);
	}
	mot_dechiffre[longueur_mot]='\0';//Et on le place bien évidemmment à la fin
	return mot_dechiffre;
}

char coder_lettre (char c, int cle)
{
	
	char resultat = c;
	if (est_lettre_minuscule(c)==true)
	{
		if (c+cle<='z')
		{
			resultat=(c+cle);
		}
		else
		{
			resultat='a'+(c + cle -'z' -1); //permet de replacer la lettre dans les minuscules en cas de dépacement
		}
	}
	else
	{
		if (est_lettre_majuscule(c)==true)
		{
			if (c+cle<='Z')
			{
				resultat=c+cle;
			}
			else
			{
				resultat='A'+(c + cle -'Z' - 1);//permet de replacer la lettre dans les majuscules en cas de dépacement
			}
		}
	}
	return resultat;
}

char decoder_lettre (char c, int cle)
{
	char resultat = c;
	if (est_lettre_minuscule(c)==true)
	{
		if (c-cle>='a')
		{
			resultat=c-cle;
		}
		else
		{
			resultat='z'-('a'-c + cle -1); //permet de replacer la lettre dans les minuscules en cas de dépacement
		}
	}
	else
	{
		if (est_lettre_majuscule(c)==true)
		{
			if (c-cle>='A')
			{
				resultat=c-cle;
			}
			else
			{
				resultat='Z'-('A'-c + cle -1);//permet de replacer la lettre dans les majuscules en cas de dépacement
			}
		}
	}
	return resultat;
}

bool est_fichier_txt (char * nom_fichier)
{
	int longueur_chaine=longueur(nom_fichier);
	bool resultat = true;
	if (longueur_chaine<=4)
	{
		resultat=false; //si la longueur est <=4 alors il n'y a pas la place pour"*.txt" donc ça ne peut pas être le nom d'un fichier
	}
	else
	{
		for (int i=0;resultat!=false&&i<longueur_chaine-4;i++)
		{
			if (nom_fichier[i]=='<'||nom_fichier[i]=='>'||nom_fichier[i]==':'||nom_fichier[i]=='"'||nom_fichier[i]=='/'||nom_fichier[i]=='\\'||nom_fichier[i]=='?'||nom_fichier[i]=='|'||nom_fichier[i]=='*')
			{
				resultat=false; //permet de tester s'il n'y a pas des caractères interdits dans le nom du fichier
			}
		}
		if (nom_fichier[longueur_chaine - 4]!='.' && nom_fichier[longueur_chaine - 3]!='t' && nom_fichier[longueur_chaine - 2]!='x'&&nom_fichier[longueur_chaine - 1]!='t')
		{
			resultat=false; //permet de tester si le fichier se termine bien par ".txt"
		}
	}
	return resultat;
}

char* choix_texte()
{
	int choix_methode;
	char * nom_du_fichier;
	do
	{
		printf("Veuillez selectionner le fichier texte a crypter (1 to 3): \n");
		printf(" 1 - portrait_Georges_Perec.txt\n");
		printf(" 2 - 81_fiches_Cuisine_Georges_Perec.txt\n");
		printf(" 3 - Selectionner un autre fichier\n");
		scanf("%d",&choix_methode);
	}
	while(choix_methode>3||choix_methode<1);
	if (choix_methode==1)
	{
		nom_du_fichier="portrait_Georges_Perec.txt";
	}
	if (choix_methode==2)
	{
		nom_du_fichier="81_fiches_Cuisine_Georges_Perec.txt";
	}
	if (choix_methode==3)
	{
		nom_du_fichier=saisir_fichier();
	}
	return nom_du_fichier;
}

void chiffrer_un_mot()
{
	char* mot_saisi = saisir_mot();
	int n = saisir_cle();
	char* mot_chiffre = chiffrement(mot_saisi,n);
	printf("Le mot crypte est : %s\n",mot_chiffre);
}

void dechiffrer_un_mot()
{
	char* mot_saisi = saisir_mot();
	int n = saisir_cle();
	char* mot_dechiffre = dechiffrement(mot_saisi,n);
	printf("Le mot decrypte est : %s\n",mot_dechiffre);
}

void chiffrer_un_texte()
{
	char* nom_fichier = choix_texte();
	char* nom_fichier_crypte = saisir_fichier_nouveau();
	int n = saisir_cle();
	int cle = (3*n)%26;
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
			fputc(coder_lettre(c,cle),new_fichier); //les caracteres du 1er fichier sont cryptés un par un et saisis en même temps sur le nouveau fichier
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

void dechiffrer_un_texte()
{
	char* nom_fichier =choix_texte(); 
	char* nom_fichier_decrypte = saisir_fichier_nouveau();
	int n;
	int cle;
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
		cle=(3*n)%26;
		c = fgetc ( fichier );
		while ( c != EOF ) //tant qu'on n'a pas atteind la fin du fichier
		{
			fputc(decoder_lettre(c,cle),new_fichier);//les caracteres du 1er fichier sont décryptés un par un et saisis en même temps sur le nouveau fichier
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
