people = {

  "name": "Alice", "number": "1", 
  "name": "Bob", "number": "2", 
  "name": "Charlie", "number": "3", 
  "name": "David", "number": "4", 
  "name": "Eve", "number": "5"
  
}

name = input("Enter a name: ")

for person in people:
  if person["name"] == name:
    print(f"{name}'s number is {person["number"]}.")
    break
  else:
    print(f"{name} is not in the phonebook.")