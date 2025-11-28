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

void rotatePoint(float x, float y, float *out_x, float *out_y,
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

void fourCorners() {

    for (int i = 0; i < 5; i++) {

        for (int j = 0; j < 5; j++) {

            if ((i == 0 || i == 4) && (j == 0 || j == 4)) {

                printf("#");

            }

            else {

                printf(" ");

            }

        }

        printf("\n");

    }

}

void rotateCorners() {

    float corners[4][2] = { 
        { 0, 0 }, 
        { 0, 4 }, 
        { 4, 0 }, 
        { 4, 4 }
    };

    float step = 30; //each step adds %f degrees ^^

    for (int n = 0; n < 12; n++) {

        float angle = (n * step); //(1%f, 2%f, 3%f, ..., n%f) series

        for (int i = 0; i < 4; i++) {

            float x = corners[i][0];
            float y = corners[i][1];

            //rotated (x, y)
            float rx;
            float ry;

            rotatePoint(x, y, &rx, &ry, angle);

            printf("Original Corner (Step %d, Corner %d): (%.2f, %.2f)\n", (n + 1), (i + 1), x, y);
            printf("Rotated Corners (Step %d, Corner %d): (%.2f, %.2f)\n", (n + 1), (i + 1), rx, ry);

        }   

    }

    



}

void drawRotatedSquare(float angle_degrees) {   //rewritten version of rotate corners

    float rx;
    float ry;

    for (int i = 0; i < 4; i++) {

        float x = square[i][0];
        float y = square[i][1];

        rotatePoint(x, y, &rx, &ry, angle_degrees);

        printf("Corner %d: (%.2f, %.2f) -> (%.2f, %.2f)\n", (i + 1), x, y, rx, ry);

    }

}

int main() {

    printf("Original Corners: \n");
    fourCorners();

    //rotateCorners();   <---- taken out for a little while.
    printf("Rotated Corners: \n");
    drawRotatedSquare(45);  //45 degrees

}