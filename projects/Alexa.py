from gtts import gTTS
import vlc
import speech_recognition as sr
import pyttsx3 
import datetime


my_lang = "ar"

def speak(my_text):
        myobj = gTTS(text=my_text,lang=my_lang,slow=False,)

        myobj.save("welcome.mp4")

        p = vlc.MediaPlayer("welcome.mp4")
        p.play()
def get_time():
     return datetime.datetime.now().strftime("%H:%M:%S")   



r = sr.Recognizer()

def listen():
     
    try:
        with sr.Microphone() as source:
          print("listening...")

                    

          r.adjust_for_ambient_noise(source)
                
          my_audio = r.listen(source)
                
          command = r.recognize_google(my_audio,language = my_lang)
          if 'اليكسا' in command or 'أليكسا' in command or 'إليكسا' in command:
            print(command)
            speak('حبيبي')   
            return command
               
    except:
        speak('قول تاني يسطا')




def compare(word_list,myVoice):
      return myVoice in word_list
          
          
     
def response():
     
    state = True
    while state:
        my_voice = listen()
        print(my_voice)
        
        if 'انهاء' in my_voice:
            state = False
        elif compare(['الوقت','وقت','الساعة','الساعه','ساعه'],my_voice):
            speak("الساعه الان هي "+get_time())
    speak('مع السلامه')


          
response()