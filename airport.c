#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#include "airport.h"

Airport* createAirport(const char* gpsId,
                       const char* type,
                       const char* name,
                       double latitude,
                       double longitude,
                       int elevationFeet,
                       const char* city,
                       const char* countryAbbrv){

    Airport *airport = (Airport *)malloc(sizeof(Airport) * 1);

    initAirport(airport, gpsId, type, name, latitude, longitude, elevationFeet, city, countryAbbrv);

    return airport;

  }


void initAirport(Airport* airport,
                 const char* gpsId,
                 const char* type,
                 const char* name,
                 double latitude,
                 double longitude,
                 int elevationFeet,
                 const char* city,
                 const char* countryAbbrv){

  airport->gpsId = (char *)malloc(sizeof(char) * strlen(gpsId) + 1);
  strcpy(airport->gpsId, gpsId);
  airport->type = (char *)malloc(sizeof(char) * strlen(type) + 1);
  strcpy(airport->type, type);
  airport->name = (char *)malloc(sizeof(char) * strlen(name) + 1);
  strcpy(airport->name, name);
  airport->latitude = latitude;
  airport->longitude = longitude;
  airport->elevationFeet = elevationFeet;
  airport->city = (char *)malloc(sizeof(char) * strlen(city) + 1);
  strcpy(airport->city, city);
  airport->countryAbbrv = (char *)malloc(sizeof(char) * strlen(countryAbbrv) + 1);
  strcpy(airport->countryAbbrv, countryAbbrv);

    return;
  }


char* airportToString(const Airport* a) {

  char *airportStr = (char *)malloc(sizeof(char) * 100);

  if (a == NULL){
    return NULL;
  }

  sprintf(airportStr, "%s, %s, %s, %f, %f, %d, %s, %s", a->gpsId, a->type, a->name, a->latitude, a->longitude, a->elevationFeet, a->city, a->countryAbbrv);

  return airportStr;

}

double getAirDistance(const Airport* origin, const Airport* destination){

  double distance = 0;
  double lat1 = origin->latitude, lat2 = destination->latitude;
  double long1 = origin->longitude, long2 = destination->longitude;
  double latRadians1 = (lat1/180) * M_PI;
  double latRadians2 = (lat2/180) * M_PI;
  double longRadians1 = (long1/180) * M_PI;
  double longRadians2 = (long2/180) * M_PI;

  distance = acos((sin(latRadians1) * sin(latRadians2)) + (cos(latRadians1) * cos(latRadians2)) * cos(longRadians2 - longRadians1)) * 6371;

    return distance;

}


double getEstimatedTravelTime(const Airport* stops,
                              int size,
                              double aveKmsPerHour,
                              double aveLayoverTimeHrs){

if(stops == NULL){
  return 1;
}
if(aveKmsPerHour < 0){
  return 1;
}

double distance = 0;
for(int i = 1; i < size; i++){
  distance += getAirDistance(&stops[i - 1], &stops[i]);
}

double time = distance/aveKmsPerHour;
double newTime = time + (aveLayoverTimeHrs * (size - 2));

return newTime;

  }
