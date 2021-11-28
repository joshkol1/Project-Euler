from decimal import *

def main():
    getcontext().prec = 15
    choose = 1
    falling = 1
    top = 0
    bottom = 9900
    for i in range(23):
        sign = 1 if i%2 == 0 else -1
        top += choose*falling*sign
        choose = choose*(22-i)/(i+1)
        falling *= 76+i
        bottom *= 76+i
    top *= 25*4*23
    print("{:.12f}".format(Decimal(top)/Decimal(bottom)))
    return 0

if __name__ == "__main__":
    main()