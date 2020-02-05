name=0
print("Gross Pay Calculator")
name = input("Enter your name or 0 to exit: ")
if name == "0":
    print("Exiting...")
else:
    hours = float(input("Hours Worked: "))
    payrate = float(input("Payrate: "))
    if hours <= 40:
        print("Employee's name: ", name)
        pay = hours * payrate
        print("Gross pay: ", pay)
    elif hours > 40:
        overtime = hours - 40
        pay = 40 * payrate
        print("Employee's name: ", name)
        print("Overtime hours: ", overtime)
        overrate = payrate * 1.5
        overpay = overtime * overrate
        print("Regular hours: ", hours)
        print("Overtime pay: ", overpay)
        print("Regular pay: ", pay)
        gross = pay + overpay
        print("Gross pay: ", gross)
