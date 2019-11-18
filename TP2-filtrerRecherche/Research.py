import Object
import Inventory

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



