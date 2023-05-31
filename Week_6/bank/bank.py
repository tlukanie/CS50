from cs50 import get_string

greeting = get_string("Greeting: ")
greeting = [x.strip() for x in greeting.split(',')]
greeting = greeting[0].lower()
if (greeting == "hello"):
    print("$0",end='')
elif (greeting[0] == 'h'):
    print("$20",end='')
else:
    print("$100",end='')
# print(greeting);