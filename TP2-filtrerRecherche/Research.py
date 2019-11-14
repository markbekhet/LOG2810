import Object
import Cart

class Research:

    def __init__(self):

        #Créer un attribut Invertaire qui est une liste d'objet
        self._inventory = Inventory()

        #Copy la liste d'inventaire dans un autre attribut
        self._objectList = inventory.getObjectList()

        #Instancie le un panier vide
        self._cart = Cart()

    # Recherche dans la liste objet un nom
    def researchByName(self, name):
        for object in self._objectList:
            if object.getName() != name:
                #Retire tout les elements de la liste qui ne possède pas le bon nom
                self._objectList.remove(object)

    # Recherche dans la liste objet un identifiant
    def researchById(self, id):
        for object in self._objectList:
            if object.getId() != id:
                # Recherche dans la liste objet un identifiant
                self._objectList.remove(object)

    # Recherche dans la liste objet un type
    def researchByType(self, type):
        for object in self._objectList:
            if object.getType() != type:
                #Recherche dans la liste objet un type
                self._objectList.remove(object)

    # Affiche la list d'objet qui correspond au recherche
    def printResearch(self):
        for object in self._objectList:
            object.printObject()

    #Ajoute la commande au panier et supprime les objets correspondant dans l'inventaire
    def confirmCommand(self):
        self._cart.addInCart(self._objectList)
        inventary.deleteObject(self._objectList)

    #Supprime les objets du panier et les ajoute dans l'inventaire
    def deleteCommand(self):
        self._cart.deleteInCart(self._objectList)
        inventary.addObject(self._objectList)



