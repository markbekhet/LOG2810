import tkinter as tk
from tkinter import filedialog
from tkinter import Canvas
items = ["Var" , "option"]

def NewFile():
    print("New File!")
def OpenFile():
    name = filedialog.askopenfilename()
    print(type(name))
def About():
    print("This is a simple example of a menu")
# In this class , the attributes will be :
# 1 - master : the main window
# 2 - labelName : the label for the name entry
# 3 - entryName: the name of the product is written here
# 4 - 
class GUI(tk.Tk):
    def __init__(self):
        tk.Tk.__init__(self)
        self.buildMenu()
        #this frame is for the Input frame in general
        self.frameInput = tk.Frame(self)
        self.frameInput.grid(row = 0, column = 0)
        
        self.buildNameFrame()

        self.buildCodeFrame()
        # This block is for the entry of the type
        self.buildTypeFrame()
        
        #This is the text box resulting from the search
        self.textBox = tk.Text(self)
        self.textBox.grid(row = 2, column =0, pady = 20)
        self.print_search_result(items)
        



    # those three functions are for the connectors between the graphic interface and the classes of the model
    def on_button_entryName(self):
        print(self.entryName.get())

    def on_button_entryCode(self):
        print(self.entryCode.get())

    def on_button_entryType(self):
        print(self.entryType.get())

    def print_search_result(self,DataList):
        for item in DataList:
            self.textBox.insert(tk.END,item+"\n")
            
            
            

    #building the GUI
    # 1- buildMenu()
    # 2- buildNameFrame()
    # 3- buildCodeFrame()
    # 4- buildTypeFrame()
    #  
    def buildMenu(self):
        menu = tk.Menu(self)
        self.config(menu=menu)
        filemenu = tk.Menu(menu)
        menu.add_cascade(label="File", menu=filemenu)
        filemenu.add_command(label="New", command=NewFile)
        filemenu.add_command(label="Open...", command=OpenFile)
        filemenu.add_separator()
        filemenu.add_command(label="Exit", command=self.quit)
        helpmenu = tk.Menu(menu)
        menu.add_cascade(label="Help", menu=helpmenu)
        helpmenu.add_command(label="About...", command=About)

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


gui = GUI()
gui.mainloop()
