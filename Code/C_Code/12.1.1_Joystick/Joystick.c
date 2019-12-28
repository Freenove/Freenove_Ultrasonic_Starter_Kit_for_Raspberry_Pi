/**********************************************************************
* Filename    : Joystick.c
* Description : Read Joystick
* Author      : www.freenove.com
* modification: 2019/12/27
**********************************************************************/
#include <wiringPi.h>
#include <pcf8591.h>
#include <stdio.h>
#include <softPwm.h>

#define address 0x48        //pcf8591 default address
#define pinbase 64          //any number above 64
#define A0 pinbase + 0
#define A1 pinbase + 1
#define A2 pinbase + 2
#define A3 pinbase + 3

#define Z_Pin 1     //define pin for axis Z

int main(void){
    int val_X,val_Y,val_Z;
    
    printf("Program is starting ... \n");
    
    wiringPiSetup();
    
    pinMode(Z_Pin,INPUT);       //set Z_Pin as input pin and pull-up mode
    pullUpDnControl(Z_Pin,PUD_UP);
    pcf8591Setup(pinbase,address);      //initialize PCF8591
    
    while(1){
        val_Z = digitalRead(Z_Pin);  //read digital value of axis Z
        val_Y = analogRead(A0);      //read analog value of axis X and Y
        val_X = analogRead(A1);
        printf("val_X: %d  ,\tval_Y: %d  ,\tval_Z: %d \n",val_X,val_Y,val_Z);
        delay(100);
    }
    return 0;
}

