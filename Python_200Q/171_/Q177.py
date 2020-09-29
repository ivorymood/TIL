from zipfile import *
import os

def compressAll(zipname, folder):
    print('[%s] -> [%s] 압축...' %(folder, zipname))
    with ZipFile(zipname, 'w') as ziph:
        for dirname, subdirs, files in os.walk(folder):
            for file in files:
                ziph.write(os.path.join(dirname, file))

folder = '../171_'
zipname = folder + '.zip'
compressAll(zipname, folder)