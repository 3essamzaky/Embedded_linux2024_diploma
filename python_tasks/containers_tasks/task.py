# import requests 
# from pprint import pprint



# response = requests.get("https://api.ipify.org/?format=json")


# pprint(response.text)


import requests 
from pprint import pprint


res = requests.get("https://ipinfo.io/<YOUR_IP>/geo")

pprint(res.url)



