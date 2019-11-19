# pourquoi voulez vous initialisez le panier avec un objectList
# on a besoin de manipuler une liste seulement dans cette classe c'est-à-dire add, delete

class Cart:
    DEFAULTTOTALMASS = 0
    def __init__(self, objectList):
        self._totalMass = DEFAULTTOTALMASS
        self._objectList = objectList
        self._isValid = True

    def getTotalMass(self):
        for object in self._objectList:
            self._totalMass += object.getMass()

        return self._totalMass

    def getObjectList(self):
        return self._objectList

    def addInCart(self, objectToAdd):
            self._objectList.append(objectToAdd)

    def deleteFromCart(self, objectToDelete):
        for objectList in self._objectList:
            if objectList.printObject() == objectToDelete.printObject:
                self._objectList.remove(objectList)

    def orderValidation(self):
        if self._totalMass > 25:
            self._isValid = False
            raise Exception("La commande est trop lourde.")




