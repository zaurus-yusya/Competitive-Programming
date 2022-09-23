
ls = []
ls2 = []
X = 500000
for i in range(X):
    ls.append(str(i))
    ls2.append(str((i + 100) % X))

str_ls = " ".join(ls)
str_ls2 = " ".join(ls2)


with open('./test_input.txt', 'w') as f:
    f.write(str(14) + "\n")

    for i in range(14):
        f.write(str(X) + " " + str(100) + "\n")
        f.write(str_ls + "\n")
        f.write(str_ls2 + "\n")


