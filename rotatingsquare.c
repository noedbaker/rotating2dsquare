#include <stdio.h>
#include <math.h>

#define M_PI 3.14159265358979323846

float square[4][2] = {

    { -1, -1 }, //bottom left
    { 1, -1 },  //bottom right
    { 1, 1 },   //top right
    { -1, 1 }   //top left

};

//use an (x, y) plan to rotate around the origin to destination (x', y')
// x' = x cos(theta) - y sin(theta)
// y' = x sin(theta) + y cos(theta)

void rotate_point(float x, float y, float *out_x, float *out_y,
float angle_degrees) {

    //rotate by 1.5 degrees i guess for 60 outputs per iteration??
    float angle_radians = angle_degrees * (M_PI / 180.0f);

    float cosine = cosf(angle_radians);
    float sine = sinf(angle_radians);

    float rotated_x = ( (x * cosine) - (y * sine) );
    float rotated_y = ( (x * sine) + (y * cosine) );

    *out_x = rotated_x;
    *out_y = rotated_y;

}

int main() {

    for (int i = 0; i < 5; i++) {

        for (int j = 0; j < 5; j++) {

            printf("# ");

        }

        printf("\n");

    }

}