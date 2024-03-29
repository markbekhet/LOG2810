# pourquoi voulez vous initialisez le panier avec un objectList
# on a besoin de manipuler une liste seulement dans cette classe c'est-à-dire add, delete
# Auteurs:
# Cécile Hornecker 1783304
# Marjorie Pomerleau 1959041
# Mark Bekhet 1949264

class Cart:
    def __init__(self):
        self._totalMass = 0
        self._objectList = []
        self._isValid = True

    def getTotalMass(self)->int:
        self._totalMass = 0
        for objectItem in self._objectList:
            self._totalMass = int(self._totalMass) + objectItem.getMass()

        return self._totalMass

    def getObjectList(self):
        return self._objectList

    def addInCart(self, objectToAdd):
            self._objectList.append(objectToAdd)

    def deleteFromCart(self, objectToDelete):
        for objectList in self._objectList:
            if objectList.printObject() == objectToDelete.printObject():
                self._objectList.remove(objectList)

    def orderValidation(self):
        if self.getTotalMass() > 25:
            return  False
            
        elif self.getTotalMass() <= 25:
            return True




