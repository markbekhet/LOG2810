import tkinter as tk
from tkinter import filedialog
from tkinter import Canvas

#this is supposed to be the search items from a search
#right now that's a temporary test until the search class is done
itemsSearch = ["Var" , "option"]
# this is the items from the cart
cartItems = []
#this is supposed to be the inventory items
inventoryItems =["Var" , "option"]

pressed = False
def NewFile():
    print("New File!")
def OpenFile():
    name = filedialog.askopenfilename()
    print(type(name))
def About():
    print("This is a simple example of a menu")


    
        

        

# In this class :
# a -  attributes:
#   1 - self : the main window
#   2 - generalFrame : the general body has self as a parent
#   3 - inventorySection: the inventory view which has the generalFrame as a parent
#   4 - searchViewFrame: the search view which has the generalFrame as a parent
#   5 - frameInput: the input frame has the searchViewFrame as a parent 
#   6 - labelName : the label for the name entry has the frameName as a parent which has the frameInput as parent
#   7 - entryName: the entry for the name entry has the frameName as a parent which has the frameInput as parent
#   8 - buttonName: the button for the name entry has the frameName as a parent which has the frameInput as parent
#   9 - labelCodeBar: the label for the code bar entry has the frameCodeBar as a parent which has the frameInput as parent
#   10 - entryCodeBar: the entry for the code bar entry has the frameCodeBar as a parent which has the frameInput as parent
#   11 - buttonCodeBar: the button for the code bar entry has the frameCodeBar as a parent which has the frameInput as parent
#   12 - labelType: the label for the type entry has the frameType as a parent which has the frameInput as parent
#   13 - entryType: the entry for the type entry has the frameType as a parent which has the frameInput as parent
#   14 - buttonType: the label for the type entry has the frameType as a parent which has the frameInput as parent
#   15 - CartButtons: the buttons for the cart to allow the possibility of a return stock
#   16 - SearchButtons: the buttons for the search box
#   17 - searchResultFrame: it has the searchViewFrame as a parent
#   18 - textBox: a text box which contains all the search result items. it has the searchResultFrame as a parent
#   19 - cartFrame: it has the generalView as a parent
#   20 - cartBox: a text box which contains all the items in the cart. It has the cartFrame as a parent
# 
# 
# 
# b - methodes : overall description
#   I - Controlers
#       1- on_button_entryName(): this method gets the string which is entered in the text box . It must call the search method for the search by name
#           and call the print_search_items function
#       2- on_button_entryType(): this method gets the string which is entered in the text box . It must call the search method for the search by type
#           and call the print_search_items function
#       3- on_button_entryCode(): this method gets the string which is entered in the text box . It must call the search method for the search by code
#           and call the print_search_items function
#       TODO
#       4 - confirmCommand(): this method calls the function to confirm the command and i will do it to delete the elements from the inventory
#       5 - onClickToAddToCart(): it should delete the specified item from the "searchList" and add it in the "CartList"
#       6 - onClickToRemoveFromCart(): it should delete the specified item from the "cartList" and add it in the "searchList"
#  
#    II - View
#       1 - print_search_result(): creates the buttons for the search that are placed in the text box
#       2 - print_cart_items(): creates the buttons for the items in the cart
#       3- buildNameFrame()
#       4- buildCodeFrame()
#       5- buildTypeFrame()
#       6- buildMenu()
#       7- buildResultSearchSecton()
#       8- buildCartSection()
#       9- searchView()
#       10 inventoryView()
# 
#


class GUI(tk.Tk):
    def __init__(self):
        tk.Tk.__init__(self, screenName = "Ineventaire", className="Inventaire")
        self.attributes("-fullscreen", True)
        self.buildMenu()
        #this frame is for the Input frame in general
        self.generalFrame = tk.Frame(self)
        self.generalFrame.grid()
        self.inventorySection = tk.Frame(self.generalFrame)
        self.searchViewFrame = tk.Frame(self.generalFrame)
        self.cartFrame = tk.Frame(self.generalFrame)
        self.cartBox = tk.Text(self.cartFrame)
        self.CartButtons = []
        
        



    # those three functions are for the connectors between the graphic interface and the classes of the model
    def on_button_entryName(self):
        print(self.entryName.get())

    def on_button_entryCode(self):
        print(self.entryCode.get())

    def on_button_entryType(self):
        print(self.entryType.get())

    def print_search_result(self,DataList):
        number = 0
        for item in DataList:
            height = 50
            button = tk.Button(self.textBox, text = str(item))
            self.SearchButtons.append(button)
            button['command'] = lambda idx=str(item): self.onClickOptionToAddToCart(idx)
            button.place(y = number*height , height=height, width = 200)
            number +=1
            
    def print_cart_items(self,DataList):
        number = 0
        for item in DataList:
            height = 50
            button = tk.Button(self.cartBox, text = str(item))
            self.CartButtons.append(button)
            button['command'] = lambda idx=str(item): self.onClickOptionToRemoveFromCart(idx)
            button.place(y = number*height , height=height, width = 200)
            number +=1
            
        

            
            
    #I want to make the same action in both directions
    # I have to manually destroy this button and manipulate the two lists        
    #handling events   
    def onClickOptionToAddToCart(self,idx):
        '''  set the double click status flag
        '''
        for button in self.SearchButtons:
            button.destroy()

        cartItems.append(idx)
        itemsSearch.remove(idx)
        self.print_cart_items(cartItems)
        self.print_search_result(itemsSearch)
        


    def onClickOptionToRemoveFromCart(self,idx):
        '''  set the double click status flag
        '''
        for button in self.CartButtons:
            button.destroy()
        
        # TODO latter
        # cartItems will not be replaced only itemsSearch will be replaced by the search list
        cartItems.remove(idx)
        itemsSearch.append(idx)
        self.print_search_result(itemsSearch)
        self.print_cart_items(cartItems)
               
            
    
    def buildMenu(self):
        menu = tk.Menu(self)
        self.config(menu=menu)
        filemenu = tk.Menu(menu)
        menu.add_cascade(label="Fichier", menu=filemenu)
        filemenu.add_command(label="Nouveau", command=NewFile)
        filemenu.add_command(label="Ouvrir", command=OpenFile)
        filemenu.add_separator()
        filemenu.add_command(label="Quitter", command=self.quit)
        helpmenu = tk.Menu(menu)
        menu.add_cascade(label="Aide", menu=helpmenu)
        helpmenu.add_command(label="A propos", command=About)

        searchMenu =tk.Menu(menu)
        
        menu.add_command(label = "vue panier" , command = self.buildCartSection)
        menu.add_command(label = "vue recherche" , command = self.searchView)
        
        
        inventoryMenu = menu.add_cascade(label = "Vue inventaire", command = self.inventoryView)
    
    
    # This block is for the entry of the name of the product
    #  First i will do a name frame and insert the rest of the elements of this section in it
    def buildNameFrame(self):
        frameName = tk.Frame(self.frameInput)
        frameName.grid(row = 0, column = 0,ipadx = 15)
        self.labelName = tk.Label(frameName, text="Entrer le nom du produit")
        self.labelName.grid(row =0, column = 0)
        self.entryName = tk.Entry(frameName)
        self.entryName.grid(row = 0, column = 1)
        self.buttonName = tk.Button(frameName, text="Get", command=self.on_button_entryName)
        self.buttonName.grid(row = 0, column =2)

    # This block is for the entry of the code bar I will do the same as the last one
    def buildCodeFrame(self):
        frameCodeBar = tk.Frame(self.frameInput)
        frameCodeBar.grid(row = 0, column = 1 ,ipadx =15)
        self.labelCodeBar = tk.Label(frameCodeBar, text="Entrer le code bar du produit")
        self.labelCodeBar.grid(row =0, column = 0)
        self.entryCode = tk.Entry(frameCodeBar)
        self.entryCode.grid(row = 0, column = 1)
        self.buttonCode = tk.Button(frameCodeBar, text="Get", command=self.on_button_entryCode)
        self.buttonCode.grid(row = 0, column =2)

    def buildTypeFrame(self):
        frameType = tk.Frame(self.frameInput)
        frameType.grid(row = 0, column =2, ipadx=15)
        self.labelType = tk.Label(frameType, text="Entrer le type du produit")
        self.labelType.grid(row =0, column = 0)
        self.entryType = tk.Entry(frameType)
        self.entryType.grid(row = 0, column = 1)
        self.buttonType = tk.Button(frameType, text="Get", command=self.on_button_entryType)
        self.buttonType.grid(row = 0, column =2)

    def buildResultSearchSection(self):
        #This is the text box resulting from the search
        self.searchResultFrame = tk.Frame(self.searchViewFrame)
        self.searchResultFrame.grid(row = 1, column =0, ipady = 20, ipadx = 0)
        labelSearch = tk.Label(self.searchResultFrame,text="Les resultats de la recherche ")
        labelSearch.grid(row = 0, column = 0)
        self.textBox = tk.Text(self.searchResultFrame)
        self.textBox.grid(row = 1,column = 0)
        self.SearchButtons = []

    def buildCartSection(self):
         self.inventorySection.grid_forget()
         self.searchViewFrame.grid_forget()

         self.cartFrame.grid(row = 2, column = 0,  ipady = 0)
         labelCart = tk.Label(self.cartFrame, text ="Le panier")
         labelCart.grid(row = 0, column = 1)
         
         self.cartBox.grid(row = 1, column = 1)
         
         self.print_cart_items(cartItems)


    def searchView(self):
        self.inventorySection.grid_forget()
        self.cartFrame.grid_forget()

        self.searchViewFrame.grid(row = 0, column = 0)
        self.frameInput = tk.Frame(self.searchViewFrame)
        self.frameInput.grid(row = 0, column = 0)
        
        self.buildNameFrame()
        self.buildCodeFrame()
        # This block is for the entry of the type
        self.buildTypeFrame()
        self.buildResultSearchSection()
        
                
        self.print_search_result(itemsSearch)
        
        

    def inventoryView(self):
        self.searchViewFrame.grid_forget()
        self.cartFrame.grid_forget()
        self.inventorySection.grid(row = 0, column =1, padx = 20)
        
        # This is the label of the inventory
        inventoryLabel= tk.Label(self.inventorySection, text = "Bienvenu a l'entrepot \n L'entrepot contient les elements suivants")
        inventoryLabel.grid(row = 0, column = 0 , ipadx= 20)
        inventoryTextBox = tk.Text(self.inventorySection)
        inventoryTextBox.grid(row = 1, column = 0, ipadx= 20,ipady = 20)
        for item in inventoryItems:
            inventoryTextBox.insert(tk.END,item +"\n")

        


gui = GUI()
gui.mainloop()
