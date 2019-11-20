class Object:
    
    #Constructeur et instanciation des attributs
    def __init__(self, typeObject, id, name):
        self.__type = typeObject
        self.__id = id
        self.__name = name
        self.__mass = 0

    def getType(self):
        return self.__type

    def getId(self):
        return self.__id

    def getName(self):
        return self.__name

    def getMass(self):
        if self.__type == "A":
            self.__mass = 1
            
        elif self.__type == "B":
            self.__mass = 3
            
        elif self.__type == "C":
            self.__mass = 5
        
        return self.__mass

        

    def setType(self, typeObject):
        self.__type = typeObject

    def setId(self, id):
        self.__id = id

    def setName(self, name):
        self.__name = name

# this notation is used to indicate the return type not necessary but helps while debugging
#This functio will help me while deleting from the inventory and even while deleting 
    def correspondsToDescription(self, description):
        if description == self.printObject() :
            return True
        
        return False

    def findName(self, name):
        if name == "":
            return True
        else:
            for index in range(0, len(name)):
                if name[index] != self.__name[index]:
                    return False

        return True

    def findId(self, id):
        if id == "":
            return True
        else:
            for index in range(0, len(id)):
                if id[index] != self.__id[index]:
                    return False

        return True

    def findType(self, type):
        if type == "":
            return True
        else:
            for index in range(0, len(type)):
                if type[index] != self.__type[index]:
                    return False

        return True

#je vais avoir besoin du return de cette fonction pour l'impression des objets dans le gui
    def printObject(self):
        ret = "Le nom de l'objet est " + self.__name + " son code est " + self.__id +" et son type est " + self.__type
        return ret



