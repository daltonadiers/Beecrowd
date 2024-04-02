def isBi(x):
    if (x%4==0 and x%100!=0) or x%400==0:
        return True
    return False

def isHulu(x):
    if x%15==0:
        return True
    return False

def isBulu(x):
    if isBi(x) and x%55==0:
        return True
    return False

buffer = ""
control = 0

while True:
    try:
        x = int(input())
        if(isBi(x)):
            if(control > 0):
                buffer += "\n"
            buffer += "This is leap year."
            control += 1
        if(isHulu(x)):
            if(control > 0):
                buffer += "\nThis is huluculu festival year."
            else:
                control += 1
                buffer += "This is huluculu festival year."
        if(isBulu(x)):
            if(control > 0):
                buffer += "\nThis is bulukulu festival year."
            else:
                control += 1
                buffer += "This is bulukulu festival year."
        if(not isBi(x) and not isHulu(x) and not isBulu(x)):
            if(control > 0):
                buffer += "\nThis is an ordinary year."
            else:
                control += 1
                buffer += "This is an ordinary year."
        buffer += "\n"
    except EOFError:
        print(buffer[:len(buffer) - 1])
        break