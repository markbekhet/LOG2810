import Object
import Inventory
# ok je pense que dans cette classe c'est mieux d'avoir deux listes. Les deux listes s'initialisent à une liste
# passé en paramètre du constructeur
# une liste sera changé avec chaque recherche et l'autre sera inchangé
# exemple d'utilité:
# On décide de mdifier notre recherche en enlevant un caractère, dans ce cas, on a besoin de savoir l'état de la liste
# précédente. Avec une seule liste on peut pas faire cela.
# Il y aura une fonction pour get la liste qui change. La liste inchangé sera plutôt utilisé dans la recherche
# En plus j'ai besoin d'une fonction pour add et delete des éléments des deux listes
# Les fonctions de la recherche actuelle c'est mieux de le faire
class Research:

    # Recherche dans la liste d'objet de type inventaire un nom
    def researchByName(self, name, liste):
        for object in liste:
            if object.getName() != name:
                #Retire tout les elements de la liste qui ne possède pas le bon nom
                liste.remove(object)
        return liste

    # Recherche dans la liste d'objet de type inventaire un identifiant
    def researchById(self, id, liste):
        for object in liste:
            if object.getId() != id:
                # Recherche dans la liste objet un identifiant
                liste.remove(object)
        return liste

    # Recherche dans la liste d'objet de type inventaire un type d'objet
    def researchByType(self, type, liste):
        for object in liste:
            if object.getType() != type:
                #Recherche dans la liste objet un type
                liste.remove(object)
        return liste

    # Affiche la list d'objet qui correspond au recherche
   # def printResearch(self):
    #    for object in self._objectList:
    #        object.printObject()

    #Ajoute la commande au panier et supprime les objets correspondant dans l'inventaire
    #def confirmCommand(self):
     #   self._cart.addInCart(self._objectList)
      #  inventary.deleteObject(self._objectList)

    #Supprime les objets du panier et les ajoute dans l'inventaire
    #def deleteCommand(self):
     #   self._cart.deleteInCart(self._objectList)
      #  inventary.addObject(self._objectList)



