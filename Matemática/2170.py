t = 0
while True:
    t += 1
    try:
        vals = list(map(float, input().split()))
        z = vals[1] - vals[0]
        z *= 100
        z /= vals[0]
        print(f"Projeto {t}:\nPercentual dos juros da aplicacao: {z:.2f} %\n")
    except EOFError:
        break