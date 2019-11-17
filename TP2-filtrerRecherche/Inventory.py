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


inventory = Inventory()
inventory.fillInventory("inventaire.txt")
for item in inventory._objectList:
    item.printObject()
    #print("Object type is "+item._type + " The code of the product "+item._id + " The name of the product is "+item._name)


object1 = Object("A", 5, "Allo")

object1.printObject()


