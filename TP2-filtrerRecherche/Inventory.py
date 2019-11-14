import Object
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
            type = fields[2]
            object = Object.Object(type, id, name)
            self._objectList.append(object)
        file.close()


inventory = Inventory()
inventory.fillInventory("inventaire.txt")
print(inventory._objectList)
object1 = Object("A", 5, "Allo")

print(object1)


