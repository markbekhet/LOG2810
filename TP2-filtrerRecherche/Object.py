class Object:
    global DEFAULTMASS
    DEFAULTMASS = 20
    #Constructeur et instanciation des attributs
    def __init__(self, typeObject, id, name):
        self._type = typeObject
        self._id = id
        self._name = name
        self._mass = DEFAULTMASS

    def getType(self):
        return self._type

    def getId(self):
        return self._id

    def getName(self):
        return self._name

    def getMass(self):
        if self._type == "A":
            self._mass = 1
        elif self._type == "B":
            self._mass = 3
        elif self._type == "C":
            self._mass = 5
        else:
            raise Exception("Type invalide")

        return self._mass

    def setType(self, typeObject):
        self._type = typeObject

    def setId(self, id):
        self._id = id

    def setName(self, name):
        self._name = name

#je vais avoir besoin du return de cette fonction pour l'impression des objets dans le gui
    def printObject(self):
        ret = "Le nom de l'objet est " + self._name + " son code est " + self._id +" et son type est " + self._type
        return ret

#object = Object("A", 5, "Allo")
#object.printObject()
#print(object.getMass())

