# include "IMU.h"
    void absloot (double pitch, double Roll, double z){
        static float totalPitch = 0.0;
        static float totalRoll = 0.0;
        static float tolal5z = 0.0;
        static int BestCounter =0;
        if(BestCounter==4){           
            
            
             totalPitch = totalPitch + pitch;
             totalPitch = totalPitch / 5.0;
               //totalPitch = totalPitch + 38.0; 
             printf("M %f;%f#\n", totalPitch,totalPitch );
            // printf("absloot=%f\n", totalPitch);
             BestCounter =0;
             totalPitch = 0.0;
            
             totalRoll = totalRoll + Roll;
             totalRoll = totalRoll / 5.0;
             //printf("absloot=%f\n", totalRoll);
             totalRoll = 0.0;
            
              tolal5z  = tolal5z + z;
             tolal5z = tolal5z / 5.0;
          //   printf("absloot=%f\n", tolal5z);
             tolal5z = 0.0;
       
        } else {
            tolal5z = tolal5z + z;
            totalRoll = totalRoll + Roll;
            totalPitch = totalPitch + pitch;
            BestCounter +=1;
        }
}
// M7;7#
    
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
        
        
        absloot(stAngles.fPitch, stAngles.fRoll, stAngles.fYaw);
        
        bcm2835_delay(100);
	} 
  
  return 0;
}
















































