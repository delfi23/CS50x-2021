from cs50 import get_int

# Ask user a height
while True:
    h = get_int("Height: ")
    # If it is between 1-8 then stop while
    if (h >= 1 and h <= 8):
        break
    
# Loop reversed
for i in reversed(range(h)):
    for j in range(0, (h*2)+2, 1):
        if j != h and j != h + 1:
            if i <= j and (i + j) <= (h * 2) + 1:
                # print # and a space bar at the end instead f the default new line
                print("#", end="")
            elif (i + j) <= (h * 2) + 1:
                print(" ", end="")
        else:
            print(" ", end="")
    print()        
