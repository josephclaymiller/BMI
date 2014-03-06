//
//  bmi.c
//  BMI
//
//  Created by Joseph Miller on 3/2/14.
//  Copyright (c) 2014 Joseph Miller. All rights reserved.
//

#include <stdio.h>

// function prototypes
float calculateBMI (const char *unitSystem);
float imperialBMI (float height, float weight);
float metricBMI (float height, float weight);
void displayBMI (float bmi);
float getHeight (const char *heightUnit);
float getWeight (const char *weightUnit);

int main(int argc, const char * argv[])
{
    float bmi;
    static const char *unitSystem;
    
    // Get system of measurment
    if (argc > 1) {
        unitSystem = &argv[1][0];
    } else {
        unitSystem = "i";
    }

    bmi = calculateBMI(unitSystem);
    displayBMI(bmi);
    
    return 0;
}

float getHeight (const char *heightUnit) {
    float height;
    // Get height from user
    printf("Please enter your height in %s: ", heightUnit);
    scanf( "%f", &height );
    return height;
}

float getWeight (const char *weightUnit) {
    float weight;
    // Get weight from user
    printf("Please enter your weight in %s: ", weightUnit);
    scanf( "%f", &weight );
    return weight;
}


float calculateBMI (const char *unitSystem) {
    float height;
    float weight;
    float bmi;
    char *heightUnit = NULL;
    char *weightUnit = NULL;
    
    // get height and weight unit based on system of measurment
    switch (*unitSystem) {
        case 'm':
            //Metric
            heightUnit = "meters";
            weightUnit = "kilograms";
            // Get height and weight from user
            height = getHeight(heightUnit);
            weight = getWeight(weightUnit);
            bmi = metricBMI(height, weight);
            break;
        default:
            //Imperial
            heightUnit = "inches";
            weightUnit = "pounds";
            // Get height and weight from user
            height = getHeight(heightUnit);
            weight = getWeight(weightUnit);
            bmi = imperialBMI(height, weight);
            break;
    }
    
    return bmi;
}

float imperialBMI (float height, float weight) {
    float bmi = (metricBMI(height, weight) * 703);
    return bmi;
}

float metricBMI (float height, float weight) {
    float bmi  = (weight / (height * height));
    return bmi;
}

void displayBMI (float bmi) {
    printf("Your BMI is %f.\n", bmi);
    if (bmi < 18.5) {
        printf("You are underweight.\n"); //Below 18.5 Underweight
    } else if (bmi < 25.0) {
        printf("You are a normal weight.\n"); //18.5 – 24.9 Normal
    } else if (bmi < 30.0) {
        printf("You are overweight.\n"); //25.0 – 29.9 Overweight
    } else {
        printf("You are obese.\n"); //30.0 and Above Obese
    }
}
