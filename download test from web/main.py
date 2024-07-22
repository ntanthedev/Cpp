import requests

dir = ""
for i in range(1,100):
    dir = str(i).zfill(2)
    url = "http://172.16.16.135/contests/test/XN/test"+dir+"/"+"xn.inp"
    baka = requests.get(url)
    with open("test"+dir+".inp", "wb") as f:
        f.write(baka.content)
    
    url = "http://172.16.16.135/contests/test/XN/test"+dir+"/"+"xn.out"
    baka = requests.get(url)
    with open("test"+dir+".out", "wb") as f:
        f.write(baka.content)
