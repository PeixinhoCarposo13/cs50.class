s = str(input("Do you agree?: "))

s = s.lower()

if s in ["y", "yes"]:
  print("You agreed")
elif s in ["n", "no"]:
  print("You disagreed")
else:
  print("Invalid input")