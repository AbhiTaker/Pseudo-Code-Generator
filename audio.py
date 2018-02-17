from gtts import gTTS
 
# This module is imported so that we can 
# play the converted audio
import os
 
# The text that you want to convert to audio
with open('output.txt', 'r') as myfile:
    data=myfile.read().replace('\n', '')
mytext = data;
 
# Language in which you want to convert
language = 'en'
 
# Passing the text and language to the engine, 
# here we have marked slow=False. Which tells 
# the module that the converted audio should 
# have a high speed
myobj = gTTS(text=mytext, lang=language, slow=False)
 
# Saving the converted audio in a mp3 file named
# welcome 
myobj.save("source_code_voice_over.mp3")
 
# Playing the converted file
os.system("mpg321 source_code_voice_over.mp3")
