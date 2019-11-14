class Object:
    DEFAULTMASS = 20
    #Constructeur et instanciation des attributs
    def __init__(self, type, id, name):
        self._type = type
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
        if type == "A":
            self._mass = 1
        elif type == "B":
            self._mass = 3
        elif type == "C":
            self._mass = 5
        else:
            raise Exception("Type invalide")

        return self._mass

    def setType(self, type):
        self._type = type

    def setId(self, id):
        self._id = id

    def setName(self, name):
        self._name = name

