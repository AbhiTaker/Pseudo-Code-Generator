import os
from gtts import gTTS
import re
from flask import Flask, render_template, request
from werkzeug import secure_filename
app = Flask(__name__)

def getTextTxt(file_path):
    if(os.path.exists(file_path)):
        pass
    else:
        print("File does not exist")
        exit()

    f = open(file_path,"r")
    return(f.read())

def docsTxt(file_path):
    string_words = getTextTxt(file_path)
    print(string_words)
    tts = gTTS(text=string_words, lang='en')
    tts.save("C:/Users/hp 74tu/Desktop/source_code_voice_over.mp3")
    os.system("mpg321 C:/Users/hp 74tu/Desktop/source_code_voice_over.mp3")


@app.route('/')
def upload_file():
  return '<html><body> <form action = "http://localhost:5000/upload" method = "POST" enctype = "multipart/form-data"><input type = "file" name = "file" /><input type = "submit"/></form></body></html>'
  
@app.route('/upload', methods = ['GET', 'POST'])
def upload_file1():
   if request.method == 'POST':
      f = request.files['file']
      f.save(secure_filename(f.filename))
      ext = f.filename.split('.')
      if ext[1] == "txt":
        docsTxt(f.filename)
      else:
        print('Invalid File')
      return ('file generated successfully')
    
if __name__ == '__main__':
   app.run(debug = True)
