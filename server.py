
from flask import Flask, render_template, url_for, redirect, request
from picamera import PiCamera
from time import sleep
import RPi.GPIO as GPIO
import time
import serial


GPIO.setwarnings(False)
GPIO.setmode(GPIO.BOARD)
buzzer=32
scale=[261, 294, 329, 349, 392, 440, 493, 523]
list=[0,0,4,4,5,5,4,3,3,2,2,1,1,0]

GPIO.setup(buzzer, GPIO.OUT)
p=GPIO.PWM(buzzer, 100)

ser= serial.Serial('/dev/ttyACM0', 115200)


app = Flask(__name__)


@app.route('/')
def home():
    return render_template('index.html')

@app.route('/', methods=['GET','POST'])
def lcdcontrol():

    if "form1" in request.form:
        segment=""
        segment="1"+ request.form["SEGMENT"]
        print(segment)
        ser.write(segment.encode('utf-8'))
    elif "form2" in request.form:
        lcd=""
        lcd = "2" + request.form['LCD']
        print(lcd)
        ser.write(lcd.encode('utf-8'))

    

    return redirect(url_for('home'))

@app.route('/picture')
def taking_picture():
    
    camera = PiCamera()
    camera.capture('/home/pi/webapp/static/image/picture.jpg')

    sleep(2)

    camera.close()
    p.start(10)
    p.ChangeDutyCycle(10)

    for i in range(len(list)):
        p.ChangeFrequency(scale[list[i]])
        print(i)
        time.sleep(1.0)

    p.stop()

    
    return redirect(url_for('home'))



if __name__ == '__main__':
    app.run(debug=True , port= 80, host = '0.0.0.0')
