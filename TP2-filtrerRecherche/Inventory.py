from Object import * 
import Cart
#delete liste objects, get, add
class Inventory:
    def __init__(self):
        self._objectList = []
        

    def fillInventory(self, textFile):
        file = open(textFile, "r")
        for line in file:
            fields = line.split(" ")
            name = fields[0]
            id = fields[1]
            typeObject = fields[2]

            objectInstance = Object(typeObject, id, name)
            self._objectList.append(objectInstance)
        file.close()


    def getIndexDependingOnDescription(self, description):
        index = 0
        
        for items in self._objectList:
            if items.correspondsToDescription(description):
                return index

            index += 1

        raise "cet element ne se trouve pas dans l'inventaire"


    def deleteFromInventory(self,description):
        try:
            index = self.getIndexDependingOnDescription(description)
            self._objectList.remove(self._objectList[index])
        except:
            return False



inventory = Inventory()
inventory.fillInventory("inventaire.txt")
for item in inventory._objectList:
    print(item.printObject())
    


#object1 = Object("A", "5", "Allo")

#print(object1.printObject())
print()
print("L'affichage apres elimination")
print()
#Ok Donc cela va etre regle automatiquement la fonction marche
objectToRemove = Object("A\n","B16A49","avion")
inventory.deleteFromInventory(objectToRemove.printObject())
for item in inventory._objectList:
    print(item.printObject())



