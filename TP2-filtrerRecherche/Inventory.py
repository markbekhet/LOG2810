from Object import * 
import Cart

class Inventory:
    def __init__(self):
        self.__objectList = {}

    def fillInventory(self, textFile):
        file = open(textFile, "r")
        for line in file:
            fields = line.split(" ")
            name = fields[0]
            id = fields[1]
            typeObject = fields[2]

            objectInstance = Object(typeObject, id, name)
            self.__objectList[objectInstance.getId()] = objectInstance
        file.close()

    def getInventoryList(self):
        return self.__objectList

    def deleteFromInventoryObject(self, objectToDelete):
        del self.__objectList[objectToDelete.getId()]

#inventory = Inventory()
#inventory.fillInventory("inventaire.txt")
#for item in inventory.getInventoryList():
#    print(inventory.getInventoryList()[item].printObject())



#object1 = Object("A", "5", "Allo")

#print(object1.printObject())
#print()
#print("L'affichage apres elimination")
#print()
#Ok Donc cela va etre regle automatiquement la fonction marche
#objectToRemove = Object("A\n","B16A49","avion")
#inventory.deleteFromInventoryObject(objectToRemove)
#for item in inventory.getInventoryList():
#    print(inventory.getInventoryList()[item].printObject())



