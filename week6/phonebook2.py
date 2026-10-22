import csv


name = input("Enter a name: ")
number = input("Enter a number: ")

with open("phonebook.csv", "a") as file:
  writer = csv.DictWriter(file, fieldnames=["name", "number"])
  writer.writerow({"name": name, "number": number})