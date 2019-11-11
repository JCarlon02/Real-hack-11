#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#include "airport.h"


int main(int argc, char **argv) {


  Airport *airport = createAirport("ICO", "Military", "The Blah Blah Airport", 41.948300, -87.655600, 354, "Dimmsdale", "US");
  Airport *airport2 = createAirport("KCI", "Civillian", "Kansas City International", 40.820600, -96.705600, 1203, "Kansas City", "US");
  Airport *airport3 = createAirport("A-51", "Military", "Area-51", 83.2349, -76.3423, 983, "Nevada", "US");
  Airport *airport4 = createAirport("WKD", "Military", "Wakanda Airport", 76.2300, -68.9890, 895, "Wakanda", "AF");


  Airport *stops = (Airport *)malloc(sizeof(Airport) * 4);

  stops[1] = *airport;
  stops[2] = *airport2;
  stops[3] = *airport3;
  stops[4] = *airport4;

  double dist = getAirDistance(airport, airport2);
  double time = getEstimatedTravelTime(stops, 2, 87.3, 2.5);
  printf("%f is the distance between the two airports\n", dist);
  printf("This is the estimated time of travel: %f\n", time);

  int counterPass = 0;

  dist = round(dist);
  time = round(time);

  if(dist == 765){
    if(time == 112){
      printf("PASSED!\n");
      counterPass++;
    }else{
      printf("FAILED!\n");
    }
  } else {
    printf("FAILED!\n");
  }


  dist = getAirDistance(airport3, airport4);
  time = getEstimatedTravelTime(stops, 4, 72.8, 3.5);
  printf("%f is the distance between the two airports\n", dist);
  printf("This is the estimated time of travel: %f\n", time);

  dist = round(dist);
  time = round(time);

  if(dist == 791){
    if(time == 218){
      printf("PASSED!\n");
      counterPass++;
    }else{
      printf("FAILED!\n");
    }
  } else {
    printf("FAILED!\n");
  }


  dist = getAirDistance(airport2, airport4);
  time = getEstimatedTravelTime(stops, 6, 30.8, 7.5);
  printf("%f is the distance between the two airports\n", dist);
  printf("This is the estimated time of travel: %f\n", time);

  dist = round(dist);
  time = round(time);

  if(dist == 4159){
    if(time == 861){
      printf("PASSED!\n");
      counterPass++;
    }else{
      printf("FAILED!\n");
    }
  } else {
    printf("FAILED!\n");
  }

  if(counterPass == 3){
    printf("Percent Passed: 100\n");
  } else if (counterPass == 2){
    printf("Percent Passed: 66.67\n");
  } else if (counterPass == 1){
    printf("Percent Passed: 33.33\n");
  } else{
    printf("Percent Passed: 0");
  }

  return 0;
}
