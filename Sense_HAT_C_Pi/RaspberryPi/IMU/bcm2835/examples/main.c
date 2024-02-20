#include "IMU.h"

void avrig (int x, int y, int z){
        static float tolal5x = 0.0;
        static float tolal5y = 0.0;
        static float tolal5z = 0.0;
        static int BestCounter =0;
        if(BestCounter==4){           
            
            
            tolal5x = tolal5x + x;
             tolal5x = tolal5x / 5.0;
            printf("avrig=%f\n", tolal5x);
            BestCounter =0;
            tolal5x == 0.0;
            
             tolal5y = tolal5y + y;
             tolal5y = tolal5y / 5.0;
            printf("avrig=%f\n", tolal5y);
            tolal5y == 0.0;
            
              tolal5z  = tolal5z + z;
             tolal5z = tolal5z / 5.0;
            printf("avrig=%f\n", tolal5z);
            tolal5z == 0.0;
            
        } else {
            tolal5z = tolal5z + z;
            tolal5y = tolal5y + y;
            tolal5x = tolal5x + x;
            BestCounter +=1;
        }
}
    void absloot (double x, double y, double z){
        static float tolal5x = 0.0;
        static float tolal5y = 0.0;
        static float tolal5z = 0.0;
        static int BestCounter =0;
        if(BestCounter==4){           
            
            
            tolal5x = tolal5x + x;
             tolal5x = tolal5x / 5.0;
            printf("absloot=%f\n", tolal5x);
            BestCounter =0;
            tolal5x == 0.0;
            
             tolal5y = tolal5y + y;
             tolal5y = tolal5y / 5.0;
            printf("absloot=%f\n", tolal5y);
            tolal5y == 0.0;
            
              tolal5z  = tolal5z + z;
             tolal5z = tolal5z / 5.0;
            printf("absloot=%f\n", tolal5z);
            tolal5z == 0.0;
            
        } else {
            tolal5z = tolal5z + z;
            tolal5y = tolal5y + y;
            tolal5x = tolal5x + x;
            BestCounter +=1;
        }
}

    
int main()
{
	IMU_ST_ANGLES_DATA stAngles;
	IMU_ST_SENSOR_DATA stGyroRawData;
	IMU_ST_SENSOR_DATA stAccelRawData;
    IMU_ST_SENSOR_DATA stMagnRawData;

	float temp;
	imuInit();
	

    
	while(1)
	{

        
        imuDataGet( &stAngles, &stGyroRawData, &stAccelRawData, &stMagnRawData);
        
		temp = QMI8658_readTemp();
        
        avrig(stGyroRawData.s16X, stGyroRawData.s16Y, stGyroRawData.s16Z);
        absloot(stAngles.fPitch, stAngles.fRoll, stAngles.fYaw);
        
        bcm2835_delay(100);
	} 
  
  return 0;
}
