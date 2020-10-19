from tkinter import *
from tkinter import ttk
def calculate(*args):

        heigh1 = float(Height.get())
        weigh2 = float(Weight.get())
        heigh=heigh1/100
        weigh=weigh2
        BMI.set(weigh/(heigh*heigh))
        if (BMI.get() <= "18.5"):
            Result.set("You are underweight")
        elif ("18.5" < BMI.get() < "24.9"):
            Result.set("You are healthy")
        elif ("25" < BMI.get() < "29.9"):
            Result.set("You are overweight")
        elif (BMI.get() <= "30"):
            Result.set("You are obese ")




root = Tk()
root.title("BMI Calculator")
root.geometry("650x700")

mainframe = ttk.Frame(root, padding="3 3 12 12")
mainframe.grid(column=0, row=0, sticky=(N, W, E, S))
mainframe.columnconfigure(0, weight=1)
mainframe.rowconfigure(0, weight=1)

Height = StringVar()
Weight=StringVar()
BMI = StringVar()
Result=StringVar()

height_entry=ttk.Entry(mainframe,width=7,textvariable=Weight)
height_entry.grid(column=4,row=1,sticky=(N,S))
weight_entry = ttk.Entry(mainframe, width=7, textvariable=Height)
weight_entry.grid(column=2, row=1, sticky=(W, E))

ttk.Button(mainframe, text="Calculate the BMI", command=calculate).grid(column=2, row=2, sticky=E)

ttk.Label(mainframe, text="Height(cm)").grid(column=1, row=1, sticky=W)
ttk.Label(mainframe,text="Weight(kg)").grid(column=3,row=1,sticky=E)
ttk.Label(mainframe, text="Your BMI").grid(column=2, row=3, sticky=W)
ttk.Label(mainframe, text="BMI").grid(column=1, row=5, sticky=W)
ttk.Label(mainframe, text="Weight(Kg)").grid(column=4, row=5, sticky=W)
ttk.Label(mainframe, text="Body State").grid(column=2, row=5, sticky=W)
ttk.Label(mainframe, text="Height(cm)").grid(column=5, row=5, sticky=E)
ttk.Label(mainframe, text="<18.5").grid(column=1, row=6, sticky=W)
ttk.Label(mainframe, text="48").grid(column=4, row=6, sticky=W)
ttk.Label(mainframe, text="Underweight").grid(column=2, row=6, sticky=W)
ttk.Label(mainframe, text="150").grid(column=5, row=6, sticky=W)
ttk.Label(mainframe, text="18.5-24.9").grid(column=1, row=7, sticky=W)
ttk.Label(mainframe, text="56").grid(column=4, row=7, sticky=W)
ttk.Label(mainframe, text="Healthy weight").grid(column=2, row=7, sticky=W)
ttk.Label(mainframe, text="160").grid(column=5, row=7, sticky=W)
ttk.Label(mainframe, text="25-29.9").grid(column=1, row=8, sticky=W)
ttk.Label(mainframe, text="67").grid(column=4, row=8, sticky=W)
ttk.Label(mainframe, text="Overweight").grid(column=2, row=8, sticky=W)
ttk.Label(mainframe, text="170").grid(column=5, row=8, sticky=W)
ttk.Label(mainframe, text=">29.9").grid(column=1, row=9, sticky=W)
ttk.Label(mainframe, text="81").grid(column=4, row=9, sticky=W)
ttk.Label(mainframe, text="Obese").grid(column=2, row=9, sticky=W)
ttk.Label(mainframe, text="180").grid(column=5, row=9, sticky=W)
bmi_entry=ttk.Entry(mainframe,width=19,textvariable=BMI)
bmi_entry.grid(column=3,row=3,sticky=(E))

ttk.Button(mainframe, text="Result", command=calculate).grid(column=2, row=11, sticky=E)


result_entry = Entry(mainframe, width=24, textvariable=Result)
result_entry.grid(column=3, row=11, sticky=(E))

for child in mainframe.winfo_children(): child.grid_configure(padx=10, pady=10)


root.mainloop()
