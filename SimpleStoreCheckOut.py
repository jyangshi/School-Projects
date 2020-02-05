print("Welcome to the Self-checkout lane!")
price1 = float(input("Enter price of item 1: "))
price2 = float(input("Enter price of item 2: "))
price3 = float(input("Enter price of item 3: "))
price4 = float(input("Enter price of item 4: "))
price5 = float(input("Enter price of item 5: "))
subtotal = price1 + price2 + price3 + price4 + price5
print("Your subtotal is: ", subtotal)
tax = subtotal * 0.06
print("Sales tax: ", tax)
total = subtotal + tax
print("Total amount due today: ", total)
