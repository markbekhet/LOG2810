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

    # Liste d'objet
    def __init__(self, liste=[]):
        self.__backgroundList=[]
        for item in liste:
            self.__backgroundList.append(item)

        self.__researchList = liste

    # Retourne la liste d'objet
    def getList(self):
        return self.__researchList

    def getCount(self):
        return len(self.__researchList)

    # Ajoute un objet au liste
    def addObject(self, obj):
        self.__backgroundList.append(obj)
        self.__researchList.append(obj)

    # Supprime un objet au liste
    def deleteObject(self, obj):
        for objectList in self.__researchList:
            if objectList.printObject() == obj.printObject():
                self.__researchList.remove(objectList)

        for objectList in self.__backgroundList:
            if objectList.printObject() == obj.printObject():
                self.__backgroundList.remove(objectList)




    def researchByName(self, name, liste):
        retList = []
        for obj in liste:
            if obj.findName(name):
                retList.append(obj)

        return retList

    # Recherche dans la liste d'objet de un identifiant
    def researchById(self, id, liste):
        retList = []
        for obj in liste:
            # A faire dans object
            if obj.findId(id):
                retList.append(obj)

        return retList

    # Recherche dans la liste d'objet de type  un type d'objet
    def researchByType(self, type, liste):
        retList = []
        for obj in liste:
            # A faire dans object
            if obj.findType(type):
                retList.append(obj)

        return retList

    def research(self, name, id, type):
        # reseach global appelle les trois
        self.__researchList = self.researchByName(name, self.__backgroundList)
        self.__researchList = self.researchById(id, self.__researchList)
        self.__researchList = self.researchByType(type, self.__researchList)




liste = Inventory.Inventory()
liste.fillInventory("inventaire.txt")
search = Research(liste.getInventoryList())
search.research("", "","")
for item in search.getList():
   print(item.printObject())


print(search.getCount())
