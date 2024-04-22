# bai toan ma di tuan
# Bai toan: co the di chuyen theo cac buoc nhu sau:
# 2 buoc sang va 1 buoc len
# 1 buoc sang va 2 buoc len
# Tim so cach di tuan tu o (0,0) den o (x,y) trong mat phang
import numpy as np
def di_tuan(x, y):
    # Khoi tao ma tran luu so cach di tuan
    a = np.zeros((x+1, y+1))
    # Khoi tao so cach di tuan tu o (0,0) den o (0,0) la 1
    a[0][0] = 1
    # Tinh so cach di tuan tu o (0,0) den o (x,y)
    for i in range(1, x+1):
        a[i][0] = a[i-1][0] + a[i-2][1]
    for j in range(1, y+1):
        a[0][j] = a[0][j-1] + a[1][j-2]
    for i in range(1, x+1):
        for j in range(1, y+1):
            a[i][j] = a[i-1][j] + a[i][j-1]
    return a[x][y]
# Test
print(di_tuan(3, 3)) # 6
print(di_tuan(4, 4)) # 20
print(di_tuan(5, 5)) # 70
print(di_tuan(6, 6)) # 252
print(di_tuan(7, 7)) # 924
print(di_tuan(8, 8)) # 3432
print(di_tuan(9, 9)) # 12870