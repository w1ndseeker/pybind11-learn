from build.pysoadd import pyadd

a = pyadd(1.2,2.3) # 重载构造
print(a.sum(2.4,4.4)) #重载加法
print(a.sum()) #默认加法

b = pyadd() #默认构造
print(b.sum(0.1,0.2)) #重载加法