#include <iostream>
using namespace std;

// Using the Bakhshali method to find in a single iteration.

float bakhshali_sqrt(float S, float N){
  float nsquared = N*N;
  float ssquared = S*S;
  return (nsquared*(nsquared+6*S)+(ssquared)) / (4*N*(nsquared+S));
}

// Using Newton / Babylonian Method

const float ACCURACY = 0.00001;

float newton_sqrt(float input, float guess = 1){
    float xn = input;
    float approx = guess;
  
    while(xn - approx > ACCURACY || xn - approx < -(ACCURACY))
    {
        approx = (approx + xn) / 2;
        xn = input / approx;
    }
    return approx;
}


int main() {
  float x = 42;
  float guess = 6.5;
  float bakhshali = bakhshali_sqrt(42, guess);
  float babylonian = newton_sqrt(42, guess);
  cout << "Using the Bakshali Method, the square root of " << x << " is (+/-)" << bakhshali << endl;
  
  cout << "Using the Babylonian Method, the square root of " << x << " is (+/-)" << babylonian << endl;
  return 0;
}