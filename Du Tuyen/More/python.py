import requests

dir = ""
for i in range(1,41):
    dir = str(i).zfill(2)
    url = "http://172.16.23.55/contests/test/ADN/test"+dir+"/"+"ADN.inp"
    baka = requests.get(url)
    with open("test"+dir+".inp", "wb") as f:
        f.write(baka.content)
    
    url = "http://172.16.23.55/contests/test/ADN/test"+dir+"/"+"ADN.out"
    baka = requests.get(url)
    with open("test"+dir+".out", "wb") as f:
        f.write(baka.content)