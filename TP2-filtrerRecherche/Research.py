import Object
import Inventory
import time


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
        self.__researchList = []
        for item in liste:
            self.__backgroundList.append(liste[item])

        for item in liste:
            self.__researchList.append(liste[item])

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
        if name =="":
            return liste
        else:
            retList = []
            for obj in liste:
                if obj.findName(name):
                    retList.append(obj)

            return retList

    # Recherche dans la liste d'objet de un identifiant
    def researchById(self, id, liste):
        if id =="":
            return liste
        else:
            retList = []
            for obj in liste:
                # A faire dans object
                if obj.findId(id):
                    retList.append(obj)

            return retList

    # Recherche dans la liste d'objet de type  un type d'objet
    def researchByType(self, typeObj, liste):
        if typeObj == "":
            return liste
        else:
            retList = []
            for obj in liste:
                # A faire dans object
                if obj.findType(typeObj):
                    retList.append(obj)

            return retList

    def research(self, name, id, type):
        startTime = time.time()
        # reseach global appelle les trois
        self.__researchList = self.researchByName(name, self.__backgroundList)
        self.__researchList = self.researchById(id, self.__researchList)
        self.__researchList = self.researchByType(type, self.__researchList)
        elapsedTime = time.time() - startTime
        print("La recherche est terminee. Le temps necessaire pour faire la recherche est " + str(elapsedTime)+" secondes")




#liste = Inventory.Inventory()
#liste.fillInventory("inventaire.txt")
#search = Research(liste.getInventoryList())
#search.research("", "","")
#for item in search.getList():
#   print(item.printObject())


#print(search.getCount())
