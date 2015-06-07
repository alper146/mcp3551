#include <SPI.h>
unsigned char sspin=8;

unsigned char a;
union{
		int32_t value;
		uint8_t aa[4];
	} c ;
	

void setup(void){
pinMode(12,INPUT);
pinMode(sspin,OUTPUT);
digitalWrite(sspin,HIGH);
SPI.begin();
SPI.setBitOrder(MSBFIRST);
SPI.setDataMode(SPI_MODE3);
SPI.setClockDivider(SPI_CLOCK_DIV16);
Serial.begin(9600);  
}

void loop(void){
 
digitalWrite(sspin,LOW);
while(digitalRead(12)){

digitalWrite(sspin,LOW);

}

c.aa[2]=SPI.transfer(0x00);
c.aa[1]=SPI.transfer(0x00);
c.aa[0]=SPI.transfer(0x00);
c.aa[3]=0x00;
digitalWrite(sspin,HIGH);
//Serial.print("  value--");
//value=value&0xFFFFFF;
/*c.aa[0]=~c.aa[0];
c.aa[1]=~c.aa[1];
c.aa[2]=~c.aa[2];*/
if((c.aa[2]&(1<<6))|(c.aa[2]&(1<<7))){
  c.aa[2]&=~(1<<6);
  Serial.println(c.value);
//c.value=(0x800000)-c.value;
}
else if(c.aa[2]&(1<<5)){
c.value=0x400000-c.value;
Serial.println(c.value);
}

else{
Serial.println(c.value);
}
  delay(10);

}
