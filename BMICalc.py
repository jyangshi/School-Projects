def wfunc():
    return float(input("Enter your weight: "))
def hfunc():
    return float(input("Enter your height: "))
def bmi(w, h):
    return w * 703 / h ** 2
def options():
    print("options")
    print("Enter Student's name")
    print("q to quit")
print("This program will calculate an individual's BMI.")
choice = "x"
options()
while choice != "q":
    choice = input("Enter student's name or quit: ")
    if choice != "q":
        w = wfunc()
        h = hfunc()
        print(choice, "'s BMI profile")
        print("Weight: ", w)
        print("Height: ", h)
        print("BMI: {0:.1f}".format(bmi(w, h)))
    elif choice == "q":
        print("Closing...")
