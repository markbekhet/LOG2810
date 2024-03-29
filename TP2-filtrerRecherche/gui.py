# Auteurs:
# Cécile Hornecker 1783304
# Marjorie Pomerleau 1959041
# Mark Bekhet 1949264

import tkinter as tk
from tkinter import filedialog
from tkinter import Canvas
import Inventory
import Object
import Cart
import Research
import time
from tkinter import ttk
import time
#this is supposed to be the search items from a search
#right now that's a temporary test until the search class is done

# this is the items from the cart
#cartItems = []
#itemsSearch = ["Var" , "option","kadkancaskcdsac","kadkancaskcdsac","kadkancaskcdsac","kadkancaskcdsac"\
#        ,"kadkancaskcdsac","kadkancaskcdsac","kadkancaskcdsac","kadkancaskcdsac","kadkancaskcdsacscsaV sV  zXZC zxv xzc xasxavshnABDNBbadnxxasadxajBJAbdjanxaNXmBxmxMZXsacksahC jasBcjszjNBxjabxjbajZBmjxz","kadkancaskcdsac",\
#            "kadkancaskcdsac","kadkancaskcdsac","kadkancaskcdsac","kadkancaskcdsac","kadkancaskcdsac","kadkancaskcdsac","kadkancaskcdsac","kadkancaskcdsac"\
#                ,"Le nom de l'objet est divan son code est B421AC et son type est A","Le nom de l'objet est divan son code est B421AC et son type est A","kadkancaskcdsacscsaV sV  zXZC zxv xzc xasxavshnABDNBbadnxxasadxajBJAbdjanxaNXmBxmxMZXsacksahC jasBcjszjNBxjabxjbajZBmjxz","kadkancaskcdsacscsaV sV  zXZC zxv xzc xasxavshnABDNBbadnxxasadxajBJAbdjanxaNXmBxmxMZXsacksahC jasBcjszjNBxjabxjbajZBmjxz","kadkancaskcdsacscsaV sV  zXZC zxv xzc xasxavshnABDNBbadnxxasadxajBJAbdjanxaNXmBxmxMZXsacksahC jasBcjszjNBxjabxjbajZBmjxz","kadkancaskcdsacscsaV sV  zXZC zxv xzc xasxavshnABDNBbadnxxasadxajBJAbdjanxaNXmBxmxMZXsacksahC jasBcjszjNBxjabxjbajZBmjxz","kadkancaskcdsacscsaV sV  zXZC zxv xzc xasxavshnABDNBbadnxxasadxajBJAbdjanxaNXmBxmxMZXsacksahC jasBcjszjNBxjabxjbajZBmjxz","kadkancaskcdsacscsaV sV  zXZC zxv xzc xasxavshnABDNBbadnxxasadxajBJAbdjanxaNXmBxmxMZXsacksahC jasBcjszjNBxjabxjbajZBmjxz","kadkancaskcdsacscsaV sV  zXZC zxv xzc xasxavshnABDNBbadnxxasadxajBJAbdjanxaNXmBxmxMZXsacksahC jasBcjszjNBxjabxjbajZBmjxz"\
#                ,"kadkancaskcdsac","kadkancaskcdsac","kadkancaskcdsac","kadkancaskcdsac","kadkancaskcdsac","kadkancaskcdsac","kadkancaskcdsac","kadkancaskcdsac","kadkancaskcdsac","kadkancaskcdsac","kadkancaskcdsac","kadkancaskcdsac","kadkancaskcdsac","kadkancaskcdsac","kadkancaskcdsac","kadkancaskcdsac","kadkancaskcdsac",]
#this is supposed to be the inventory items


pressed = False
def NewFile():
    print("New File!")

def About():
    print("This is a simple example of a menu")

#the array in the parameters corresponds to an array of Object which is the most probable return in the arrays of the Research and the array of the Cart
#i will need a function to delete an Object from the array of Reasearch and another one to delete an Object from the Cart 
def gettingObjectCorrespondingFromList(array, objecctDescription):
    for item in array:
        if item.correspondsToDescription(objecctDescription):
            return item


        
def gettingElementFromList(array, itemDescription):
    for item in array:
        if str(item)+"\n" ==itemDescription:
            return item
        

# In this class :
# a -  attributes:
#   1 - self : the main window
#   2 - generalFrame : the general body has self as a parent
#   3 - inventorySection: the inventory view which has the generalFrame as a parent
#   4 - searchViewFrame: the search view which has the generalFrame as a parent
#   5 - frameInput: the input frame has the searchViewFrame as a parent 
#   
#   6 - entryName: the entry for the name entry has the frameName as a parent which has the frameInput as parent
#   
#   
#   7 - entryCodeBar: the entry for the code bar entry has the frameCodeBar as a parent which has the frameInput as parent
#   
#   8 - entryType: the entry for the type entry has the frameType as a parent which has the frameInput as parent
#   
#   9 - cartButtons: the buttons for the cart to allow the possibility of a return stock
#   10 - searchButtons: the buttons for the search box
#   11 - searchResultFrame: it has the searchViewFrame as a parent
#   12 - textBox: a text box which contains all the search result items. it has the searchResultFrame as a parent
#   13 - cartFrame: it has the generalView as a parent
#   14 - cartBox: a text box which contains all the items in the cart. It has the cartFrame as a parent
#   15-  inventoryTextBox: a text box which parent is inventorySection
# 
# 
# b - methodes : overall description
#   I - Controlers
#       1- onButtonEntryName(): this method gets the string which is entered in the text box . It must call the search method for the search by name
#           and call the print_search_items function
#       2- onButtonEntryType(): this method gets the string which is entered in the text box . It must call the search method for the search by type
#           and call the print_search_items function
#       3- onButtonEntryCode(): this method gets the string which is entered in the text box . It must call the search method for the search by code
#           and call the print_search_items function
#       TODO
#       4 - confirmCommand(): this method calls the function to confirm the command and i will do it to delete the elements from the inventory
#       5 - onClickToAddToCart(): it should delete the specified item from the "searchList" and add it in the "CartList"
#       6 - onClickToRemoveFromCart(): it should delete the specified item from the "cartList" and add it in the "searchList"
#  
#    II - View
#       1 - printSearchResult(): creates the buttons for the search that are placed in the text box
#       2 - printCartItems(): creates the buttons for the items in the cart
#       3- buildNameFrame()
#       4- buildCodeFrame()
#       5- buildTypeFrame()
#       6- buildMenu()
#       7- buildResultSearchSecton()
#       8- buildCartSection()
#       9- searchView()
#       10- inventoryView()
#       11- openFile()
#       12- quit()
# 
#


class GUI(tk.Tk):
    def __init__(self):
        tk.Tk.__init__(self, screenName = "Inventaire", className="Inventaire")
        #self.attributes("-fullscreen", True)
        self.geometry("1000x1000")
        self.buildMenu()
        #this frame is for the Input frame in general
        self.__generalFrame = tk.Frame(self)
        self.__generalFrame.grid()
        self.__inventorySection = tk.Frame(self.__generalFrame)
        self.__searchViewFrame = tk.Frame(self.__generalFrame)
        self.__cartFrame = tk.Frame(self.__generalFrame)
        
        self.__cartButtons = []
        self.__inventory = Inventory.Inventory()

        self.__inventoryTextBox = tk.Text(self.__inventorySection)
        self.__cart = Cart.Cart()
        self.__search = Research.Research()

        self.__searchResultFrame = tk.Frame(self.__searchViewFrame)
        self.__searchResultBox = tk.Listbox(self.__searchResultFrame, width = 100,height = 30)
        self.__cartBox = tk.Listbox(self.__cartFrame,width = 100, height = 30)
        self.__searchButtons = []
        self.__selectedView = ""



    # those three functions are for the connectors between the graphic interface and the classes of the model


    def onButtonGet(self):


        self.__search.research(self.__entryName.get(), self.__entryCode.get(), self.__entryType.get())
        self.printSearchResult(self.__search.getList())





    def printSearchResult(self,DataList):
        startTime = time.time()
        self.__searchResultBox.delete(0,tk.END)

        number = 0
        for item in DataList:
            if number<10:
                #button = tk.Button(self.__searchResultBox, text = item.printObject())
                #self.__searchButtons.append(button)
                self.__searchResultBox.insert(tk.END, item.printObject())
                #self.__searchResultBox.window_create(self.__searchResultBox.index("end"),window = tk.Label(self.__searchResultBox, text = "\n"))
                self.__searchResultBox.bind('<<ListboxSelect>>',self.onClickOptionToAddToCart)
                self.__searchResultBox.insert(tk.END,"\n")
                #self.__searchResultBox.insert(tk.END, "\n")
                #button['command'] = lambda idx=item: self.onClickOptionToAddToCart(idx)
                #button.place(y = number*height , height=height)
                number +=1

            else:
                break

        
        searchCount = tk.Label(self.__searchViewFrame, text = "Le nombre d'items possibles résultantes de votre recherche est " + str(self.__search.getCount()))
        searchCount.grid(row = 5, column = 0)
        elspsedTime = time.time()-startTime
        print("La creation des bouttons est terminee pour la recherche. Le temps pris est de " + str(elspsedTime)+" secondes") 
            
    def printCartItems(self,DataList):
        startTime = time.time()
        number = 0
        self.__cartBox.delete(0,tk.END)
        
        for item in DataList:
    
            height = 20
            #the problem is mainly here i am writing a text on the  button but it is solved because i did a function to return the object from the list corresponding to the description
            #button = tk.Button(self.__cartBox, text = item.printObject())
            #self.__cartButtons.append(button)
            self.__cartBox.insert( tk.END, item.printObject())
            self.__cartBox.bind('<<ListboxSelect>>',self.onClickOptionToRemoveFromCart)
            self.__cartBox.insert(tk.END,"\n")
            # here the function will be called
            #button['command'] = lambda idx=item: self.onClickOptionToRemoveFromCart(idx)
            #button.place(y = number*height , height=height)
            number +=1

        

        elspsedTime = time.time() - startTime
        print("La creation des bouttons pour le panier est terminee. Le temps pris est de " + str(elspsedTime) + " secondes")

        

            
            
    #I want to make the same action in both directions
    # I have to manually destroy this button and manipulate the two lists        
    #handling events   
    def onClickOptionToAddToCart(self,evt):
        '''  set the double click status flag
        '''
        #for button in self.__searchButtons:

         #   button.destroy()
        w = evt.widget
        if len(w.curselection()) != 0:
            startTime = time.time()
            index = int(w.curselection()[0])
            value = w.get(index)
            valueInArray = gettingObjectCorrespondingFromList(self.__search.getList(),value)
            self.__cart.addInCart(valueInArray)
            startTime = time.time()
            self.__search.deleteObject(valueInArray)
            print("Le temps pris pour enlever un element de la liste de la recherche est " + str(time.time()-startTime))
        #self.printCartItems(self.__cart.getObjectList())
        self.printSearchResult(self.__search.getList())
        
    
    def onConfirmButton(self):
    
        
        for objectItem in self.__cart.getObjectList():
            #self.__cart.deleteFromCart(objectItem)
            self.__inventory.deleteFromInventoryObject(objectItem)
            
        self.__cart = Cart.Cart()

        self.__search = Research.Research(self.__inventory.getInventoryList())
        #self.printInventorySection(self.__inventory.getInventoryList())
        self.buildCartItems()


    def onResetButton(self):
        self.__search= Research.Research(self.__inventory.getInventoryList())
            
        self.__cart = Cart.Cart()
        self.buildCartItems() 


    def onClickOptionToRemoveFromCart(self,evt):
        '''  set the double click status flag
        '''
        #for button in self.__cartButtons:
        #    button.destroy()
        
        # TODO latter
        # cartItems will not be replaced only itemsSearch will be replaced by the search list
        #this will be an Object type so in the Cart class I need to put a function which removes
        w = evt.widget
        if len(w.curselection())!= 0:
            index = int(w.curselection()[0])
            value = w.get(index)
            valueInArray = gettingObjectCorrespondingFromList(self.__cart.getObjectList(),value) 
            self.__cart.deleteFromCart(valueInArray)
            self.__search.addObject(valueInArray)
        #self.printSearchResult(self.__search.getList())
        self.buildCartItems()
            

    def openFile(self):
        name = filedialog.askopenfilename()
        self.__inventory.fillInventory(name)
        self.__search = Research.Research(self.__inventory.getInventoryList())
        if self.__selectedView == "Inventory":
            self.printInventorySection(self.__inventory.getInventoryList())
        
        elif self.__selectedView == "Search":
        #self.__search.research("","","")
            self.printSearchResult(self.__search.getList())

        print("Vous pouvez commencer a faire vos recherches ")
    
    def buildMenu(self):
        menu = tk.Menu(self)
        self.config(menu=menu)
        filemenu = tk.Menu(menu)
        menu.add_cascade(label="Fichier", menu=filemenu)
        filemenu.add_command(label="Nouveau", command=NewFile)
        filemenu.add_command(label="Ouvrir", command=self.openFile)
        filemenu.add_separator()
        filemenu.add_command(label="Quitter", command=self.quit)
        helpmenu = tk.Menu(menu)
        menu.add_cascade(label="Aide", menu=helpmenu)
        helpmenu.add_command(label="À propos", command=About)

        searchMenu =tk.Menu(menu)
        
        menu.add_command(label = "Vue panier" , command = self.buildCartSection)
        menu.add_command(label = "Vue recherche" , command = self.searchView)
        

        inventoryMenu = menu.add_cascade(label = "Vue inventaire", command = self.inventoryView)
    
    
    # This block is for the entry of the name of the product
    #  First i will do a name frame and insert the rest of the elements of this section in it
    def buildNameFrame(self):
        frameName = tk.Frame(self.__frameInput)
        frameName.grid(row = 0, column = 0,ipadx = 15)
        labelName = tk.Label(frameName, text="Entrer le nom du produit")
        labelName.grid(row =0, column = 0)
        self.__entryName = tk.Entry(frameName)
        self.__entryName.grid(row = 0, column = 1)
        #buttonName = tk.Button(frameName, text="Get", command=self.onButtonEntryName)
        #buttonName.grid(row = 0, column =2)

    # This block is for the entry of the code bar I will do the same as the last one
    def buildCodeFrame(self):
        frameCodeBar = tk.Frame(self.__frameInput)
        frameCodeBar.grid(row = 0, column = 1 ,ipadx =15)
        labelCodeBar = tk.Label(frameCodeBar, text="Entrer le code bar du produit")
        labelCodeBar.grid(row =0, column = 0)
        self.__entryCode = tk.Entry(frameCodeBar)
        self.__entryCode.grid(row = 0, column = 1)
        #buttonCode = tk.Button(frameCodeBar, text="Get", command=self.onButtonEntryCode)
        #buttonCode.grid(row = 0, column =2)

    def buildTypeFrame(self):
        frameType = tk.Frame(self.__frameInput)
        frameType.grid(row = 0, column =2, ipadx=15)
        labelType = tk.Label(frameType, text="Entrer le type du produit")
        labelType.grid(row =0, column = 0)
        self.__entryType = tk.Entry(frameType)
        self.__entryType.grid(row = 0, column = 1)
        #buttonType = tk.Button(frameType, text="Get", command=self.onButtonEntryType)
        #buttonType.grid(row = 0, column =2)

    def buildResultSearchSection(self):
        #This is the text box resulting from the search

        self.__searchResultFrame.grid(row = 1, column =0, ipady = 20, ipadx = 0)
        labelSearch = tk.Label(self.__searchResultFrame,text="Les résultats de la recherche ")
        labelSearch.grid(row = 0, column = 0)
        scrollbV = ttk.Scrollbar(self.__searchViewFrame)
        scrollbH = ttk.Scrollbar(self.__searchViewFrame)
        

        self.__searchResultBox.grid(row = 1,column = 0,columnspan =10)

        scrollbV.grid(row = 1, column = 1,sticky='nsew')
        scrollbH.grid(row = 2, column = 0,sticky='nsew')
        self.__searchResultBox["yscrollcommand"] = scrollbV.set
        self.__searchResultBox["xscrollcommand"] = scrollbH.set
        scrollbV.config(command=self.__searchResultBox.yview)
        scrollbH.config(command=self.__searchResultBox.xview)
        


    def buildCartSection(self):
         self.__inventorySection.grid_forget()
         self.__searchViewFrame.grid_forget()
         self.__selectedView = "Cart"
         #self.__search.research("","","")

         self.__cartFrame.grid(row = 2, column = 0,  ipady = 0)
         labelCart = tk.Label(self.__cartFrame, text ="Le panier")
         labelCart.grid(row = 0, column = 0,ipady = 15)
         
         scrollbV = ttk.Scrollbar(self.__cartFrame)
         scrollbH = ttk.Scrollbar(self.__cartFrame)
         

         self.__cartBox.grid(row = 1, column = 0,padx = 15)

         scrollbV.grid(row = 1, column = 1,sticky='nsew')
         scrollbH.grid(row = 2, column = 0,sticky='nsew')
         self.__cartBox["yscrollcommand"] = scrollbV.set
         self.__cartBox["xscrollcommand"] = scrollbH.set
         scrollbV.config(command=self.__cartBox.yview)
         scrollbH.config(command=self.__cartBox.xview)
         self.buildCartItems()
         
         

    def buildCartItems(self):
        self.printCartItems(self.__cart.getObjectList())
        if self.__cart.getTotalMass()> 25 :
            label = tk.Label(self.__cartFrame,text = "Votre commande est trop lourde. Veuillez choisir autre elements")
            label.grid(row = 3, column = 0)
        else:
            #label.grid_forget()
            button = tk.Button(self.__cartFrame,text ="Confirmer",command = self.onConfirmButton)
            button.grid(row = 3 , column = 0)
            

        cancelButton = tk.Button(self.__cartFrame,text = "Annuler", command = self.onResetButton)
        cancelButton.grid(row = 4, column = 0)


        


    def searchView(self):
        self.buildCartSection()
        self.buildCartSection()
        self.__inventorySection.grid_forget()
        self.__cartFrame.grid_forget()
        self.__selectedView = "Search"

        self.__searchViewFrame.grid(row = 0, column = 0)
        self.__frameInput = tk.Frame(self.__searchViewFrame)
        self.__frameInput.grid(row = 0, column = 0)
        
        self.buildNameFrame()
        self.buildCodeFrame()
        # This block is for the entry of the type
        self.buildTypeFrame()
        getButton = tk.Button(self.__frameInput, text="Get", command=self.onButtonGet)
        getButton.grid(row = 0, column =3,ipadx = 15)
        self.buildResultSearchSection()
        self.__search.research("","","")
                
        self.printSearchResult(self.__search.getList())
        
        

    def inventoryView(self):
        self.__searchViewFrame.grid_forget()
        self.__cartFrame.grid_forget()
        self.__selectedView = "Inventory"
        self.__inventorySection.grid(row = 0, column =1, padx = 20)
        scrollbV = ttk.Scrollbar(self.__inventorySection)
        scrollbH = ttk.Scrollbar(self.__inventorySection)
        # This is the label of the inventory
        inventoryLabel= tk.Label(self.__inventorySection, text = "Bienvenue a l'entrepôt \n L'entrepôt contient les éléments suivants")
        inventoryLabel.grid(row = 0, column = 0 , ipadx= 20)
        scrollbV.grid(row=1, column=1, sticky='nsew')
        scrollbH.grid(row=2, column=0, sticky='nsew')
        self.__inventoryTextBox["yscrollcommand"] = scrollbV.set
        self.__inventoryTextBox["xscrollcommand"] = scrollbH.set

        scrollbV.config(command=self.__inventoryTextBox.yview)
        scrollbH.config(command=self.__inventoryTextBox.xview)

        self.__inventoryTextBox.grid(row = 1, column = 0, ipadx= 20,ipady = 20)
        self.printInventorySection(self.__inventory.getInventoryList())

    def printInventorySection(self,dataList):
        startTime = time.time()
        self.__inventoryTextBox.delete("1.0",tk.END)
        number = 0 
        for item in dataList:
            
            self.__inventoryTextBox.insert(tk.END, self.__inventory.getInventoryList()[item].printObject() + "\n")
            
            number +=1

            
        elapsedTime =time.time() - startTime
        print("Le temps pris pour imprimer tous les elements de l'inventaire est " + str(elapsedTime) + " s \n")



