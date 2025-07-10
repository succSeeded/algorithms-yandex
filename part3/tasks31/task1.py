f = open("input.txt", "r")
n = int(f.readline())
f.close()

f = open("output.txt", "a")
out = 1

for i in range(n):
    out *= i+1

f.write(str(out))
f.close()