#include<SD.h>;
#include<SPI.h>;
#include<TMRpcm.h>;

int sensor=A0;
TMRpcm tmr;
const int chipselect=4;
File myfile;  //creating an object 

void setup() {

tmr.speakerPin = 9;
pinMode(chipselect,OUTPUT);
 pinMode(sensor,INPUT);
Serial.begin(9600);
//checking whether the sd opens or nor
if(!SD.begin(chipselect)){
Serial.println("file not found");
}
if(SD.exists("music1.wav")){
Serial.println("file exists");
}
if(SD.remove("music1.wav")==true){
Serial.println("the sd is removed");
}
else{
Serial.println("the file couldnot be removed");
}
myfile=SD.open("music1.wav",FILE_READ);
  if (myfile) {
    tmr.play("music1.wav");
 tmr.volume(2);

    // read from the file until there's nothing else in it:
    while (myfile.available()) {
      Serial.write(myfile.read());
    }
    // close the file:
    myfile.close();
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening test.txt");
  }
 
}
void loop() {

int value=analogRead(sensor);
//myfile=SD.open("myfile.txt",FILE_WRITE");
Serial.println(value);
if (value<=200){
tmr.play("music1.wav");

}
else{
tmr.play("music2.wav");
}
}
