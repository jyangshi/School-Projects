print("Welcome to the Team Manager")
menu = 0
roster = []
while menu != 9:
    print("----------Main Menu----------")
    print("1. Display team Roster")
    print("2. Add team member")
    print("3. Remove team member")
    print("4. Edit team member")
    print("9. Exit")
    menu = int(input("Pick an item from the menu: "))
    if menu == 1:
        current = 0
        if len(roster) > 0:
            while current < len(roster):
                print(current, ".", roster[current])
                current = current + 1
        else:
            print("List is empty")
    elif menu == 2:
        name = input("Type in a name to add: ")
        roster.append(name)
    elif menu == 3:
        remove = input("What name would you like to remove: ")
        if remove in roster:
            item_number = roster.index(remove)
            del roster[item_number]
        else:
            print(remove, "was not found")
    elif menu == 4:
        old = input("What name would you like to change: ")
        if old in roster:
            item_number = roster.index(old)
            new = input("What is the new name: ")
            roster[item_number] = new
        else:
            print(old, "was not found")

print("Exiting...")
