from urllib.request import urlopen

url = 'https://www.python.org/'
with urlopen(url) as f:
    doc = f.read().decode()
    with open('pythonhome.html', 'w', encoding='utf-8') as h:
        h.writelines(doc)