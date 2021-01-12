#include <stdio.h>
#include <math.h>

// for testing only - do not change
void getTestInput(int argc, char* argv[], float* a, float* b)
{
  if (argc == 3) {
    sscanf(argv[1], "%f", a);
    sscanf(argv[2], "%f", b);
  }
}



// add your areaOfCircle function here - it must NOT printf, instead it must
// return the result to be printed in main


static float start;
static float end;
static char input[256];

double areaOfCircle (float rad){
  double area = rad*rad*M_PI;
  return area;
}

void getVals(){
  while(1){
    printf("Start:\n");
    while(1){
      fgets(input, 256, stdin);
      if((sscanf(input,"%f", &start) == 1) && (start > 0)){
        break;
      }
      printf("Invalid start\n");
    }
    printf("End:\n");
    while(1){
      fgets(input, 256, stdin);
      if((sscanf(input,"%f", &end) == 1) && (end > 0)){
        break;
      }
      printf("Invalid end\n");
    }
    if(start <= end) break;
    printf("%f is not greater than or equal to %f \n", start, end);
  }
}

int main(int argc, char* argv[]) 
{
  // the two variables which control the number of times areaOfCircle is called

  if(argc == 3){
    sscanf(argv[1], "%f", &start);
    sscanf(argv[2], "%f", &end);
    if((start < 0) || (end < 0) || (start > end)){
      getVals();
    }
  }else{
    getVals();
  }
  // for testing only - do not change
  getTestInput(argc, argv, &start, &end);

  printf("calculating area of circle starting at %f, and ending at %f\n", start, end);
  
  // add your code below to call areaOfCircle function with values between
  // start and end
  
  for (float i = start; i <= end; i++){
    printf("area of circle with radius of %f: %f\n", i, areaOfCircle(i));
  }  
}
