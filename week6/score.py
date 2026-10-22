scores = []

for i in range(3):
    try:
        score = float(input(f"Enter score {i + 1}: "))
        # .append() method is used to add an element to the end of the list
        scores.append(score)
    except ValueError:
        print("Invalid input.")
        break

# sum is used for sum all elements in the list and len is used to get the number of elements in the list
average = sum(scores) / len(scores)

print(f"{average:.2f}")