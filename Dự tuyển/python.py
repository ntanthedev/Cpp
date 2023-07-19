import requests
import os

for _id in range(30000000, 40000000):
    link = "https://diemthi.tuoitre.vn/csv-thpt-score"
    payload={
        "code":"",
        "data":f"{_id}"
    }
    r = requests.post(link, data=payload)
    text = r.json() 
    if(text['success'] == False):
        print(f"Không tìm thấy {_id}")
    else:
        print(f"Đã tìm thấy {_id}") 
        out= f"SBD: {text['info']['SBD']} \n toán {text['info']['TOAN']} \n văn {text['info']['VA']} \n lý {text['info']['LI']} \n hóa {text['info']['HO']} \n sinh {text['info']['SI']} \n sử {text['info']['SU']} \n địa {text['info']['DI']} \n GDCD {text['info']['GDCD']} \n anh {text['info']['NN']}"
        with open(f"out/{_id}.txt", "a") as f:
            f.write(out)
        f.close()