#ifndef INTERPRETEUR_H
#define INTERPRETEUR_H


class Interpreteur
{
public:
    Interpreteur();
};
// Dans cette classe, on met la map contenant tous les noms des operateurs -> fait une map de map pour avoir une "separation"
// entre les differents types d'operateurs (operateurs de pile etc.)
//Cette classe permet d'executer la commande associée a la commande "trouvée" apres avoir fait tourner les regex.
// On peut faire une map pour stocker les =/= regex et les faire tourner successivement sur les entées lues et entées par l'utilisateur

#endif // INTERPRETEUR_H
