from Object import * 
import Cart

class Inventory:
    def __init__(self):
        self.__objectList = []
        

    def fillInventory(self, textFile):
        file = open(textFile, "r")
        for line in file:
            fields = line.split(" ")
            name = fields[0]
            id = fields[1]
            typeObject = fields[2]

            objectInstance = Object(typeObject, id, name)
            self.__objectList.append(objectInstance)
        file.close()


    def getIndexDependingOnDescription(self, description):
        index = 0
        
        for items in self.__objectList:
            if items.correspondsToDescription(description):
                return index

            index += 1

        raise "cet element ne se trouve pas dans l'inventaire"

    def getInventoryList(self):
        return self.__objectList

    def deleteFromInventoryDependingOnDescription(self,description):
        try:
            index = self.getIndexDependingOnDescription(description)
            self.__objectList.remove(self.__objectList[index])
        except:
            return False

    def deleteFromInventoryObject(self, object):
        self.deleteFromInventoryDependingOnDescription(object.printObject())

#inventory = Inventory()
#inventory.fillInventory("inventaire.txt")
#for item in inventory.getInventoryList():
#    print(item.printObject())
    


#object1 = Object("A", "5", "Allo")

#print(object1.printObject())
#print()
#print("L'affichage apres elimination")
#print()
#Ok Donc cela va etre regle automatiquement la fonction marche
#objectToRemove = Object("A\n","B16A49","avion")
#inventory.deleteFromInventoryDependingOnDescription(objectToRemove.printObject())
#for item in inventory.getInventoryList():
#    print(item.printObject())



