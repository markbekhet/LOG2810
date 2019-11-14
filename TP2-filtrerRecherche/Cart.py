class Cart:
    DEFAULTTOTALMASS = 0
    def __init__(self, objectList):
        self._totalMass = DEFAULTTOTALMASS
        self._objectList = objectList

    def getTotalMass(self):
        for object in range(len(_objectList)):
            self._totalMass += object.getMass()

        return self._totalMass

    def getObjectList(self):
        return self._objectList

    def addInCart(self, objectList):
        for object in range(len(objectList)):
            self._objectList.append(object)

    def deleteFromCart(self, objectList):
        for object in range(len(objectList)):
            self._objectList.remove(object)



