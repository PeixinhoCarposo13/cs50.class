#With wile loop
n = 0
while n < 3:
  print("meaw while loop")
  n += 1

#With for loop
for i in range(3):
  print("meaw for loop")

#with while True loop ( it is an infinite loop but we can break it with a condition)
j = 0
while True:
  print("meaw while True loop")
  j += 1
  if j == 3:
    break

#with function
def meaw():
  print("meaw function")

for i in range(3):
  meaw()
