while True:
  try:
    n = int(input("Enter with the height: "))

    # Vertical line
    for i in range(n):
      print("#")

    #Horizontal line, this is a pythonic way to print a character multiple times
    print("?"* n)

    # Full Brick, pythonic way to print a character multiple times in a row and then print it multiple times in a column
    for row in range(n):
      print("#"* n)

  except ValueError:
    print("Invalid input.")
    break
