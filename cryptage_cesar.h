#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/*
 * Fonction qui permet de demander à l'utilisateur de saisir un mot
 * Retour : accès (à la zone mémoire) du mot crée
 */
char * saisir_mot ();

/*
 * Fonction qui permet de demander à l'utilisateur de saisir le n choisi pour la clé
 * Retour : n correspondant à la clé voulu
 */
int saisir_cle ();

/*
 * Fonction qui permet de demander à l'utilisateur de saisir le nom d'un fichier
 * Retour : accès (à la zone mémoire) du nom du fichier
 */
char * saisir_fichier();

/*
 * Fonction qui permet de demander à l'utilisateur de saisir le nom d'un nouveau fichier
 * Retour : accès (à la zone mémoire) du nom du nouveau fichier
 */
char * saisir_fichier_nouveau();

/*
 * Fonction qui permet renvoyer la longueur du mot rentré en paramètre
 * Parametre chaine : mot mesuré
 * Retour : la longueur de ce mot
 */
unsigned int longueur(const char * chaine);

/*
 * Fonction qui permet de tester si le caractere est en minuscule
 * Parametre caractere : caractere évalué
 * Retour : true si le caractere est en minuscule sinon false
 */
bool est_lettre_minuscule (char caractere);

/*
 * Fonction qui permet de tester si le caractere est en majuscule
 * Parametre caractere : caractere évalué
 * Retour : true si le caractere est en majuscule sinon false
 */
bool est_lettre_majuscule (char caractere);

/*
 * Fonction qui permet de crypter un mot selon Cesar
 * Parametre mot : mot à crypter
 * Parametre n : correspond au n utilisé dans la cle
 * Retour : l'accès mémoire du mot crypté selon Cesar
 */
char * chiffrement (char* mot, int n);

/*
 * Fonction qui permet de décrypter un mot selon Cesar
 * Parametre mot : mot à décrypter
 * Parametre n : correspond au n utilisé dans la cle
 * Retour : l'accès mémoire du mot décrypté selon Cesar
 */
char * dechiffrement (char* mot, int n);

/*
 * Fonction qui permet de crypter une lettre selon Cesar
 * Parametre c : lettre à crypter
 * Parametre cle : cle de cryptage
 * Retour : lettre crypté selon Cesar
 */
char coder_lettre (char c, int cle);

/*
 * Fonction qui permet de décrypter une lettre selon Cesar
 * Parametre c : lettre à décrypter
 * Parametre cle : cle de cryptage
 * Retour : lettre décrypté selon Cesar
 */
char decoder_lettre (char c, int cle);

/*
 * Fonction qui permet de demander à l'utilisateur le fichier qu'il souhaite utiliser
 * Retour : accès (à la zone mémoire) du nom du fichier
 */
char* choix_texte();

/*
 * Fonction qui permet de tester si la chaîne de caractere correspond bien à un fichier .txt
 * Parametre nom_fichier : chaîne de caractere évaluée
 * Retour : true si cela correspond sinon false
 */
bool est_fichier_txt (char * nom_fichier);

/*
 * Fonction qui permet de chiffrer un mot
 */
void chiffrer_un_mot();

/*
 * Fonction qui permet de déchiffrer un mot
 */
void dechiffrer_un_mot();

/*
 * Fonction qui permet de chiffrer un texte
 */
void chiffrer_un_texte();

/*
 * Fonction qui permet de déchiffrer un texte
 */
void dechiffrer_un_texte();
