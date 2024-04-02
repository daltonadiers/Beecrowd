while True:
    try:
        n = int(input())
        base = 1
        digits=1
        while base % n !=0:
            base = (10*base+1)%n
            digits+=1
        print(digits)
    except EOFError:
        break