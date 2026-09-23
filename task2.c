#include <stdio.h>
#include <ctype.h>

double toCelsius(double value, char scale) {
    if (scale == 'C') {
	return value;
    } else if (scale == 'F') {
	return (value - 32)*5.0/9.0;
    } else if (scale == 'K') {
	return value - 273.15;
    }
    return value;
}

double fromCelsius(double celsius, char scale) {
    if (scale == 'C') {
	return celsius;
    } else if (scale == 'F') {
	return celsius * 9.0 / 5.0 + 32;
    } else if (scale == 'K') {
	return celsius + 273.15;
    } 
    return celsius;
}

int isValidScale(char scale) {
    scale = toupper(scale);
    if (scale == 'C' || scale == 'F' || scale == 'K') {
	return 1;
    }
    return 0;
}

int main(void) {
    double value;
    char fromScale, toScale;

    printf("Enter the temperature value: ");
    scanf("%lf", &value);

    printf("Enter the original scale (C, F, or K): ");
    scanf(" %c", &fromScale);

    printf("Enter the scale to convert to (C, F, or K): ");
    scanf(" %c", &toScale);

    if (!isValidScale(fromScale) || !isValidScale(toScale)) {
	printf("Invalid scale entered.\n");
        return 1;
    }

    double celsius = toCelsius(value, fromScale);
    double converted = fromCelsius(celsius, toScale);
    printf("Converted temperature: %.2f %c\n", converted, toScale);
    
    if (celsius < 0) {
        printf("Temperature category: Freezing\n");
        printf("Weather advisory: Wear a heavy coat!\n");
    } else if (celsius < 10) {
        printf("Temperature category: Cold\n");
        printf("Weather advisory: Wear a jacket!\n");
    } else if (celsius < 25) {
        printf("Temperature category: Comfortable\n");
        printf("Weather advisory: Enjoy the nice weather!\n");
    } else if (celsius < 35) {
        printf("Temperature category: Hot\n");
        printf("Weather advisory: Drink lots of water!\n");
    } else {
        printf("Temperature category: Extreme Heat\n");
        printf("Weather advisory: Stay indoors!\n");
    }
    return 0;
}
