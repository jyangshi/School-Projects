class Player:
    def __init__(self, name, phone, jerseyNumber):
        self.name = name
        self.phone = phone
        self.jerseyNumber = jerseyNumber
def menu():
    print("----------Main Menu----------")
    print("1. Display team Roster")
    print("2. Add team member")
    print("3. Remove team member")
    print("4. Edit team member")
    print("9. Exit")
def print_team(team):
    print("Team Roster:")
    if len(team) == 0:
        print("No players in the team")
    else:
        for x in team.keys():
            print("Name:", x)
            print("Phone number:", team[x].phone)
            print("Jersey number:", team[x].jerseyNumber)
def add_player(team):
    name = input("Type in a name to add: ")
    phone = input("Type in phone number: ")
    number = input("Type in jersey number: ")
    roster[name] = Player(name, phone, number)
def remove_player(team):
    remove = input("What name would you like to remove: ")
    if remove in team:
        del team[remove]
    else:
        print(remove, "was not found")
def edit_player(team):
    old_name = input("What name would you like to change: ")
    if old_name in team:
        new_name = input("What is the new name: ")
        phone = input("What is the new phone number: ")
        number = input("What is the new jersey number: ")
        if old_name == new_name:
            team[old_name].phone = phone
            team[old_name].jerseyNumber = number
        else:
            del team[old_name]
            team[new_name] = Player(new_name, phone, number)
    else:
        print(old_name, "was not found")

roster = {}
choice = 0
menu()
while choice != 9:
    choice = int(input("Pick a number: "))
    if choice == 1:
       print_team(roster)
    elif choice == 2:
       add_player(roster)
    elif choice == 3:
        remove_player(roster)
    elif choice == 4:
        edit_player(roster)
print("Exiting...")
