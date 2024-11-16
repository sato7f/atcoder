f=open('P1','r',encoding='UTF-8')
datalist=f.readlines()
f.close()
for i in range(len(datalist)):
    datalist[i] = list(map(int, datalist[i].split()))
print(type(datalist[1][0]))



a=str(datalist[1][0])
f=open('syuturyoku','a',encoding='UTF-8')
f.write(a)
f.close()