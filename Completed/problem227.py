import numpy as np

coefs = np.zeros([50, 50])

for i in np.arange(50):
    if i == 0:
        coefs[i, 0] = 19/36
        coefs[i, 1] = 2/9
        coefs[i, 2] = 1/36
    elif i == 1:
        coefs[i, 0] = 2/9
        coefs[i, 1] = 1/2
        coefs[i, 2] = 2/9
        coefs[i, 3] = 1/36
    elif i == 48:
        coefs[i, 46] = 1/36
        coefs[i, 47] = 2/9
        coefs[i, 48] = 19/36
        coefs[i, 49] = 2/9
    elif i == 49:
        coefs[i, 47] = 1/18
        coefs[i, 48] = 4/9
        coefs[i, 49] = 1/2
    else:
        coefs[i, i-2] = 1/36
        coefs[i, i-1] = 2/9
        coefs[i, i] = 1/2
        coefs[i, i+1] = 2/9
        coefs[i, i+2] = 1/36

coefs -= np.identity(50)

b = -1*np.ones(50)
sol = np.linalg.solve(coefs, b)
print(sol[49])