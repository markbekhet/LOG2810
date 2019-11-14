import tkinter as tk


# In this class , the attributes will be :
# 1 - master : the main window
# 2 - labelName : the label for the
class GUI(tk.Tk):
    def __init__(self):
        tk.Tk.__init__(self)
        #La taille de l'ecran
        self.geometry("300x200+30+30")
        #
        self.labelName = tk.Label(self, text="Entrer Le nom du produit")
        self.labelName.pack(padx= 5, pady=0, side= tk.LEFT )

        self.entryName = tk.Entry(self)
        self.entryName.pack(padx = 0, pady = 0,side = tk.LEFT )
        self.entryName.pack()
        self.button = tk.Button(self, text="Get", command=self.on_button)
        self.button.pack(padx = 0, pady = 0, side =tk.LEFT )





        self.labelCodeBar = tk.Label(self, text="Entrer le code bar du produit")

    def on_button(self):
        print(self.entryName.get())


gui = GUI()
gui.mainloop()
