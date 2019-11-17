class Object:
    global DEFAULTMASS
    DEFAULTMASS = 20
    #Constructeur et instanciation des attributs
    def __init__(self, typeObject, id, name):
        self.__type = typeObject
        self.__id = id
        self.__name = name
        self.__mass = DEFAULTMASS

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
        else:
            raise Exception("Type invalide")

        return self.__mass

    def setType(self, typeObject):
        self.__type = typeObject

    def setId(self, id):
        self.__id = id

    def setName(self, name):
        self.__name = name

# this notation is used to indicate the return type not necessary but helps while debugging
#This functio will help me while deleting from the inventory and even while deleting 
    def correspondsToDescription(self, description)->bool:
        if description == self.printObject() :
            return True
        
        return False

     
    


#je vais avoir besoin du return de cette fonction pour l'impression des objets dans le gui
    def printObject(self):
        ret = "Le nom de l'objet est " + self.__name + " son code est " + self.__id +" et son type est " + self.__type
        return ret



