import requests

dir = ""
for i in range(1,21):
    dir = str(i).zfill(2)
    url = "http://192.168.1.35/contests/test/PALIND7/PALIND7$"+dir+"/"+"PALIND7.inp"
    baka = requests.get(url)
    with open("test"+dir+".inp", "wb") as f:
        f.write(baka.content)
    
    url = "http://192.168.1.35/contests/test/PALIND7/PALIND7$"+dir+"/"+"PALIND7.out"
    baka = requests.get(url)
    with open("test"+dir+".out", "wb") as f:
        f.write(baka.content)
