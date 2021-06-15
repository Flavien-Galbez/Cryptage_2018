
/*
 * Fonction qui permet à l'utilisateur l'autre méthode de cryptage
 */
void autre_methode();

/*
 * Fonction qui permet de crypter une lettre selon l'autre méthode de cryptage
 * Parametre c : lettre à crypter
 * Parametre n : cle de cryptage
 * Retour : lettre crypté selon l'autre méthode de cryptage
 */
char coder_lettre_alternatif (char c, int n);

/*
 * Fonction qui permet de décrypter une lettre selon l'autre méthode de cryptage
 * Parametre c : lettre à décrypter
 * Parametre n : cle de cryptage
 * Retour : lettre décrypté selon l'autre méthode de cryptage
 */
char decoder_lettre_alternatif (char c, int n);

/*
 * Fonction qui permet de crypter un mot selon l'autre méthode de cryptage
 * Parametre mot : mot à crypter
 * Parametre n : cle de cryptage
 * Retour : l'accès mémoire du mot crypté selon l'autre méthode de cryptage
 */
char * chiffrement_alternatif (char* mot, int n);

/*
 * Fonction qui permet de décrypter un mot selon l'autre méthode de cryptage
 * Parametre mot : mot à décrypter
 * Parametre n : cle de cryptage
 * Retour : l'accès mémoire du mot décrypté selon l'autre méthode de cryptage
 */
char * dechiffrement_alternatif (char* mot, int n);

/*
 * Fonction qui permet de crypter un mot selon l'autre méthode de cryptage
 */
void chiffrer_un_mot_alternatif();

/*
 * Fonction qui permet de décrypter un mot selon l'autre méthode de cryptage
 */
void dechiffrer_un_mot_alternatif();

/*
 * Fonction qui permet de crypter un texte selon l'autre méthode de cryptage
 */
void chiffrer_un_texte_alternatif();

/*
 * Fonction qui permet de décrypter un texte selon l'autre méthode de cryptage
 */
void dechiffrer_un_texte_alternatif();


