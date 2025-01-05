#ifndef PERCEPTRON_H
#define PERCEPTRON_H

//structure Neurone
extern struct Neurone *neurone;

//initialisation
struct Neurone *initialisation(int N, int M);

//y somme pondérée des entrées moyennant les coefs
float y(struct Neurone *neurone, int j);

//z la fonction seuil
int z(struct Neurone *neurone, int M);

//apprendre la fonction de correction des coef et du biais
int apprendre(struct Neurone *neurone, float tx_apprentissage, int M);

//procedure supprimer les mallocs
void supprimer_neurone(struct Neurone *neurone);

//procedure pour remplir les tables realite[j] et X[i][j]
void tablesAvecJ(struct Neurone *neurone, int N, int j, int *masse, int *annee, int *d);

#endif